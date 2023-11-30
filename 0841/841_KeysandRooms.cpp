#include "../inc.h"

class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {}
};

void test(vector<vector<int>>&& rooms, bool expect) {
    save4print(rooms);
    assert_eq_ret(expect, Solution().canVisitAllRooms(rooms));
}

int main() {
    test({{1}, {2}, {3}, {}}, true);
    test({{1, 3}, {3, 0, 1}, {2}, {0}}, false);
    return 0;
}
