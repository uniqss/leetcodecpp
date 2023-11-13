#include "../inc.h"

class RecentCounter {
    queue<int> q;

   public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) q.pop();
        return q.size();
    }
};

void test(const vector<string>& ops, const vector<vector<int>>& params, const vector<ComplexVal>& expect) {
    RecentCounter so;
    vector<ComplexVal> ret;
    for (int i = 0; i < ops.size(); ++i) {
        const string& op = ops[i];
        const vector<int>& param = params[i];
        if (op == "RecentCounter") {
            ret.push_back(null);
        } else if (op == "ping") {
            auto curr = so.ping(param[0]);
            ret.push_back(curr);
        }
    }
    assert_eq_ret(expect, ret);
    print(ops);
    print(params);
}

int main() {
    test({"RecentCounter", "ping", "ping", "ping", "ping"}, {{}, {1}, {100}, {3001}, {3002}}, {null, 1, 2, 3, 3});
    return 0;
}