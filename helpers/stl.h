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

using namespace std;

void print() {
    cout << "###############################################" << endl << endl;
}
template <class T>
void print(const T& raw) {
    cout << raw << endl;
}

void print(const bool& raw) {
    cout << (raw ? "true" : "false") << endl;
}

template <class T>
void print(const vector<T>& vr, bool new_line = true) {
    cout << "[";
    for (size_t i = 0; i < vr.size(); ++i) {
        cout << vr[i];
        if (i < vr.size() - 1) cout << " ";
    }
    cout << "]";
    if (new_line) cout << endl;
}
template <class T>
void print(const vector<vector<T>>& vvr, bool new_line = true) {
    cout << "[";
    for (size_t i = 0; i < vvr.size(); ++i) {
        print(vvr[i], false);
    }
    cout << "]";
    if (new_line) cout << endl;
}
