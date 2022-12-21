#pragma once

#include "stl.h"

#include "StringHelper.h"
#include "complexval.h"
#include "LinkedListHelper.h"
#include "TreeHelper.h"
#include "NArrayTreeHelper.h"

#define null nullptr


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
