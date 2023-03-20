#include "../inc/inc.h"

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

MinStack* g_mstack = nullptr;

ComplexVal test_i(const string& op, const vector<int>& args) {
    ComplexVal ret = null;
    if (op == "MinStack") {
        g_mstack = new MinStack();
    } else if (op == "push") {
        g_mstack->push(args[0]);
    } else if (op == "getMin") {
        ret = g_mstack->getMin();
    } else if (op == "pop") {
        g_mstack->pop();
    } else if (op == "top") {
        ret = g_mstack->top();
    }
    return ret;
}

void test(const vector<string>& oplist, const vector<vector<int>>& arglist, const vector<vector<int>>& expect) {
    vector<ComplexVal> ret;
    for (size_t i = 0; i < oplist.size(); ++i) {
        const string& op = oplist[i];
        const vector<int>& arg = arglist[i];
        ComplexVal retcomplex = test_i(op, arg);
        ret.push_back(retcomplex);
    }
    vector<ComplexVal> expectvec;
    for (size_t i = 0; i < expect.size(); ++i) {
        const vector<int>& exp = expect[i];
        if (exp.empty())
            expectvec.push_back(null);
        else
            expectvec.push_back(exp[0]);
    }

    if (ret == expectvec) {
        print("ok.");
    } else {
        print("not ok.");
        print(oplist);
        print(arglist);
        print(expect);
        print(ret);
        print();
    }

    if (g_mstack != nullptr) {
        delete g_mstack;
        g_mstack = nullptr;
    }
}

int main() {
    test({"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"}, {{}, {-2}, {0}, {-3}, {}, {}, {}, {}},
         {{}, {}, {}, {}, {-3}, {}, {0}, {-2}});

    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

 */
