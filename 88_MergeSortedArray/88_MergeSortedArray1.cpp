#include "../stl.h"

class Solution
{
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int mi = m - 1;
        int ni = n - 1;
        int idx = m + n - 1;
        nums1.resize(m + n);
        while (mi >= 0 && ni >= 0)
        {
            if (nums1[mi] > nums2[ni])
            {
                nums1[idx--] = nums1[mi--];
            }
            else
            {
                nums1[idx--] = nums2[ni--];
            }
        }
        while (ni >= 0)
        {
            nums1[idx--] = nums2[ni--];
        }
    }
};

void test(std::vector<int>& v1, int m, std::vector<int>& v2, int n)
{
    Solution s;
    pvi(v1);
    praw(m);
    pvi(v2);
    praw(n);
    s.merge(v1, m, v2, n);
    pvi(v1);
    pnewline();
}

int main()
{
    vector<int> vi1;
    vector<int> vi2;
    int m = 0;
    int n = 0;

    vi1 = {1, 2, 3, 0, 0, 0};
    m = 3;
    vi2 = {2, 5, 6};
    n = 3;
    test(vi1, m, vi2, n);

    vi1 = {1, 2, 3, 6, 0, 0, 0};
    m = 4;
    vi2 = {2, 5, 7};
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
