#include "../inc.h"

template <class T>
class QueueElement {
   public:
    QueueElement(const T& _data) : data(_data), next(nullptr) {}
    T data;
    QueueElement* next;
};

template <class T>
class Queue {
    QueueElement<T>* front;
    int count;

   public:
    Queue() : front(nullptr), count(0) {}
    ~Queue() {
        while (front != nullptr) {
            QueueElement<T>* tmp = front;
            front = front->next;
            delete tmp;
        }
    }
    void push(const T& val) {
        QueueElement<T>* element = new QueueElement<T>(val);
        element->next = front;
        front = element;
        ++count;
    }
    bool pop() {
        if (front != nullptr) {
            QueueElement<T>* tmp = front;
            front = front->next;
            delete tmp;
            --count;
            return true;
        }
        return false;
    }
    T* top() {
        if (front != nullptr) {
            return &front->data;
        }
        return nullptr;
    }
    const T* top() const {
        if (front != nullptr) {
            return &front->data;
        }
        return nullptr;
    }
    int size() const {
        return count;
    }
    void foreach (std::function<bool(const T&)> func) const {
        QueueElement<T>* curr = front;
        while (curr != nullptr) {
            if (!func(curr->data)) break;
            curr = curr->next;
        }
    }
};

template <class T>
void pqi(const Queue<T>& q) {
    q.foreach ([&](const T& t) {
        cout << t << "\t";
        return true;
    });
    cout << endl;
}

int main() {
    Queue<int> qi;
    for (int i = 0; i < 5; ++i) {
        qi.push(i);
    }
    pqi(qi);

    qi.pop();
    qi.pop();
    pqi(qi);
    praw(qi.size());
    qi.push(1024);
    pqi(qi);
    qi.push(0);
    pqi(qi);
    praw(qi.size());

    return 0;
}
