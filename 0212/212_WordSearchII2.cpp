#include "../inc.h"

struct PrefixTree {
    unordered_map<char, PrefixTree*> children;
    string word;
    ~PrefixTree() {
        for (auto [_, c] : children)
            if (c) delete c;
        children.clear();
    }
    void AddWord(const string& word) {
        PrefixTree* curr = this;
        for (auto c : word) {
            if (curr->children.count(c) == 0) curr->children[c] = new PrefixTree();
            curr = curr->children[c];
        }
        curr->word = word;
    }
};

class Solution {
    static inline const vector<pair<int, int>> nexts = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> ret;
        PrefixTree pt;
        for (const auto& word : words) pt.AddWord(word);
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, &pt, ret);
            }
        }
        return vector<string>(ret.begin(), ret.end());
    }
    void dfs(vector<vector<char>>& board, int x, int y, PrefixTree* curr, unordered_set<string>& ret) {
        char ch = board[x][y];
        if (curr->children.count(ch) == 0) return;
        curr = curr->children[ch];
        board[x][y] = '#';
        if (!curr->word.empty()) ret.emplace(curr->word), curr->word.clear();
        int m = board.size(), n = board[0].size();
        for (auto [nx, ny] : nexts) {
            nx += x, ny += y;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] != '#') {
                dfs(board, nx, ny, curr, ret);
            }
        }
        board[x][y] = ch;
    }
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
