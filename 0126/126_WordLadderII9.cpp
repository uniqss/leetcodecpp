#include "../inc.h"

class Solution {
   public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret;
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return ret;

        queue<string> queue1, queue2, &q1 = queue1, &q2 = queue2;
        q1.emplace(beginWord), q2.emplace(endWord);
        std::unordered_set<string> dict(wordList.begin(), wordList.end());
        dict.insert(beginWord);
        std::unordered_set<string> used1 = {beginWord}, used2 = {endWord}, &u1 = used1, &u2 = used2;
        std::unordered_map<string, vector<string>> roads1, roads2, &r1 = roads1, &r2 = roads2;
        r1[beginWord].push_back(beginWord);
        r2[endWord].push_back(endWord);
        int count = 0;
        while (!q1.empty() && !q2.empty()) {
            ++count;
            if (q1.size() > q2.size()) {
                swap(q1, q2);
                swap(u1, u2);
                swap(r1, r2);
            }
            auto qsize = q1.size();
            while (qsize-- != 0) {
                string s = q1.front();
                q1.pop();
                string to = s;
                for (size_t i = 0; i < s.size(); ++i) {
                    char c0 = s[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        s[i] = c;
                        if (u1.count(s) > 0) continue;
                        if (u2.count(s) > 0) {
                            r2[s]
                            r1[to]
                            return count + 1;
                        }
                        if (dict.count(s) > 0) {
                            r1[s] = r1[to];
                            r1[s].push_back(s);
                            u1.insert(s);
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
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}, {{"hit", "hot", "dot", "dog", "cog"}, {"hit", "hot", "lot", "log", "cog"}});
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, {});
    return 0;
}
