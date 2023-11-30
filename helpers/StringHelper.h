#pragma once

#include "stl.h"

// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.
//
// Slice is a simple structure containing a pointer into some external
// storage and a size.  The user of a Slice must ensure that the slice
// is not used after the corresponding external storage has been
// deallocated.
//
// Multiple threads can invoke const methods on a Slice without
// external synchronization, but if any of the threads may call a
// non-const method, all threads accessing the same Slice must use
// external synchronization.

// slice minimal implemention inspired by leveldb
class Slice {
   public:
    const char* str;
    int len;
};

int splitStr(const char* str, int str_len, char delim, std::vector<Slice>& ret, int max_part_num) {
    int cur_part_num = 0;

    for (int i = 0; i < str_len; ++i) {
        if (str[i] == delim) continue;

        if (cur_part_num >= max_part_num) {
            return -1;
        }

        int end = i + 1;
        for (; end < str_len; ++end) {
            if (str[end] == delim) {
                --end;
                break;
            }
        }

        if (end == str_len) {
            ret.push_back({str + i, end - i});
        } else {
            ret.push_back({str + i, end - i + 1});
        }
        ++cur_part_num;

        i = end;
    }

    return 0;
}

bool isStrPalindrome(const string& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        ++l, --r;
    }
    return true;
}

vector<vector<char>> vvs2vvc(const vector<vector<string>>& vvs) {
    vector<vector<char>> ret;
    for (int i = 0; i < (int)vvs.size(); ++i) {
        ret.resize(ret.size() + 1);
        vector<char>& curr = ret[ret.size() - 1];
        for (int j = 0; j < (int)vvs[i].size(); ++j) {
            if (vvs[i][j].size() == 1) curr.emplace_back(vvs[i][j][0]);
        }
    }
    return ret;
}
