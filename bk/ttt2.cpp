#include <iostream>
#include <vector>
#include <string>

// Helper macro to print the variable name and value
#define printParameter(variable) std::cout << #variable << ": " << variable << std::endl;

// Base case for the recursive macro
#define printParameters(variable)     \
    do {                          \
        printParameter(variable); \
    } while (0)

// Recursive macro to process multiple parameters
#define printParameters(variable, ...) \
    do {                               \
        printParameter(variable);      \
        printParameters(__VA_ARGS__)       \
    } while (0)

// Macro to print the variable name and value
#define save4print(...)               \
    do {                              \
        printParameters(__VA_ARGS__); \
    } while (0)


int main() {
    int integerParam = 42;
    std::string stringParam = "Hello, World!";
    std::vector<int> intVectorParam = {1, 2, 3};
    std::vector<std::string> stringVectorParam = {"apple", "banana", "cherry"};
    double doubleParam = 3.14;
    std::vector<double> doubleVectorParam = {1.1, 2.2, 3.3};
    std::vector<std::vector<int>> nestedIntVectorParam = {{1, 2}, {3, 4}};
    std::vector<std::vector<std::string>> nestedStringVectorParam = {{"apple", "banana"}, {"cherry", "date"}};

    save4print(integerParam, stringParam, intVectorParam, stringVectorParam, doubleParam, doubleVectorParam,
               nestedIntVectorParam, nestedStringVectorParam);

    return 0;
}