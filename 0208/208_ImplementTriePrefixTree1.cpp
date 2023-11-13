#include "../inc.h"

/*
其实哪里还有bug，但是实在是太痛苦了，官方的例子我都数了大概三四十个没数出来哪里没对上。。。
*/

struct _TrieNode {
    string curr;
    bool leaf = false;
    vector<_TrieNode*> children;
    _TrieNode(string v) : curr(v) {}
    _TrieNode(string v, bool leaf) : curr(v), leaf(leaf) {}
};

class Trie {
    _TrieNode root;

    void _insert_children(_TrieNode* root, const string& word) {
        for (auto child : root->children) {
            int same = 0, msize = min(word.size(), child->curr.size());
            while (same < msize && word[same] == child->curr[same]) ++same;
            if (same == 0) continue;
            if (same == child->curr.size()) {
                if (word.size() > child->curr.size()) {
                    _insert_children(child, word.substr(same));
                }
                child->leaf = true;
            } else {
                _TrieNode* grandson = new _TrieNode(child->curr.substr(same));
                grandson->children = child->children;
                grandson->leaf = child->leaf;
                child->children = {grandson};
                child->curr = child->curr.substr(0, same);
                child->leaf = same == word.size();
                if (same < word.size()) {
                    _insert_children(child, word.substr(same));
                }
            }
            return;
        }
        root->children.emplace_back(new _TrieNode(word, true));
    }
    bool _search(_TrieNode* root, const string& word) const {
        int same = 0, msize = min(root->curr.size(), word.size());
        while (same < msize && root->curr[same] == word[same]) ++same;
        if (same < root->curr.size()) return false;
        if (root->curr.size() == word.size()) return root->leaf;
        for (auto c : root->children) {
            if (_search(c, word.substr(same))) return true;
        }
        return false;
    }
    bool _startsWith(_TrieNode* root, const string& word) const {
        int same = 0, msize = min(root->curr.size(), word.size());
        while (same < msize && root->curr[same] == word[same]) ++same;
        if (same == word.size()) return true;
        if (same == root->curr.size()) {
            for (auto c : root->children) {
                if (_startsWith(c, word.substr(same))) return true;
            }
        }
        return false;
    }

   public:
    Trie() : root("") {}

    void insert(string word) {
        if (root.children.empty()) {
            root.children.emplace_back(new _TrieNode(word, true));
            return;
        }
        _insert_children(&root, word);
    }

    bool search(string word) const {
        for (auto c : root.children) {
            if (_search(c, word)) return true;
        }
        return false;
    }

    bool startsWith(string prefix) const {
        for (auto c : root.children) {
            if (_startsWith(c, prefix)) return true;
        }
        return false;
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
