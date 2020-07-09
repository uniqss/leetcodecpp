#include "../stl.h"


int getLeastCountMoney1(int n) {
	vector<int> f(n + 1);
	int i, cost;
	f[0] = 0;
	for (i = 1; i <= n; i++)
	{
		cost = INT_MAX;
		if (i - 1 >= 0) cost = min(cost, f[i - 1] + 1);
		if (i - 5 >= 0) cost = min(cost, f[i - 5] + 1);
		if (i - 11 >= 0) cost = min(cost, f[i - 11] + 1);
		f[i] = cost;
	}
	return f[n];
}

int main()
{
	int cost = getLeastCountMoney1(15);
	cout << cost << endl;

	return 0;
}
