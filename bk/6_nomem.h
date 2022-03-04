#pragma once
#include "inc.h"

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1) return s;
		auto slen = s.size();
		string ret = "";
		auto repeatLen = numRows * 2 - 2;
		for (auto l = 0; l < numRows; l++)
		{
			for (auto down = l; down < slen; down += repeatLen)
			{
				ret.push_back(s[down]);
				auto downmod = down % repeatLen;
				if (downmod > 0 && downmod < numRows - 1)
				{
					auto n = numRows - 1;
					auto up = 2 * n - downmod + down - downmod;
					if (up < slen)
					{
						ret.push_back(s[up]);
					}
				}
			}
		}
		return ret;
	}
};
