#include "../inc.h"

// 中文算法的另一种写法，port到其他语言会方便一点，某些语言不能在for循环中改变for初始化的参数
class Solution {
   public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        int start = 0;
        while (start < n) {
            if (s[start] != ' ') {
                if (idx != 0) s[idx++] = ' ';

                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];

                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                start = end;
            }
            ++start;
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};

void test(string&& s, string expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().reverseWords(s));
}

int main() {
    test("a", "a");
    test("the sky is blue", "blue is sky the");
    test("  hello world  ", "world hello");
    test("a good   example", "example good a");
    test("example good a", "a good example");
    return 0;
}
