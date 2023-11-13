#include "../inc.h"

/*
这个解是对的，但是会超时，，，得深度优化
*/
struct Trie {
    vector<Trie*> children;
    bool leaf = false;
    Trie() : children(26) {}
    ~Trie() {
        for (auto c : children)
            if (c) delete c;
        children.clear();
    }
};

void trieAddWord(Trie* root, const string& word) {
    Trie* curr = root;
    for (int i = 0; i < word.size(); ++i) {
        if (curr->children[word[i] - 'a'] == nullptr) curr->children[word[i] - 'a'] = new Trie();
        curr = curr->children[word[i] - 'a'];
        if (i == word.size() - 1) curr->leaf = true;
    }
}

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie prefixtree;
        for (const auto& w : wordDict) trieAddWord(&prefixtree, w);
        vector<bool> exist(26);
        for (const auto& word : wordDict)
            for (char c : word) exist[c - 'a'] = true;
        for (auto c : s)
            if (!exist[c - 'a']) return false;
        return helper(s, &prefixtree, 0);
    }
    bool helper(const string& s, Trie* root, int start) {
        if (start == s.size()) return true;
        Trie* curr = root;
        for (int i = start; i < s.size(); ++i) {
            auto c = s[i] - 'a';
            if (curr->children[c] == nullptr) return false;
            curr = curr->children[c];
            if (curr->leaf) {
                if (helper(s, root, i + 1)) return true;
            }
        }
        return false;
    }
};

void test(string s, vector<string>&& wordDict, bool expect) {
    save4print(s, wordDict);
    assert_eq_ret(expect, Solution().wordBreak(s, wordDict));
}

int main() {
    test(
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
        {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"}, false);
    test("leetcode", {"leet", "code"}, true);
    test("applepenapple", {"apple", "pen"}, true);
    test("catsandog", {"cats", "dog", "sand", "and", "cat"}, false);
    return 0;
}
