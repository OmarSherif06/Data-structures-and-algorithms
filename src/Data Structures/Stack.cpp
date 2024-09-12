#include <iostream>
#define MAX 10000

template<typename T>
class Stack {
    private:
        T array[MAX];
        int top;

    public:

        Stack() {
            top = -1;
        }

        void push(const T& value) {
            if (top >= MAX) {
                throw std::overflow_error("Stack overflow");
            } else {
                array[++top] = value;
            }
        }

        T pop() {
            if (top < 0) {
                throw std::underflow_error("Stack underflow");
            }
            return array[top--];
        }

        T peek() {
            if (top < 0) {
                throw std::underflow_error("Stack is empty");
            } else {
                return array[top];
            }
        }

        bool isEmpty() {
            return top < 0;
        }

        int search(const T& key) {
             if (top < 0) {
                throw std::underflow_error("Stack is empty");
            }

            for (int i = top; i >= 0; i--) {
                if (array[i] == key) {
                    return i;
                }
            }

            return -1;
        }
};