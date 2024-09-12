#include <iostream>

using std::cout;
using std::endl;

class Node {
    public:
        int data;
        Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
    public:
        Node* head;

    LinkedList() {
        this->head = nullptr;
    }

    ~LinkedList() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            Node* nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }
    }
    
    void append(int data) {
        Node* newNode = new Node(data);

        if (this->head == nullptr) {
            this->head = newNode;
        } else {
            Node* last = this->head;
            while(last->next != nullptr) {
                last = last->next;
            }
            last->next = newNode;
        }

    }

    int pop(int index) {
        if (this->head == nullptr) {
            throw std::out_of_range("List is empty");
        }

        Node* currentNode = this->head;
        Node* previousNode = nullptr;

        if (index == 0) {
            this->head = currentNode->next;
            int data = currentNode->data;
            delete currentNode;
            return data;
        }

        int counter = 0;
        while (currentNode != nullptr) {
            if (counter == index) {
                if (previousNode != nullptr) {
                    previousNode->next = currentNode->next;
                }
                int data = currentNode->data;
                delete currentNode;
                return data;
            }
            previousNode = currentNode;
            currentNode = currentNode->next;
            counter++;
        } 

        throw std::out_of_range("Index out of bounds");

    }

    void print() const {
        if (this->head == nullptr) {
            cout << "Linked list is empty" << endl;
            return;
        }

        Node* currentNode = this->head;
        cout << "Linked List: ";
        while (currentNode != nullptr) {
            cout << currentNode->data;
            if (currentNode->next != nullptr) {
                cout << ", ";
            }
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    int size() const {
        int count = 1;
        Node* currentNode = this->head;
        while (currentNode->next != nullptr) {
            count++;
            currentNode = currentNode->next;
        }
        return (count == 0) ? 0 : count;

    }

};