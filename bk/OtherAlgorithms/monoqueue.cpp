#include "../inc.h"

class MonoQueue {
    // first is the value
    // second is the elements deleted count before this element.
    deque<pair<int, int>> vals;
    bool ascending;

   public:
    MonoQueue(bool _ascending) : ascending(_ascending) {}
    void push(int val) {
        int count = 0;
        if (ascending) {
            while (!vals.empty() && vals.back().first > val) {
                count += vals.back().second + 1;
                vals.pop_back();
            }
        } else {
            while (!vals.empty() && vals.back().first < val) {
                count += vals.back().second + 1;
                vals.pop_back();
            }
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
    int front_val() {
        return vals.front().first;
    }
    int front_deleted() {
        return vals.front().second;
    }
    void foreach (std::function<bool(int val, int deleted)> func) {
        for (auto& it : vals) {
            if (!func(it.first, it.second)) return;
        }
    }
    bool empty() {
        return vals.empty();
    }
};

void test(vector<int>& vi, vector<int>& val1, vector<int>& del1, vector<int>& val2, vector<int>& del2) {
    MonoQueue mq1(false);
    MonoQueue mq2(true);
    for (size_t i = 0; i < vi.size(); ++i) {
        mq1.push(vi[i]);
        mq2.push(vi[i]);
    }

    mq1.foreach ([&](int val, int deleted) {
        val1.push_back(val);
        del1.push_back(deleted);
        return true;
    });

    mq2.foreach ([&](int val, int deleted) {
        val2.push_back(val);
        del2.push_back(deleted);
        return true;
    });
}

int main() {
    vector<int> vi;

    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int> dis(1, 100);
    for (int i = 0; i < 30; i++) {
        auto result = dis(generator);
        vi.push_back(result);
    }

    print(vi);
    vector<int> val1;
    vector<int> val2;
    vector<int> del1;
    vector<int> del2;
    test(vi, val1, del1, val2, del2);
    print(val1);
    print(del1);
    print();
    print(val2);
    print(del2);

    return 0;
}