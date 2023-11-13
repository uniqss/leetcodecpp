#include "../inc.h"

class Solution {
   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {}
};

void test(vector<vector<string>>&& vvsboard, vector<string>&& words, vector<string>&& expect) {
    auto board = vvs2vvc(vvsboard);
    save4print(board, words);
    sort(expect.begin(), expect.end());
    auto ret = Solution().findWords(board, words);
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test({{"a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"},
          {"a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"},
          {"a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"},
          {"a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"},
          {"a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"},
          {"a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"},
          {"a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"},
          {"a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"},
          {"a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"},
          {"a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"},
          {"a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"},
          {"a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"}},
         {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"},
         {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"});
    test({{"o", "a", "a", "n"}, {"e", "t", "a", "e"}, {"i", "h", "k", "r"}, {"i", "f", "l", "v"}},
         {"oath", "pea", "eat", "rain", "hklf", "hf"}, {"oath", "eat", "hklf", "hf"});
    test({{"a", "b", "c", "e"}, {"x", "x", "c", "d"}, {"x", "x", "b", "a"}}, {"abc", "abcd"}, {"abc", "abcd"});
    test({{"a", "a"}}, {"aaa"}, {});
    test({{"o", "a", "b", "n"}, {"o", "t", "a", "e"}, {"a", "h", "k", "r"}, {"a", "f", "l", "v"}}, {"oa", "oaa"},
         {"oa", "oaa"});
    test({{"o", "a", "a", "n"}, {"e", "t", "a", "e"}, {"i", "h", "k", "r"}, {"i", "f", "l", "v"}},
         {"oath", "pea", "eat", "rain"}, {"eat", "oath"});
    test({{"a", "b"}, {"c", "d"}}, {"abcb"}, {});
    return 0;
}
