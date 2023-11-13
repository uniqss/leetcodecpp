#include <iostream>
#include <string>

#define save4print2(args...)                           \
    do {                                               \
        auto targs = std::make_tuple(args);            \
        auto tnames = std::make_tuple(#args);          \
        std::cout << std::get<0>(targs) << std::endl;  \
        std::cout << std::get<0>(tnames) << std::endl; \
        std::cout << "#args:" << #args << std::endl;   \
    } while (false);

int main() {
    int i = 1024;
    std::string s = "hello world";
    double d = 123.456;
    save4print2(i, s, d);
    return 0;
}
