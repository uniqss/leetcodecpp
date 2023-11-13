#include "../inc.h"

class Solution {
   public:
    string simplifyPath(const string& path) {}
};

void test(const std::string& path, const string& expect) {
    save4print(path);
    Solution so;
    auto ret = so.simplifyPath(path);
    assert_eq_ret(expect, ret);
}

int main() {
    test("/a//b////c/d//././/..", "/a/b/c");
    test("/home/", "/home");
    test("/../", "/");
    test("/home//foo/", "/home/foo");
    return 0;
}
