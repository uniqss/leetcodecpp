#include "../stl.h"

template <class T>
class DequeElement {
   public:
    DequeElement(const T& _data) : data(_data), prev(nullptr), next(nullptr) {}
    T data;
    DequeElement* prev;
    DequeElement* next;
};

template <class T>
class Deque {
    DequeElement<T>* head;
    DequeElement<T>* tail;
    int count;

   public:
    Deque() : head(nullptr), tail(nullptr), count(0) {}
    ~Deque() {
        while (head != nullptr) {
            DequeElement<T>* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    void push_front(const T& val) {
        DequeElement<T>* element = new DequeElement<T>(val);
        element->next = head;
        if (head != nullptr) head->prev = element;
        head = element;
        if (tail == nullptr) tail = element;
        ++count;
    }
    void push_back(const T& val) {
        DequeElement<T>* element = new DequeElement<T>(val);
        element->prev = tail;
        if (tail != nullptr) tail->next = element;
        tail = element;
        if (head == nullptr) head = element;
        ++count;
    }
    bool pop_front() {
        if (head != nullptr) {
            DequeElement<T>* tmp = head;
            head = head->next;
            if (tail == tmp) tail = nullptr;
            delete tmp;
            --count;
            return true;
        }
        return false;
    }
    bool pop_back() {
        if (tail != nullptr) {
            DequeElement<T>* tmp = tail;
            tail = tail->prev;
            if (head == tmp) head = nullptr;
            delete tmp;
            --count;
            return true;
        }
        return false;
    }
    T* front() {
        if (head != nullptr) {
            return &head->data;
        }
        return nullptr;
    }
    const T* front() const {
        if (head != nullptr) {
            return &head->data;
        }
        return nullptr;
    }
    T* back() {
        if (tail != nullptr) {
            return &tail->data;
        }
        return nullptr;
    }
    const T* back() const {
        if (tail != nullptr) {
            return &tail->data;
        }
        return nullptr;
    }
    int size() const {
        return count;
    }
    void foreach (std::function<bool(const T&)> func) const {
        DequeElement<T>* curr = head;
        while (curr != nullptr) {
            if (!func(curr->data)) break;
            curr = curr->next;
        }
    }
};

template <class T>
void pqi(const Deque<T>& q) {
    q.foreach ([&](const T& t) {
        cout << t << "\t";
        return true;
    });
    cout << endl;
}

int main() {
    Deque<int> dqi;
    for (int i = 0; i < 5; ++i) {
        dqi.push_back(i);
    }
    pqi(dqi);

    dqi.pop_front();
    dqi.pop_front();
    pqi(dqi);
    for (int i = 10; i < 15; ++i) {
        dqi.push_front(i);
    }
    pqi(dqi);

    praw(dqi.size());
    dqi.push_back(1024);
    pqi(dqi);
    dqi.push_back(0);
    pqi(dqi);
    praw(dqi.size());

    return 0;
}
