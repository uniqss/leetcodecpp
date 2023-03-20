#include "../inc/inc.h"

void splitStr(const string& str, vector<string>& ret, string delim = "/") {
    std::size_t start = 0;
    while (true) {
        auto end = str.find(delim, start);
        if (end == string::npos) {
            ret.push_back(str.substr(start, end - start));
            break;
        } else {
            ret.push_back(str.substr(start, end - start));
            start = end + delim.size();
        }
    }
}

class Solution {
   public:
    string simplifyPath(const string& path) {
        vector<string> pathSplit;
        splitStr(path, pathSplit);
        vector<string> pathValid;
        for (auto p : pathSplit) {
            if (p.empty()) continue;
            if (p == ".") continue;
            if (p == "..") {
                if (!pathValid.empty()) pathValid.pop_back();
                continue;
            }
            pathValid.push_back(p);
        }
        string ret;
        for (auto p : pathValid) {
            ret += "/" + p;
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
