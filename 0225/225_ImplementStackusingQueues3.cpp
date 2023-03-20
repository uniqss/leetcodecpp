#include "../inc/inc.h"

class MyStack {
    queue<int> q;

   public:
    MyStack() {}

    void push(int x) { q.push(x); }

    int pop() {
        int qsize = q.size();
        if (qsize == 0) return -1;
        int ret = -1;
        --qsize;
        while (qsize-- > 0) {
            q.push(q.front());
            q.pop();
        }
        ret = q.front();
        q.pop();
        return ret;
    }

    int top() {
        int qsize = q.size();
        if (qsize == 0) return -1;
        int ret = -1;
        --qsize;
        while (qsize-- > 0) {
            q.push(q.front());
            q.pop();
        }
        ret = q.front();
        q.push(q.front());
        q.pop();
        return ret;
    }

    bool empty() { return q.empty(); }
};


void test(const vector<string>& ops, const vector<vector<int>>& params, const vector<ComplexVal>& expect) {
    MyStack stk;
    vector<ComplexVal> rets;
    for (size_t i = 0; i < ops.size(); ++i) {
        const string& op = ops[i];
        const vector<int>& param = params[i];
        ComplexVal ret = null;
        if (op == "MyStack") {
        } else if (op == "push") {
            stk.push(param[0]);
        } else if (op == "pop") {
            ret = stk.pop();
        } else if (op == "top") {
            ret = stk.top();
        } else if (op == "empty") {
            ret = stk.empty();
        }

        rets.emplace_back(ret);
    }
    if (rets == expect) {
        print("ok");
    } else {
        print("not ok");
        print(ops);
        print(params);
        print(expect);
        print(rets);
        print();
    }
}

int main() {
    test({"MyStack", "push", "push", "top", "pop", "empty"}, {{}, {1}, {2}, {}, {}, {}}, {null, null, null, 2, 2, false});
    return 0;
}
