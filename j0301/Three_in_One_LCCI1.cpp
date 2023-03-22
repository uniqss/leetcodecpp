#include "../inc.h"

class TripleInOne {
    vector<int> m_vals;
    vector<int> m_counts;
    int m_stackSize;

   public:
    TripleInOne(int stackSize) : m_stackSize(stackSize) {
        m_vals.resize(stackSize * 3);
        m_counts.resize(3, 0);
    }

    void push(int stackNum, int value) {
        if (m_counts[stackNum] >= m_stackSize) {
            // throw
            return;
        }
        m_vals[stackNum * m_stackSize + m_counts[stackNum]] = value;
        ++m_counts[stackNum];
    }

    int pop(int stackNum) {
        if (m_counts[stackNum] == 0) {
            // throw
            return -1;
        }
        --m_counts[stackNum];
        return m_vals[stackNum * m_stackSize + m_counts[stackNum]];
    }

    int peek(int stackNum) {
        if (m_counts[stackNum] == 0) {
            // throw
            return -1;
        }
        return m_vals[stackNum * m_stackSize + m_counts[stackNum] - 1];
    }

    bool isEmpty(int stackNum) { return m_counts[stackNum] == 0; }
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
    return 0;
}
