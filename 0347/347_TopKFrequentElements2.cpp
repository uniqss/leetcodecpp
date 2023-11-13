#include "../inc.h"

class Solution {
    struct PairIIGreaterFirst {
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const { return lhs.first > rhs.first; }
    };

   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> n2count;
        for (int n : nums) ++n2count[n];
        priority_queue<pair<int, int>, vector<pair<int, int>>, PairIIGreaterFirst> pq;
        for (const auto& [n, count] : n2count) {
            pq.emplace(count, n);
            if (pq.size() > k) pq.pop();
        }
        vector<int> ret;
        while (!pq.empty()) {
            const auto& [count, n] = pq.top();
            ret.emplace_back(n);
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
