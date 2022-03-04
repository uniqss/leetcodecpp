#pragma once
#include "inc.h"



class Solution {
public:
	string longestPalindrome(string s) {
		int begin = 0; int maxlen = 0;
		int slen = s.size();
		int j = 0;
		/*
		 *		0	1	2	3	4	5	.	len	.	slen - 1
		 * 0	1
		 * 1		1
		 * 2			1
		 * 3				1
		 * 4					1
		 * .
		 * i
		 * .
		 * slen - len - 1
		 * len: [0, slen)
		 * i: [0, slen - len)
		 * j: [i + len, slen)
		 *
		 * round 1: len=0, i:[0, slen), j=i
		 *		0	1	2	3	4
		 * 0	1
		 * 1		1
		 * 2			1
		 * 3				1
		 * 4					1
		 * 
		 * round 2: len=1, i:[0, slen-1), j=i+1
		 *		0	1	2	3	4
		 * 0	1
		 * 1	?	1
		 * 2		?	1
		 * 3			?	1
		 * 4				?	1
		 *
		 * round 3: len=2, i:[0, slen-2), j=i+2
		 *		0	1	2	3	4
		 * 0	1
		 * 1	?	1
		 * 2	*	?	1
		 * 3		*	?	1
		 * 4			*	?	1
		 *
		 * round 4: len=3, i:[0, slen-3), j=i+3
		 *		0	1	2	3	4
		 * 0	1
		 * 1	?	1
		 * 2	*	?	1
		 * 3	#	*	?	1
		 * 4		#	*	?	1
		 *
		 * round 5: len=4, i:[0, slen-4), j=i+4
		 *		0	1	2	3	4
		 * 0	1
		 * 1	?	1
		 * 2	*	?	1
		 * 3	#	*	?	1
		 * 4	@	#	*	?	1
		 * 
		 * f[0][0]=1       f[1][1]=1       f[2][2]=1       f[3][3]=1       f[4][4]=1
		 * f[0][1]=0       f[1][2]=0       f[2][3]=0       f[3][4]=0
		 * f[0][2]=3       f[1][3]=3       f[2][4]=0
		 * f[0][3]=0       f[1][4]=0
		 * f[0][4]=0
		 * 
		 * 
		 * dp(i, i) = 1
		 * dp(i, i + 1) = s[i] == s[i + 1] ? 2 : 0
		 * dp(i, j) = (s[i] == s[j] && dp(i + 1, j - 1) > 0) ? dp(i + 1, j - 1) + 2 : 0
		 * 
		 */
		vector<vector<int> > f(slen, vector<int>(slen));
#if 1
#define PFIJ cout << "f[" << (i) << "][" << (j) << "]=" << f[(i)][(j)] << "\t";
#else
#endif
		for (int len = 0; len < slen; len++)
		{
			for (int i = 0;i + len < slen;i++)
			{
				j = i + len;
				if (len == 0)
				{
					f[i][j] = len + 1;
					PFIJ;
				}
				else if (len == 1)
				{
					if (s[i] == s[j])
					{
						f[i][j] = len + 1;
						PFIJ;
					}
					else
					{
						f[i][j] = 0;
						PFIJ;
					}
				}
				else
				{
					if (s[i] == s[j] && f[i + 1][j - 1] > 0)
					{
						f[i][j] = len + 1;
						PFIJ;
					}
					else
					{
						f[i][j] = 0;
						PFIJ;
					}
				}
				if (f[i][j] > maxlen)
				{
					begin = i; maxlen = f[i][j];
				}
			}
			cout << endl;
		}
		return s.substr(begin, maxlen);
	}
};