#include "linkedlist.h"

#include <iostream>

using namespace std;

void pilist(const LinkedList<int>& li) {
    Node<int>* curr = li.head;
    while (curr != li.tail) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    LinkedList<int> li;
    for (int i = 0; i < 5; i++) {
        li.Append(i);
    }
    pilist(li);

    Node<int>* elem = li.Find(3);
    cout << elem->data << endl;
    li.Delete(elem);
    pilist(li);
    elem = li.Find(4);
    elem->data = 1024;
    pilist(li);

    return 0;
}
