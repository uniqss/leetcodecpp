/*
* Paint House
* There are a row of n houses, each house can be painted with one of the three colors: red, blue or green.
The cost of painting each house with a certain color is different. You have to paint all the houses such
that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example,
costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with
color green, and so on... Find the minimum cost to paint all houses.
*/

/*
* 这个题目在一维的时候是有问题的，因为三色只要相邻的颜色不相同，那么就只用两种颜色就可以了，ABABAB，找出最省的两色，
如果总数为单数就把最省的颜色多用一个 假设A < B < C，则ABABABA，定第一个一定为A，只用一个公式就能算出
数量为奇数 (n/2 + 1) * A + n/2 * B
数量为偶数 (n/2) * A + n/2 * B

也可简化为： (n+1) / 2 * A + n/2 * B
*/
class Solution
{
public:
	int minCost(vector<vector<int>>& costs) {
		// 这里还是按正规dp解
		if (costs.size() == 0)
		{
			return 0;
		}
		for (auto i = 1; i < costs.size(); i++)
		{
			costs[i][0] += std::min(costs[i - 1][1], costs[i - 1][2]);
			costs[i][1] += std::min(costs[i - 1][0], costs[i - 1][2]);
			costs[i][2] += std::min(costs[i - 1][0], costs[i - 1][1]);
		}
		auto j = costs.size() - 1;
		return std::min(std::min(costs[j][0], costs[j][1]), costs[j][2]);
	}
};
