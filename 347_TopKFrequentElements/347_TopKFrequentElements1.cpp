#include "../inc.h"

class mycmp_pqpii {
   public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) { return lhs.second > rhs.second; }
};

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> num2freq;
        for (int num : nums) {
            ++num2freq[num];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp_pqpii> pq;
        for (pair<int, int> pii : num2freq) {
            pq.push(pii);
            if (pq.size() > k) pq.pop();
        }
        for (int i = pq.size() - 1; i >= 0; --i) {
            ret.emplace_back(pq.top().first);
            pq.pop();
        }

        return ret;
    }
};

void test(vector<int>&& nums, int k, vector<int>&& expect) {
    Solution so;
    auto ret = so.topKFrequent(nums, k);
    sort(expect.begin(), expect.end());
    sort(ret.begin(), ret.end());
    if (expect == ret) {
        print("ok");
    } else {
        print("not ok");
        print(nums);
        print(k);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 1, 1, 2, 2, 3}, 2, {1, 2});
    test({1}, 1, {1});
    return 0;
}
