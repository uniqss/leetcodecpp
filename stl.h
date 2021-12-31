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

#include "complexval.h"
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
