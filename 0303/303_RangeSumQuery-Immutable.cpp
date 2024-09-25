#include "../inc.h"

class NumArray {
   public:
    NumArray(vector<int>& nums) {}

    int sumRange(int left, int right) {}
};

void test(const vector<string>&& ops, vector<vector<int>>&& params,
          const vector<ComplexVal>& expect) {
    shared_ptr<NumArray> na = nullptr;
    vector<ComplexVal> ret;
    for (int i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];
        auto& param = params[i];
        if (op == "NumArray") {
            na = make_shared<NumArray>(param);
            ret.emplace_back(null);
        } else if (op == "sumRange") {
            auto reti = na->sumRange(param[0], param[1]);
            ret.emplace_back(reti);
        } else {
            print("unknown param:", param);
        }
    }
    assert_eq_ret(expect, ret);
}

int main() {
    test({"NumArray", "sumRange", "sumRange", "sumRange"},
         {{{-2, 0, 3, -5, 2, -1}}, {0, 2}, {2, 5}, {0, 5}}, {null, 1, -1, -3});
    return 0;
}
