#include "../stl.h"

class MyCircularDequeElement {
   public:
    MyCircularDequeElement(int _val) : val(_val), next(nullptr), prev(nullptr) {}
    int val;
    MyCircularDequeElement* next;
    MyCircularDequeElement* prev;
};

class MyCircularDeque {
    MyCircularDequeElement* head;
    MyCircularDequeElement* tail;
    int capacity;
    int count;

   public:
    MyCircularDeque(int k) : head(nullptr), tail(nullptr), count(0), capacity(k) {
    }
    ~MyCircularDeque() {
        while (head != nullptr) {
            MyCircularDequeElement* e = head;
            head = head->next;
            delete e;
        }
    }

    bool insertFront(int value) {
        if (count >= capacity) return false;
        MyCircularDequeElement* e = new MyCircularDequeElement(value);
        e->next = head;
        if (head != nullptr) head->prev = e;
        if (tail == nullptr) tail = e;
        head = e;
        ++count;
        return true;
    }

    bool insertLast(int value) {
        if (count >= capacity) return false;
        MyCircularDequeElement* e = new MyCircularDequeElement(value);
        e->prev = tail;
        if (tail != nullptr) tail->next = e;
        if (head == nullptr) head = e;
        tail = e;
        ++count;
        return true;
    }

    bool deleteFront() {
        if (count == 0) return false;
        MyCircularDequeElement* e = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        if (tail == e) tail = nullptr;
        delete e;
        --count;
        return true;
    }

    bool deleteLast() {
        if (count == 0) return false;
        MyCircularDequeElement* e = tail;
        tail = tail->prev;
        if (tail != nullptr) tail->next = nullptr;
        if (head == e) head = nullptr;
        delete e;
        --count;
        return true;
    }

    int getFront() {
        if (count > 0) return head->val;
        return -1;
    }

    int getRear() {
        if (count > 0) return tail->val;
        return -1;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count >= capacity;
    }
};

MyCircularDeque* g_cdq = nullptr;

ComplexVal testop(const string& op, const vector<int>& args) {
    ComplexVal ret;
    if (op == "MyCircularDeque") {
        g_cdq = new MyCircularDeque(args[0]);
        ret = nullptr;
    } else if (op == "insertLast") {
        ret = g_cdq->insertLast(args[0]);
    } else if (op == "insertFront") {
        ret = g_cdq->insertFront(args[0]);
    } else if (op == "deleteLast") {
        ret = g_cdq->deleteLast();
    } else if (op == "deleteFront") {
        ret = g_cdq->deleteFront();
    } else if (op == "getRear") {
        ret = g_cdq->getRear();
    } else if (op == "isFull") {
        ret = g_cdq->isFull();
    } else if (op == "isEmpty") {
        ret = g_cdq->isEmpty();
    } else if (op == "getFront") {
        ret = g_cdq->getFront();
    } else {
        ps("unknown command!!!");
        praw(op);
    }
    return ret;
}

void test(const vector<string>& oplist, const vector<vector<int>>& argslist, const vector<ComplexVal>& expected) {
    vector<ComplexVal> ret;

    for (size_t i = 0; i < oplist.size(); ++i) {
        const string& op = oplist[i];
        const vector<int>& arg = argslist[i];
        ret.push_back(testop(op, arg));
    }
    if (ret != expected) {
        ps("### not ok");
        pvs(oplist);
        pvcomplex(expected);
        pvcomplex(ret);
    } else {
        ps("ok");
    }
}

int main() {
    vector<string> oplist;
    vector<vector<int>> argslist;
    vector<ComplexVal> expected;

    oplist = {"MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"};
    argslist = {{3}, {1}, {2}, {3}, {4}, {}, {}, {}, {4}, {}};
    expected = {null, true, true, true, false, 2, true, true, true, 4};
    test(oplist, argslist, expected);

    /*
    ["MyCircularDeque","insertFront","getFront","isEmpty","deleteFront","insertLast","getRear","insertLast","insertFront","deleteLast","insertLast","isEmpty"]
    [[8],[5],[],[],[],[3],[],[7],[7],[],[4],[]]
    [null,true,5,false,true,true,3,true,true,true,true,false]
    */
    oplist = {"MyCircularDeque", "insertFront", "getFront", "isEmpty", "deleteFront", "insertLast", "getRear", "insertLast", "insertFront", "deleteLast", "insertLast", "isEmpty"};
    argslist = {{8}, {5}, {}, {}, {}, {3}, {}, {7}, {7}, {}, {4}, {}};
    expected = {null, true, 5, false, true, true, 3, true, true, true, true, false};
    test(oplist, argslist, expected);

    /*
    ["MyCircularDeque","insertFront","insertLast","getFront","insertLast","getFront","insertFront","getRear","getFront","getFront","deleteLast","getRear"]
[[5],[7],[0],[],[3],[],[9],[],[],[],[],[]]
[null,true,true,7,true,7,true,3,9,9,true,0]
    */
    oplist = {"MyCircularDeque", "insertFront", "insertLast", "getFront", "insertLast", "getFront", "insertFront", "getRear", "getFront", "getFront", "deleteLast", "getRear"};
    argslist = {{5}, {7}, {0}, {}, {3}, {}, {9}, {}, {}, {}, {}, {}};
    expected = {null, true, true, 7, true, 7, true, 3, 9, 9, true, 0};
    test(oplist, argslist, expected);

    if (g_cdq != nullptr) {
        delete g_cdq;
        g_cdq = nullptr;
    }
    return 0;
}