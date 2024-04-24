#include "../inc.h"

class AnimalShelf {
    queue<pair<int, int>> m_qcat;
    queue<pair<int, int>> m_qdog;
    int m_next;

   public:
    AnimalShelf() : m_next(0) {}

    void enqueue(vector<int> animal) {
        if (animal[1] == 0) {
            m_qcat.push({animal[0], ++m_next});
        } else {
            m_qdog.push({animal[0], ++m_next});
        }
    }

    vector<int> dequeueAny() {
        if (m_qcat.empty()) return dequeueDog();
        if (m_qdog.empty()) return dequeueCat();
        return m_qcat.front().second < m_qdog.front().second ? dequeueCat() : dequeueDog();
    }

    vector<int> dequeueDog() {
        if (m_qdog.empty()) return {-1, -1};
        vector<int> ret = {m_qdog.front().first, 1};
        m_qdog.pop();
        if (m_qdog.empty() && m_qcat.empty()) m_next = 0;
        return ret;
    }

    vector<int> dequeueCat() {
        if (m_qcat.empty()) return {-1, -1};
        vector<int> ret = {m_qcat.front().first, 0};
        m_qcat.pop();
        if (m_qdog.empty() && m_qcat.empty()) m_next = 0;
        return ret;
    }
};

void test(const vector<string>& ops, const vector<vector<int>>& params,
          const vector<ComplexVal>& expect) {
    save4print(ops, params);
    AnimalShelf* q = nullptr;
    vector<ComplexVal> ret;
    for (size_t i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];
        auto param = params[i];
        if (op == "AnimalShelf") {
            q = new AnimalShelf();
            ret.emplace_back(null);
        } else if (op == "enqueue") {
            q->enqueue(param);
            ret.emplace_back(null);
        } else if (op == "dequeueAny") {
            auto curr = q->dequeueAny();
            ret.emplace_back(curr);
        } else if (op == "dequeueDog") {
            auto curr = q->dequeueDog();
            ret.emplace_back(curr);
        } else if (op == "dequeueCat") {
            auto curr = q->dequeueCat();
            ret.emplace_back(curr);
        }
    }
    assert_eq_ret(expect, ret);
    delete q;
}

int main() {
    test({"AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog", "dequeueAny"},
         {{}, {{0, 0}}, {{1, 0}}, {}, {}, {}}, {null, null, null, {0, 0}, {-1, -1}, {1, 0}});
    test({"AnimalShelf", "enqueue", "enqueue", "enqueue", "dequeueDog", "dequeueCat", "dequeueAny"},
         {{}, {{0, 0}}, {{1, 0}}, {{2, 1}}, {}, {}, {}},
         {null, null, null, null, {2, 1}, {0, 0}, {1, 0}});
    return 0;
}
