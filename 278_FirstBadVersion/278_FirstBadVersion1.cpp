#include "../stl.h"

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

vector<bool> g_bad_version;

bool isBadVersion(int version) {
    return g_bad_version[version - 1];
}

class Solution {
   public:
    int firstBadVersion(int n) {
        // []
        int left = 1;
        int right = n;
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            bool isBad = isBadVersion(mid);
            if (isBad)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

void test(int n, int bad) {
    Solution so;
    g_bad_version.resize(n, false);
    for (int i = bad - 1; i < n; ++i) {
        g_bad_version[i] = true;
    }

    int ret = so.firstBadVersion(n);
    if (ret == bad) {
        praw("ok.");
    } else {
        praw("not ok.");
        praw(n);
        praw(bad);
        praw(ret);
        pnewline();
    }
}

int main() {
    test(5, 4);
    test(1, 1);
    test(3, 1);
    return 0;
}
/*
[-1,0,3,5,9,12]
9
[-1,0,3,5,9,12]
2
*/
