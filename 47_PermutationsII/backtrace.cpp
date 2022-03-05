#include "../stl.h"

vector<int> vis;
void backtrace(vector<int>& nums, int start, int len, vector<int>& perm) {
    if (start == len) {
        pvraw(perm, true);
        return;
    }

    for (int i = 0; i < len; ++i) {
        if (vis[i]) {
            continue;
        }
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
    std::generate(vi.begin(), vi.end(), [n = 2]() mutable { return ++n; });
    vector<int> perm;
    backtrace(vi, 0, vi.size(), perm);

    return 0;
}
