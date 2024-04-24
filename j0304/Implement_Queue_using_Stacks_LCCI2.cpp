#include "../inc.h"

class MyQueue {
    stack<int> m_stki;
    stack<int> m_stko;

   public:
    MyQueue() {}
    void push(int x) { m_stki.push(x); }
    int pop() {
        if (m_stko.empty()) {
            while (m_stki.size() > 0) {
                m_stko.push(m_stki.top());
                m_stki.pop();
            }
        }
        if (m_stko.empty()) return -1;
        auto ret = m_stko.top();
        m_stko.pop();
        return ret;
    }

    int peek() {
        if (m_stko.empty()) {
            while (m_stki.size() > 0) {
                m_stko.push(m_stki.top());
                m_stki.pop();
            }
        }
        if (m_stko.empty()) return -1;
        return m_stko.top();
    }

    bool empty() { return m_stki.empty() && m_stko.empty(); }
};

void test(const vector<string>& ops, const vector<vector<int>>& params,
          const vector<ComplexVal>& expect) {
    save4print(ops, params);
    MyQueue* q = nullptr;
    vector<ComplexVal> ret;
    for (size_t i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];
        const auto& param = params[i];
        if (op == "MyQueue") {
            q = new MyQueue();
            ret.emplace_back(null);
        } else if (op == "push") {
            q->push(param[0]);
            ret.emplace_back(null);
        } else if (op == "peek") {
            auto cret = q->peek();
            ret.emplace_back(cret);
        } else if (op == "pop") {
            auto cret = q->pop();
            ret.emplace_back(cret);
        } else if (op == "empty") {
            auto cret = q->empty();
            ret.emplace_back(cret);
        }
    }
    assert_eq_ret(expect, ret);
    delete q;
}

int main() {
    test({"MyQueue", "push", "push", "peek", "pop", "empty"}, {{}, {1}, {2}, {}, {}, {}},
         {null, null, null, 1, 1, false});
    return 0;
}
