#include "../inc.h"

class RecentCounter {
   public:
    RecentCounter() {}

    int ping(int t) {}
};

void test(const vector<string>& ops, const vector<vector<int>>& params, const vector<ComplexVal>& expect) {
    save4print(ops, params);
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
}

int main() {
    test({"RecentCounter", "ping", "ping", "ping", "ping"}, {{}, {1}, {100}, {3001}, {3002}}, {null, 1, 2, 3, 3});
    return 0;
}
