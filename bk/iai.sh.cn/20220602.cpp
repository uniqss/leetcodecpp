#include <vector>
#include <limits.h>
#include <iostream>
#include <string>
using namespace std;

/*
这个平台出错根本没法查出错用例，输入输出强制和算法逻辑搅和在一起，简直让人大跌眼镜  长期刷会降低技术水平的，还是算了
*/

int main() {
    string input;
    string password;
    cin.tie(0);
    cin >> password;
    int count = 0;
    int curr_wait_seconds = 1;
    int total_wait_seconds = 0;
    int n = 0;
    cin >> n;
    while (--n >= 0) {
        cin >> input;
        ++count;
        if (count > 3) {
            total_wait_seconds += curr_wait_seconds;
            curr_wait_seconds <<= 1;
        }
        if (count > 10) {
            cout << "Locked";
            return 0;
        }
    }
    cout << total_wait_seconds;
    return 0;
}
