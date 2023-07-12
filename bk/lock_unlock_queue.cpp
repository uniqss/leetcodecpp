
extern void lock();
extern void unlock();
struct SimpleAutoLocker {
    SimpleAutoLocker() { lock(); }
    ~SimpleAutoLocker() { unlock(); }
};

int statck[1024];
int stack_index = 0;

bool __full() {
    return stack_index == 1024;
}
bool __empty() {
    return stack_index == 0;
}

bool full() {
    SimpleAutoLocker _;
    return __full();
}

bool empty() {
    SimpleAutoLocker _;
    return __empty();
}

bool push(int value) {
    SimpleAutoLocker _;
    if (__full()) {
        return false;
    }

    if (full()) {
        return false;
    }
    statck[stack_index++] = value;
    return true;
}

bool pop(int& value) {
    SimpleAutoLocker _;
    if (__empty()) {
        return false;
    }

    value = statck[--stack_index];
    return true;
}
