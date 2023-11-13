#pragma once

#include "stl.h"

#include "StringHelper.h"
#include "complexval.h"
#include "LinkedListHelper.h"
#include "TreeHelper.h"
#include "NArrayTreeHelper.h"

#include "uassert.h"

#ifndef null
#define null nullptr
#endif


template <class T>
void sortvvrawInner(vector<vector<T>>& vals) {
    std::for_each(vals.begin(), vals.end(), [](vector<T>& v) { std::sort(v.begin(), v.end()); });
}

template <class T>
void sortvvrawOuter(vector<vector<T>>& vals) {
    std::sort(vals.begin(), vals.end(), [](const vector<T>& lhs, const vector<T>& rhs) {
        for (size_t i = 0; i < lhs.size() && i < rhs.size(); ++i) {
            if (lhs[i] < rhs[i]) return true;
            if (lhs[i] > rhs[i]) return false;
        }
        return false;
    });
}

template <class T>
void sortvvrawInnerAndOuter(vector<vector<T>>& vals) {
    sortvvrawInner(vals);
    sortvvrawOuter(vals);
}
template <class T1, class T2>
void sortvvrawInnerAndOuter(vector<vector<T1>>& vals1, vector<vector<T2>>& vals2) {
    sortvvrawInnerAndOuter(vals1);
    sortvvrawInnerAndOuter(vals2);
}
template <class T1, class T2, class T3>
void sortvvrawInnerAndOuter(vector<vector<T1>>& vals1, vector<vector<T2>>& vals2, vector<vector<T2>>& vals3) {
    sortvvrawInnerAndOuter(vals1);
    sortvvrawInnerAndOuter(vals2);
    sortvvrawInnerAndOuter(vals3);
}
