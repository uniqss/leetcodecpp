#include "../inc.h"

class MinStack {
   public:
    MinStack() {}

    void push(int val) {}

    void pop() {}

    int top() {}

    int getMin() {}
};

void test(const vector<string>& oplist, const vector<vector<int>>& arglist, const vector<vector<int>>& expect) {
    MinStack mstk;
    vector<vector<int>> ret;
    for (int i = 0; i < oplist.size(); ++i) {
        const string& op = oplist[i];
        const vector<int>& param = arglist[i];

        vector<int> curr;
        if (op == "MinStack") {
        } else if (op == "push") {
            mstk.push(param[0]);
        } else if (op == "getMin") {
            curr.emplace_back(mstk.getMin());
        } else if (op == "pop") {
            mstk.pop();
        } else if (op == "top") {
            curr.emplace_back(mstk.top());
        }
        ret.emplace_back(curr);
    }
    assert_eq_ret(expect, ret);
    print(oplist);
    print(arglist);
}

int main() {
    test({"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"}, {{}, {-2}, {0}, {-3}, {}, {}, {}, {}},
         {{}, {}, {}, {}, {-3}, {}, {0}, {-2}});

    return 0;
}
