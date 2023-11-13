#include "../inc.h"

class Solution {
   public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // lowerbound 经典用法    简直被惊艳到了
        // 因为随着输入字符越来越多，lower_bound的上一次值一直有效，本身二分性能就很高
        vector<vector<string>> ret(searchWord.size());
        sort(products.begin(), products.end());
        auto it_last = products.begin();
        string word;
        for (int i = 0; i < searchWord.size(); ++i) {
            word += searchWord[i];
            auto it_lower = std::lower_bound(it_last, products.end(), word);
            for (int j = 0; j < 3; ++j) {
                if (it_lower + j < products.end() && (*(it_lower + j)).find(word) == 0) {
                    ret[i].emplace_back(*(it_lower + j));
                } else {
                    break;
                }
            }
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