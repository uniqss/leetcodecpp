#include "../inc.h"

/*
中文官方题解，hard实至名归
非常取巧，只是计算每一个字符被统计到的次数  本质上是个数学问题
假设某字符ch出现在 i位置，前面一次出现在j位置，后面一次出现在k位置
则从j开始一直到k结束，其中有效的被统计入总数的ch数量应该是(i - j) * (k - i)
头尾的取巧：头扔上一个-1上去，尾扔上一个s.size()进去
*/
class Solution {
   public:
    int uniqueLetterString(string s) {
        int ret = 0, n = s.size();
        unordered_map<char, vector<int>> c2idxes;
        for (int i = 0; i < n; ++i) {
            c2idxes[s[i]].emplace_back(i);
        }
        for (auto&& [_, arr] : c2idxes) {
            arr.insert(arr.begin(), -1);
            arr.emplace_back(n);
            for (int i = 1; i < arr.size() - 1; ++i) {
                ret += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
            }
        }
        return ret;
    }
};

void test(string s, int expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().uniqueLetterString(s));
}

int main() {
    test("ABC", 10);
    test("ABA", 8);
    test("LEETCODE", 92);
    return 0;
}
