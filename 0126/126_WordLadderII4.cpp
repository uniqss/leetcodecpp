#include "../inc.h"

// bfs还是有问题，图的搜索掌握的还不够
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
        queue<vector<int>> q;
        q.push({start});
        vis[start] = true;
        bool found = false;
        while (!q.empty()) {
            if (found) break;
            int qsize = q.size();
            vector<bool> vis_currlayer(n);
            for (int qi = 0; qi < qsize; ++qi) {
                auto road = q.front();
                q.pop();
                for (int to : tos[road.back()]) {
                    if (vis[to]) continue;
                    vis_currlayer[to] = true;
                    road.emplace_back(target);
                    if (to == target) {
                        ret.resize(ret.size() + 1);
                        for (int r : road) {
                            ret[ret.size() - 1].emplace_back(wordList[r]);
                        }
                        found = true;
                    } else {
                        q.emplace(road);
                    }
                    road.pop_back();
                }
                for (int i = 0; i < n; ++i) vis[i] = vis[i] || vis_currlayer[i];
            }
        }
        return ret;
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
    test("qa", "sq",
         {"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le",
          "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn",
          "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc",
          "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co",
          "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an",
          "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io",
          "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye"},
         {});
    test(
        "red", "tax", {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"},
        {{"red", "ted", "tad", "tax"}, {"red", "ted", "tex", "tax"}, {"red", "rex", "tex", "tax"}});
    test("a", "c", {"a", "b", "c"}, {{"a", "c"}});
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"},
         {{"hit", "hot", "dot", "dog", "cog"}, {"hit", "hot", "lot", "log", "cog"}});
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, {});
    return 0;
}
