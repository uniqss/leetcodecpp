#include "../inc.h"

/*
参考中文官方，存 unordered_map<char, string> 似乎要方便一点点
*/
class Solution {
    std::unordered_map<char, string> dict;

   public:
    vector<string> letterCombinations(string digits) {
        dict['2'] = "abc";
        dict['3'] = "def";
        dict['4'] = "ghi";
        dict['5'] = "jkl";
        dict['6'] = "mno";
        dict['7'] = "pqrs";
        dict['8'] = "tuv";
        dict['9'] = "wxyz";

        vector<string> ret;
        string curr;
        dfs(ret, curr, 0, digits);
        return ret;
    }
    void dfs(vector<string>& ret, string& curr, size_t idx, const string& digits) {
        if (digits.empty()) return;
        if (idx == digits.size()) {
            ret.emplace_back(curr);
            return;
        }
        for (char c : dict[digits[idx]]) {
            curr.push_back(c);
            dfs(ret, curr, idx + 1, digits);
            curr.pop_back();
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
