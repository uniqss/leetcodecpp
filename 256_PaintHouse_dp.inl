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
* �����Ŀ��һά��ʱ����������ģ���Ϊ��ɫֻҪ���ڵ���ɫ����ͬ����ô��ֻ��������ɫ�Ϳ����ˣ�ABABAB���ҳ���ʡ����ɫ��
�������Ϊ�����Ͱ���ʡ����ɫ����һ�� ����A < B < C����ABABABA������һ��һ��ΪA��ֻ��һ����ʽ�������
����Ϊ���� (n/2 + 1) * A + n/2 * B
����Ϊż�� (n/2) * A + n/2 * B

Ҳ�ɼ�Ϊ�� (n+1) / 2 * A + n/2 * B
*/
class Solution
{
public:
	int minCost(vector<vector<int>>& costs) {
		// ���ﻹ�ǰ�����dp��
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
