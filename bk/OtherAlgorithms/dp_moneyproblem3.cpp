#include "../inc.h"


vector<int> getLeastCountMoney3(const vector<unsigned>& moneys, int n) {
	auto moneysize = moneys.size();
	vector<vector<int>> f(n + 1, vector<int>(moneysize + 1));
	int i, cost;
	vector<int> costs(moneysize);
	for (auto& tmp : f[0]) { tmp = 0; }
	for (i = 1; i <= n; i++)
	{
		cost = INT_MAX;
		for (auto& costtmp : costs) { costtmp = INT_MAX; }
		for (int costidx = 0; costidx < moneysize; ++costidx)
		{
			if (i >= moneys[costidx])
			{
				costs[costidx] = f[i - moneys[costidx]][0] + 1;
				cost = min(costs[costidx], cost);
			}
		}

		// set f[i]
		for (int costidx = 0; costidx < moneysize; ++costidx)
		{
			if (cost == costs[costidx] && i >= moneys[costidx])
			{
				f[i] = f[i - moneys[costidx]];
				f[i][0] = cost;
				f[i][costidx + 1] ++;
				break;
			}
		}
	}
	return f[n];
}

int main()
{
	vector<unsigned> moneys = { 1, 5, 11 };
	vector<int> cost = getLeastCountMoney3(moneys, 15);
	print(cost);

	return 0;
}
