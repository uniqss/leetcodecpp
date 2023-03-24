#include "../inc.h"

class AnimalShelf {
    struct MyQueue {
        int val;
        int type;
        int seq;
        MyQueue* next;
        MyQueue(int _val, int _type, MyQueue* _next = nullptr) : val(_val), type(_type), next(_next) {
            static int m_nextseq = 0;
            seq = ++m_nextseq;
        }
    };
    MyQueue* m_head;
    MyQueue* m_tail;

   public:
    AnimalShelf() : m_head(nullptr), m_tail(nullptr) {}

    void enqueue(vector<int> animal) {
        MyQueue* curr = new MyQueue(animal[0], animal[1]);
        if (m_tail == nullptr) {
            m_head = curr;
            m_tail = curr;
        } else {
            m_tail->next = curr;
            m_tail = curr;
        }
    }

    vector<int> dequeueAny() {
        vector<int> ret;

        return ret;
    }

    vector<int> dequeueDog() {
        vector<int> ret;
        return ret;
    }

    vector<int> dequeueCat() {
        vector<int> ret;
        return ret;
    }
};

void test(const vector<string>& ops, const vector<vector<int>>& params, const vector<ComplexVal>& expect) {
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
    delete q;
}

int main() {
    test({"AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog", "dequeueAny"},
         {{}, {{0, 0}}, {{1, 0}}, {}, {}, {}}, {null, null, null, {0, 0}, {-1, -1}, {1, 0}});
    test({"AnimalShelf", "enqueue", "enqueue", "enqueue", "dequeueDog", "dequeueCat", "dequeueAny"},
         {{}, {{0, 0}}, {{1, 0}}, {{2, 1}}, {}, {}, {}}, {null, null, null, null, {2, 1}, {0, 0}, {1, 0}});
    return 0;
}
