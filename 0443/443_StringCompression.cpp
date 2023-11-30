#include "../inc.h"

class Solution {
   public:
    int compress(vector<char>& chars) {}
};

void test(vector<char>&& chars, int expect) {
    save4print(chars);
    assert_eq_ret(expect, Solution().compress(chars));
}

int main() {
    test({'a', 'a', 'b', 'b', 'c', 'c', 'c'}, 6);
    test({'a'}, 1);
    test({'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}, 4);
    return 0;
}
