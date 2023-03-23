#include "../inc.h"

class MinStack {
    struct StackNode {
        int val;
        int min;
        StackNode* next;
        StackNode(int _val, StackNode* _next) : val(_val), next(_next) {
            if (next != nullptr) {
                min = std::min(next->min, val);
            } else {
                min = val;
            }
        }
    };
    StackNode* m_top;

   public:
    /** initialize your data structure here. */
    MinStack() { m_top = nullptr; }

    void push(int x) {
        StackNode* curr = new StackNode(x, m_top);
        m_top = curr;
    }

    void pop() {
        if (m_top != nullptr) {
            StackNode* top = m_top;
            m_top = m_top->next;
            delete top;
        } else {
            // throw
        }
    }

    int top() {
        if (m_top != nullptr) {
            return m_top->val;
        } else {
            // throw
            return -1;
        }
    }

    int getMin() {
        if (m_top != nullptr) {
            return m_top->min;
        } else {
            // throw
            return -1;
        }
    }
};

void test(const vector<string>& ops, const vector<vector<int>>& params, const vector<ComplexVal>& expect) {
    MinStack* pstack = nullptr;
    vector<ComplexVal> ret;
    for (size_t i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];
        const auto& param = params[i];
        if (op == "MinStack") {
            pstack = new MinStack();
            ret.emplace_back(null);
        } else if (op == "push") {
            pstack->push(param[0]);
            ret.emplace_back(null);
        } else if (op == "pop") {
            pstack->pop();
            ret.emplace_back(null);
        } else if (op == "top") {
            auto val = pstack->top();
            ret.emplace_back(val);
        } else if (op == "getMin") {
            auto val = pstack->getMin();
            ret.emplace_back(val);
        }
    }
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(ops);
        print(params);
        print(expect);
        print(ret);
        print();
    }
    delete pstack;
}

int main() {
    test({"MinStack", "push", "push", "top", "getMin", "pop", "getMin", "top"}, {{}, {1}, {2}, {}, {}, {}, {}, {}},
         {null, null, null, 2, 1, null, 1, 1});
    test({"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"}, {{}, {-2}, {0}, {-3}, {}, {}, {}, {}},
         {null, null, null, null, -3, null, 0, -2});
    return 0;
}
