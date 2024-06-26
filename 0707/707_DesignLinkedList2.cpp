#include "../stl.h"
#include "../complexval.h"

class MyLinkedList {
    struct MyInnerNode {
        MyInnerNode* next;
        int val;
        MyInnerNode() : next(nullptr), val(0) {}
        MyInnerNode(int _val, MyInnerNode* _next = nullptr) : next(_next), val(_val) {}
    };
    MyInnerNode* head;

   public:
    MyLinkedList() : head(new MyInnerNode()) {}

    int get(int index) {
        MyInnerNode* curr = head;
        while (index-- >= 0 && curr != nullptr) {
            curr = curr->next;
        }
        return curr == nullptr ? -1 : curr->val;
    }

    void addAtHead(int val) {
        MyInnerNode* node = new MyInnerNode(val, head->next);
        head->next = node;
    }

    void addAtTail(int val) {
        MyInnerNode* node = new MyInnerNode(val);
        MyInnerNode* prev = head;
        while (prev->next != nullptr) {
            prev = prev->next;
        }
        prev->next = node;
    }

    // If index is greater than the length, the node will not be inserted
    void addAtIndex(int index, int val) {
        MyInnerNode* node = new MyInnerNode(val);
        MyInnerNode* prev = head;
        for (int i = 0; i < index; ++i) {
            if (prev->next == nullptr) return;
            prev = prev->next;
        }

        node->next = prev->next;
        prev->next = node;
    }

    void deleteAtIndex(int index) {
        MyInnerNode* prev = head;
        while (--index >= 0 && prev->next != nullptr) prev = prev->next;
        if (prev->next != nullptr) {
            MyInnerNode* tmp = prev->next;
            prev->next = prev->next->next;
            delete tmp;
        }
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