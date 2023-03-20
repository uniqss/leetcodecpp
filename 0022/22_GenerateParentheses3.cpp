#include "../inc/inc.h"

// brute-force
// 1 <= n <= 8 无非就是最多16个 ( 或者 ) 最多65536个，要做的是想办法剪枝
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        int size = std::pow(2, 2 * n);
        vector<string> ret;
        for (int data = 0; data < size; ++data) {
            int leftcount = 0;
            int rightcount = 0;
            for (int bit = 0; bit < 2 * n; ++bit) {
                if ((data & (0x01 << bit)) > 0) {
                    ++rightcount;
                } else {
                    ++leftcount;
                }
                if (rightcount < leftcount) break;
                if (rightcount > n || leftcount > n) break;
            }
            if (rightcount != leftcount || rightcount > n || leftcount > n) continue;
            string tmp(2 * n, ')');
            for (int i = 0; i < 2 * n - 1; ++i) {
                if ((data & (0x01 << i)) > 0) {
                    tmp[i] = '(';
                }
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};

void test(int n, vector<string>&& expect) {
    Solution so;
    auto ret = so.generateParenthesis(n);

    std::sort(expect.begin(), expect.end());
    std::sort(ret.begin(), ret.end());

    if (ret != expect) {
        print("not ok.");
        print(n);
        print(expect);
        print(ret);
    } else {
        print("ok");
    }
}

int main() {
    test(1, {"()"});
    test(2, {"(())", "()()"});
    test(3, {"((()))", "(()())", "(())()", "()(())", "()()()"});
    test(4, {"(((())))", "((()()))", "((())())", "((()))()", "(()(()))", "(()()())", "(()())()", "(())(())", "(())()()", "()((()))", "()(()())", "()(())()", "()()(())", "()()()()"});
    return 0;
}

/*
3
1

["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]
*/
