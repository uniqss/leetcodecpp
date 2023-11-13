#include "../inc.h"

// dfs works, but very slow...
class WordDictionary {
    vector<WordDictionary*> children;
    bool leaf = false;

   public:
    WordDictionary() : children(26) {}
    ~WordDictionary() {
        for (auto c : children) delete c;
        children.clear();
    }

    void addWord(string word) {
        WordDictionary* curr = this;
        for (int i = 0; i < (int)word.size(); ++i) {
            char c = word[i] - 'a';
            if (curr->children[c] == nullptr) {
                curr->children[c] = new WordDictionary();
            }
            curr = curr->children[c];
            if (i + 1 == word.size()) curr->leaf = true;
        }
    }

    bool search(string word) { return dfs(this, word, 0); }
    bool dfs(WordDictionary* curr, const string& word, int idx) {
        int n = word.size();
        if (idx == n) return curr->leaf;
        char c = word[idx];
        if (c == '.') {
            for (auto child : curr->children) {
                if (child) {
                    if (dfs(child, word, idx + 1)) return true;
                }
            }
        } else {
            curr = curr->children[c - 'a'];
            if (curr == nullptr) return false;
            if (dfs(curr, word, idx + 1)) return true;
        }
        return false;
    }
};

void test(const vector<string>& ops, const vector<vector<string>>& params, const vector<ComplexVal>& expect) {
    save4print(ops, params);
    WordDictionary obj;
    vector<ComplexVal> ret;
    for (int i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];
        const auto& param = params[i];
        if (op == "WordDictionary") {
            ret.emplace_back(null);
        } else if (op == "addWord") {
            ret.emplace_back(null);
            obj.addWord(param[0]);
        } else if (op == "search") {
            ret.emplace_back(ComplexVal(obj.search(param[0])));
        }
    }
    assert_eq_ret(expect, ret);
}

int main() {
    test({"WordDictionary", "addWord", "addWord", "addWord", "search", "search", "search", "search"},
         {{}, {"bad"}, {"dad"}, {"mad"}, {"pad"}, {"bad"}, {".ad"}, {"b.."}},
         {null, null, null, null, false, true, true, true});
    return 0;
}
