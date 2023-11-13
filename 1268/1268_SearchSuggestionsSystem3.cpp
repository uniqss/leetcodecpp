#include "../inc.h"

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

void dfs_matched(Trie* curr, const string& word, string& remain, vector<string>& ret) {
    if (ret.size() >= 3) return;
    if (curr == nullptr) return;
    if (curr->leaf) ret.emplace_back(word + remain);
    if (ret.size() >= 3) return;
    for (int i = 0; i < 26; ++i) {
        remain.push_back('a' + i);
        dfs_matched(curr->children[i], word, remain, ret);
        remain.pop_back();
    }
}

void dfs(Trie* root, const string& word, vector<string>& ret) {
    Trie* curr = root;
    for (int i = 0; i < word.size() && curr != nullptr; ++i) curr = curr->children[word[i] - 'a'];
    string remain = "";
    dfs_matched(curr, word, remain, ret);
}

class Solution {
   public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ret(searchWord.size());
        Trie tree;
        for (auto p : products) {
            Trie* curr = &tree;
            for (int i = 0; i < p.size(); ++i) {
                auto c = p[i] - 'a';
                if (!curr->children[c]) curr->children[c] = new Trie();
                curr = curr->children[c];
                if (i == p.size() - 1) curr->leaf = true;
            }
        }
        Trie* pre = &tree;
        string currWord = "";
        for (int i = 0; i < searchWord.size(); ++i) {
            currWord += searchWord[i];
            dfs(&tree, currWord, ret[i]);
        }

        return ret;
    }
};

void test(vector<string>&& products, string searchword, const vector<vector<string>>& expect) {
    auto p1 = products;
    auto p2 = searchword;
    Solution so;
    auto ret = so.suggestedProducts(products, searchword);
    assert_eq_ret(expect, ret);
    print(p1);
    print(p2);
}

int main() {
    test({"havana"}, "tatiana", {{}, {}, {}, {}, {}, {}, {}});
    test({"mobile", "mouse", "moneypot", "monitor", "mousepad"}, "mouse",
         {{"mobile", "moneypot", "monitor"},
          {"mobile", "moneypot", "monitor"},
          {"mouse", "mousepad"},
          {"mouse", "mousepad"},
          {"mouse", "mousepad"}});
    test({"havana"}, "havana", {{"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}});
    return 0;
}