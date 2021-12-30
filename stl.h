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

using namespace std;

#include "LinkedListHelper.h"
#include "TreeHelper.h"

template <class T>
void praw(const T& raw) {
    cout << raw << endl;
}

void ps(const char* str) {
    cout << str << endl;
}

template <class T>
void pvraw(const vector<T>& vr) {
    std::for_each(vr.begin(), vr.end(), [](const T& s) { cout << s << " "; });
    cout << endl;
}

template <class T>
void pvvraw(const vector<vector<T>>& vvr) {
    std::for_each(vvr.begin(), vvr.end(), [](const vector<T>& vr) {
        pvraw(vr);
    });
    cout << endl;
}

void pvs(const vector<string>& vs) {
    std::for_each(vs.begin(), vs.end(), [](const string& s) { cout << s << " "; });
    cout << endl;
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

class ComplexVal {
   public:
    int valtype;  // 0:nullptr 1:int 2:bool 3:string
    int vali;
    bool valb;
    string vals;
    // ptr must be nullptr
    ComplexVal() : valtype(-1) {}
    ComplexVal(void* ptr) : valtype(0) {}
    ComplexVal(int val) : valtype(1), vali(val) {}
    ComplexVal(bool val) : valtype(2), valb(val) {}
    ComplexVal(const string& str) : valtype(3), vals(str) {}
};

bool operator==(const ComplexVal& lhs, const ComplexVal& rhs) {
    if (lhs.valtype != rhs.valtype) return false;
    switch (lhs.valtype) {
        case 0:
            return true;
        case 1:
            return lhs.vali == rhs.vali;
        case 2:
            return lhs.valb == rhs.valb;
        case 3:
            return lhs.vals == rhs.vals;
        case -1:
            return true;

        default:
            return false;
    }
    return false;
}

void pvcomplex(const vector<ComplexVal>& vc) {
    std::for_each(vc.begin(), vc.end(), [](const ComplexVal& cv) {
        switch (cv.valtype) {
            case 0:
                cout << "null";
                break;
            case 1:
                cout << cv.vali;
                break;
            case 2:
                if (cv.valb)
                    cout << "true";
                else
                    cout << "false";
                break;
            case 3:
                cout << cv.vals;
                break;

            default:
                cout << "not initialized";
                break;
        }
        cout << " ";
    });
    cout << endl;
}

#define null nullptr
