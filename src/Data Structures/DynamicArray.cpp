#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class DynamicArray {
    private:
        int size;
        int capacity;
        T* array;

    public:

        DynamicArray() {
            size = 0;
            capacity = 1;
            array = new T[capacity];
        }

        ~DynamicArray() {
            delete[] array;
        }

        void shrink() {
            capacity /= 2;
            T* newArray = new T[capacity];

            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }

        void grow() {
            capacity *= 2;
            T* newArray = new T[capacity];

            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }

        void append(const T& element) {
            if (size == capacity) {
                grow();
            }
            array[size++] = element;
        }

        T peek(int index) {
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index out of bounds");
            }

            return array[index];
        }

        void insert(const T& element, int index) {
            if (index >= size || index < 0) {
                this->append(element);
                return;
            }

            if (size == capacity) {
                grow();
            }

            for (int i = size; i > index; i--) {
                array[i] = array[i - 1];
            }

            array[index] = element;
            size++;
        }

        T pop() {
            if (size == 0) {
                throw std::out_of_range("Cannot pop from an empty array");
            }

            int index = size - 1;
            T data = array[index];
            array[index] = T();
            size--;

            if (size > 0 && size <= capacity / 4) {
                shrink();
            }

            return data;
        }
        
        T pop(int index) {
            if (size == 0) {
                throw std::out_of_range("Cannot pop from an empty array");
            }

            if (size > 0 && size <= capacity / 4) {
                shrink();
            }

            T data = array[index];

            for (int i = index; i < size - 1; i++) {
                array[i] = array[i + 1];
            }

            array[size - 1] = T();
            size--;

            return data;
        }

        void print() {
            if (size == 0) {
                throw std::out_of_range("Array is empty");
            }
            cout << "[";
            for (int i = 0; i < size; i++) {
                cout << array[i] << (i < size - 1 ? ", " : "");
            }
            cout << "]" << endl;
        }


};
