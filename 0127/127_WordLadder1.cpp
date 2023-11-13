#include "../inc.h"

/*
这题是真特么难
为什么会巨慢如爬呢(1058ms，只击败了20%的速度)，，，是因为不是用的图的思维吗？
*/
class Solution {
    std::unordered_set<string> dict, existed;

   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        dict.insert(wordList.begin(), wordList.end());
        if (dict.count(endWord) == 0) return 0;
        int depth1 = 0, depth2 = 0;
        unordered_set<string> curr1 = {beginWord}, curr2 = {endWord};
        bool found = bfs(depth1, depth2, curr1, curr2);
        if (found) return depth1 + depth2 + 1;
        return 0;
    }

    bool bfs(int& depth1, int& depth2, unordered_set<string>& curr1, unordered_set<string>& curr2) {
        ++depth1;
        unordered_set<string> currlayer;
        for (auto& dict_word : dict) {
            if (existed.count(dict_word) > 0) continue;
            for (auto& curr : curr1) {
                if (strOneDifferent(dict_word, curr)) {
                    if (curr2.count(dict_word) > 0) return true;
                    currlayer.emplace(dict_word);
                }
            }
        }
        if (currlayer.empty()) return false;
        existed.insert(curr1.begin(), curr1.end());
        curr1 = currlayer;

        if (depth1 > depth2) return bfs(depth2, depth1, curr2, curr1);
        return bfs(depth1, depth2, curr1, curr2);
    }

    bool strOneDifferent(const string& lhs, const string& rhs) {
        int count = 0;
        for (size_t i = 0; i < lhs.size(); ++i) {
            if (lhs[i] != rhs[i]) {
                if (++count > 1) return false;
            }
        }
        return count == 1;
    }
};

void test(string&& beginWord, string&& endWord, vector<string>&& wordList, int expect) {
    save4print(beginWord, endWord, wordList);
    assert_eq_ret(expect, Solution().ladderLength(beginWord, endWord, wordList));
}

int main() {
    test("a", "c", {"a", "b", "c"}, 2);
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}, 5);
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, 0);
    return 0;
}
