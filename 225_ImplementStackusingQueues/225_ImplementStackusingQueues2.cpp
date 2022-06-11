#include "../inc.h"

// 对1的性能优化，使用两个引用，不用实际交换队列的内存
class MyStack {
    queue<int> q1;
    queue<int> q2;
    queue<int>& q;
    queue<int>& qtmp;

   public:
    MyStack() : q(q1), qtmp(q2) {}

    void push(int x) { q.push(x); }

    int pop() {
        int qsize = q.size();
        if (qsize == 0) return -1;
        int ret = -1;
        --qsize;
        while (qsize-- > 0) {
            qtmp.push(q.front());
            q.pop();
        }
        ret = q.front();
        swap(q, qtmp);
        qtmp.pop();
        return ret;
    }

    int top() {
        if (q.empty()) return -1;
        int ret = pop();
        push(ret);
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
        praw("ok");
    } else {
        praw("not ok");
        pvraw(ops);
        pvvraw(params);
        pvcomplex(expect);
        pvcomplex(rets);
        pnewline();
    }
}

int main() {
    test({"MyStack", "push", "push", "top", "pop", "empty"}, {{}, {1}, {2}, {}, {}, {}}, {null, null, null, 2, 2, false});
    return 0;
}
