#include "../inc/inc.h"

class Solution {
    vector<char> vc;

   public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        vc = {'A', 'C', 'G', 'T'};
        if (dict.count(end) == 0) return -1;
        unordered_set<string> curr1 = {start}, curr2 = {end};
        unordered_set<string> used;
        int depth1 = 0;
        int depth2 = 0;
        bool found = dfs(depth1, depth2, curr1, curr2, used, dict);
        if (found) return depth1 + depth2;
        return -1;
    }
    bool dfs(int& depth1, int& depth2, unordered_set<string>& curr1, unordered_set<string>& curr2, unordered_set<string>& used, const unordered_set<string>& dict) {
        ++depth1;
        unordered_set<string> curr_layer;
        for (const string& curr : curr1) {
            string s = curr;
            for (size_t i = 0; i < s.size(); ++i) {
                for (char c : vc) {
                    if (s[i] == c) continue;
                    s[i] = c;
                    if (dict.count(s) == 0) continue;
                    if (used.count(s) > 0) continue;
                    if (curr2.count(s) > 0) return true;
                    curr_layer.insert(s);
                }
                s[i] = curr[i];
            }
        }
        if (curr_layer.empty()) return false;
        used.insert(curr1.begin(), curr1.end());
        curr1 = curr_layer;
        if (depth1 > depth2) return dfs(depth2, depth1, curr2, curr1, used, dict);
        return dfs(depth1, depth2, curr1, curr2, used, dict);
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
    test("AACCTTGG", "AATTCCGG", {"AATTCCGG", "AACCTGGG", "AACCCCGG", "AACCTACC"}, -1);
    test("AACCGGTT", "AACCGCAA", {"AACCGGTA", "AACCGGAA", "AACCGCAA"}, 3);
    test("AACCGGTT", "AACCGGTA", {}, -1);
    test("AACCGGTT", "AACCGGTA", {"AACCGGTA"}, 1);
    test("AACCGGTT", "AAACGGTA", {"AACCGGTA", "AACCGCTA", "AAACGGTA"}, 2);
    test("AAAAACCC", "AACCCCCC", {"AAAACCCC", "AAACCCCC", "AACCCCCC"}, 3);
    return 0;
}
