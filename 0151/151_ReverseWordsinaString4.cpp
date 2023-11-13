#include "../inc.h"

// 仔细体味与中文经典算法的区别
/*
中文经典的意思是，我遇到一个合法的开头，就处理这一个word，处理完reverse，一个word一个word的处理，直到结束，所以没有尾巴的问题
我的意思是遇到一个客格就结算一次前面的合法word，所以我开始前先把前面的空格去掉了。而且我这样有尾巴的问题，最后一个需要修复
相对而言还是中文经典更经典
中文经典是把所有的空格视为【无需处理状态】，所以【无需处理状态里面】直接无视遇到的char，直到再次出现合法char
*/
class Solution {
   public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        size_t begin = 0, end = 0, pos = 0;
        while (s[pos] == ' ') ++pos;

        while (pos < s.size()) {
            if (s[pos] == ' ') {
                reverse(s.begin() + begin, s.begin() + end);
                while (pos < s.size() && s[pos] == ' ') ++pos;
                s[end++] = ' ';
                begin = end;
            } else {
                s[end++] = s[pos++];
            }
        }
        if (s[end - 1] == ' ') --end;
        reverse(s.begin() + begin, s.begin() + end);
        s.resize(end);
        return s;
    }
};

void test(string&& s, string expect) {
    save4print(s);
    Solution so;
    auto ret = so.reverseWords(s);
    assert_eq_ret(expect, ret);
}

int main() {
    test("a", "a");
    test("the sky is blue", "blue is sky the");
    test("  hello world  ", "world hello");
    test("a good   example", "example good a");
    test("example good a", "a good example");
    return 0;
}
