#include "../inc.h"

// 甚矬，然性能尚可，留之
class Solution {
   public:
    string simplifyPath(const string& path) {
        deque<string> q;
        int psize = path.size(), start = 1;
        while (start < psize && path[start] == '/') ++start;
        for (int i = 1; i < psize; ++i) {
            if (path[i] == '/') {
                if (path[i - 1] != '/') {
                    string curr = path.substr(start, i - start);
                    start = i;
                    while (start < psize && path[start] == '/') ++start;
                    i = max(i, start);
                    if (curr == ".") {
                    } else if (curr == "..") {
                        if (!q.empty()) {
                            q.pop_back();
                        }
                    } else {
                        q.emplace_back(curr);
                    }
                }
            }
        }
        if (start < psize) {
            string curr = path.substr(start, psize);
            if (curr == ".") {
            } else if (curr == "..") {
                if (!q.empty()) {
                    q.pop_back();
                }
            } else {
                q.emplace_back(curr);
            }
        }
        string ret;
        for (const auto& s : q) ret += "/" + s;
        if (ret.empty()) ret = "/";
        return ret;
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
