#pragma once
#include "inc.h"



class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1) return s;
		vector<string> vs(numRows);
		auto slen = s.size();
		int i = 0; int idx = 0; bool bDown = true; int downidxmax = numRows - 1;
		for (; i < slen; i++) {
			vs[idx] += s[i];
			if (bDown) {
				idx++;
				if (idx == downidxmax) bDown = false;
			}
			else
			{
				idx--;
				if (idx == 0) bDown = true;
			}
		}
		string ret;
		for (const auto& s : vs) { ret += s; }
		return ret;
	}
};