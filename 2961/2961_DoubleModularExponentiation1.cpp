#include "../inc.h"

/*
这题居然翻车了巨久，没想明白，当时用了两种方式，一种是pow(a, x)=pow(a*a,x/2)的折半，一种是powmod(a, b,
m) a^b%m开辟n空间等重取模 结果一直在溢出,int64都溢出 本质上就是a^b%m没想清楚 假设a = x * m + y其中x
= a/m计算机自动向下取整  y=a%m 先分析b=2 a^2%m = ((x*m+y)*(x*m+y))%m = (x^2m^2 + 2*x*y*m + y^2)%m = y^2%m
所以得出证明结论：a^b%m=(a%m)^b%m
这个坑爹的结论必须记到脑子里，下次不要再在这种破问题上翻车一小时了
*/
class Solution {
   public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ret;
        int n = variables.size();
        for (int i = 0; i < n; ++i) {
            const auto& v = variables[i];
            int a = v[0], b = v[1], c = v[2], m = v[3];
            int curr = a % 10;
            for (int i = 2; i <= b; ++i) {
                curr = (curr * a) % 10;
            }
            curr %= m;
            int pre = curr;
            for (int i = 2; i <= c; ++i) {
                curr = (curr * pre) % m;
            }
            if (curr == target) ret.emplace_back(i);
        }
        return ret;
    }
};

void test(vector<vector<int>>&& v, int target, const vector<int>& expect) {
    save4print(v, target);
    assert_eq_ret(expect, Solution().getGoodIndices(v, target));
}

int main() {
    test({{9, 2, 8, 5}, {7, 8, 8, 8}, {8, 9, 6, 1}, {8, 6, 2, 2}, {3, 6, 3, 1}}, 9, {});
    test({{39, 3, 1000, 1000}}, 17, {});
    test({{2, 3, 3, 10}, {3, 3, 3, 1}, {6, 1, 1, 4}}, 2, {0, 2});
    test({{39, 3, 1000, 1000}}, 17, {});
    return 0;
}
