#include "../stl.h"

/*
用这种方式居然也能搞出全数排列，这个算法也能模拟自然数的循环增加的过程
*/

vector<int> vis;
void backtrace(const vector<int>& nums, int start, int len, vector<int>& perm) {
    if (start == len) {
        pvraw(perm, true);
        return;
    }

    for (int i = 0; i < len; ++i) {
        // if (vis[i]) continue;
        perm.emplace_back(nums[i]);
        vis[i] = 1;
        backtrace(nums, start + 1, len, perm);
        vis[i] = 0;
        perm.pop_back();
    }
}

int main() {
    vector<int> vi(4);
    vis.resize(vi.size(), 0);
    // 这位n同学很神奇，类型是反推出来的，根据返回值，相当于
    /*
    auto func(){
        return (int)123;
    }
    */
    std::generate(vi.begin(), vi.end(), [n_student = 2]() mutable { return ++n_student; });
    vector<int> perm;
    backtrace(vi, 0, vi.size(), perm);

    return 0;
}
