#include "../inc.h"

// 中文经典on o1算法，有一点点快慢指针的焦糊味在里面，最重要是对erase的调用只有一次，太经典
class Solution {
   public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                if (idx != 0) s[idx++] = ' ';

                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];

                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};

void test(string&& s, string expect) {
    Solution so;
    auto ret = so.reverseWords(s);
    if (expect == ret) {
        print("ok");
    } else {
        print("not ok.");
        print(s);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test("a", "a");
    test("the sky is blue", "blue is sky the");
    test("  hello world  ", "world hello");
    test("a good   example", "example good a");
    test("example good a", "a good example");
    return 0;
}
