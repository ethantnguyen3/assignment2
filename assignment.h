#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include <iostream>
#include <string>
#include <stdexcept>


// Node structure
template <typename Item_Type>
class SNode {
public:
    Item_Type item; // The item stored in the node
    SNode* next;    // Pointer to the next node

    // Constructor
    SNode(const Item_Type& item, SNode* next = nullptr) 
        : item(item), next(next) {}
};

// Singly Linked List Class
template <typename Item_Type>
class SinglyLinkedList {
private:
    SNode<Item_Type>* head; // Pointer to the head of the list
    SNode<Item_Type>* tail; // Pointer to the tail of the list
    int num_items; // Number of items in the list

public:
    // Constructor
    SinglyLinkedList();

    // Member functions
     void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front(); 
    void pop_back();
    Item_Type front() const;  
    Item_Type back() const;
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item);
    void printList() const;


    // Destructor
    ~SinglyLinkedList();
};

#endif

