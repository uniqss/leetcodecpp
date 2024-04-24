#include "../inc.h"

class ParkingSystem {
    array<int, 3> m_capacity;
    array<int, 3> m_curr;

   public:
    ParkingSystem(int big, int medium, int small) {
        m_capacity.fill(0);
        m_curr.fill(0);
        m_capacity[0] = big;
        m_capacity[1] = medium;
        m_capacity[2] = small;
    }

    bool addCar(int carType) {
        bool ret = m_curr[carType - 1] < m_capacity[carType - 1];
        if (ret) ++m_curr[carType - 1];
        return ret;
    }
};

void test(const vector<std::string>& ops, const vector<vector<int>>&& params, const vector<ComplexVal>& expects) {
    save4print(ops, params);
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
    assert_eq_ret(expects, ret);
}

int main() {
    test({"ParkingSystem", "addCar", "addCar", "addCar", "addCar"}, {{1, 1, 0}, {1}, {2}, {3}, {1}},
         {null, true, true, false, false});
    return 0;
}