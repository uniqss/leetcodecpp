#include "../inc.h"

class Solution {
   public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {}
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