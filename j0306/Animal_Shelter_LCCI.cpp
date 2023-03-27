#include "../inc.h"

class AnimalShelf {
   public:
    AnimalShelf() {}

    void enqueue(vector<int> animal) {}

    vector<int> dequeueAny() {}

    vector<int> dequeueDog() {}

    vector<int> dequeueCat() {}
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
    delete q;
}

int main() {
    test({"AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog", "dequeueAny"},
         {{}, {{0, 0}}, {{1, 0}}, {}, {}, {}}, {null, null, null, {0, 0}, {-1, -1}, {1, 0}});
    test({"AnimalShelf", "enqueue", "enqueue", "enqueue", "dequeueDog", "dequeueCat", "dequeueAny"},
         {{}, {{0, 0}}, {{1, 0}}, {{2, 1}}, {}, {}, {}}, {null, null, null, null, {2, 1}, {0, 0}, {1, 0}});
    return 0;
}
