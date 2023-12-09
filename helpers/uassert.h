#pragma once

#include "stl.h"
#include "complexval.h"

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

unordered_map<int, ComplexVal> __save4printx;
unordered_map<int, vector<ComplexVal>> __save4printvx;
unordered_map<int, vector<vector<ComplexVal>>> __save4printvvx;
vector<string> __save4printnames;
int __g_testcase_count = 0;

void __save4print(const string& paramname, const ComplexVal& v) {
    __save4printx[__save4printnames.size()] = v;
    __save4printnames.emplace_back(paramname);
}
template <typename T>
void __save4print(const string& paramname, const T& v) {
    ComplexVal c(v);
    __save4print(paramname, c);
}
void __save4print(const string& paramname, const vector<ComplexVal>& v) {
    __save4printvx[__save4printnames.size()] = v;
    __save4printnames.emplace_back(paramname);
}
template <typename T>
void __save4print(const string& paramname, const vector<T>& v) {
    vector<ComplexVal> vx;
    for (const auto& vv : v) {
        vx.emplace_back(ComplexVal(vv));
    }
    __save4print(paramname, vx);
}
void __save4print(const string& paramname, const vector<vector<ComplexVal>>& v) {
    __save4printvvx[__save4printnames.size()] = v;
    __save4printnames.emplace_back(paramname);
}
template <typename T>
void __save4print(const string& paramname, const vector<vector<T>>& v) {
    vector<vector<ComplexVal>> vvx;
    for (const auto& vv : v) {
        vector<ComplexVal> vx;
        for (const auto& vvv : vv) {
            vx.push_back(ComplexVal(vvv));
        }
        vvx.emplace_back(vx);
    }
    __save4print(paramname, vvx);
}
void __clear_save4prints() {
    __save4printnames.clear();
    __save4printx.clear();
    __save4printvx.clear();
    __save4printvvx.clear();
}


// currently 10 parameters, if not enough, just add it.
#define __SAVE4PRINT_OVERRIDE(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, NAME, ...) NAME
#define __SAVE4PRINT_PRINT_VAL(val) __save4print(#val, val);

#define __SAVE4PRINT_PRINT_PARAM0()
#define __SAVE4PRINT_PRINT_PARAM1(val) __SAVE4PRINT_PRINT_VAL(val)
#define __SAVE4PRINT_PRINT_PARAM2(val, ...) __SAVE4PRINT_PRINT_VAL(val) __SAVE4PRINT_PRINT_PARAM1(__VA_ARGS__)
#define __SAVE4PRINT_PRINT_PARAM3(val, ...) __SAVE4PRINT_PRINT_VAL(val) __SAVE4PRINT_PRINT_PARAM2(__VA_ARGS__)
#define __SAVE4PRINT_PRINT_PARAM4(val, ...) __SAVE4PRINT_PRINT_VAL(val) __SAVE4PRINT_PRINT_PARAM3(__VA_ARGS__)
#define __SAVE4PRINT_PRINT_PARAM5(val, ...) __SAVE4PRINT_PRINT_VAL(val) __SAVE4PRINT_PRINT_PARAM4(__VA_ARGS__)
#define __SAVE4PRINT_PRINT_PARAM6(val, ...) __SAVE4PRINT_PRINT_VAL(val) __SAVE4PRINT_PRINT_PARAM5(__VA_ARGS__)
#define __SAVE4PRINT_PRINT_PARAM7(val, ...) __SAVE4PRINT_PRINT_VAL(val) __SAVE4PRINT_PRINT_PARAM6(__VA_ARGS__)
#define __SAVE4PRINT_PRINT_PARAM8(val, ...) __SAVE4PRINT_PRINT_VAL(val) __SAVE4PRINT_PRINT_PARAM7(__VA_ARGS__)
#define __SAVE4PRINT_PRINT_PARAM9(val, ...) __SAVE4PRINT_PRINT_VAL(val) __SAVE4PRINT_PRINT_PARAM8(__VA_ARGS__)
#define __SAVE4PRINT_PRINT_PARAM10(val, ...) __SAVE4PRINT_PRINT_VAL(val) __SAVE4PRINT_PRINT_PARAM9(__VA_ARGS__)
#define save4print(...)                                                                                    \
    __SAVE4PRINT_OVERRIDE("", ##__VA_ARGS__, __SAVE4PRINT_PRINT_PARAM10, __SAVE4PRINT_PRINT_PARAM9,        \
                          __SAVE4PRINT_PRINT_PARAM8, __SAVE4PRINT_PRINT_PARAM7, __SAVE4PRINT_PRINT_PARAM6, \
                          __SAVE4PRINT_PRINT_PARAM5, __SAVE4PRINT_PRINT_PARAM4, __SAVE4PRINT_PRINT_PARAM3, \
                          __SAVE4PRINT_PRINT_PARAM2, __SAVE4PRINT_PRINT_PARAM1, __SAVE4PRINT_PRINT_PARAM0) \
    (__VA_ARGS__)

void psavedargs() {
    for (int __save4printidx = 0; __save4printidx < (int)__save4printnames.size(); ++__save4printidx) {
        if (__save4printx.count(__save4printidx) > 0)
            __print(__save4printnames[__save4printidx], ":"), __print(__save4printx[__save4printidx]);
        if (__save4printvx.count(__save4printidx) > 0)
            __print(__save4printnames[__save4printidx], ":"), __print(__save4printvx[__save4printidx]);
        if (__save4printvvx.count(__save4printidx) > 0)
            __print(__save4printnames[__save4printidx], ":"), __print(__save4printvvx[__save4printidx]);
        if (__save4printidx > 0 && __save4printidx % 4 == 0) __print("\n", "");
    }
    __clear_save4prints();
}

#define assert_eq_ret(__a, __b)                                                            \
    std::string __aname = #__a, __bname = #__b;                                            \
    __aname.resize(max(__aname.size(), __bname.size()), ' ');                              \
    __bname.resize(max(__aname.size(), __bname.size()), ' ');                              \
    ++__g_testcase_count;                                                                  \
    __print_newline __pn;                                                                  \
    if (__eq(__a, __b)) {                                                                  \
        print("ok.");                                                                      \
        __pn.cancel();                                                                     \
        __clear_save4prints();                                                             \
        return;                                                                            \
    } else {                                                                               \
        print("not ok.");                                                                  \
        __print(__aname, ":["), __print((__a), ""), print("]");                            \
        __print(__bname, ":["), __print((__b), ""), print("]");                            \
        psavedargs();                                                                      \
        __print("\n##################### testcase ", ""), __print(__g_testcase_count, ""), \
            __print(" end. ##################\n", "");                                     \
    }

#define assert_retnone(__expr)                                                             \
    ++__g_testcase_count;                                                                  \
    __print_newline __pn;                                                                  \
    if ((__expr)) {                                                                        \
        print("ok.");                                                                      \
        __pn.cancel();                                                                     \
        __clear_save4prints();                                                             \
        return;                                                                            \
    } else {                                                                               \
        print("not ok.");                                                                  \
        print((#__expr));                                                                  \
        psavedargs();                                                                      \
        __print("\n##################### testcase ", ""), __print(__g_testcase_count, ""), \
            __print(" end. ##################\n", "");                                     \
    }
