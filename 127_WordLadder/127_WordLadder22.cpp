#include "../inc.h"

/*
这个算法果然牛逼，反向走，遍历每一个位置从a到z，而不是去dict里面循环
事实上，我们可不可以做一个估算，如果dict的循环的代价比a-z的循环要低，我们就循环dict，否则我们就循环a-z ？
*/
class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

        // 我们是不是可以再对整个wordList扫一遍建立一个简单的索引，把边缘切掉？提升不是很明显，如果量比较小，双层for的占比会比较重，如果量比较大，数学平均上来说，能切掉的面积就会变小
        vector<unordered_set<char>> valids(beginWord.size());
        for (const auto& word : wordList) {
            for (size_t i = 0; i < word.size(); ++i) {
                valids[i].insert(word[i]);
            }
        }

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
                    for (char c : valids[j]) {
                        s[j] = c;
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
        praw("ok.");
    } else {
        praw("not ok.");
        praw(beginWord);
        praw(endWord);
        pvraw(wordList);
        praw(expect);
        praw(ret);
        pnewline();
    }
}

int main() {
    test("a", "c", {"a", "b", "c"}, 2);
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}, 5);
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, 0);
    return 0;
}
