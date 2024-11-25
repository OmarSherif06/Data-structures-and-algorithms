#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class Node {
    public:
        T data;
        Node* next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class LinkedList {
    public:
        Node<T>* head;

    LinkedList() {
        this->head = nullptr;
    }

    ~LinkedList() {
        Node<T>* currentNode = head;
        while (currentNode != nullptr) {
            Node<T>* nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }
    }
    
    void append(T data) {
        Node<T>* newNode = new Node(data);

        if (this->head == nullptr) {
            this->head = newNode;
        } else {
            Node<T>* last = this->head;
            while(last->next != nullptr) {
                last = last->next;
            }
            last->next = newNode;
        }

    }

    T pop(int index) {
        if (this->head == nullptr) {
            throw std::out_of_range("List is empty");
        }

        Node<T>* currentNode = this->head;
        Node<T>* previousNode = nullptr;

        if (index == 0) {
            this->head = currentNode->next;
            T data = currentNode->data;
            delete currentNode;
            return data;
        }

        int counter = 0;
        while (currentNode != nullptr) {
            if (counter == index) {
                if (previousNode != nullptr) {
                    previousNode->next = currentNode->next;
                }
                T data = currentNode->data;
                delete currentNode;
                return data;
            }
            previousNode = currentNode;
            currentNode = currentNode->next;
            counter++;
        } 

        throw std::out_of_range("Index out of bounds");

    }
    
    void reverse() {
        Node<T>* previousNode = nullptr;
        Node<T>* currentNode = this->head;
        Node<T>* nextNode = nullptr;

        while (currentNode != nullptr) {
            nextNode = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }

        this->head = previousNode;
    }

    void print() const {
        if (this->head == nullptr) {
            cout << "Linked list is empty" << endl;
            return;
        }

        Node<T>* currentNode = this->head;
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
        Node<T>* currentNode = this->head;
        while (currentNode->next != nullptr) {
            count++;
            currentNode = currentNode->next;
        }
        return (count == 0) ? 0 : count;

    }

};