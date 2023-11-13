#include "../inc.h"

class Solution {
    vector<vector<bool>> f;
    vector<vector<string>> ret;
    vector<string> curr;
    int n = 0;

   public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        f.resize(n, vector<bool>(n, true));
        // 要保证f[i + 1][j - 1]一直可用，只能i从大往小，而j从小往大。这是个trick
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = f[i + 1][j - 1] && s[i] == s[j];
            }
        }
        dfs(s, 0);
        return ret;
    }
    void dfs(const string& s, int i) {
        if (i == n) {
            ret.emplace_back(curr);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (f[i][j]) {
                curr.emplace_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                curr.pop_back();
            }
        }
    }
};

void test(string s, vector<vector<string>>&& expect) {
    save4print(s);
    sort(expect.begin(), expect.end());
    auto ret = Solution().partition(s);
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test("abbab", {{"a", "b", "b", "a", "b"}, {"a", "b", "bab"}, {"a", "bb", "a", "b"}, {"abba", "b"}});
    test("aab", {{"a", "a", "b"}, {"aa", "b"}});
    test("a", {{"a"}});
    return 0;
}