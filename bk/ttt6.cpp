#include <iostream>
#include <string>

template <typename T>
void __save4print(const std::string& vname, const T& v) {
    std::cout << vname << ": " << v << std::endl;
}

template <typename... Args>
void xxxxxx(Args&&... args) {
    ((std::cout << args << " "), ...);
}

#define save4print(...) xxxxxx(#__VA_ARGS__, __VA_ARGS__)

void test(int i, double d, const std::string& s) {
    save4print(i);
    save4print(d);
    save4print(s);
}

int main() {
    int i = 1;
    double d = 3.1415926;
    std::string s = "asdf";
    test(i, d, s);
    save4print("Multiple", "Arguments", "Supported", 123, 4.567);
    return 0;
}