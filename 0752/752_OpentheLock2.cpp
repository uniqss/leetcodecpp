#include "../inc.h"

class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {
#pragma pack(1)
        union charint {
            int vi;
            char vc[4];
            charint(const string& s) {
                for (int i = 0; i < 4; ++i) vc[i] = s[i];
            }
            bool operator==(const charint& rhs) { return vi == rhs.vi; }
        };
#pragma pack()
        charint t(target);
        unordered_set<int> vis;
        for (const auto& d : deadends) {
            charint tmp(d);
            vis.emplace(tmp.vi);
        }
        queue<charint> q;
        q.push(string("0000"));
        int ret = 0;
        while (!q.empty()) {
            int qsize = q.size();
            for (int qi = 0; qi < qsize; ++qi) {
                auto curr = q.front();
                if (curr.vi == t.vi) return ret;
                q.pop();
                if (vis.count(curr.vi) > 0) continue;
                vis.emplace(curr.vi);
                for (int i = 0; i < 4; ++i) {
                    char pre = curr.vc[i];
                    curr.vc[i] = pre + 1;
                    if (pre == '9') curr.vc[i] = '0';
                    if (vis.count(curr.vi) == 0) q.emplace(curr);
                    curr.vc[i] = pre - 1;
                    if (pre == '0') curr.vc[i] = '9';
                    if (vis.count(curr.vi) == 0) q.emplace(curr);
                    curr.vc[i] = pre;
                }
            }
            ++ret;
        }
        return -1;
    }
};

void test(vector<string>&& deadends, string&& target, int expect) {
    save4print(deadends, target);
    assert_eq_ret(expect, Solution().openLock(deadends, target));
}

int main() {
    test({"0201", "0101", "0102", "1212", "2002"}, "0202", 6);
    test({"8888"}, "0009", 1);
    test({"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"}, "8888", -1);
    return 0;
}
