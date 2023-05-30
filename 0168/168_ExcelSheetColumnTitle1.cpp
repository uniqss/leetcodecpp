#include "../inc.h"

class Solution {
   public:
    string convertToTitle(int columnNumber) {
        string ret;
        vector<char> dict(26, 'A');
        for (size_t i = 1; i < dict.size(); i++) {
            dict[i] += i;
        }

        while (columnNumber > 0) {
            char mod = (columnNumber - 1) % 26;
            ret += dict[mod];
            columnNumber = (columnNumber - 1) / 26;
        }

        std::reverse(ret.begin(), ret.end());

        return ret;
    }
};

void test(int columnNumber, string expect) {
    Solution so;
    auto ret = so.convertToTitle(columnNumber);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(columnNumber);
        print(expect);
        print(ret);
    }
}

int main() {
    test(1, "A");
    test(28, "AB");
    test(701, "ZY");
    return 0;
}
