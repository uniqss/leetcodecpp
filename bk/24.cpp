#include "../inc.h"

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
double calc_one(const string& str) {
    clear();
    static unordered_map<char, int> pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    int n = str.size();
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

unordered_set<string> calc(vector<int>&& d) {
    unordered_set<string> ret;
    vector<string> ops = {"+", "-", "*", "/"};
    vector<string> full;
    char tmp[64];
    auto add = [&full, &tmp](const char* fmt, int e, int f, int g, int h, const char* o1,
                             const char* o2, const char* o3) {
        std::snprintf(tmp, 64, fmt, e, o1, f, o2, g, o3, h);
        full.push_back(tmp);
    };
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
                                /*
                                (a.b).c.d
                                a.(b.c).d
                                a.b.(c.d)
                                (a.b.c).d
                                a.(b.c.d)
                                (a.b).(c.d)
                                ((a.b).c).d
                                (a.(b.c)).d
                                a.((b.c).d)
                                a.(b.(c.d))
                                */
                                add("(%d%s%d)%s%d%s%d", e, f, g, h, o1, o2, o3);
                                add("%d%s(%d%s%d)%s%d", e, f, g, h, o1, o2, o3);
                                add("%d%s%d%s(%d%s%d)", e, f, g, h, o1, o2, o3);
                                add("(%d%s%d%s%d)%s%d", e, f, g, h, o1, o2, o3);
                                add("%d%s(%d%s%d%s%d)", e, f, g, h, o1, o2, o3);
                                add("(%d%s%d)%s(%d%s%d)", e, f, g, h, o1, o2, o3);
                                add("((%d%s%d)%s%d)%s%d", e, f, g, h, o1, o2, o3);
                                add("(%d%s(%d%s%d))%s%d", e, f, g, h, o1, o2, o3);
                                add("%d%s((%d%s%d)%s%d)", e, f, g, h, o1, o2, o3);
                                add("%d%s(%d%s(%d%s%d))", e, f, g, h, o1, o2, o3);
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