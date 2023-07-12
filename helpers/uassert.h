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

#define assert_eq_ret(__a, __b) \
    __print_newline __pn;       \
    if ((__a) == (__b)) {       \
        print("ok.");           \
        __pn.cancel();          \
        return;                 \
    } else {                    \
        print("not ok.");       \
        print((__a));           \
        print((__b));           \
    }
