#include "../inc/inc.h"

/*
用层的思想做，有点绕。本质上还是bfs
这个例子也能看出，unordered_set在频繁增删的情况下，性能和queue的对比，是要差很多的
*/
class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) return 0;
        vector<char> vc = {'A', 'C', 'G', 'T'};
        std::unordered_set<string> dict;
        dict.insert(bank.begin(), bank.end());
        std::unordered_set<string> last_layer;
        std::unordered_set<string> curr_layer;
        std::unordered_set<string> existed;
        curr_layer.insert(start);
        int ssize = (int)start.size();
        int depth = 0;
        for (depth = 0; depth < ssize; ++depth) {
            last_layer = curr_layer;
            curr_layer.clear();
            for (auto it : last_layer) {
                for (int i = 0; i < ssize; ++i) {
                    char last_c = it[i];
                    for (char c : vc) {
                        if (last_c == c) continue;
                        it[i] = c;
                        if (dict.count(it) == 0) continue;
                        if (existed.count(it) > 0) continue;
                        existed.insert(it);
                        if (it == end) return depth + 1;
                        curr_layer.insert(it);
                    }
                    it[i] = last_c;
                }
            }
        }

        return -1;
    }
};

void test(string&& start, string&& end, vector<string>&& bank, int expected) {
    Solution so;
    auto ret = so.minMutation(start, end, bank);
    if (ret == expected) {
        print("ok.");
    } else {
        print("not ok.");
        print(start);
        print(end);
        print(bank);
        print(expected);
        print(ret);
        print();
    }
}

int main() {
    test("AACCGGTT", "AACCGCAA", {"AACCGGTA", "AACCGGAA", "AACCGCAA"}, 3);
    test("AACCGGTT", "AACCGGTA", {}, -1);
    test("AACCGGTT", "AACCGGTA", {"AACCGGTA"}, 1);
    test("AACCGGTT", "AAACGGTA", {"AACCGGTA", "AACCGCTA", "AAACGGTA"}, 2);
    test("AAAAACCC", "AACCCCCC", {"AAAACCCC", "AAACCCCC", "AACCCCCC"}, 3);
    return 0;
}
