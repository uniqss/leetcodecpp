#include "../inc.h"

class Trie {
    vector<Trie*> children;
    bool leaf = false;

    // []
    const Trie* _search(const Trie* root, const string& word, int start, int stop) const {
        if (root == nullptr) return root;
        if (start >= stop) return root->children[word[start] - 'a'];
        return _search(root->children[word[start] - 'a'], word, start + 1, stop);
    }

   public:
    Trie() : children(26, nullptr) {}
    ~Trie() {
        for (auto c : children)
            if (c) delete c;
        children.clear();
    }

    void insert(string word) {
        Trie* curr = this;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            c -= 'a';
            if (curr->children[c] == nullptr) {
                curr->children[c] = new Trie();
            }
            curr = curr->children[c];
            if (i == word.size() - 1) curr->leaf = true;
        }
    }

    bool search(string word) const {
        auto node = _search(this, word, 0, word.size() - 1);
        return node != nullptr && node->leaf;
    }

    bool startsWith(string prefix) const {
        auto node = _search(this, prefix, 0, prefix.size() - 1);
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

void test(vector<string>&& ops, vector<vector<string>>&& params, vector<ComplexVal>&& expect) {
    save4print(ops, params);
    Trie tree;
    vector<ComplexVal> ret;
    for (int i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];
        const auto& param = params[i];
        if (op == "Trie") {
            ret.emplace_back(null);
        } else if (op == "insert") {
            tree.insert(param[0]);
            ret.emplace_back(null);
        } else if (op == "search") {
            auto curr = tree.search(param[0]);
            ret.emplace_back(curr);
        } else if (op == "startsWith") {
            auto curr = tree.startsWith(param[0]);
            ret.emplace_back(curr);
        }
    }
    assert_eq_ret(expect, ret);
}

int main() {
    test({"Trie",       "insert",     "insert",     "insert",     "insert",     "insert",     "insert",
          "search",     "search",     "search",     "search",     "search",     "search",     "search",
          "search",     "search",     "startsWith", "startsWith", "startsWith", "startsWith", "startsWith",
          "startsWith", "startsWith", "startsWith", "startsWith"},
         {{},     {"app"},      {"apple"}, {"beer"}, {"add"},  {"jam"},  {"rental"}, {"apps"}, {"app"},
          {"ad"}, {"applepie"}, {"rest"},  {"jan"},  {"rent"}, {"beer"}, {"jam"},    {"apps"}, {"app"},
          {"ad"}, {"applepie"}, {"rest"},  {"jan"},  {"rent"}, {"beer"}, {"jam"}},
         {null,  null, null, null,  null, null, null,  false, true,  false, false, false, false,
          false, true, true, false, true, true, false, false, false, true,  true,  true});
    test({"Trie", "insert", "search", "search", "startsWith", "insert", "search"},
         {{}, {"apple"}, {"apple"}, {"app"}, {"app"}, {"app"}, {"app"}}, {null, null, true, false, true, null, true});

    return 0;
}
