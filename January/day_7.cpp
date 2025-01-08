#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;

public:
    LinkedList() : head(nullptr) {}


    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }


    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    void merge(LinkedList& list2) {
        Node* p = head;
        Node* q = list2.head;
        Node* dummy = new Node(0); 
        Node* last = dummy;

        // Fusionar ambas listas
        while (p && q) {
            if (p->data < q->data) {
                last->next = p;
                p = p->next;
            } else {
                last->next = q;
                q = q->next;
            }
            last = last->next;
        }

        if (p) {
            last->next = p;
        } else {
            last->next = q;
        }

        head = dummy->next;
        delete dummy; 

        list2.head = nullptr;
    }

    
};

int main() {
    LinkedList list1, list2;
    list1.insert(1);
    list1.insert(3);
    list1.insert(5);
    list2.insert(2);
    list2.insert(4);
    list2.insert(6);

    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();

    list1.merge(list2);

    cout << "Merged List: ";
    list1.display();

    return 0;
}
