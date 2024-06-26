#include "../inc.h"

class SortedStack {
    struct MStackNode {
        int val;
        MStackNode* next;
        MStackNode(int _val, MStackNode* _next = nullptr) : val(_val), next(_next) {}
    };
    MStackNode* m_stk;

   public:
    SortedStack() : m_stk(nullptr) {}

    void push(int val) {
        MStackNode fake(0, m_stk);
        MStackNode* prev = &fake;
        while (prev->next != nullptr && prev->next->val < val) {
            prev = prev->next;
        }

        MStackNode* curr = new MStackNode(val, prev->next);
        prev->next = curr;

        m_stk = fake.next;
    }

    void pop() {
        if (m_stk != nullptr) {
            auto head = m_stk;
            m_stk = m_stk->next;
            delete head;
        }
    }

    int peek() { return m_stk != nullptr ? m_stk->val : -1; }

    bool isEmpty() { return m_stk == nullptr; }
};

void test(const vector<string>& ops, const vector<vector<int>>& params,
          const vector<ComplexVal>& expect) {
    save4print(ops, params);
    SortedStack* stk;
    vector<ComplexVal> ret;
    for (size_t i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];
        const auto& param = params[i];
        if (op == "SortedStack") {
            stk = new SortedStack();
            ret.emplace_back(null);
        } else if (op == "push") {
            stk->push(param[0]);
            ret.emplace_back(null);
        } else if (op == "peek") {
            auto curr = stk->peek();
            ret.emplace_back(curr);
        } else if (op == "pop") {
            stk->pop();
            ret.emplace_back(null);
        } else if (op == "isEmpty") {
            auto curr = stk->isEmpty();
            ret.emplace_back(curr);
        }
    }
    assert_eq_ret(expect, ret);
}

int main() {
    test({"SortedStack", "pop", "pop", "push", "pop", "isEmpty"}, {{}, {}, {}, {1}, {}, {}},
         {null, null, null, null, null, true});
    test({"SortedStack", "push", "push", "peek", "pop", "peek"}, {{}, {1}, {2}, {}, {}, {}},
         {null, null, null, 1, null, 2});
    return 0;
}
