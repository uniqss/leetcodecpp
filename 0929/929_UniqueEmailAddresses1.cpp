#include "../inc.h"

class Solution {
   public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> dict;
        for (auto e : emails) {
            auto split = e.find('@');
            int valid = 0;
            for (int i = 0; i < split && e[i] != '+'; ++i) {
                if (e[i] != '.') e[valid++] = e[i];
            }
            string addr = e.substr(0, valid) + e.substr(split);
            dict.insert(addr);
        }
        return (int)dict.size();
    }
};

void test(vector<string>&& emails, int expect) {
    save4print(emails);
    assert_eq_ret(expect, Solution().numUniqueEmails(emails));
}

int main() {
    test({"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com",
          "testemail+david@lee.tcode.com"},
         2);
    test({"a@leetcode.com", "b@leetcode.com", "c@leetcode.com"}, 3);
    return 0;
}
