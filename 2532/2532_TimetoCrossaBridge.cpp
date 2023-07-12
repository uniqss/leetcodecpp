#include "../inc.h"

// 官网题解，为什么要加一起？？？

class Solution {
   public:
    using PII = pair<int, int>;
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        // 定义等待中的工人优先级比较规则，时间总和越高，效率越低，优先级越低，越优先被取出
        auto wait_priority_cmp = [&](int x, int y) {
            int time_x = time[x][0] + time[x][2];
            int time_y = time[y][0] + time[y][2];
            return time_x != time_y ? time_x < time_y : x < y;
        };

        priority_queue<int, vector<int>, decltype(wait_priority_cmp)> wait_left(wait_priority_cmp),
            wait_right(wait_priority_cmp);

        priority_queue<PII, vector<PII>, greater<PII>> work_left, work_right;

        int remain = n, cur_time = 0;
        for (int i = 0; i < k; i++) {
            wait_left.push(i);
        }
        while (remain > 0 || !work_right.empty() || !wait_right.empty()) {
            // 1. 若 work_left 或 work_right 中的工人完成工作，则将他们取出，并分别放置到 wait_left 和 wait_right 中。
            while (!work_left.empty() && work_left.top().first <= cur_time) {
                wait_left.push(work_left.top().second);
                work_left.pop();
            }
            while (!work_right.empty() && work_right.top().first <= cur_time) {
                wait_right.push(work_right.top().second);
                work_right.pop();
            }

            if (!wait_right.empty()) {
                // 2. 若右侧有工人在等待，则取出优先级最低的工人并过桥
                int id = wait_right.top();
                wait_right.pop();
                cur_time += time[id][2];
                work_left.push({cur_time + time[id][3], id});
            } else if (remain > 0 && !wait_left.empty()) {
                // 3. 若右侧还有箱子，并且左侧有工人在等待，则取出优先级最低的工人并过桥
                int id = wait_left.top();
                wait_left.pop();
                cur_time += time[id][0];
                work_right.push({cur_time + time[id][1], id});
                remain--;
            } else {
                // 4. 否则，没有人需要过桥，时间过渡到 work_left 和 work_right 中的最早完成时间
                int next_time = INT_MAX;
                if (!work_left.empty()) {
                    next_time = min(next_time, work_left.top().first);
                }
                if (!work_right.empty()) {
                    next_time = min(next_time, work_right.top().first);
                }
                if (next_time != INT_MAX) {
                    cur_time = max(next_time, cur_time);
                }
            }
        }
        return cur_time;
    }
};

void test(int n, int k, vector<vector<int>>&& time, int expect) {
    auto time_param = time;
    Solution so;
    auto ret = so.findCrossingTime(n, k, time);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(n);
        print(k);
        print(time_param);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test(1, 3, {{1, 1, 2, 1}, {1, 1, 3, 1}, {1, 1, 4, 1}}, 6);
    test(3, 2, {{1, 9, 1, 8}, {10, 10, 10, 10}}, 50);
    return 0;
}
