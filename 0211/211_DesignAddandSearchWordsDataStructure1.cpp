#include "../inc.h"

class WordDictionary {
    vector<WordDictionary*> children;
    bool tail = false;

   public:
    WordDictionary() : children(26) {}

    void addWord(string word) {
        WordDictionary* curr = this;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i] - 'a';
            if (curr->children[c] == nullptr) {
                curr->children[c] = new WordDictionary();
            }
            curr = curr->children[c];
            if (i + 1 == word.size()) curr->tail = true;
        }
    }

    bool search(string word) {
        WordDictionary* curr = this;
        queue<pair<WordDictionary*, int>> q;
        int wsize = word.size(), idx;
        q.emplace(curr, 0);
        while (!q.empty()) {
            curr = q.front().first, idx = q.front().second, q.pop();
            if (idx == wsize) {
                if (curr->tail) return true;
                continue;
            }
            char c = word[idx];
            if (c == '.') {
                for (auto child : curr->children) {
                    if (child != nullptr) q.emplace(child, idx + 1);
                }
            } else {
                curr = curr->children[c - 'a'];
                if (curr != nullptr) q.emplace(curr, idx + 1);
            }
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
