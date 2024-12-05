#include "Stackt.h"

// Constructor to initialize the stack with the given size
template <typename T>
Stackt<T>::Stackt(int size) {
    capacity = size;
    arr = new T[capacity];
    top = -1;  // Stack is initially empty
}

// Destructor to clean up memory
template <typename T>
Stackt<T>::~Stackt() {
    delete[] arr;
}

// Push an element onto the stack
template <typename T>
void Stackt<T>::push(T data) {
    if (isFull()) {
        std::cout << "Stack overflow" << std::endl;
        return;
    }
    arr[++top] = data;  // Increment top and push the element
}

// Pop the top element from the stack
template <typename T>
T Stackt<T>::pop() {
    if (isEmpty()) {
        std::cout << "Stack underflow" << std::endl;
        return -1;  // Returning -1 as an error value (adjust based on your use case)
    }
    return arr[top--];  // Return the top element and decrement top
}

// Peek at the top element without removing it
template <typename T>
T Stackt<T>::peek() const {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        return -1;  // Adjust based on your use case
    }
    return arr[top];
}

// Check if the stack is empty
template <typename T>
bool Stackt<T>::isEmpty() const {
    return top == -1;
}

// Check if the stack is full
template <typename T>
bool Stackt<T>::isFull() const {
    return top == capacity - 1;
}

// Explicit instantiation for common types (optional)
// template class Stackt<int>;
// template class Stackt<float>;
