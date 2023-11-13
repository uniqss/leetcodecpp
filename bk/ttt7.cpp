// 感谢群里的 c语言大佬罗**提供的这个实现，他说这叫泛型宏，有必要深入研究一下
#include <iostream>
#include <vector>

template <typename T>
void __print(const std::string& vname, const T& t) {
    std::cout << vname << ":" << t << " ";
}
template <typename T>
void __print(const std::string& vname, const std::vector<T>& v) {
    std::cout << vname << ":{";
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i < (int)v.size() - 1) std::cout << ",";
    }
    std::cout << "} ";
}

#define _PRINT_OVERRIDE(_1, _2, _3, _4, _5, NAME, ...) NAME
#define _PRINT_VAL(val) \
    __print(#val, val); \
    std::cout << std::endl;

#define _PRINT_PARAM0()
#define _PRINT_PARAM1(val) _PRINT_VAL(val)
#define _PRINT_PARAM2(val, ...) _PRINT_VAL(val) _PRINT_PARAM1(__VA_ARGS__)
#define _PRINT_PARAM3(val, ...) _PRINT_VAL(val) _PRINT_PARAM2(__VA_ARGS__)
#define _PRINT_PARAM4(val, ...) _PRINT_VAL(val) _PRINT_PARAM3(__VA_ARGS__)
#define PRINT_ALL_PARAM(...)                                                                                      \
    _PRINT_OVERRIDE("", ##__VA_ARGS__, _PRINT_PARAM4, _PRINT_PARAM3, _PRINT_PARAM2, _PRINT_PARAM1, _PRINT_PARAM0) \
    (__VA_ARGS__)

void test(int i, const std::string& s, float f, const std::vector<int>& vi) {
    PRINT_ALL_PARAM();
    PRINT_ALL_PARAM(i);
    PRINT_ALL_PARAM(i, s);
    PRINT_ALL_PARAM(i, s, f);
    PRINT_ALL_PARAM(i, s, f, vi);
}
int main() {
    test(1024, "hello world", 3.1415926, {1024, 2048});
    return 0;
}
