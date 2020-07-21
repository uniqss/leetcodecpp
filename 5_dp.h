#pragma once
#include "stl.h"



class Solution {
public:
	string longestPalindrome(string s) {
		int begin = 0; int maxlen = 0;
		int slen = s.size();
		int j = 0;
		vector<vector<int> > vvi(slen, vector<int>(slen));
		for (int len = 0; len < slen; len++)
		{
			for (int i = 0;i + len < slen;i++)
			{
				j = i + len;
				if (len == 0)
				{
					vvi[i][j] = len + 1;
				}
				else if (len == 1)
				{
					if (s[i] == s[j])
					{
						vvi[i][j] = len + 1;
					}
					else
					{
						vvi[i][j] = 0;
					}
				}
				else
				{
					if (s[i] == s[j] && vvi[i + 1][j - 1] > 0)
					{
						vvi[i][j] = len + 1;
					}
					else
					{
						vvi[i][j] = 0;
					}
				}
				if (vvi[i][j] > maxlen)
				{
					begin = i; maxlen = vvi[i][j];
				}
			}
		}
		return s.substr(begin, maxlen);
	}
};