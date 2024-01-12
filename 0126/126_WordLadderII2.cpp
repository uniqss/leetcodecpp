#include "../inc.h"

// 还是超时间限制
class Solution {
   public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> w2i;
        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end())
            wordList.emplace_back(beginWord);
        int n = 0, wsize = wordList.size();
        for (const auto& word : wordList) w2i[word] = n++;
        if (w2i.count(endWord) == 0) return {};
        vector<vector<int>> tos(n);
        auto strfit = [](const string& s1, const string& s2) -> bool {
            int diff = 0;
            for (int i = 0; i < s1.size(); ++i)
                if (s1[i] != s2[i])
                    if (++diff > 1) return false;
            return true;
        };
        for (int i = 0; i < wsize; ++i) {
            for (int j = i + 1; j < wsize; ++j) {
                if (strfit(wordList[i], wordList[j]))
                    tos[i].emplace_back(j), tos[j].emplace_back(i);
            }
        }

        vector<bool> vis(n);
        vector<vector<string>> ret;
        int start = w2i[beginWord];
        int target = w2i[endWord];
        vector<int> road = {start};
        function<void(int)> dfs = [&](int curr) {
            for (auto to : tos[curr]) {
                if (vis[to]) continue;
                vis[to] = true;
                road.emplace_back(to);
                if (to == target) {
                    ret.resize(ret.size() + 1);
                    for (int i : road) ret[ret.size() - 1].emplace_back(wordList[i]);
                } else {
                    dfs(to);
                }
                road.pop_back();
                vis[to] = false;
            }
        };
        vis[start] = true;
        dfs(start);
        vector<vector<string>> ret_md;
        int minlen = INT_MAX;
        for (const auto& r : ret) minlen = min(minlen, (int)r.size());
        for (const auto& ri : ret) {
            if (ri.size() == minlen) ret_md.emplace_back(ri);
        }
        return ret_md;
    }
};

void test(string&& beginWord, string&& endWord, vector<string>&& wordList,
          vector<vector<string>>&& expect) {
    save4print(beginWord, endWord, wordList);
    sort(expect.begin(), expect.end());
    auto ret = Solution().findLadders(beginWord, endWord, wordList);
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test(
        "red", "tax", {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"},
        {{"red", "ted", "tad", "tax"}, {"red", "ted", "tex", "tax"}, {"red", "rex", "tex", "tax"}});
    test("a", "c", {"a", "b", "c"}, {{"a", "c"}});
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"},
         {{"hit", "hot", "dot", "dog", "cog"}, {"hit", "hot", "lot", "log", "cog"}});
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, {});
    return 0;
}
