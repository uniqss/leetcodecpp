#include <cstring>
#include <stdexcept>

template <class T>
class Node {
   public:
    Node(const T& d) : data(d), next(nullptr), prev(nullptr) {}
    Node() : next(nullptr), prev(nullptr) { memset(&data, 0, sizeof(data)); }
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <class T>
class LinkedList {
   public:
    LinkedList() {
        head = new Node<T>();
        tail = new Node<T>();
        head->next = tail;
        tail->prev = head;
    }
    Node<T>* head;
    Node<T>* tail;
    void InsertAfter(Node<T>* pos, const T& d) {
        if (pos == nullptr) {
            throw std::logic_error("pos == nullptr");
            return;
        }
        Node<T>* node = new Node<T>(d);
        node->prev = pos;
        node->next = pos->next;
        pos->next = node;
        node->next->prev = node;
    }
    void Append(const T& d) { InsertAfter(tail->prev, d); }
    void PreAppend(const T& d) { InsertAfter(head, d); }
    void Delete(Node<T>* node) {
        // warning
        if (node == nullptr) return;
        if (node->prev != nullptr) node->prev->next = node->next;
        if (node->next != nullptr) node->next->prev = node->prev;
        delete node;
    }
    Node<T>* Find(const T& data) {
        Node<T>* curr = head;
        // 有头有尾这里也可不判空
        while (curr != tail && curr != nullptr) {
            if (curr->data == data) return curr;
            curr = curr->next;
        }
        return nullptr;
    }
};