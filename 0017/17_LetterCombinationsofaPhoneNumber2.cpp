#include "../inc.h"

/*
这样写似乎更好看一点点
*/
class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty()) return ret;
        vector<string> keyMap = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string curr(digits);
        dfs(ret, keyMap, curr, 0, digits);

        return ret;
    }
    void dfs(vector<string>& ret, const vector<string>& keyMap, string& curr, int currIdx, const string& digits) {
        if (currIdx >= curr.size()) {
            ret.emplace_back(curr);
            return;
        }

        for (char c : keyMap[digits[currIdx] - '2']) {
            curr[currIdx] = c;
            dfs(ret, keyMap, curr, currIdx + 1, digits);
        }
    }
};

void test(string&& digits, vector<string>&& expected) {
    save4print(digits);
    auto ret = Solution().letterCombinations(digits);
    std::sort(ret.begin(), ret.end());
    std::sort(expected.begin(), expected.end());
    assert_eq_ret(expected, ret);
}

int main() {
    test("23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});
    test("", {});
    test("2", {"a", "b", "c"});
    return 0;
}
