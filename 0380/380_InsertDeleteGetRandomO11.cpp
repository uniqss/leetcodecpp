#include "../inc.h"

/*
这等于水过去了，其实getRandom的平均是O(n/2),它要挨个访问平均剩余元素的一半
*/
class RandomizedSet {
    unordered_set<int> datas;

   public:
    RandomizedSet() {}

    bool insert(int val) {
        bool ret = datas.count(val) == 0;
        datas.insert(val);
        return ret;
    }

    bool remove(int val) {
        bool ret = datas.count(val) != 0;
        datas.erase(val);
        return ret;
    }

    int getRandom() {
        int rd = rand() % (int)datas.size();
        auto it = datas.begin();
        while (--rd>=0) it = ++it;
        return *it;
    }
};

void test(const vector<string>& ops, const vector<vector<int>>& params, const vector<ComplexVal>& expect) {
    RandomizedSet s;
    unordered_set<int> check;
    vector<ComplexVal> ret;
    vector<ComplexVal> checkexpect;
    for (int i = 0; i < (int)ops.size(); ++i) {
        const string& op = ops[i];
        const auto& param = params[i];
        if (op == "RandomizedSet") {
            ret.emplace_back(null);
            checkexpect.emplace_back(null);
        } else if (op == "insert") {
            auto curr = s.insert(param[0]);
            ret.emplace_back(curr);
            checkexpect.push_back((bool)(check.count(param[0]) == 0));
            check.insert(param[0]);
        } else if (op == "remove") {
            auto curr = s.remove(param[0]);
            ret.emplace_back(curr);
            checkexpect.push_back((bool)(check.count(param[0]) != 0));
            check.erase(param[0]);
        } else if (op == "getRandom") {
            auto curr = s.getRandom();
            ret.emplace_back(curr);
            int currcheck = curr;
            if (check.count(curr) == 0) {
                currcheck = *check.begin();
            }
            checkexpect.emplace_back(currcheck);
        }
    }
    assert_eq_ret(checkexpect, ret);
    print(ops);
    print(params);
}

int main() {
    test({"RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"},
         {{}, {1}, {2}, {2}, {}, {1}, {2}, {}}, {null, true, false, true, 2, true, false, 2});
    return 0;
}
