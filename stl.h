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

using namespace std;

#include "LinkedListHelper.h"

void pi(int i) {
    cout << i << endl;
}

void ps(const char* str) {
    cout << str << endl;
}

void ps(const string& str) {
    cout << str << endl;
}

void pvi(const vector<int>& vi) {
    std::for_each(vi.begin(), vi.end(), [](int i) { cout << i << " "; });
    cout << endl;
}

void pvvi(const vector<vector<int>>& vvi) {
    for (const auto& it : vvi) {
        for (const auto& it2 : it) {
            cout << it2 << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void pnewline() {
    cout << "###############################################" << endl
         << endl;
}
