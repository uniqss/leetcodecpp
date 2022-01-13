class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
	    if (strs.empty())
	    {
            return "";
	    }
	    if (strs.size() == 1)
	    {
			return strs[0];
	    }
        size_t end = 0;
        const string& str = strs[0];
    	for (;end < str.size();end++)
    	{
    		for (size_t i = 1;i < strs.size();i++)
    		{
	            if (end > strs[i].size())
	            {
					return str.substr(0, end);
	            }
	            if (str[end] != strs[i][end])
	            {
					return str.substr(0, end);
	            }
    		}
    	}
        return str.substr(0, end);
    }
};