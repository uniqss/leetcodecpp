#include "../inc.h"

class Solution {
   public:
    string simplifyPath(const string& path) {
        string ret;
        vector<string> valid;
        std::size_t start = 0, end = 0;
        auto append = [](auto start, auto end, vector<string>& valid, const string& path) {
            string substr = path.substr(start, end - start);
            if (substr == ".." && !valid.empty()) valid.pop_back();
            if (substr != "." && substr != "..") valid.push_back(substr);
        };
        for (; end < path.size(); ++end) {
            if (path[end] == '/') {
                if (end > start) append(start, end, valid, path);
                start = end + 1;
            }
        }
        if (end > start) append(start, end, valid, path);

        for (auto it : valid) {
            ret += "/" + it;
        }

        return ret.empty() ? "/" : ret;
    }
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
