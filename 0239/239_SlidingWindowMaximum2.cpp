#include "../inc.h"

// nomoqueue
class MonoQueue {
    // first: val
    // second: the numbers of elements deleted before
    deque<pair<int, int>> vals;

   public:
    void push(int val) {
        int count = 0;
        while (!vals.empty() && val > vals.back().first) {
            count += vals.back().second + 1;
            vals.pop_back();
        }
        vals.push_back({val, count});
    }
    void pop() {
        if (vals.front().second > 0) {
            --vals.front().second;
        } else {
            vals.pop_front();
        }
    }
    int max() {
        return vals.front().first;
    }
};

class Solution {
   public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        MonoQueue mq;
        vector<int> ret;
        for (size_t i = 0; i < nums.size(); ++i) {
            mq.push(nums[i]);
            if ((int)i >= k - 1) {
                ret.push_back(mq.max());
                mq.pop();
            }
        }
        return ret;
    }
};

void test(const vector<int>& nums, int k, const vector<int>& expect) {
    print(nums);
    print(k);
    Solution s;
    auto ret = s.maxSlidingWindow(nums, k);
    if (ret == expect) {
        print("ok");
    } else {
        print("##### not ok");
        print(expect);
        print(ret);
    }
    print();
}

int main() {
    test({7, 2, 4}, 2, {7, 4});
    test({1, 3, -1, -3, 5, 3, 6, 7}, 3, {3, 3, 5, 5, 6, 7});
    test({1}, 1, {1});
    return 0;
}
