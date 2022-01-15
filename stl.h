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

using namespace std;

#include "StringHelper.h"
#include "complexval.h"
#include "LinkedListHelper.h"
#include "TreeHelper.h"
#include "NArrayTreeHelper.h"

template <class T>
void praw(const T& raw) {
    cout << raw << endl;
}

template <class T>
void pvraw(const vector<T>& vr, bool new_line = true) {
    cout << "[";
    for (size_t i = 0; i < vr.size(); ++i) {
        cout << vr[i];
        if (i < vr.size() - 1) cout << " ";
    }
    cout << "]";
    if (new_line) cout << endl;
}

template <class T>
void pvvraw(const vector<vector<T>>& vvr, bool new_line = true) {
    cout << "[";
    for (size_t i = 0; i < vvr.size(); ++i) {
        pvraw(vvr[i], false);
    }
    cout << "]";
    if (new_line) cout << endl;
}

void pnewline() {
    cout << "###############################################" << endl
         << endl;
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

void vcomplexToString(string& ret, const vector<ComplexVal>& vals) {
    ret = "[";
    for (size_t i = 0; i < vals.size(); ++i) {
        const ComplexVal& val = vals[i];
        if (i > 0) ret += ",";
        ret += val.ToString();
    }
    ret += "]";
}

void vcomplexFromString(vector<ComplexVal>& vals, const std::string& str) {
    vector<Slice> vstrs;
    splitStr(str.c_str() + 1, str.size() - 2, ',', vstrs, INT_MAX);

    vals.resize(vstrs.size());
    for (size_t i = 0; i < vstrs.size(); ++i) {
        const Slice& vstr = vstrs[i];
        string s = vstr.str;
        s = s.substr(0, vstr.len);
        vals[i].FromString(s);
    }
}
