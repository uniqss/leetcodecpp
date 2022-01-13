class Solution {
public:
	int romanToInt(string s) {
		//vector<int> vi{ 1, 5, 10, 50, 100, 500, 1000 };
		//vector<char> vs{ 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
		//unordered_map<char, int> dict;
		//for (int i = 0; i < vi.size(); i++)
		//	dict[vs[i]] = vi[i];
		
		unordered_map<char, int> dict{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

		int ret = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int post = i + 1;
			if (post < s.size() && dict[s[i]] < dict[s[post]])
			{
				ret += dict[s[post]] - dict[s[i]];
				i++;
				continue;
			}

			ret += dict[s[i]];
		}
		return ret;
	}
};