#ifndef PALINDROMELL_H
#define PALINDROMELL_H
#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
};

// Global head pointer matching your template style
template <typename T>
Node<T> *head = nullptr;

template <typename T>
void push(T newData){
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = head<T>;
    head<T> = newNode;
}
    
template<typename T>
bool isEmpty(){
    return head<T> == nullptr;
}

template <typename T>
T pop(){
    if(head<T> == nullptr){
        std::cout << "[ Stack underflow ]" << std::endl;
        return T(); // Returns default value of T
    }

    Node<T>* temp = head<T>;
    T tempVal = temp->data;
    head<T> = head<T>->next;
    
    delete temp;
    return tempVal;
}

#endif
