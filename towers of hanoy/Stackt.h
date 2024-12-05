#ifndef STACKT_H
#define STACKT_H

#include <iostream>

template <typename T>
class Stackt {
private:
    T* arr;          // Array to hold stack elements
    int capacity;    // Maximum size of the stack
    int top;         // Index of the top element in the stack

public:
    Stackt(int size = 100);  // Constructor with a default size
    ~Stackt();               // Destructor to clean up dynamically allocated memory

    void push(T data);       // Push an element onto the stack
    T pop();                 // Pop the top element from the stack
    T peek() const;          // Get the top element without removing it
    bool isEmpty() const;    // Check if the stack is empty
    bool isFull() const;     // Check if the stack is full
};
#endif
