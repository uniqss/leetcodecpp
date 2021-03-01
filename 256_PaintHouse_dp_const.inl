/*
* ��Ϊ��û���Ա����ȷ���������ǲ���const.�����const����ֻ���ڲ��ٶ���һ���ṹ��
* �����Ż����������������ˣ���Ϊֻ�ü�¼��һ�ε�����
*/
class Solution
{
public:
	int minCost(const vector<vector<int>>& costs) {
		if (costs.size() == 0)
		{
			return 0;
		}
#if 0
		// ����һ������
		vector<vector<int>> matrix(costs.size(), vector<int>(3));
		matrix[0] = costs[0];

		for (auto i = 1; i < costs.size(); i++)
		{
			matrix[i][0] = costs[i][0] + std::min(matrix[i - 1][1], matrix[i - 1][2]);
			matrix[i][1] = costs[i][1] + std::min(matrix[i - 1][0], matrix[i - 1][2]);
			matrix[i][2] = costs[i][2] + std::min(matrix[i - 1][0], matrix[i - 1][1]);
		}
		auto j = costs.size() - 1;
		return std::min(std::min(matrix[j][0], matrix[j][1]), matrix[j][2]);
#else
		// ����������
		vector<int> current = costs[0];
		vector<int> last = current;
		for (auto i = 1;i < costs.size();i++)
		{
			current[0] = costs[i][0] + std::min(last[1], last[2]);
			current[1] = costs[i][1] + std::min(last[0], last[2]);
			current[2] = costs[i][2] + std::min(last[0], last[1]);
			last = current;
		}
		return std::min(std::min(current[0], current[1]), current[2]);
#endif
	}
};
