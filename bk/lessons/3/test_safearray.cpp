#include "safearray.h"

#include <iostream>

using namespace std;

class TestClass {
   public:
    int i;
};

int main() {
    SafeArray<int> si;
    for (int i = 0; i < 5; i++) {
        si.push_back(i);
    }

    cout << si[0] << endl;
    cout << si[3] << endl;
    cout << si[10] << endl;

    SafeArray<TestClass> st;
    for (int i = 0; i < 3; i++) {
        TestClass t = {i};
        st.push_back(t);
    }
    cout << st[1].i << endl;
    cout << st[10].i << endl;

    return 0;
}
