#include "../inc.h"

template <class T>
class StackElement {
   public:
    T data;
    StackElement* next;
    // StackElement() : data(0), next(nullptr) {}
    StackElement(const T& _data) : data(_data), next(nullptr) {}
};

template <class T>
class MinStack {
    StackElement<T>* m_etop;

   public:
    MinStack() : m_etop(nullptr) {
    }

    void push(const T& val) {
        StackElement<T>* e = new StackElement<T>(val);
        e->next = m_etop;
        m_etop = e;
    }

    T pop() {
        auto tmp = m_etop;
        T ret = tmp->data;
        m_etop = m_etop->next;
        delete tmp;
        return ret;
    }

    T top() {
        return m_etop->data;
    }
};

MinStack<int>* g_testintstack = nullptr;

int test(const string& op, const vector<int>& args) {
    int ret = -1024;
    if (op == "MinStack") {
        g_testintstack = new MinStack<int>();
    } else if (op == "push") {
        g_testintstack->push(args[0]);
    } else if (op == "pop") {
        ret = g_testintstack->pop();
    } else if (op == "top") {
        ret = g_testintstack->top();
    }
    return ret;
}

int main() {
    vector<string> oplist;
    vector<vector<int>> argslist;
    vector<int> ret;

    oplist = {"MinStack", "push", "push", "push", "pop", "top"};
    argslist = {{}, {-2}, {0}, {-3}, {}, {}, {}, {}};
    ret = {};
    for (size_t i = 0; i < oplist.size(); ++i) {
        const string& op = oplist[i];
        const vector<int>& arg = argslist[i];
        ret.push_back(test(op, arg));
    }
    print(ret);

    if (g_testintstack != nullptr) {
        delete g_testintstack;
        g_testintstack = nullptr;
    }
    return 0;
}
