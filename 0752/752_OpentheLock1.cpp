#include "../inc.h"

/*
time complexity: O(10^4 *4*4)
space complexity: O(10^4)  752. Open the Lock
*/
class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis(deadends.begin(), deadends.end());
#pragma pack(1)
        union charint {
            int vi;
            char vc[4];
        };
#pragma pack()
        queue<string> q({"0000"});
        int ret = 0;
        while (!q.empty()) {
            int qsize = q.size();
            for (int qi = 0; qi < qsize; ++qi) {
                auto curr = q.front();
                if (curr == target) return ret;
                q.pop();
                if (vis.count(curr) > 0) continue;
                vis.emplace(curr);
                for (int i = 0; i < curr.size(); ++i) {
                    char pre = curr[i];
                    curr[i] = pre + 1;
                    if (pre == '9') curr[i] = '0';
                    if (vis.count(curr) == 0) q.emplace(curr);
                    curr[i] = pre - 1;
                    if (pre == '0') curr[i] = '9';
                    if (vis.count(curr) == 0) q.emplace(curr);
                    curr[i] = pre;
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
