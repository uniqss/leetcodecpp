#include "inc.h"


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int i = 0, j = 0, len = s.size();
		int ret = 0;
		int vc[256];
		memset(vc, -1, sizeof(vc));
		for (; i < len; i++) {
			for (j = i; j < len; j++) {
				if (vc[s[j]] >= i) {
					ret = max(ret, j - i);
					i = vc[s[j]];
					memset(vc, -1, sizeof(vc));
					break;
				}
				vc[s[j]] = j;
			}
			if (j == len) {
				ret = max(ret, j - i);
				break;
			}
		}
		return ret;
	}
};