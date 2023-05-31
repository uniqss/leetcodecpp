#include "../inc.h"

std::string goStr;
int goPos;
void reset(const string& file) {
    goStr = file;
    goPos = 0;
}

int read4(char buff4[4]) {
    if (goPos >= goStr.size()) return 0;
    int ret = 0;
    for (int i = 0; i < 4 && goPos < goStr.size(); i++) {
        buff4[i] = goStr[goPos];
        ++goPos;
        ++ret;
    }
    return ret;
}

class Solution {
   public:
    int read(char* buf, int n) {
        int bufpos = 0;
        char buf4[4] = {0};
        while (n > 0) {
            int currRead = read4(buf4);
            if (currRead == 0) break;
            for (int i = 0; i < currRead && i < n; i++) {
                buf[bufpos] = buf4[i];
                ++bufpos;
            }
            n -= currRead;
        }
        return bufpos;
    }
};

void test(string&& file, int n, int expect) {
    reset(file);
    Solution so;
    string buf;
    buf.resize(file.size(), '\0');
    auto ret = so.read(buf.data(), n);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(file);
        print(n);
        print(expect);
        print(ret);
    }
}

int main() {
    test("abc", 4, 3);
    test("abcde", 5, 5);
    test("abcdABCD1234", 12, 12);
    test("leetcode", 5, 5);
    return 0;
}
