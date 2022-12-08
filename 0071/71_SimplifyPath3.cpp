#include "../inc.h"

class Solution {
   public:
    string simplifyPath(const string& path) {
        string ret;
        deque<string> valid;
        std::size_t start = 0, end = 0;
        auto append = [](auto start, auto end, deque<string>& valid, const string& path) {
            string substr = path.substr(start, end - start);
            if (substr == ".." && !valid.empty()) valid.pop_back();
            if (substr != "." && substr != "..") valid.emplace_back(substr);
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
