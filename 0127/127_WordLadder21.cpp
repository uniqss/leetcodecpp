#include "../inc/inc.h"

/*
这个算法果然牛逼，反向走，遍历每一个位置从a到z，而不是去dict里面循环
事实上，我们可不可以做一个估算，如果dict的循环的代价比a-z的循环要低，我们就循环dict，否则我们就循环a-z ？
*/
class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        wordList.push_back(beginWord);
        queue<string> queue1, queue2, &q1 = queue1, &q2 = queue2;
        unordered_set<string> visited1 = {beginWord}, visited2 = {endWord}, &v1 = visited1, &v2 = visited2, allWordSet(wordList.begin(), wordList.end());
        queue1.emplace(beginWord);
        queue2.emplace(endWord);
        int count = 0;
        while (!q1.empty() && !q2.empty()) {
            ++count;
            if (q1.size() > q2.size()) {
                swap(q1, q2);
                swap(v1, v2);
            }
            auto qsize = q1.size();
            for (size_t i = 0; i < qsize; ++i) {
                string s = q1.front();
                q1.pop();
                for (size_t j = 0; j < s.size(); ++j) {
                    char c0 = s[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        s[j] = c;
                        // 理论上来说，如果allWordSet比较大时，一条线起点到终点，不命中的概率要大于已经存在于v1中的概率
                        if (allWordSet.count(s) == 0) continue;
                        if (v1.count(s) > 0) continue;
                        if (v2.count(s) > 0) return count + 1;

                        q1.emplace(s);
                        v1.emplace(s);
                    }
                    s[j] = c0;
                }
            }
        }
        return 0;
    }
};

void test(string&& beginWord, string&& endWord, vector<string>&& wordList, int expect) {
    Solution so;
    auto ret = so.ladderLength(beginWord, endWord, wordList);
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
    test("a", "c", {"a", "b", "c"}, 2);
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}, 5);
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, 0);
    return 0;
}
