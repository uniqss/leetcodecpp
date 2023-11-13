#include "../inc.h"

class MinStack {
    stack<int> stackval;
    stack<int> stackmin;

   public:
    MinStack() {
    }

    void push(int val) {
        stackval.push(val);
        if (stackmin.empty())
            stackmin.push(val);
        else {
            if (val <= stackmin.top()) {
                stackmin.push(val);
            }
        }
    }

    void pop() {
        int top = stackval.top();
        if (top <= stackmin.top()) {
            stackmin.pop();
        }
        stackval.pop();
    }

    int top() {
        return stackval.top();
    }

    int getMin() {
        return stackmin.top();
    }
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
