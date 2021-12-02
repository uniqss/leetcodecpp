#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void pLinkedList(const ListNode* head) {
    while (head != nullptr)
    {
        cout << head->val << "\t";
        head = head->next;
    }
    cout << endl;
}

void releaseLinkedList(ListNode* head) {
    ListNode* next = nullptr;
    while (head != nullptr)
    {
        next = head->next;
        delete head;
        head = next;
    }
}

void pvi(const vector<int>& vi) {
    std::for_each(vi.begin(), vi.end(), [](int i) { cout << i << " "; });
    cout << endl;
}

void pvvi(const vector<vector<int>>& vvi) {
    for (const auto& it : vvi) {
        for (const auto& it2 : it) {
            cout << it2 << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
