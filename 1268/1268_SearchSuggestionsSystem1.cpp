#include "../inc.h"

class Trie {
   public:
    vector<Trie*> children;
    bool leaf = false;

   public:
    Trie() : children(26, nullptr), leaf(false) {}
    ~Trie() {
        for (auto c : children) {
            if (c) delete c;
        }
        children.clear();
    }
    void insert(const string& word) {
        Trie* curr = this;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i] - 'a';
            if (curr->children[c] == nullptr) {
                curr->children[c] = new Trie();
            }
            curr = curr->children[c];
            if (i == word.size() - 1) curr->leaf = true;
        }
    }
    void matchprefix(const string& word, vector<string>& ret) const { dfs(this, word, 0, word.size() - 1, "", ret); }

   private:
    // []
    void dfs(const Trie* root, const string& word, int begin, int end, string after, vector<string>& ret) const {
        if (root == nullptr || ret.size() >= 3) return;
        if (begin <= end) {
            dfs(root->children[word[begin] - 'a'], word, begin + 1, end, "", ret);
        } else {
            if (root->leaf) {
                ret.emplace_back(word + after);
            }
            for (int i = 0; i < 26; ++i) {
                if (!root->children[i]) continue;
                after.push_back('a' + i);
                dfs(root->children[i], word, begin, end, after, ret);
                after.pop_back();
            }
        }
    }
};

class Solution {
   public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ret(searchWord.size());
        Trie root;
        for (auto p : products) root.insert(p);
        for (int i = 0; i < searchWord.size(); ++i) {
            root.matchprefix(searchWord.substr(0, i + 1), ret[i]);
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
    test({"mobile", "mouse", "moneypot", "monitor", "mousepad"}, "mouse",
         {{"mobile", "moneypot", "monitor"},
          {"mobile", "moneypot", "monitor"},
          {"mouse", "mousepad"},
          {"mouse", "mousepad"},
          {"mouse", "mousepad"}});
    test({"havana"}, "havana", {{"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}});
    return 0;
}