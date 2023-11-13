#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define save4print(...) printParameters(__VA_ARGS__)

template <typename T>
void __printParameter(const std::string& pname, const T& param) {
    std::cout << pname << ": " << param << std::endl;
}
template <typename T>
void __printParameter(const std::string& pname, const std::vector<T>& param) {
    std::cout << pname << ": ";
    std::for_each(param.begin(), param.end(), [](const T& p) { std::cout << p << " "; });
    std::cout << std::endl;
}

// Helper macro to print the parameter name and value
#define printParameter(param) __printParameter(#param, param)

template <typename... Args>
void printParameters(Args&&... args) {
    ((printParameter(args)), ...);
}

int main() {
    int integerParam = 42;
    std::string stringParam = "Hello, World!";
    std::vector<int> intVectorParam = {1, 2, 3};
    std::vector<std::string> stringVectorParam = {"apple", "banana", "cherry"};
    double doubleParam = 3.14;
    std::vector<double> doubleVectorParam = {1.1, 2.2, 3.3};

    save4print(integerParam, stringParam, intVectorParam, stringVectorParam, doubleParam, doubleVectorParam);

    return 0;
}
