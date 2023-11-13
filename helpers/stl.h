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
#include <memory>

using namespace std;

template <class T>
void __print(const T& raw, const std::string& delimiter = "\t") {
    cout << raw << delimiter;
}
void __print(const bool& raw, const string& delimiter = "\t") {
    cout << (raw ? "true" : "false") << delimiter;
}
template <class T>
void __print(const vector<T>& vr, const string& delimiter = "\t") {
    cout << "{";
    for (size_t i = 0; i < vr.size(); ++i) {
        if (i < vr.size() - 1)
            __print(vr[i], ",");
        else
            __print(vr[i], "");
    }
    cout << "}" << delimiter;
}
template <class T>
void __print(const vector<vector<T>>& vvr, const string& delimiter = "\t") {
    cout << "{\n";
    for (size_t i = 0; i < vvr.size(); ++i) {
        __print(vvr[i], "");
        if (i < vvr.size() - 1) cout << "\n";
    }
    cout << "}" << delimiter;
}

template <typename... Args>
void print(Args&&... args) {
    (__print(args), ...);
    cout << endl;
}

template <typename T>
void deleteAndClearPtrContainer(T& c) {
    for (auto p : c) delete p;
    c.clear();
}
template <typename T>
void deleteAndClearPtrContainer(queue<T*>& c) {
    while (!c.empty()) {
        delete c.front();
        c.pop();
    }
}
template <typename T>
void deleteAndClearPtrContainer(deque<T*>& c) {
    while (!c.empty()) {
        delete c.front();
        c.pop_front();
    }
}
template <typename T>
void deleteAndClearPtrContainer(stack<T*>& c) {
    while (!c.empty()) {
        delete c.top();
        c.pop();
    }
}
