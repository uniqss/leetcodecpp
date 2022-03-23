#include "../inc.h"

class Solution {
    std::unordered_map<char, vector<char>> dict;

   public:
    vector<string> letterCombinations(string digits) {
        for (char i = 2; i <= 7; ++i) {
            dict['0' + i] = {(char)('a' + (i - 2) * 3), (char)('a' + (i - 2) * 3 + 1), (char)('a' + (i - 2) * 3 + 2)};
        }
        dict['7'].emplace_back('s');
        dict['8'].emplace_back('t');
        dict['8'].emplace_back('u');
        dict['8'].emplace_back('v');
        dict['9'].emplace_back('w');
        dict['9'].emplace_back('x');
        dict['9'].emplace_back('y');
        dict['9'].emplace_back('z');

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
    Solution so;
    auto ret = so.letterCombinations(digits);
    std::sort(ret.begin(), ret.end());
    std::sort(expected.begin(), expected.end());
    if (ret == expected) {
        praw("ok.");
    } else {
        praw("not ok.");
        praw(digits);
        pvraw(expected);
        pvraw(ret);
    }
}

int main() {
    test("23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});
    test("", {});
    test("2", {"a", "b", "c"});
    return 0;
}
