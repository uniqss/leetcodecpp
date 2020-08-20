#include "stl.h"

//#include "3.h"
//#include "4.h"
//#include "5_dp.h"
//#include "5_expand_center.h"
//#include "6.h"
//#include "6_nomem.h"
//#include "7.h"
//#include "8.inl"
//#include "9.inl"
//#include "10.inl"
//#include "10_1.inl"
//#include "11.inl"
//#include "12.inl"
#include "13.inl"



int main() {
	Solution s;
	string str;
	string str1;
	string str2;
	int i;
	int i1;
	int i2;
#define TESTID 13
#if TESTID == 3
	string str = "";
	str = "abcabcbb";
	//str = "pwwkew";
	//str = " ";
	//str = "au";
	//str = "dvdf";
	//str = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	//str = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int ret = s.lengthOfLongestSubstring(str);
#elif TESTID == 4
#if 1
	vector<int> v1{ 1, 2, 3 };
	vector<int> v2{ 1, 2, 3, 4, 5, 6, 7 };
#elif 1
	vector<int> v1{ 1, 3 };
	vector<int> v2{ 2 };
#endif
	auto ret = s.findMedianSortedArrays(v1, v2);
#elif TESTID == 5
	str = "babad";
	//str = "baba";
	//str = "cbbd";
	//str = "abcda";
	auto ret = s.longestPalindrome(str);
#elif TESTID == 6
	string str = "PAYPALISHIRING";
	// "PAHNAPLSIIGYIR"
	auto ret = s.convert(str, 3);
#elif TESTID == 7
	i = 1234;
	i = -5678;
	i = 1534236469;
	auto ret = s.reverse(i);
#elif TESTID == 8
	str = "  -321saldkf";
	str = "123-";
	auto ret = s.myAtoi(str);
#elif TESTID == 9
	i1 = 123321;
	auto ret = s.isPalindrome(i1);

#elif TESTID == 10
#if 1
	str1 = "aab";
	str2 = "c*a*b*";
#elif 0
	str1 = "aa";
	str2 = "a*";
#endif
	auto ret = s.isMatch(str1, str2);

#elif TESTID == 11
	vector<int> vi { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	auto ret = s.maxArea(vi);
#elif TESTID == 12
	i = 1994;
	auto ret = s.intToRoman(i);
#elif TESTID == 13
	str = "MCMXCIV";
	auto ret = s.romanToInt(str);
#endif

	cout << ret << endl;

	cout << "done" << endl;
}