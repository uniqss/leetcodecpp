#include "../inc.h"

// 我加入了额外机制前移时判定数量过滤里面的次数，还原成string直接做hash的key，居然11%   看来string的代价确实是很大，没改前1的cpu有50%多
class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wsize = words.size(), onesize = words[0].size(), allsize = wsize * onesize, ssize = s.size();
        if (ssize < allsize) return {};
        unordered_map<string, int> str2count;
        vector<int> countsall(26), countscurr(26);
        for (const auto& word : words) {
            for (char c : word) ++countsall[c - 'a'];
            ++str2count[word];
        }
        vector<int> ret;
        for (int i = 0; i < ssize; ++i) {
            char c = s[i] - 'a';
            ++countscurr[c];
            if (i < allsize - 1) continue;
            int startpos = i + 1 - allsize;
            if (i >= allsize) --countscurr[s[startpos - 1] - 'a'];
            if (countscurr != countsall) continue;
            unordered_map<string, int> str2countcurr;
            bool valid = true;
            for (int j = 0; j < wsize; ++j) {
                auto str = s.substr(startpos + j * onesize, onesize);
                ++str2countcurr[str];
                if (str2countcurr[str] > str2count[str]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ret.emplace_back(startpos);
            }
        }
        return ret;
    }
};

void test(string s, vector<string>&& words, vector<int>&& expect) {
    save4print(s);
    save4print(words);
    Solution so;
    auto ret = so.findSubstring(s, words);
    sort(expect.begin(), expect.end());
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test("barfoothefoobarman", {"foo", "bar"}, {0, 9});
    test("wordgoodgoodgoodbestword", {"word", "good", "best", "word"}, {});
    test("barfoofoobarthefoobarman", {"bar", "foo", "the"}, {6, 9, 12});
    return 0;
}
