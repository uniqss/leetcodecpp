#include "../inc.h"

// 这题目不难，就是烦，，，太多细节容易出错。按难度系数只能算中等，但是如果按出错的概率，算的上hard里面的中级hard偏上
class Solution {
   public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int wsize = words.size();
        vector<int> wordslen(wsize);
        for (int i = 0; i < wsize; ++i) wordslen[i] = words[i].size();
        int first = 0, last = 0;
        while (last < wsize) {
            int count = wordslen[last];
            for (int i = last + 1; i < wsize; ++i) {
                if (count + wordslen[i] + 1 <= maxWidth) {
                    count += wordslen[i] + 1;
                    last = i;
                } else
                    break;
            }

            int spacecount = 0, lineinnercount = last - first, currspacecount = 0, spacemod = 0;
            if (last < wsize - 1) {
                spacecount = maxWidth - count;
                if (lineinnercount > 0) {
                    currspacecount = spacecount / lineinnercount;
                    spacemod = spacecount % lineinnercount;
                }
            }

            ret.resize(ret.size() + 1);
            string& line = ret[ret.size() - 1];
            line.resize(maxWidth, ' ');
            int start = 0;
            for (int i = first; i <= last; ++i) {
                for (char c : words[i]) line[start++] = c;
                ++start;
                start += currspacecount;
                if (spacemod > 0) ++start, --spacemod;
            }

            first = ++last;
        }

        return ret;
    }
};

void test(vector<string>&& words, int maxWidth, const vector<string>& expect) {
    save4print(words);
    save4print(maxWidth);
    Solution so;
    auto ret = so.fullJustify(words, maxWidth);
    assert_eq_ret(expect, ret);
}

int main() {
    test({"This", "is", "an", "example", "of", "text", "justification."}, 16,
         {"This    is    an", "example  of text", "justification.  "});
    test({"What", "must", "be", "acknowledgment", "shall", "be"}, 16,
         {"What   must   be", "acknowledgment  ", "shall be        "});
    test({"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art",
          "is", "everything", "else", "we", "do"},
         20,
         {"Science  is  what we", "understand      well", "enough to explain to", "a  computer.  Art is",
          "everything  else  we", "do                  "});
    return 0;
}
