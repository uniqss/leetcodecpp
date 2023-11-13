#include "../inc.h"

class Solution {
   public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {}
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
