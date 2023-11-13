#include "../inc.h"

class Trie {
   public:
    Trie() {}
    ~Trie() {}

    void insert(string word) {}

    bool search(string word) const {}

    bool startsWith(string prefix) const {}
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
