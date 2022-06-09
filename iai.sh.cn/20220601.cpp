#include <vector>
#include <limits.h>
#include <iostream>
using namespace std;

int getLeastCountMoney(int n) {
    vector<int> f(n + 1);
    int i, cost;
    f[0] = 0;
    for (i = 1; i <= n; i++) {
        cost = INT_MAX;
        if (i - 1 >= 0) cost = min(cost, f[i - 1] + 1);
        if (i - 5 >= 0) cost = min(cost, f[i - 5] + 1);
        if (i - 10 >= 0) cost = min(cost, f[i - 10] + 1);
        if (i - 20 >= 0) cost = min(cost, f[i - 20] + 1);
        f[i] = cost;
    }
    return f[n];
}

int main() {
    int n;
    cin.tie(0);
    cin >> n;

    auto ret = getLeastCountMoney(n);
    cout << ret;
    return 0;
}
