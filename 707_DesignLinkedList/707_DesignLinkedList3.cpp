#include "../stl.h"
#include "../complexval.h"


class MyListNode {
   public:
    MyListNode* next;
    int val;
    MyListNode() : next(nullptr), val(0) {}
    MyListNode(MyListNode* n) : next(n), val(0) {}
    MyListNode(int v) : next(nullptr), val(v) {}
    MyListNode(MyListNode* n, int v) : next(n), val(v) {}
};
class MyLinkedList {
    MyListNode fhead;
    // easier if we save len as a member. but remember to increase and decrease the len.
    int len;

   public:
    MyLinkedList() : len(0) {}

    int get(int index) {
        if (index >= len) return -1;
        MyListNode* tmp = &fhead;
        for (int i = 0; i <= index; ++i) {
            tmp = tmp->next;
        }
        return tmp->val;
    }

    void addAtHead(int val) {
        MyListNode* node = new MyListNode(fhead.next, val);
        fhead.next = node;
        ++len;
    }

    void addAtTail(int val) {
        MyListNode* prev = &fhead;
        while (prev->next != nullptr) {
            prev = prev->next;
        }
        MyListNode* node = new MyListNode(val);
        prev->next = node;
        ++len;
    }

    // If index is greater than the length, the node will not be inserted
    void addAtIndex(int index, int val) {
        if (index > len) return;
        MyListNode* prev = &fhead;
        for (int i = 0; i < index; ++i) {
            prev = prev->next;
        }
        MyListNode* node = new MyListNode(prev->next, val);
        prev->next = node;
        ++len;
    }

    void deleteAtIndex(int index) {
        if (index >= len) return;
        MyListNode* prev = &fhead;
        for (int i = 0; i < index; ++i) {
            prev = prev->next;
        }
        MyListNode* tmp = prev->next;
        prev->next = prev->next->next;
        delete tmp;
        --len;
    }
};

#define null nullptr

void plist(MyLinkedList* list) {
    for (int i = 0; i < 20; ++i) {
        int val = list->get(i);
        if (val == -1) break;
        cout << val << "\t";
    }
    cout << "|" << endl;
}

MyLinkedList* g_list = nullptr;
void test(const vector<string>& ops, const vector<vector<int>>& params, const vector<ComplexVal>& expect) {
    int idx = 0;
    vector<ComplexVal> ret;
    for (auto op : ops) {
        const vector<int>& param = params[idx];
        if (op == "MyLinkedList") {
            g_list = new MyLinkedList();
            ret.emplace_back(null);
        } else if (op == "addAtHead") {
            g_list->addAtHead(param[0]);
            ret.emplace_back(null);
        } else if (op == "addAtTail") {
            g_list->addAtTail(param[0]);
            ret.emplace_back(null);
        } else if (op == "addAtIndex") {
            g_list->addAtIndex(param[0], param[1]);
            ret.emplace_back(null);
        } else if (op == "get") {
            int val = g_list->get(param[0]);
            ret.emplace_back(val);
            // std::cout << "val:" << val << std::endl;
        } else if (op == "deleteAtIndex") {
            g_list->deleteAtIndex(param[0]);
            ret.emplace_back(null);
        }
        ++idx;
        plist(g_list);
    }

    if (expect == ret) {
        print("ok");
    } else {
        print("not ok.");
        print(ops);
        print(params);
        print(expect);
        print(ret);
        print();
    }

    if (g_list) {
        delete g_list;
        g_list = nullptr;
    }
}

/*
["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[1],[1]]
*/
int main() {
    test({"MyLinkedList", "addAtIndex", "get"}, {{}, {0, 0}, {0}}, {null, null, 0});
    test({"MyLinkedList", "addAtIndex", "get"}, {{}, {1, 0}, {0}}, {null, null, -1});
    test({"MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"}, {{}, {1}, {3}, {1, 2}, {1}, {1}, {1}},
         {null, null, null, null, 2, null, 3});

    /*
    ["MyLinkedList","addAtHead","get","addAtHead","addAtHead","deleteAtIndex","addAtHead","get","get","get","addAtHead","deleteAtIndex"]
    [[],[4],[1],[1],[5],[3],[7],[3],[3],[3],[1],[4]]
    */
    test({"MyLinkedList", "addAtHead", "get", "addAtHead", "addAtHead", "deleteAtIndex", "addAtHead", "get", "get", "get", "addAtHead", "deleteAtIndex"},
         {{}, {4}, {1}, {1}, {5}, {3}, {7}, {3}, {3}, {3}, {1}, {4}}, {null, null, -1, null, null, null, null, 4, 4, 4, null, null});

    return 0;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */