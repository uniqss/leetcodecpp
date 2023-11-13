#include "./OtherAlgorithms/murmurhash64b.hpp"

#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

void test(const string& str, unsigned long long expect) {
    auto ret = utility::Murmurhash64bStr(str);
    if (expect == ret) {
        cout << "ok." << endl;
    } else {
        cout << "not ok." << endl;
        cout << "str:" << str << endl;
        cout << "expected: " << expect << " ret: " << ret << endl;
    }
}
void testii(int64_t i1, int i2, unsigned long long expect) {
    auto ret = utility::Murmurhash64bII(i1, i2);
    if (expect == ret) {
        cout << "ok." << endl;
    } else {
        cout << "not ok." << endl;
        cout << "expect:" << expect << " ret:" << ret << endl;
        cout << "i1:" << i1 << " i2:" << i2 << endl;
    }
}

int main() {
    test("hello world", 15872188016033428291ul);
    test("hello|world", 18154384023894766483ul);
    test("world hello", 3885965473734762678ul);
    test("123456789|1001", 3735326771242004321ul);
    test("123456789|1002", 1645870013858767195ul);
    test("你好世界", 3269873437238233672ul);
    test("1717720317549350912|1001", 9344049702176278212ul);
    testii(1717720317549350912, 1001, 3168977379835420589ul);
    return 0;
}
