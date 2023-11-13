#include "../inc.h"

class Solution {
   public:
    vector<int> partitionLabels(string s) {}
};

void test(string s, const vector<int>& expect) {
    Solution so;
    auto ret = so.partitionLabels(s);
    assert_eq_ret(expect, ret);
    print(s);
}

int main() {
    test("ababcbacadefegdehijhklij", {9, 7, 8});
    test("eccbbbbdec", {10});
    return 0;
}
