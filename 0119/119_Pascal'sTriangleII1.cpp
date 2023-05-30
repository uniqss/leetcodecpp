#include "../inc.h"

class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; i++) {
            int saved = 1, curr = 0;
            for (int j = 1; j < i; j++) {
                curr = ret[j];
                ret[j] += saved;
                saved = curr;
            }
        }

        return ret;
    }
};

void test(int rowIndex, const vector<int>& expect) {
    Solution so;
    auto ret = so.getRow(rowIndex);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(rowIndex);
        print(expect);
        print(ret);
    }
}

int main() {
    test(3, {1, 3, 3, 1});
    test(0, {1});
    test(1, {1, 1});
    return 0;
}
