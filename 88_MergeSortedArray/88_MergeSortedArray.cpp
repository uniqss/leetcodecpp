#include "../inc.h"

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    }
};

void test(std::vector<int>& v1, int m, std::vector<int>& v2, int n) {
    Solution s;
    pvraw(v1);
    praw(m);
    pvraw(v2);
    praw(n);
    s.merge(v1, m, v2, n);
    pvraw(v1);
    pnewline();
}

int main() {
    vector<int> vi1;
    vector<int> vi2;
    int m = 0;
    int n = 0;

    vi1 = {1, 2, 3, 0, 0, 0};
    m = 3;
    vi2 = {2, 5, 6};
    n = 3;
    test(vi1, m, vi2, n);

    vi1 = {1};
    m = 1;
    vi2 = {};
    n = 0;
    test(vi1, m, vi2, n);

    vi1 = {0};
    m = 0;
    vi2 = {1};
    n = 1;
    test(vi1, m, vi2, n);

    return 0;
}
