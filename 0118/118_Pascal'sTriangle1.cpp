#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        ret[0].push_back(1);
        for (int i = 1; i < numRows; i++) {
            auto& prev = ret[i - 1];
            auto& curr = ret[i];
            curr.resize(i + 1, 1);
            for (size_t j = 1; j < i; j++) {
                curr[j] = prev[j - 1] + prev[j];
            }
        }

        return ret;
    }
};

void test(int numRows, const vector<vector<int>>& expect) {
    Solution so;
    auto ret = so.generate(numRows);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(numRows);
        print(expect);
        print(ret);
    }
}

int main() {
    test(5, {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}});
    test(1, {{1}});
    return 0;
}
