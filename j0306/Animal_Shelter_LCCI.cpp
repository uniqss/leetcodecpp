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
    
}

int main() {
    test({"AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog", "dequeueAny"},
         {{}, {{0, 0}}, {{1, 0}}, {}, {}, {}}, {null, null, null, {0, 0}, {-1, -1}, {1, 0}});
    test({"AnimalShelf", "enqueue", "enqueue", "enqueue", "dequeueDog", "dequeueCat", "dequeueAny"},
         {{}, {{0, 0}}, {{1, 0}}, {{2, 1}}, {}, {}, {}}, {null, null, null, null, {2, 1}, {0, 0}, {1, 0}});
    return 0;
}
