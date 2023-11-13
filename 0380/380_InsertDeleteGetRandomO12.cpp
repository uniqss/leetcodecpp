#include "../inc.h"

/*
这个是正解，真正的O(1)。
思路：
    数组能o1随机访问，hash能o1随机访问o1随机删除
    如果我们删除的元素恰好是数组的最后一个，那么就很容易，数组缩一，hash删key
    如果我们删除的元素不是数组的最后一个，就把删除的元素，换到最后一个，再执行上述操作
*/
class RandomizedSet {
    vector<int> vi;
    unordered_map<int, int> v2idx;

   public:
    RandomizedSet() {}

    bool insert(int val) {
        bool ret = v2idx.count(val) == 0;
        if (ret) {
            vi.emplace_back(val);
            v2idx[val] = (int)vi.size() - 1;
        }
        return ret;
    }

    bool remove(int val) {
        bool ret = v2idx.count(val) != 0;
        if (ret) {
            int lastidx = vi.size() - 1;
            int curridx = v2idx[val];
            if (curridx != lastidx) {
                swap(v2idx[vi[lastidx]], v2idx[vi[curridx]]);
                swap(vi[lastidx], vi[curridx]);
            }
            vi.resize(lastidx);
            v2idx.erase(val);
        }
        return ret;
    }

    int getRandom() {
        int rd = rand() % vi.size();
        return vi[rd];
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
