class Solution {
public:
	bool isPalindrome(int x) {
		int reverse = 0;
		if (x < 0 || x > 0 && x % 10 == 0)
		{
			return false;
		}
		int xmod = 0;
		while (x > reverse)
		{
			xmod = x % 10;
			reverse *= 10;
			reverse += xmod;
			x /= 10;
		}
		if (x == reverse || x == reverse / 10)
		{
			return true;
		}
		return false;
	}
};