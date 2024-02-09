#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;


stack<double> nums;
stack<char> ops;
void clear() {
    while (ops.size()) ops.pop();
    while (nums.size()) nums.pop();
}
void eval() {
    double b = nums.top();
    nums.pop();
    double a = nums.top();
    nums.pop();
    double c = 0;
    char op = ops.top();
    ops.pop();
    if (op == '+') {
        c = a + b;
    } else if (op == '-') {
        c = a - b;
    } else if (op == '*') {
        c = a * b;
    } else if (op == '/') {
        if (b == 0)
            c = 100000000;
        else
            c = a / b;
    }
    nums.push(c);
}
static unordered_map<char, int> pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
double calc_one(const string& str) {
    clear();
    int n = (int)str.size();
    for (int i = 0; i < n; ++i) {
        char c = str[i];
        if (isdigit(c)) {
            int j = i, v = 0;
            while (j < n && isdigit(str[j])) {
                v = v * 10 + str[j++] - '0';
            }
            i = j - 1;
            nums.push(v);
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (ops.size() && ops.top() != '(') eval();
            ops.pop();
        } else {
            while (ops.size() && pr[ops.top()] >= pr[c]) eval();
            ops.push(c);
        }
    }
    while (ops.size()) eval();
    double ret = nums.top();
    clear();
    return ret;
}

#define ADDSUB(op) (*op == '+' || *op == '-')
#define MULDIV(op) (*op == '*' || *op == '/')
// same priority
#define SP2(op1, op2) (pr[*op1] == pr[*op2])
// same priority
#define SP3(op1, op2, op3) (pr[*op1] == pr[*op2] && pr[*op2] == pr[*op3])
#define DECP2(op1, op2) (pr[*op1] >= pr[*op2])
#define INCP2(op1, op2) (pr[*op1] <= pr[*op2])
#define DECP3(op1, op2, op3) (pr[*op1] >= pr[*op2] && pr[*op2] >= pr[*op3])
#define INCP3(op1, op2, op3) (pr[*op1] <= pr[*op2] && pr[*op2] <= pr[*op3])
bool swapablelr(const char* op) {
    return *op == '+' || *op == '*';
}
bool checkp2(const char* op, int l, int r) {
    if ((*op == '+' || *op == '*') && l < r) return false;
    return true;
}
bool checkp3(const char* op1, const char* op2, int v1, int v2, int v3) {
    if (SP2(op1, op2) && swapablelr(op1) && v1 < v2) return false;
    if (SP2(op1, op2) && swapablelr(op2) && v1 < v3) return false;
    if (*op1 == '-' && *op2 == '+' && v2 == v3) return false;  // -x+x = +x-x
    if (*op1 == '/' && *op2 == '*' && v2 == v3) return false;  // /x*x = *x/x
    if (pr[*op2] > pr[*op1] && swapablelr(op2) && v2 < v3) return false;
    if (pr[*op1] < pr[*op2] && swapablelr(op1)) return false;
    if (SP2(op1, op2) && v2 < v3) return false;
    return true;
}
bool checkdiv1(const char* op, int v) {
    if (*op == '/' && v == 1) return false;
    return true;
}
const char* trans(const char* pattern) {
    static unordered_map<const char*, string> dict;
    auto it = dict.find(pattern);
    if (it == dict.end()) {
        string p = pattern;
        string& to = dict[pattern];
        for (int i = 0; i < (int)p.size(); ++i) {
            if (p[i] >= 'a' && p[i] <= 'z') {
                to += "%d";
            } else if (p[i] == '.') {
                to += "%s";
            } else {
                to += p[i];
            }
        }
        return to.c_str();
    }
    return it->second.c_str();
}
unordered_set<string> calc(vector<int>&& d) {
    unordered_set<string> ret;
    vector<string> ops = {"+", "-", "*", "/"};
    vector<string> full;
    auto add = [&full](const char* fmt, int e, int f, int g, int h, const char* o1, const char* o2, const char* o3) {
        char tmp[64] = {0};
        std::snprintf(tmp, 64, fmt, e, o1, f, o2, g, o3, h);
        full.push_back(tmp);
    };
    function<bool(int, int, int, int, const char*, const char*, const char*)> op1swapab =
        [](int a, int b, int, int, const char* op1, const char*, const char*) -> bool {
        if (*op1 == '+' || *op1 == '*') return a >= b;
        return true;
    };
    vector<pair<string, function<bool(int, int, int, int, const char*, const char*, const char*)>>> patterns;
    patterns.push_back(
        {trans("a.b.c.d"), [](int a, int b, int c, int d, const char* op1, const char* op2, const char* op3) -> bool {
             if (!checkp2(op1, a, b)) return false;
             if (!checkdiv1(op1, b)) return false;
             if (!checkdiv1(op2, c)) return false;
             if (!checkdiv1(op3, d)) return false;
             if (swapablelr(op1) && pr[*op2] > pr[*op1]) return false;
             if (swapablelr(op2) && pr[*op3] > pr[*op2]) return false;
             if (pr[*op3] > pr[*op2] && c < d) return false;
             if (*op2 == '-' && *op3 == '+' && c == d) return false;  // -x+x = +x-x
             if (*op2 == '/' && *op3 == '*' && c == d) return false;  // /x*x = *x/x
             if (*op1 == '/' && *op2 == '*' && b == c) return false;  // /x*x = *x/x
             if (SP2(op2, op3) && c < d) return false;
             if (SP3(op1, op2, op3) && (b < c || c < d)) return false;
             if (SP2(op1, op2) && pr[*op2] >= pr[*op3] && (a < b || b < c)) return false;
             if (SP3(op1, op2, op3) && swapablelr(op2) && a < c) return false;
             if (SP3(op1, op2, op3) && swapablelr(op3) && a < d) return false;
             if (swapablelr(op3) && swapablelr(op2) && pr[*op2] <= pr[*op3] && c < d) return false;
             if (swapablelr(op3) && swapablelr(op2) && pr[*op2] < pr[*op3]) return false;  // a.b+c*d = c*d+a.b
             return true;
         }});
    patterns.push_back(
        {trans("(a.b).c.d"), [](int a, int b, int c, int d, const char* op1, const char* op2, const char* op3) -> bool {
             if (DECP3(op1, op2, op3)) return false;
             if (!checkp2(op1, a, b)) return false;
             if (!checkdiv1(op1, b)) return false;
             if (!checkdiv1(op2, c)) return false;
             if (!checkdiv1(op3, d)) return false;
             if (pr[*op1] >= pr[*op2]) return false;
             if (SP2(op2, op3) && c < d) return false;
             if (SP2(op1, op2) && pr[*op2] >= pr[*op3] && (a < b || b < c)) return false;
             if (swapablelr(op3) && swapablelr(op2) && pr[*op2] <= pr[*op3] && c < d) return false;
             if (swapablelr(op3) && swapablelr(op2) && pr[*op2] < pr[*op3]) return false;  // (a.b)+c*d = c*d+a.b
             return true;
         }});
    patterns.push_back(
        {trans("a.(b.c).d"), [](int a, int b, int c, int d, const char* op1, const char* op2, const char* op3) -> bool {
             if (DECP3(op1, op2, op3)) return false;
             if (*op1 == '-' && *op2 == '-') return false;  // a-(b-c).d = (c-b).d + a
             if (!checkp2(op2, b, c)) return false;
             if (!checkdiv1(op2, c)) return false;
             if (!checkdiv1(op3, d)) return false;
             if (pr[*op1] <= pr[*op3] && swapablelr(op1)) return false;
             if (pr[*op1] >= pr[*op3] && swapablelr(op1)) return false;
             if (SP2(op1, op3) && swapablelr(op3) && a < d) return false;
             return true;
         }});
    patterns.push_back(
        {trans("a.b.(c.d)"), [](int a, int b, int c, int d, const char* op1, const char* op2, const char* op3) -> bool {
             if (SP3(op1, op2, op3)) return false;
             if (!checkdiv1(op1, b)) return false;
             if (!checkdiv1(op3, d)) return false;
             if (*op2 == '-' && *op3 == '-') return false;  // a.b-(c-d) = (a.b)-c+d
             if (pr[*op1] == pr[*op2]) return false;
             if (pr[*op2] >= pr[*op1] && swapablelr(op1)) return false;
             if (pr[*op3] >= pr[*op2]) return false;
             // if (pr[*op2] >= pr[*op1] && swapablelr(op2)) return false;
             if (swapablelr(op2)) return false;
             if (!checkp2(op3, c, d)) return false;
             if (swapablelr(op1) && SP2(op1, op2) && a < b) return false;
             return true;
         }});
    patterns.push_back(
        {trans("(a.b.c).d"), [](int a, int b, int c, int d, const char* op1, const char* op2, const char* op3) -> bool {
             if (DECP3(op1, op2, op3)) return false;
             if (DECP2(op1, op2) && swapablelr(op1) && a < b) return false;
             if (!checkp3(op1, op2, a, b, c)) return false;
             if (!checkdiv1(op1, b)) return false;
             if (!checkdiv1(op2, c)) return false;
             if (!checkdiv1(op3, d)) return false;
             return true;
         }});
    patterns.push_back(
        {trans("a.(b.c.d)"), [](int a, int b, int c, int d, const char* op1, const char* op2, const char* op3) -> bool {
             if (DECP3(op1, op2, op3)) return false;
             if (swapablelr(op1)) return false;
             if (*op1 == '-' && *op2 == '-') return false;  // a-(b-c.d) = a-b+c.d
             if (!checkp3(op2, op3, b, c, d)) return false;
             if (!checkdiv1(op2, c)) return false;
             if (!checkdiv1(op3, d)) return false;
             return true;
         }});
    patterns.push_back({trans("(a.b).(c.d)"),
                        [](int a, int b, int c, int d, const char* op1, const char* op2, const char* op3) -> bool {
                            if (DECP3(op1, op2, op3)) return false;
                            if (!checkp2(op1, a, b)) return false;
                            if (!checkp2(op3, c, d)) return false;
                            if (pr[*op2] <= pr[*op3]) return false;
                            if (pr[*op1] >= pr[*op2]) return false;
                            if (swapablelr(op2) && !((a >= c && a >= d) || (b >= c && b >= d))) return false;
                            if (!checkdiv1(op1, b)) return false;
                            if (!checkdiv1(op3, d)) return false;
                            return true;
                        }});
    patterns.push_back({trans("((a.b).c).d"),
                        [](int a, int b, int c, int d, const char* op1, const char* op2, const char* op3) -> bool {
                            if (DECP3(op1, op2, op3)) return false;
                            if (pr[*op1] >= pr[*op2]) return false;
                            if (pr[*op2] >= pr[*op3]) return false;
                            if (!checkp2(op1, a, b)) return false;
                            if (!checkdiv1(op1, b)) return false;
                            if (!checkdiv1(op2, c)) return false;
                            if (!checkdiv1(op3, d)) return false;
                            return true;
                        }});
    patterns.push_back({trans("(a.(b.c)).d"),
                        [](int a, int b, int c, int d, const char* op1, const char* op2, const char* op3) -> bool {
                            if (DECP3(op1, op2, op3)) return false;
                            if (swapablelr(op1)) return false;
                            if (pr[*op2] >= pr[*op1]) return false;
                            if (pr[*op1] >= pr[*op3]) return false;
                            if (!checkp2(op2, b, c)) return false;
                            if (!checkdiv1(op2, c)) return false;
                            if (!checkdiv1(op3, d)) return false;
                            return true;
                        }});
    patterns.push_back({trans("a.((b.c).d)"),
                        [](int a, int b, int c, int d, const char* op1, const char* op2, const char* op3) -> bool {
                            if (DECP3(op1, op2, op3)) return false;
                            if (swapablelr(op1)) return false;
                            if (!checkp2(op2, b, c)) return false;
                            if (pr[*op2] >= pr[*op3]) return false;
                            if (pr[*op3] >= pr[*op1]) return false;
                            if (!checkdiv1(op2, c)) return false;
                            if (!checkdiv1(op3, d)) return false;
                            return true;
                        }});
    patterns.push_back({trans("a.(b.(c.d))"),
                        [](int a, int b, int c, int d, const char* op1, const char* op2, const char* op3) -> bool {
                            if (DECP3(op1, op2, op3)) return false;
                            if (pr[*op3] >= pr[*op2]) return false;
                            if (pr[*op2] >= pr[*op1]) return false;
                            if (swapablelr(op1)) return false;
                            if (swapablelr(op2)) return false;
                            if (!checkp2(op3, c, d)) return false;
                            if (!checkdiv1(op3, d)) return false;
                            return true;
                        }});

    for (int i = 0; i < 4; ++i) {
        int e = d[i];
        for (int j = 0; j < 4; ++j) {
            if (j == i) continue;
            int f = d[j];
            for (int k = 0; k < 4; ++k) {
                if (k == i || k == j) continue;
                int g = d[k];
                for (int l = 0; l < 4; ++l) {
                    if (l == i || l == j || l == k) continue;
                    int h = d[l];
                    for (const string& op1 : ops) {
                        const char* o1 = op1.c_str();
                        for (const string& op2 : ops) {
                            const char* o2 = op2.c_str();
                            for (const string& op3 : ops) {
                                const char* o3 = op3.c_str();
#ifndef FULLMODE
                                for (auto p : patterns) {
                                    if (p.second(e, f, g, h, o1, o2, o3)) {
                                        add(p.first.c_str(), e, f, g, h, o1, o2, o3);
                                    }
                                }
#endif
#ifdef FULLMODE
                                //(a.b).c.d
                                add("(%d%s%d)%s%d%s%d", e, f, g, h, o1, o2, o3);
                                // a.(b.c).d
                                add("%d%s(%d%s%d)%s%d", e, f, g, h, o1, o2, o3);
                                // a.b.(c.d)
                                add("%d%s%d%s(%d%s%d)", e, f, g, h, o1, o2, o3);
                                //(a.b.c).d
                                add("(%d%s%d%s%d)%s%d", e, f, g, h, o1, o2, o3);
                                // a.(b.c.d)
                                add("%d%s(%d%s%d%s%d)", e, f, g, h, o1, o2, o3);
                                //(a.b).(c.d)
                                add("(%d%s%d)%s(%d%s%d)", e, f, g, h, o1, o2, o3);
                                //((a.b).c).d
                                add("((%d%s%d)%s%d)%s%d", e, f, g, h, o1, o2, o3);
                                //(a.(b.c)).d
                                add("(%d%s(%d%s%d))%s%d", e, f, g, h, o1, o2, o3);
                                // a.((b.c).d)
                                add("%d%s((%d%s%d)%s%d)", e, f, g, h, o1, o2, o3);
                                // a.(b.(c.d))
                                add("%d%s(%d%s(%d%s%d))", e, f, g, h, o1, o2, o3);
#endif
                            }
                        }
                    }
                }
            }
        }
    }
    for (const auto& one : full) {
        double curr = calc_one(one);
        if (curr == 24) {
            ret.insert(one);
        }
    }
    return ret;
}

int main() {
    cout << "24点游戏. uniqs@163.com" << endl;
    cout << "请输入4个数字，用空格或者TAB分隔，然后敲回车" << endl;
    int a, b, c, d;
    while (true) {
        cin >> a >> b >> c >> d;
        cout << "################################################" << endl;
        unordered_set<string> ret = calc({a, b, c, d});
        for (auto r : ret) cout << r << endl;
        cout << "----------------------------------------------" << endl;
    }
    return 0;
}