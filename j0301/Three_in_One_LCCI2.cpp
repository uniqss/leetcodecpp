#include "../inc.h"

class TripleInOne {
    vector<int> m_data;
    int m_stacksize;
    std::array<int, 3> m_stacknums;

   public:
    TripleInOne(int stackSize) : m_stacksize(stackSize) {
        m_data.resize(stackSize * 3);
        m_stacknums.fill(0);
    }

    void push(int stackNum, int value) {
        if (m_stacksize <= 0) return;
        if (stackNum > m_stacksize) return;
        if (m_stacknums[stackNum] >= m_stacksize) return;
        m_data[stackNum * m_stacksize + m_stacknums[stackNum]] = value;
        ++m_stacknums[stackNum];
    }

    int pop(int stackNum) {
        if (m_stacknums[stackNum] <= 0) return -1;

        int ret = m_data[stackNum * m_stacksize + m_stacknums[stackNum] - 1];
        --m_stacknums[stackNum];
        return ret;
    }

    int peek(int stackNum) {
        return m_stacknums[stackNum] > 0
                   ? m_data[stackNum * m_stacksize + m_stacknums[stackNum] - 1]
                   : -1;
    }

    bool isEmpty(int stackNum) { return m_stacknums[stackNum] == 0; }
};

void test(const vector<string>& ops, const vector<vector<int>>& params,
          const vector<ComplexVal>& expect) {
    save4print(ops, params);
    vector<ComplexVal> ret;
    TripleInOne* so = nullptr;
    for (size_t i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];
        const auto& param = params[i];
        if (op == "TripleInOne") {
            so = new TripleInOne(param[0]);
            ret.push_back(null);
        } else if (op == "push") {
            so->push(param[0], param[1]);
            ret.push_back(null);
        } else if (op == "pop") {
            auto currret = so->pop(param[0]);
            ret.push_back(currret);
        } else if (op == "peek") {
            auto currret = so->peek(param[0]);
            ret.push_back(currret);
        } else if (op == "isEmpty") {
            auto curret = so->isEmpty(param[0]);
            ret.push_back(curret);
        }
    }
    assert_eq_ret(expect, ret);
    delete so;
}

int main() {
    test({"TripleInOne", "peek",    "pop",     "isEmpty", "push",    "pop",     "push", "push",
          "pop",         "push",    "push",    "isEmpty", "pop",     "peek",    "push", "peek",
          "isEmpty",     "peek",    "pop",     "push",    "isEmpty", "pop",     "peek", "peek",
          "pop",         "peek",    "isEmpty", "pop",     "push",    "isEmpty", "peek", "push",
          "peek",        "isEmpty", "isEmpty", "isEmpty", "isEmpty", "peek",    "push", "push",
          "peek",        "isEmpty", "peek",    "isEmpty", "push",    "push",    "push", "peek",
          "peek",        "pop",     "push",    "push",    "isEmpty", "peek",    "pop",  "push",
          "peek",        "peek",    "pop",     "isEmpty", "pop",     "peek",    "peek", "push",
          "push"},
         {{18},    {1},     {2}, {1},    {2, 40}, {2},     {0, 44}, {1, 40}, {0},     {1, 54},
          {0, 42}, {0},     {1}, {1},    {0, 56}, {2},     {0},     {2},     {2},     {1, 15},
          {1},     {1},     {0}, {2},    {0},     {0},     {1},     {0},     {0, 32}, {0},
          {0},     {0, 30}, {2}, {1},    {1},     {0},     {0},     {0},     {0, 56}, {1, 40},
          {2},     {0},     {0}, {0},    {2, 11}, {0, 16}, {0, 3},  {2},     {0},     {2},
          {0, 39}, {0, 63}, {1}, {2},    {0},     {2, 36}, {1},     {0},     {2},     {1},
          {0},     {1},     {2}, {0, 8}, {0, 38}},
         {null,  -1,   -1,    true,  null,  40,   null, null,  44,    null,  null,  false, 54,
          40,    null, -1,    false, -1,    -1,   null, false, 15,    56,    -1,    56,    42,
          false, 42,   null,  false, 32,    null, -1,   false, false, false, false, 30,    null,
          null,  -1,   false, 56,    false, null, null, null,  11,    3,     11,    null,  null,
          false, -1,   63,    null,  40,    39,   36,   false, 39,    40,    -1,    null,  null});
    test({"TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"},
         {{1}, {0, 1}, {0, 2}, {0}, {0}, {0}, {0}}, {null, null, null, 1, -1, -1, true});
    return 0;
}
