#include "../inc/inc.h"

class Solution {
   public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> q;
        int size = nums.size();
        int numsi = 0;
        for (int i = 0; i < k; ++i) {
            numsi = nums[i];
            while (!q.empty() && q.back() < numsi) {
                q.pop_back();
            }
            q.emplace_back(nums[i]);
        }
        ret.emplace_back(q.front());
        for (int i = k; i < size; ++i) {
            numsi = nums[i];
            while (!q.empty() && q.back() < numsi) {
                q.pop_back();
            }
            q.push_back(numsi);

            if (q.size() > k || nums[i - k] == q.front()) q.pop_front();
            ret.emplace_back(q.front());
        }

        return ret;
    }
};

void test(const vector<int>& nums, int k, const vector<int>& expect) {
    Solution s;
    auto ret = s.maxSlidingWindow(nums, k);
    if (ret == expect) {
        print("ok");
    } else {
        print("##### not ok");
        print(nums);
        print(k);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({7, 2, 4}, 2, {7, 4});
    test({1, 3, -1, -3, 5, 3, 6, 7}, 3, {3, 3, 5, 5, 6, 7});
    test({1}, 1, {1});
    return 0;
}
