#include "../inc/inc.h"

class Solution {
    struct Helper{
        string word;
        vector<string> road;
        unordered_set<string> used;
        Helper(const string& _word)     {
            word = _word;
            road = {_word};
            used = {_word};
        }
    };
   public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.count(endWord) == 0) return ret;

        unordered_set<string> used = {beginWord};
        dict.erase(beginWord);
        queue<Helper> q;
        q.push({beginWord, {beginWord}, {beginword}});
        bool lastLayer = false;
        while (!q.empty() && !lastLayer) {
            auto qsize = q.size();
            while (qsize-- != 0) {
                string s = q.front().first;
                vector<string> roadLast = q.front().second;
                q.pop();
                for (size_t i = 0; i < s.size(); ++i) {
                    char c0 = s[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        s[i] = c;
                        if (used.count(s) > 0) continue;
                        if (s == endWord) {
                            lastLayer = true;
                            ret.emplace_back(roadLast);
                            ret.back().emplace_back(endWord);
                        }
                        if (lastLayer) continue;
                        if (dict.count(s) > 0) {
                            used.insert(s);
                            q.push({s, roadLast});
                            q.back().second.emplace_back(s);
                        }
                    }
                    s[i] = c0;
                }
            }
        }
        return ret;
    }
};

void test(string&& beginWord, string&& endWord, vector<string>&& wordList, vector<vector<string>>&& expect) {
    Solution so;
    auto ret = so.findLadders(beginWord, endWord, wordList);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(beginWord);
        print(endWord);
        print(wordList);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test("red", "tax", {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"},
         {{"red", "ted", "tad", "tax"}, {"red", "ted", "tex", "tax"}, {"red", "rex", "tex", "tax"}});
    test("a", "c", {"a", "b", "c"}, {{"a", "c"}});
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}, {{"hit", "hot", "dot", "dog", "cog"}, {"hit", "hot", "lot", "log", "cog"}});
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, {});
    return 0;
}
