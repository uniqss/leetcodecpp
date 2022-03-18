#include "../stl.h"

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

vector<bool> all_version;

bool isBadVersion(int version) {
    all_version = {false, false, false, true, true};
    return all_version[version];
}

class Solution {
   public:
    int firstBadVersion(int n) {}
};

void test(vector<bool>&& all, int expect) {
    Solution so;
    int ret = so.firstBadVersion(nums, target);
    if (ret == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvraw(nums);
        praw(expect);
        praw(ret);
        pnewline();
    }
}

int main() {
    test({-1, 0, 3, 5, 9, 12}, 9, 4);
    test({-1, 0, 3, 5, 9, 12}, 2, -1);
    test({5}, 5, 0);
    return 0;
}
/*
[-1,0,3,5,9,12]
9
[-1,0,3,5,9,12]
2
*/
