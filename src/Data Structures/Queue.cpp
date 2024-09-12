#include <iostream>
#define MAX 10000

template <typename T>
class Queue {
    private:
        T elements[MAX];
        int head;
        int tail;
        int size;

    public:

        Queue() {
            head = 0;
            tail = -1;
            size = 0;
        }

        void enqueue(const T& element) {
            if (size > MAX) {
                throw std::overflow_error("Stack overflow");
            }
            elements[++tail] = element;
            size++;
        }

        void dequeue() {
            if (size < 0) {
                throw std::underflow_error("Queue underflow");
            }
            head++;
            size--;
        }

        T peek() {
            if (size <= 0) {
                throw std::underflow_error("Queue is Empty");
            }
            return elements[head];
        }

        bool contains(const T& element) {
            for (int i = 0; i < size; i++) {
                if (elements[i] == element) {
                    return true;
                }
            }
            return false;
        }

        bool isEmpty() {
            return size == 0;
        }

        int getSize() {
            return size;
        }

};