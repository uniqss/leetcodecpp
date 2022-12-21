int fibonacci(int first, int second, int n) {
    if (n <= 0) return 0;
    if (n < 3) return 1;
    if (n == 3) return first + second;
    return fibonacci(second, first + second, n - 1);
}

#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int fibonacci_2(int i) {
    if (i <= 0) return 0;
    if (i == 1) return 1;
    return fibonacci_2(i - 1) + fibonacci_2(i - 2);
}

void time_consumption() {
    int n;
    while (cin >> n) {
        milliseconds start_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        int ret = fibonacci_2(n);
        milliseconds end_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        cout << ret << "\t" << milliseconds(end_time).count() - milliseconds(start_time).count() << "ms" << endl;
    }
}

int main() {
    time_consumption();
    return 0;
}
