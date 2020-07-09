#include "../stl.h"


vector<int> getLeastCountMoney2(int n) {
	vector<vector<int>> f(n + 1, vector<int>(4));
	int i, cost, cost1, cost2, cost3;
	f[0] = { 0, 0, 0, 0 };
	for (i = 1; i <= n; i++)
	{
		cost1 = cost2 = cost3 = INT_MAX;
		if (i - 1 >= 0) cost1 = f[i - 1][0] + 1;
		if (i - 5 >= 0) cost2 = f[i - 5][0] + 1;
		if (i - 11 >= 0) cost3 = f[i - 11][0] + 1;

		cost = min(cost1, min(cost2, cost3));
		if (cost == cost1) f[i] = { cost1, f[i - 1][1] + 1, f[i - 1][2], f[i - 1][3] };
		if (cost == cost2) f[i] = { cost2, f[i - 5][1], f[i - 5][2] + 1, f[i - 5][3] };
		if (cost == cost3) f[i] = { cost3, f[i - 11][1], f[i - 11][2], f[i - 11][3] + 1 };
	}
	return f[n];
}

int main()
{
	vector<int> cost = getLeastCountMoney2(17);
	for (auto i : cost)
	{
		cout << i << "\t";
	}
	cout << endl;

	return 0;
}
