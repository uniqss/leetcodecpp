#pragma once
#include "stl.h"

class Solution {
public:
	string longestPalindrome(string s) {
		int slen = s.size();
		if (slen == 0) return s;
		int maxlen = -1;
		int leni = 0;
		int leni1 = 0;
		size_t center = 0;
		size_t count = 0;
		for (auto i = 0; i < slen; i++)
		{
			leni = expandAroundCenter(s, i, i);
			leni1 = expandAroundCenter(s, i, i + 1);
			if (maxlen < leni) {
				maxlen = leni;
				center = i;
				count = leni;
			}
			if (maxlen < leni1)
			{
				maxlen = leni1;
				center = i;
				count = leni1;
			}
		}
		return s.substr(center - (count - 1) / 2, count);
	}
	int expandAroundCenter(const string& s, int left, int right) {
		int slen = s.size();
		while (left >= 0 && right <= slen - 1 && s[left] == s[right])
		{
			left--;
			right++;
		}
		return right - left - 1;
	}
};

