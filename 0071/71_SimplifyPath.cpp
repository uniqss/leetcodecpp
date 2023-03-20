#include "../inc/inc.h"

class Solution {
   public:
    string simplifyPath(const string& path) {}
};

void test(const std::string& path, const string& expect) {
    Solution so;
    auto ret = so.simplifyPath(path);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(path);
        print(expect);
        print(ret);
    }
}

int main() {
    test("/a//b////c/d//././/..", "/a/b/c");
    test("/home/", "/home");
    test("/../", "/");
    test("/home//foo/", "/home/foo");
    return 0;
}
