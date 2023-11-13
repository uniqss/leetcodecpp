#include "../inc.h"

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {}
};

void test(vector<vector<char>>&& board, const string& word, bool expect) {
    save4print(board, word);
    assert_eq_ret(expect, Solution().exist(board, word));
}

int main() {
    test({{'a'}}, "a", true);
    test({{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "ABCCED", true);
    test({{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "SEE", true);
    test({{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "ABCB", false);
    return 0;
}
