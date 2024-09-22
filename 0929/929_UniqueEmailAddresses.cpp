#include "../inc.h"

class Solution {
   public:
    int numUniqueEmails(vector<string>& emails) {}
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
