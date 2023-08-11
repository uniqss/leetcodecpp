#include "../inc.h"

class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {}
};

void test(vector<vector<int>>&& rooms, bool expect) {
    Solution so;
    auto ret = so.canVisitAllRooms(rooms);
    assert_eq_ret(expect, ret);
    print(rooms);
}

int main() {
    test({{1}, {2}, {3}, {}}, true);
    test({{1, 3}, {3, 0, 1}, {2}, {0}}, false);
    return 0;
}
