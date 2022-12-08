#include "../inc.h"

/*
bfs非递归解法，dfs从头到尾只有从上到下的一条路径，不需要记录其他数据，而bfs的思路需要记录每一层。bfs是一层一层计算的过程，其实这题还是蛮适合用bfs的，因为最终要的就是最后一层
*/
class Solution {
    struct Helper {
        string str;
        int left;
        int right;
        Helper(const std::string& s, int l, int r) : str(s), left(l), right(r) {}
    };

   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        int n2 = n * 2;
        vector<Helper> currLayer = {Helper("(", 1, 0)};
        vector<Helper> lastLayer;
        for (int i = 1; i < n2; ++i) {
            lastLayer = currLayer;
            currLayer.clear();
            for (auto it : lastLayer) {
                if (it.left < n) currLayer.emplace_back(Helper(it.str + "(", it.left + 1, it.right));
                if (it.left > it.right) currLayer.emplace_back(Helper(it.str + ")", it.left, it.right + 1));
            }
        }
        for (auto it : currLayer) ret.emplace_back(it.str);
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
    test(4, {"(((())))", "((()()))", "((())())", "((()))()", "(()(()))", "(()()())", "(()())()", "(())(())", "(())()()", "()((()))", "()(()())", "()(())()",
             "()()(())", "()()()()"});
    return 0;
}

/*
3
1

["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]
*/
