#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <chrono>
#include <thread>
#include <random>
#include <functional>
#include <array>
#include <string.h>
#include <bitset>
#include <forward_list>
#include <sstream>
#include <limits.h>
#include <tuple>
#include <bit>
#include <cstdarg>

using namespace std;

inline void __print() {}
template <typename T>
void __print(const T& raw) {
    cout << raw;
}
inline void __print(const bool& raw) {
    cout << (raw ? "true" : "false");
}
template <typename T1, typename T2>
inline void __print(const std::pair<T1, T2>& p) {
    cout << "{" << p.first << "|" << p.second << "}";
}
template <typename T>
void __print(const vector<T>& vr) {
    cout << "{";
    int n = vr.size(), idx = 0;
    for (const auto& v : vr) {
        __print(v);
        if (++idx < n) cout << ",";
    }
    cout << "}";
}
template <typename T>
void __print(const list<T>& vr) {
    cout << "{";
    int n = vr.size(), idx = 0;
    for (const auto& v : vr) {
        __print(v);
        if (++idx < n) cout << ",";
    }
    cout << "}";
}
template <typename T>
void __print(const set<T>& vr) {
    cout << "{";
    int n = vr.size(), idx = 0;
    for (const auto& v : vr) {
        __print(v);
        if (++idx < n) cout << ",";
    }
    cout << "}";
}
template <typename T>
void __print(const unordered_set<T>& vr) {
    cout << "{";
    int n = vr.size(), idx = 0;
    for (const auto& v : vr) {
        __print(v);
        if (++idx < n) cout << ",";
    }
    cout << "}";
}
template <typename K, typename V>
void __print(const map<K, V>& m) {
    cout << "{";
    int n = m.size(), idx = 0;
    for (const auto& [k, v] : m) {
        __print(k);
        cout << "=>";
        __print(v);
        if (++idx < n) cout << ",";
        cout << endl;
    }
    cout << "}";
}
template <typename K, typename V>
void __print(const unordered_map<K, V>& m) {
    cout << "{";
    int n = m.size(), idx = 0;
    for (const auto& [k, v] : m) {
        __print(k);
        cout << "=>";
        __print(v);
        if (++idx < n) cout << ",";
        cout << endl;
    }
    cout << "}";
}

template <typename... Args>
void print(Args&&... args) {
    (__print(args), ...);
    cout << endl;
}
