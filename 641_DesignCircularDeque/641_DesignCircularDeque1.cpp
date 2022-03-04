#include "../inc.h"

class MyCircularDeque {
    vector<int> val;
    size_t lastIdxFront;
    size_t lastIdxLast;
    size_t count;

   public:
    MyCircularDeque(int k) {
        val.resize(k);
        lastIdxFront = 1;
        lastIdxLast = 0;
        count = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        lastIdxFront = (lastIdxFront + val.size() - 1) % val.size();
        val[lastIdxFront] = value;
        ++count;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        lastIdxLast = (lastIdxLast + 1) % val.size();
        val[lastIdxLast] = value;
        ++count;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        lastIdxFront = (lastIdxFront + 1) % val.size();
        --count;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        lastIdxLast = (lastIdxLast + val.size() - 1) % val.size();
        --count;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return val[lastIdxFront];
    }

    // Returns the last item from Deque. Returns -1 if the deque is empty.
    int getRear() {
        if (isEmpty()) return -1;
        return val[lastIdxLast];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == val.size();
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
        praw("unknown command!!!");
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
        praw("### not ok");
        pvraw(oplist);
        pvcomplex(expected);
        pvcomplex(ret);
    } else {
        praw("ok");
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

    /*
    ["MyCircularDeque","insertFront","getRear","deleteLast","getRear","insertFront","insertFront","insertFront","insertFront","isFull","insertFront","isFull","getRear","deleteLast","getFront","getFront","insertLast","deleteFront","getFront","insertLast","getRear","insertLast","getRear","getFront","getFront","getFront","getRear","getRear","insertFront","getFront","getFront","getFront","getFront","deleteFront","insertFront","getFront","deleteLast","insertLast","insertLast","getRear","getRear","getRear","isEmpty","insertFront","deleteLast","getFront","deleteLast","getRear","getFront","isFull","isFull","deleteFront","getFront","deleteLast","getRear","insertFront","getFront","insertFront","insertFront","getRear","isFull","getFront","getFront","insertFront","insertLast","getRear","getRear","deleteLast","insertFront","getRear","insertLast","getFront","getFront","getFront","getRear","insertFront","isEmpty","getFront","getFront","insertFront","deleteFront","insertFront","deleteLast","getFront","getRear","getFront","insertFront","getFront","deleteFront","insertFront","isEmpty","getRear","getRear","getRear","getRear","deleteFront","getRear","isEmpty","deleteFront","insertFront","insertLast","deleteLast"]
[[77],[89],[],[],[],[19],[23],[23],[82],[],[45],[],[],[],[],[],[74],[],[],[98],[],[99],[],[],[],[],[],[],[8],[],[],[],[],[],[75],[],[],[35],[59],[],[],[],[],[22],[],[],[],[],[],[],[],[],[],[],[],[21],[],[26],[63],[],[],[],[],[87],[76],[],[],[],[26],[],[67],[],[],[],[],[36],[],[],[],[72],[],[87],[],[],[],[],[85],[],[],[91],[],[],[],[],[],[],[],[],[],[34],[44],[]]

[null,true,89,true,-1,true,true,true,true,false,true,false,19,true,45,45,true,true,82,true,98,true,99,82,82,82,99,99,true,8,8,8,8,true,true,75,true,true,true,59,59,59,false,true,true,22,true,98,22,false,false,true,75,true,74,true,21,true,true,74,false,63,63,true,true,76,76,true,true,74,true,26,26,26,67,true,false,36,36,true,true,true,true,87,74,87,true,85,true,true,false,74,74,74,74,true,74,false,true,true,true,true]
    */
    oplist = {"MyCircularDeque", "insertFront", "getRear", "deleteLast", "getRear", "insertFront", "insertFront", "insertFront", "insertFront", "isFull", "insertFront", "isFull", "getRear", "deleteLast", "getFront", "getFront", "insertLast", "deleteFront", "getFront", "insertLast", "getRear", "insertLast", "getRear", "getFront", "getFront", "getFront", "getRear", "getRear", "insertFront", "getFront", "getFront", "getFront", "getFront", "deleteFront", "insertFront", "getFront", "deleteLast", "insertLast", "insertLast", "getRear", "getRear", "getRear", "isEmpty", "insertFront", "deleteLast", "getFront", "deleteLast", "getRear", "getFront", "isFull", "isFull", "deleteFront", "getFront", "deleteLast", "getRear", "insertFront", "getFront", "insertFront", "insertFront", "getRear", "isFull", "getFront", "getFront", "insertFront", "insertLast", "getRear", "getRear", "deleteLast", "insertFront", "getRear", "insertLast", "getFront", "getFront", "getFront", "getRear", "insertFront", "isEmpty", "getFront", "getFront", "insertFront", "deleteFront", "insertFront", "deleteLast", "getFront", "getRear", "getFront", "insertFront", "getFront", "deleteFront", "insertFront", "isEmpty", "getRear", "getRear", "getRear", "getRear", "deleteFront", "getRear", "isEmpty", "deleteFront", "insertFront", "insertLast", "deleteLast"};
    argslist = {{77}, {89}, {}, {}, {}, {19}, {23}, {23}, {82}, {}, {45}, {}, {}, {}, {}, {}, {74}, {}, {}, {98}, {}, {99}, {}, {}, {}, {}, {}, {}, {8}, {}, {}, {}, {}, {}, {75}, {}, {}, {35}, {59}, {}, {}, {}, {}, {22}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {21}, {}, {26}, {63}, {}, {}, {}, {}, {87}, {76}, {}, {}, {}, {26}, {}, {67}, {}, {}, {}, {}, {36}, {}, {}, {}, {72}, {}, {87}, {}, {}, {}, {}, {85}, {}, {}, {91}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {34}, {44}, {}};
    expected = {null, true, 89, true, -1, true, true, true, true, false, true, false, 19, true, 45, 45, true, true, 82, true, 98, true, 99, 82, 82, 82, 99, 99, true, 8, 8, 8, 8, true, true, 75, true, true, true, 59, 59, 59, false, true, true, 22, true, 98, 22, false, false, true, 75, true, 74, true, 21, true, true, 74, false, 63, 63, true, true, 76, 76, true, true, 74, true, 26, 26, 26, 67, true, false, 36, 36, true, true, true, true, 87, 74, 87, true, 85, true, true, false, 74, 74, 74, 74, true, 74, false, true, true, true, true};
    test(oplist, argslist, expected);

    if (g_cdq != nullptr) {
        delete g_cdq;
        g_cdq = nullptr;
    }
    return 0;
}
