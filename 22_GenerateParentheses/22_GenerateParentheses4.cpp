#include "../stl.h"

// brute-force bitset
// 1 <= n <= 8 无非就是最多16个 ( 或者 ) 最多65536个，要做的是想办法剪枝
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        int size = std::pow(2, 2 * n);
        vector<string> ret;
        for (int data = 0; data < size; ++data) {
            std::bitset<16> bits(data);
            if (bits.count() != n) continue;
            int leftcount = 0;
            int rightcount = 0;
            for (size_t i = 0; i < 2 * n; ++i) {
                if (bits.test(i)) {
                    ++leftcount;
                } else {
                    ++rightcount;
                }
                if (rightcount > leftcount) break;
            }
            if (rightcount != leftcount) continue;
            string tmp(2 * n, ')');
            for (size_t i = 0; i < 2 * n; ++i) {
                if (bits.test(i)) {
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
        praw("not ok.");
        praw(n);
        pvraw(expect);
        pvraw(ret);
    } else {
        praw("ok");
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
