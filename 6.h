#pragma once
#include "stl.h"



class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1) return s;
		vector<string> vs(numRows);
		auto slen = s.size();
		int i = 0; int idx = 0; int count = 2 * (numRows - 1); int downidxmax = numRows - 1;
		for (; i < slen; i++) {
			idx = i % count;
			if (idx <= downidxmax) {
			}
			else {
				idx = count - idx;
			}
			vs[idx] += s[i];
		}
		string ret;
		for (const auto& s : vs) { ret += s; }
		return ret;
	}
};