#include <stdio.h>

// Macros to handle specific data types using _Generic
#define handle_variable(variable) \
    _Generic((variable), \
        int:    handle_int, \
        char*:  handle_string, \
        char[]: handle_string, \
        double: handle_double \
    )(variable)

// Functions to print the variable name and value for specific data types
void handle_int(int variable) {
    printf("int: %d\n", variable);
}

void handle_string(char* variable) {
    printf("char*: %s\n", variable);
}

void handle_double(double variable) {
    printf("double: %f\n", variable);
}

// Base case for the recursive macro
#define PRINT_PARAM(variable) handle_variable(variable)

// Recursive macro to process multiple parameters
#define printParameters(variable, ...) \
    PRINT_PARAM(variable) \
    printParameters(__VA_ARGS__)

// Macro to print the variable name and value
#define save4print(...) \
    do { \
        printParameters(__VA_ARGS__); \
    } while (0)

int main() {
    int integerParam = 42;
    char* stringParam = "Hello, World!";
    char charArrayParam[] = "Array Example";
    double doubleParam = 3.14;

    save4print(integerParam, stringParam, charArrayParam, doubleParam);

    return 0;
}