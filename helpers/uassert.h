#include "stl.h"

struct __print_newline {
    bool doprint = true;
    void cancel() { doprint = false; }
    ~__print_newline() {
        if (doprint) {
            print();
            doprint = false;
        }
    }
};

#define assert_ret(__expr, __ret) \
    __print_newline __pn;         \
    if ((__expr)) {               \
        print("ok");              \
        __pn.cancel();            \
        return (__ret);           \
    } else {                      \
        print("not ok");          \
    }

#define assert_retnone(__expr) \
    __print_newline __pn;      \
    if ((__expr)) {            \
        print("ok");           \
        __pn.cancel();         \
        return;                \
    } else {                   \
        print("not ok");       \
    }

template <typename T>
bool __eq(const T& a, const T& b) {
    return a == b;
}
template <>
bool __eq(const double& a, const double& b) {
    // cout << std::numeric_limits<float>::epsilon() << "\t" << std::fabs(a - b) << "\t" << std::abs(a - b) << endl;f
    // 这里用double会有问题，有些测试用例的精度非常差，粒度非常粗，只能到float的级别，项目中还是要精确到double级别的
    // return std::fabs(a - b) <= std::numeric_limits<double>::epsilon();
    return std::fabs(a - b) <= std::numeric_limits<float>::epsilon();
}

#define assert_eq_ret(__a, __b) \
    __print_newline __pn;       \
    if (__eq(__a, __b)) {       \
        print("ok.");           \
        __pn.cancel();          \
        return;                 \
    } else {                    \
        print("not ok.");       \
        print((__a));           \
        print((__b));           \
    }
