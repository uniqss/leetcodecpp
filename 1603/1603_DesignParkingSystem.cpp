#include "../inc.h"

class ParkingSystem {
   public:
    ParkingSystem(int big, int medium, int small) {}
};

void test(const vector<std::string>& ops, const vector<vector<int>>&& params, const vector<ComplexVal>& expects) {
    if (ops.size() != params.size()) {
        print("param error");
        return;
    }
    std::unique_ptr<ParkingSystem> ps = nullptr;
    vector<ComplexVal> ret;
    for (size_t i = 0; i < ops.size(); i++) {
        const auto& op = ops[i];
        const auto& param = params[i];
        if (op == "ParkingSystem") {
            ps = std::make_unique<ParkingSystem>(param[0], param[1], param[2]);
            ret.emplace_back(nullptr);
        } else if (op == "addCar") {
            auto curr_ret = ps->addCar(param[0]);
            ret.emplace_back(curr_ret);
        }
    }
    if (expects == ret) {
        print("ok");
    } else {
        print("not ok.");
        print(ops);
        print(params);
        print(expects);
        print(ret);
    }
}

int main() {
    test({"ParkingSystem", "addCar", "addCar", "addCar", "addCar"}, {{1, 1, 0}, {1}, {2}, {3}, {1}},
         {null, true, true, false, false});
    return 0;
}