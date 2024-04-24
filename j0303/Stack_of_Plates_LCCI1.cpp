#include "../inc.h"

class StackOfPlates {
    struct StackNode {
        int val;
        StackNode* next;
        StackNode(int _val, StackNode* _next) : val(_val), next(_next) {}
    };
    int m_cap;
    vector<pair<StackNode*, int>> m_stacks;

   public:
    StackOfPlates(int cap) : m_cap(cap) {}

    void push(int val) {
        if (m_cap <= 0) return;
        if (m_stacks.empty() || m_stacks[m_stacks.size() - 1].second >= m_cap) {
            StackNode* node = new StackNode(val, nullptr);
            m_stacks.push_back({node, 1});
        } else {
            auto& it = m_stacks[m_stacks.size() - 1];
            ++it.second;
            it.first = new StackNode(val, it.first);
        }
    }

    int pop() {
        if (m_stacks.empty()) return -1;
        for (int i = (int)m_stacks.size() - 1; i >= 0; --i) {
            auto& it = m_stacks[i];
            if (it.second == 0) {
                m_stacks.pop_back();
                continue;
            } else {
                auto ret = it.first->val;
                auto node = it.first;
                it.first = it.first->next;
                if (--it.second == 0) {
                    m_stacks.pop_back();
                }
                delete node;
                return ret;
            }
        }
        return -1;
    }

    int popAt(int index) {
        if (m_stacks.empty()) return -1;
        if (index >= m_stacks.size()) return -1;
        auto& it = m_stacks[index];
        auto ret = it.first->val;
        auto node = it.first;
        it.first = it.first->next;
        delete node;
        if (--it.second == 0) {
            m_stacks.erase(m_stacks.begin() + index);
        }
        return ret;
    }
};

void test(const vector<string>& ops, const vector<vector<int>>& params,
          const vector<ComplexVal>& expect) {
    save4print(ops, params);
    StackOfPlates* pstack = nullptr;
    vector<ComplexVal> ret;
    for (size_t i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];
        const auto& param = params[i];
        if (op == "StackOfPlates") {
            pstack = new StackOfPlates(param[0]);
            ret.emplace_back(null);
        } else if (op == "push") {
            pstack->push(param[0]);
            ret.emplace_back(null);
        } else if (op == "popAt") {
            auto cret = pstack->popAt(param[0]);
            ret.emplace_back(cret);
        } else if (op == "pop") {
            auto cret = pstack->pop();
            ret.emplace_back(cret);
        }
    }

    assert_eq_ret(expect, ret);
    delete pstack;
}

int main() {
    test({"StackOfPlates", "push", "push", "push", "push", "push", "push", "push", "push", "push",
          "push",          "push", "push", "push", "push", "push", "push", "push", "push", "push",
          "push",          "push", "push", "push", "push", "push", "push", "push", "push", "push",
          "push",          "push", "push", "pop",  "pop",  "pop",  "pop",  "pop",  "pop",  "pop",
          "pop",           "pop",  "pop",  "pop",  "pop",  "pop",  "pop",  "pop",  "pop",  "pop",
          "pop",           "pop",  "pop",  "pop",  "pop",  "pop",  "pop",  "pop",  "pop",  "pop",
          "pop",           "pop",  "pop",  "pop",  "pop"},
         {{0},  {2},  {8},  {56}, {1},  {39}, {40}, {44}, {63}, {11}, {38}, {20}, {55},
          {25}, {14}, {11}, {1},  {20}, {16}, {6},  {18}, {3},  {39}, {45}, {2},  {22},
          {64}, {6},  {30}, {39}, {3},  {19}, {63}, {},   {},   {},   {},   {},   {},
          {},   {},   {},   {},   {},   {},   {},   {},   {},   {},   {},   {},   {},
          {},   {},   {},   {},   {},   {},   {},   {},   {},   {},   {},   {},   {}},
         {null, null, null, null, null, null, null, null, null, null, null, null, null,
          null, null, null, null, null, null, null, null, null, null, null, null, null,
          null, null, null, null, null, null, null, -1,   -1,   -1,   -1,   -1,   -1,
          -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
          -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1});
    test({"StackOfPlates", "pop",   "pop",   "popAt", "popAt", "pop",   "push",  "push",  "push",
          "push",          "pop",   "push",  "push",  "popAt", "pop",   "popAt", "push",  "popAt",
          "pop",           "push",  "pop",   "pop",   "pop",   "popAt", "push",  "pop",   "popAt",
          "pop",           "push",  "popAt", "popAt", "push",  "popAt", "popAt", "push",  "pop",
          "popAt",         "popAt", "popAt", "pop",   "popAt", "popAt", "push",  "popAt", "push",
          "push",          "pop",   "popAt", "popAt", "push",  "popAt", "push",  "pop",   "pop",
          "push",          "push",  "push",  "popAt", "popAt", "pop",   "popAt", "pop",   "pop",
          "push",          "push"},
         {{6}, {},  {},   {1},  {3},  {},   {40}, {10}, {44}, {44}, {},   {24}, {42},
          {4}, {},  {0},  {42}, {5},  {},   {29}, {},   {},   {},   {0},  {56}, {},
          {4}, {},  {34}, {1},  {4},  {52}, {4},  {6},  {63}, {},   {6},  {6},  {1},
          {},  {6}, {2},  {47}, {1},  {45}, {52}, {},   {6},  {6},  {20}, {4},  {17},
          {},  {},  {43}, {6},  {30}, {2},  {3},  {},   {3},  {},   {},   {51}, {46}},
         {null, -1, -1,   -1,   -1,   -1,   null, null, null, null, 44,   null, null,
          -1,   42, 24,   null, -1,   42,   null, 29,   44,   10,   40,   null, 56,
          -1,   -1, null, -1,   -1,   null, -1,   -1,   null, 63,   -1,   -1,   -1,
          52,   -1, -1,   null, -1,   null, null, 52,   -1,   -1,   null, -1,   null,
          17,   20, null, null, null, -1,   -1,   30,   -1,   6,    43,   null, null});
    test({"StackOfPlates", "push", "push", "push", "popAt", "popAt", "popAt"},
         {{2}, {1}, {2}, {3}, {0}, {0}, {0}}, {null, null, null, null, 2, 1, 3});
    test({"StackOfPlates", "push", "push", "popAt", "pop", "pop"}, {{1}, {1}, {2}, {1}, {}, {}},
         {null, null, null, 2, 1, -1});
    return 0;
}
