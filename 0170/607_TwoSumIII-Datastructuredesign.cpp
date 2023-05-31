#include "../inc.h"

class TwoSum {
   public:
    void add(int number) {}

    bool find(int value) {}
};

void test(vector<string>&& ops, const vector<int>& params, const vector<ComplexVal>& expects) {
    TwoSum ts;
    vector<ComplexVal> rets;
    for (size_t i = 0; i < ops.size(); i++) {
        const auto& op = ops[i];
        auto param = params[i];
        if (op == "add") {
            ts.add(param);
            // rets.push_back(null);
        } else if (op == "find") {
            auto ret = ts.find(param);
            rets.push_back(ret);
        }
    }
    if (rets == expects) {
        print("ok");
    } else {
        print("not ok");
        print(ops);
        print(params);
        print(expects);
        print(rets);
    }
}

int main() {
    test({"add", "add", "add", "find", "find"}, {1, 3, 5, 4, 7}, {true, false});
    test({"add", "add", "find", "find", "find", "add", "find"}, {2, 3, 4, 5, 6, 3, 6}, {false, true, false, true});
    return 0;
}
