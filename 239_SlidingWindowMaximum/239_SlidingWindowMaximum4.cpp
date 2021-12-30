#include "../stl.h"

class Solution {
   public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        deque<int> nmax;
        deque<int> ndel;
        vector<int> ret;
        for (size_t i = 0; i < nums.size(); ++i) {
            // mono queue push back
            int deleted = 0;
            while (!nmax.empty() && nums[i] > nmax.back()) {
                deleted += ndel.back() + 1;
                nmax.pop_back();
                ndel.pop_back();
            }
            nmax.push_back(nums[i]);
            ndel.push_back(deleted);

            // mono queue pop front if needed
            if (i >= k) {
                if (ndel.front() > 0)
                    --ndel.front();
                else {
                    nmax.pop_front();
                    ndel.pop_front();
                }
            }

            // save ret
            if (i >= k - 1) {
                ret.push_back(nmax.front());
            }
        }
        return ret;
    }
};

void test(const vector<int>& nums, int k, const vector<int>& expect) {
    pvi(nums);
    praw(k);
    Solution s;
    auto ret = s.maxSlidingWindow(nums, k);
    if (ret == expect) {
        praw("ok");
    } else {
        praw("##### not ok");
        pvi(expect);
        pvi(ret);
    }
    pnewline();
}

int main() {
    test({7, 2, 4}, 2, {7, 4});
    test({1, 3, -1, -3, 5, 3, 6, 7}, 3, {3, 3, 5, 5, 6, 7});
    test({1}, 1, {1});
    return 0;
}
