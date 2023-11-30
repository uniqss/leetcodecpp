#include "../inc.h"

void test(const vector<int>& vi) {
    auto _pdist = [&](auto it) {
        int dist = std::distance(vi.begin(), it);
        __print(dist, " -> ");
        if (it != vi.end()) {
            print(*it);
        } else {
            print(-1);
        }
    };
    auto pname = [](const string& name) {
        auto pos = name.find('3');
        if (pos == string::npos)
            __print(name, ": ");
        else {
            __print(name.substr(0, pos), "\t");
            __print(name.substr(pos, name.size()), ": ");
        }
    };
#define pdist(v) pname(#v), _pdist(v);

    print("vi:", vi);

    {
        auto ubl35 = upper_bound(vi.begin(), vi.end(), 35, less<int>());
        pdist(ubl35);
        auto ubl30 = upper_bound(vi.begin(), vi.end(), 30, less<int>());
        pdist(ubl30);
    }
    {
        auto uble35 = upper_bound(vi.begin(), vi.end(), 35, less_equal<int>());
        pdist(uble35);
        auto uble30 = upper_bound(vi.begin(), vi.end(), 30, less_equal<int>());
        pdist(uble30);
    }
    {
        auto ubg35 = upper_bound(vi.begin(), vi.end(), 35, greater<int>());
        pdist(ubg35);
        auto ubg30 = upper_bound(vi.begin(), vi.end(), 30, greater<int>());
        pdist(ubg30);
    }
    {
        auto ubge35 = upper_bound(vi.begin(), vi.end(), 35, greater_equal<int>());
        pdist(ubge35);
        auto ubge30 = upper_bound(vi.begin(), vi.end(), 30, greater_equal<int>());
        pdist(ubge30);
    }

    {
        auto lbl35 = lower_bound(vi.begin(), vi.end(), 35, less<int>());
        pdist(lbl35);
        auto lbl30 = lower_bound(vi.begin(), vi.end(), 30, less<int>());
        pdist(lbl30);
    }
    {
        auto lble35 = lower_bound(vi.begin(), vi.end(), 35, less_equal<int>());
        pdist(lble35);
        auto lble30 = lower_bound(vi.begin(), vi.end(), 30, less_equal<int>());
        pdist(lble30);
    }
    {
        auto lbg35 = lower_bound(vi.begin(), vi.end(), 35, greater<int>());
        pdist(lbg35);
        auto lbg30 = lower_bound(vi.begin(), vi.end(), 30, greater<int>());
        pdist(lbg30);
    }
    {
        auto lbge35 = lower_bound(vi.begin(), vi.end(), 35, greater_equal<int>());
        pdist(lbge35);
        auto lbge30 = lower_bound(vi.begin(), vi.end(), 30, greater_equal<int>());
        pdist(lbge30);
    }
    print();
}

int main() {
    test({10, 20, 30, 40, 50, 60});
    test({10, 20, 30, 30, 40, 50, 60});
    test({10, 20, 30, 30, 40, 40, 50, 60});

    // 这个结果做成表格，让人裸填的话，翻车率会超出想像

    // !!! 以后尽量不用 lower_bound/upper_bound两个接口  需要时，自己手写
    // !!! 并在项目中建议不要使用，不要拉高代码的理解和维护成本
    // !!! 所有使用了这俩API的函数，必须做完整数据测试

    return 0;
}
