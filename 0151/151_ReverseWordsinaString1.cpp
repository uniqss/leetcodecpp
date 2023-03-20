#include "../inc/inc.h"

// 自己写的，略显冗长
class Solution {
   public:
    void trimBlank(string& s) {
        size_t pos = 0;
        while (pos < s.size() && s[pos] == ' ') ++pos;
        if (s[0] == ' ') s.erase(s.begin(), s.begin() + pos);
        pos = s.size() - 1;
        while (pos >= 0 && s[pos] == ' ') --pos;
        if (s[s.size() - 1] == ' ') s.erase(s.begin() + pos + 1, s.end());
        if (s.size() == 1) return;
        for (size_t i = s.size() - 2; i > 0; --i) {
            if (s[i] == ' ' && s[i + 1] == ' ') {
                s.erase(i, 1);
            }
        }
    }
    string reverseWords(string s) {
        trimBlank(s);
        // cout << "s:|" << s << "|" << endl;
        reverse(s.begin(), s.end());
        bool entry = false;
        size_t pbegin = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + pbegin, s.begin() + i);
                entry = false;
            } else {
                if (!entry) pbegin = i;
                entry = true;
            }
        }
        reverse(s.begin() + pbegin, s.end());

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
