#include "../inc.h"

class WordDictionary {
   public:
    WordDictionary() {}
    ~WordDictionary() {}

    void addWord(string word) {}

    bool search(string word) {}
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
