#pragma once

#include "stl.h"



class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(); int n = nums2.size();
		if (m > n)
		{
			return findMedianSortedArrays(nums2, nums1);
		}

		int begin = 0; int end = m;
		int i = 0; int j = 0;
		int ivpre = 0; int iv = 0;
		int jvpre = 0; int jv = 0;
		int leftmax = 0; int rightmin = 0;
		for (;begin <= end;)
		{
			i = (begin + end) / 2;
			j = (m + n + 1) / 2 - i;
			ivpre = i > 0 ? nums1[i - 1] : INT_MIN;
			iv = i < m ? nums1[i] : INT_MAX;
			jvpre = j > 0 ? nums2[j - 1] : INT_MIN;
			jv = j < n ? nums2[j] : INT_MAX;
			if (ivpre < jv)
			{
				leftmax = max(ivpre, jvpre);
				rightmin = min(iv, jv);
				begin = i + 1;
			}
			else
			{
				end = i - 1;
			}
		}

		if ((m + n ) % 2 == 0)
		{
			return ((double)(leftmax + rightmin)) / 2;
		}
		else
		{
			return (double)leftmax;
		}
	}
};