#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <array>

struct LowerCaseCharCounter {
    std::array<int, 26> counter;
    LowerCaseCharCounter(const std::string& str) {
        counter = {0};
        std::for_each(str.begin(), str.end(), [&](const char& c) { ++counter[c - 'a']; });
    }
    LowerCaseCharCounter(const char* str) {
        counter = {0};
        while (*str != '\0') {
            ++counter[*str - 'a'];
            ++str;
        }
    }
    bool operator==(const LowerCaseCharCounter& rhs) const {
        return this->counter == rhs.counter;
    }
};

struct UserHash {
    std::size_t operator()(const LowerCaseCharCounter& key) const {
        std::size_t ret = 0;
        const auto& arr = key.counter;
        std::for_each(arr.begin(), arr.end(), [&](auto val) { ret += std::hash<decltype(val)>()(val); });
        return ret;
    }
};

int main() {
    std::unordered_map<LowerCaseCharCounter, int, UserHash> um;
    um["asdf"] = 1234;
    std::cout << um["asdf"] << std::endl;
    um["dfas"] = 5678;
    std::cout << um["asdf"] << std::endl;
    std::cout << um["dfas"] << std::endl;
    return 0;
}
