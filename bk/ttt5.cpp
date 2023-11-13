#include <iostream>
#include <string>
#include <vector>

template <typename T>
void __save4print(const std::string& vname, const T& v) {
    std::cout << vname << ":" << v << std::endl;
}
template <typename T>
void __save4print(const std::string& vname, const std::vector<T>& v) {
    std::cout << vname << ":{";
    for (const auto& vi : v) std::cout << vi << ", ";
    std::cout << "}" << std::endl;
}

#define save4print(v) __save4print(#v, v)

void test(int i, double d, const std::string& s, const std::vector<int>& vi, const std::vector<std::string>& vs) {
    save4print(i);
    save4print(d);
    save4print(s);
    save4print(vi);
    save4print(vs);
}

int main() {
    int i = 1;
    double d = 3.1415926;
    std::string s = "asdf";
    std::vector<int> vi = {1, 0, 2, 4};
    std::vector<std::string> vs = {"hello", "world"};
    test(i, d, s, vi, vs);
    return 0;
}
