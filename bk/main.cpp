#include "inc.h"

#define TESTID 1824

#if TESTID == 3
#include "3.h"
#elif TESTID == 4
#include "4.h"
#elif TESTID == 5
#include "5_dp.h"
//#include "5_expand_center.h"
#elif TESTID == 6
#include "6.h"
//#include "6_nomem.h"
#elif TESTID == 7
#include "7.h"
#elif TESTID == 8
#include "8.inl"
#elif TESTID == 9
#include "9.inl"
#elif TESTID == 10
#if 0
#include "10.inl"
#else
#include "10_1.inl"
#endif
#elif TESTID == 11
#include "11.inl"
#elif TESTID == 12
#include "12.inl"
#elif TESTID == 13
#include "13.inl"
#elif TESTID == 14
#include "14.inl"
#elif TESTID == 15
#if 1
#include "15.inl"
#else
#include "15_1.inl"
#endif
#elif TESTID == 16
#elif TESTID == 24
#if 0
#include "24.inl"
#else
#include "24_1.inl"
#endif
#elif TESTID == 32
#include "32_LongestValidParentheses.inl"
#elif TESTID == 42
#if 0
#include "42_TrappingRainWater.inl"
#else
#include "42_TrappingRainWater_dp.inl"
#endif
#elif TESTID == 44
#include "44_WildcardMatching.inl"
#elif TESTID == 53
#if 1
#include "53_MaximumSubarray.inl"
#else
#include "53_MaximumSubarray_dp.inl"
#endif
#elif TESTID == 62
#if 0
#include "62_UniquePaths_dp.inl"
#elif 0
#include "62_UniquePaths_dp2.inl"
#else
#include "62_UniquePaths_dp3.inl"
#endif
#elif TESTID == 63
#include "63_UniquePathsII_dp.inl"
#elif TESTID == 64
#include "64_MinimumPathSum_dp.inl"
#elif TESTID == 70
#if 0
#include "70_ClimbingStairs_dp.inl"
#else
#include "70_ClimbingStairs_dp2.inl"
#endif
#elif TESTID == 72
#include "72_EditDistance.inl"
#elif TESTID == 84
#include "84_LargestRectangleInHistogram.inl"
#elif TESTID == 85
#include "85_MaximalRectangle.inl"
#elif TESTID == 256
#if 1
#include "256_PaintHouse_dp.inl"
#else
#include "256_PaintHouse_dp_const.inl"
#endif
#elif TESTID == 1824
#include "1824_MinimumSidewayJumps.inl"
#elif TESTID == 1903
#include "1903_LargestOddNumberinString.inl"
#elif TESTID == 1958
#include "1958_CheckIfMoveIsLegal.inl"
#endif


int main() {
	Solution s;
	string str;
	string str1;
	string str2;
	vector<string> vs;
	vector<string> vs2;
	vector<int> vi;
	vector<int> vi2;
	vector<vector<int>> vvi;
	vector<vector<int>> vvi2;
	int i;
	int i0;
	int i1;
	int i2;
	int i4;
	int j;
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
	vector<int> vi{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	auto ret = s.maxArea(vi);
#elif TESTID == 12
	i = 1994;
	auto ret = s.intToRoman(i);
#elif TESTID == 13
	str = "MCMXCIV";
	auto ret = s.romanToInt(str);
#elif TESTID == 14
	//vs = { "flower","flow","flight" };
	vs = { "abca", "abc" };
	auto ret = s.longestCommonPrefix(vs);
#elif TESTID == 15
	//vs = { "flower","flow","flight" };
	vi = { -1, 4, 0, 1, 1, 2, -1 };
	auto ret = s.threeSum(vi);
	for (int iiii = 0; iiii < ret.size(); iiii++)
	{
		const auto& tmp = ret[iiii];
		for (int j = 0; j < tmp.size(); j++)
		{
			cout << tmp[j] << " ";
		}
		cout << endl;
	}
#elif TESTID == 24
	ListNode* pList = new ListNode(1);
	pList->next = new ListNode(2);
	pList->next->next = new ListNode(3);
	pList->next->next->next = new ListNode(4);
	pList->next->next->next->next = nullptr;
	ListNode* pNewList = s.swapPairs(pList);
	while (pNewList)
	{
		ListNode* pNext = pNewList->next;
		delete pNewList;
		pNewList = pNext;
	}
#elif TESTID == 32
	str = ")()())";
	//str = "()(()";
	auto ret = s.longestValidParentheses(str);
	cout << ret << endl;
#elif TESTID == 42
	//vi = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	//vi = { 4,2,0,3,2,5 };
	vi = { 2,0,2 };
	//vi = { 4,2,3 };
	auto result = s.trap(vi);
	cout << result << endl;
#elif TESTID == 44
	str1 = "abc";
	str2 = "*bc";
	auto result = s.isMatch(str1, str2);
	cout << result << endl;
#elif TESTID == 53
	vi = { -2,1,-3,4,-1,2,1,-5,4 };
	auto result = s.maxSubArray(vi);
	cout << result << endl;
#elif TESTID == 62
	i1 = 3, i2 = 7;
	auto result = s.uniquePaths(i1, i2);
	cout << result << endl;
#elif TESTID == 63
	vvi = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
	auto result = s.uniquePathsWithObstacles(vvi);
	cout << result << endl;
#elif TESTID == 64
	vvi = { {1, 3, 1}, {1, 5, 1}, {4, 2, 1} };
	auto result = s.minPathSum(vvi);
	cout << result << endl;
#elif TESTID == 70
	i = 3;
	auto result = s.climbStairs(i);
	cout << result << endl;
#elif TESTID == 72
	str1 = "horse";
	str2 = "ros";
	auto result = s.minDistance(str1, str2);
	cout << result << endl;
#elif TESTID == 84
	vi = { 2,1,5,6,2,3 };
	auto result = s.largestRectangleArea(vi);
	cout << result << endl;
#elif TESTID == 85
	vector<vector<char>> Matrix = {
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'} };
	auto result = s.maximalRectangle(Matrix);
	cout << result << endl;
#elif TESTID == 256
	i0 = 3;
	i1 = 5;
	i2 = 7;
	i = 11;
	for (j = 0; j < i; j++)
	{
		vvi.push_back({ i0, i1, i2 });
	}
	auto ret = s.minCost(vvi);
	cout << ret << endl;
#elif TESTID == 1824
	vi = {0,1,2,3,0};
	// vi = {0,1,1,3,3,0};
	// vi = {0,2,1,0,3,0};
	auto ret = s.minSideJumps(vi);
	cout << ret << endl;
#elif TESTID == 1903
	str1 = "52";
	auto ret = s.largestOddNumber(str1);
	cout << ret << endl;
#elif TESTID == 1958
vector<vector<char>> board = {
	{'.','.','.','.','.','.','.','.'},
	{'.','B','.','.','W','.','.','.'},
	{'.','.','W','.','.','.','.','.'},
	{'.','.','.','W','B','.','.','.'},
	{'.','.','.','.','.','.','.','.'},
	{'.','.','.','.','B','W','.','.'},
	{'.','.','.','.','.','.','W','.'},
	{'.','.','.','.','.','.','.','B'}};
	auto ret = s.checkMove(board, 4, 4, 'W');
	cout << ret << endl;
#endif

	cout << "done" << endl;
}