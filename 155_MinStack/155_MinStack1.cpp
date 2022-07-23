#include "../inc.h"

template <class T>
class StackElement {
   public:
    T data;
    T min;
    StackElement* next;
    StackElement(T _data) : data(_data), min(_data), next(nullptr) {}
};

class MinStack {
    StackElement<int>* m_etop;

   public:
    MinStack() : m_etop(nullptr) {}

    void push(int val) {
        StackElement<int>* e = new StackElement<int>(val);
        if (m_etop != nullptr) e->min = min(val, m_etop->min);
        e->next = m_etop;
        m_etop = e;
    }

    void pop() {
        auto tmp = m_etop;
        m_etop = m_etop->next;
        delete tmp;
    }

    int top() { return m_etop->data; }

    int getMin() { return m_etop->min; }
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
        praw("ok.");
    } else {
        praw("not ok.");
        pvraw(oplist);
        pvvraw(arglist);
        pvvraw(expect);
        pvcomplex(ret);
        pnewline();
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
