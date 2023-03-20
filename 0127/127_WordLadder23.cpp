#include "../inc/inc.h"

/*
这里两个queue，实则不是根据depth来了，因为每个节点的分叉可能是不一样的。例如：
            .
        .   .   .
            .
            .
            .       => 这时从上到下的depth为第5层，即使是到了第5层，依然是应该从上往下找而不是从下往上找
            .
    .   .   .   .   .   => 这时从下往上的depth为第3层
        .   .   .
            .
上面有连续的4个只有一个节点的情况，用两个queue的意思是，我们每次都从少的一方出发，不管它的depth是多少。
*/

class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 这一步一定要记住，首先要干的第一件事情就是check一下end是否在list里，不在直接返回0
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        queue<string> queue1, queue2, &q1 = queue1, &q2 = queue2;
        q1.emplace(beginWord), q2.emplace(endWord);
        std::unordered_set<string> used1 = {beginWord}, used2 = {endWord}, &u1 = used1, &u2 = used2;
        std::unordered_set<string> dict(wordList.begin(), wordList.end());
        // 这一步其实可以省掉，这样写是为了避免代码比较赘余
        dict.insert(beginWord);
        int count = 0;
        while (!q1.empty() && !q2.empty()) {
            ++count;
            if (q1.size() > q2.size()) {
                swap(q1, q2);
                swap(u1, u2);
            }
            auto qsize = q1.size();
            while (qsize-- != 0) {
                string s = q1.front();
                q1.pop();
                for (size_t i = 0; i < s.size(); ++i) {
                    char c0 = s[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        s[i] = c;
                        if (u1.count(s) > 0) continue;
                        if (u2.count(s) > 0) return count + 1;
                        if (dict.count(s) > 0) {
                            u1.insert(s);
                            q1.emplace(s);
                        }
                    }
                    s[i] = c0;
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
