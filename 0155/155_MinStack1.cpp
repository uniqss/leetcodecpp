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
