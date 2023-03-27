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
        return m_stacknums[stackNum] > 0 ? m_data[stackNum * m_stacksize + m_stacknums[stackNum] - 1] : -1;
    }

    bool isEmpty(int stackNum) { return m_stacknums[stackNum] == 0; }
};

void test(const vector<string>& ops, const vector<vector<int>>& params, const vector<ComplexVal>& expect) {
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

    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(params);
        print(params);
        print(expect);
        print(ret);
        print();
    }

    delete so;
}

int main() {
    test({"TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"}, {{1}, {0, 1}, {0, 2}, {0}, {0}, {0}, {0}},
         {null, null, null, 1, -1, -1, true});
    test({"TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"}, {{1}, {0, 1}, {0, 2}, {0}, {0}, {0}, {0}},
         {null, null, null, 1, -1, -1, true});
    return 0;
}
