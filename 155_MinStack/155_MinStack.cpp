#include "../stl.h"

template <class T>
class StackElement {
   public:
    T data;
    StackElement* next;
    StackElement() : data(0), next(nullptr) {}
    StackElement(const T& _data) : data(_data), next(nullptr) {}
};

class MinStack {
    StackElement<int>* m_etop;

   public:
    MinStack() : m_etop(nullptr) {
    }

    void push(int val) {
        StackElement<int>* e = new StackElement(val);
        e->next = m_etop;
        m_etop = e;
    }

    void pop() {
        auto tmp = m_etop;
        m_etop = m_etop->next;
        delete tmp;
    }

    int top() {
        return m_etop->data;
    }

    int getMin() {
        return 0;
    }
};

MinStack* g_mstack = nullptr;

int test(const string& op, const vector<int>& args) {
    int ret = INT_MIN;
    if (op == "MinStack") {
        g_mstack = new MinStack();
    } else if (op == "push") {
        g_mstack->push(args[0]);
    } else if (op == "getMin") {
        ret = g_mstack->getMin();
    } else if (op == "pop") {
        g_mstack->pop();
    }
    return ret;
}

int main() {
    vector<string> oplist;
    vector<vector<int>> argslist;
    vector<int> ret;

    oplist = {"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"};
    argslist = {{}, {-2}, {0}, {-3}, {}, {}, {}, {}};
    ret = {};
    for (size_t i = 0; i < oplist.size(); ++i) {
        const string& op = oplist[i];
        const vector<int>& arg = argslist[i];
        ret.push_back(test(op, arg));
    }
    pvi(ret);

    if (g_mstack != nullptr) {
        delete g_mstack;
        g_mstack = nullptr;
    }
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
