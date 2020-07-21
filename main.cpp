#include "stl.h"

//#include "3.h"
//#include "4.h"
//#include "5_dp.h"
//#include "5_expand_center.h"
//#include "6.h"
//#include "6_nomem.h"
//#include "7.h"
#include "8.inl"


int main() {
	Solution s;
	string str;
	string str1;
	string str2;
	int i;
	int i1;
	int i2;
#if 0
	string str = "";
	str = "abcabcbb";
	//str = "pwwkew";
	//str = " ";
	//str = "au";
	//str = "dvdf";
	//str = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	//str = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int ret = s.lengthOfLongestSubstring(str);
#elif 0
#if 1
	vector<int> v1{ 1, 2, 3 };
	vector<int> v2{ 1, 2, 3, 4, 5, 6, 7 };
#elif 1
	vector<int> v1{ 1, 3 };
	vector<int> v2{ 2 };
#endif
	auto ret = s.findMedianSortedArrays(v1, v2);
#elif 0
	string str = "";
	//string str = "babad";
	//string str = "baba";
	//string str = "cbbd";
	//string str = "abcda";
	auto ret = s.longestPalindrome(str);
#elif 0
	string str = "PAYPALISHIRING";
	// "PAHNAPLSIIGYIR"
	auto ret = s.convert(str, 3);
#elif 0
	i = 1234;
	i = -5678;
	i = 1534236469;
	auto ret = s.reverse(i);
#elif 1
	str = "  -321saldkf";
	str = "123-";
	auto ret = s.myAtoi(str);

#endif

	cout << ret << endl;

	cout << "done" << endl;
}