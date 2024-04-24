#include "../inc.h"

class MyQueue {
    struct MyStk {
        int val;
        MyStk* next;
        MyStk(int _val, MyStk* _next = nullptr) : val(_val), next(_next) {}
    };
    MyStk* m_stki;
    MyStk* m_stko;

   private:
    void fill() {
        if (m_stko != nullptr) return;
        if (m_stki == nullptr) return;
        while (m_stki != nullptr) {
            MyStk* next = m_stki->next;
            m_stki->next = m_stko;
            m_stko = m_stki;
            m_stki = next;
        }
        m_stki = nullptr;
    }

   public:
    MyQueue() : m_stki(nullptr), m_stko(nullptr) {}
    void push(int x) { m_stki = new MyStk(x, m_stki); }
    int pop() {
        fill();
        if (m_stko == nullptr) return -1;
        auto ret = m_stko->val;
        auto head = m_stko;
        m_stko = m_stko->next;
        delete head;
        return ret;
    }

    int peek() {
        fill();
        return m_stko != nullptr ? m_stko->val : -1;
    }

    bool empty() { return m_stko == nullptr && m_stki == nullptr; }
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
