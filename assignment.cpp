#include "assignment.h" 
#include <iostream>
#include <string>
#include <stdexcept>
//constructor
template <typename Item_Type>
SinglyLinkedList<Item_Type>::SinglyLinkedList() : head(nullptr), tail(nullptr), num_items(0) {}
//destructor
template <typename Item_Type>
SinglyLinkedList<Item_Type>::~SinglyLinkedList() {
    while (!empty()) {
        pop_front();
    }
}

// Function to insert an item at the head of the list
template <typename Item_Type>
void SinglyLinkedList<Item_Type>::push_front(const Item_Type& item) {
    SNode<Item_Type>* newNode = new SNode<Item_Type>(item, head);
    head = newNode; // Always update head to the new node
    if (tail == nullptr) { // If the list was empty
        tail = newNode; 
    }
    num_items++; 
}
// Function to insert an item at the tail of the list
template <typename Item_Type>
    void SinglyLinkedList<Item_Type>::push_back(const Item_Type& item) {
        // Create a new node, pointing next to the current tail 
        
        if (tail != nullptr) {
            tail->next = new SNode<Item_Type>(item,  nullptr); 
             // Update tail to the new node
            tail = tail->next;
            num_items++;
        }
        else 
            push_front(item); //if empty list
        
    }
// Function to delete an item at the head of the list
template <typename Item_Type>
void SinglyLinkedList<Item_Type>::pop_front() {
    if (empty()) 
        throw std::invalid_argument("Attempt to call pop_front() on an empty list");
    
    SNode<Item_Type>* removed_node = head;
    head = head->next;
    delete removed_node;

    if (head == nullptr) // If the list is now empty
        tail = nullptr;
    
    num_items--;
} 
// Function to delete an item at the tail of the list
template <typename Item_Type>
void SinglyLinkedList<Item_Type>::pop_back() {
        // Check if the list is empty
        if (head == nullptr) 
            throw std::invalid_argument("Attempt to call pop_back() on an empty list");
        SNode<Item_Type>* current = head;
        SNode<Item_Type>* temp = current;
        SNode<Item_Type>* removed_node = tail;
        while (current->next != nullptr) {
            temp = current;
            current = current->next ;
        }
        tail = temp;
        delete removed_node; 
        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;
        num_items--;
    } 
// Function to return the item at the head of the list
template <typename Item_Type>
Item_Type SinglyLinkedList<Item_Type>::front() const {
        // Check if the list is empty 
        if (head == nullptr) 
            throw std::invalid_argument("Attempt to call front() on an empty list"); 
        return head->item;
    } 
// Function to return an item at the tail of the list
template <typename Item_Type>
    Item_Type SinglyLinkedList<Item_Type>::back() const {
    // Check if the list is empty 
        if (tail == nullptr) 
            throw std::invalid_argument("Attempt to call front() on an empty list"); 
        return tail->item;
    
    }
// Function to return if list is empty
template <typename Item_Type>
bool SinglyLinkedList<Item_Type>::empty() const {
    return head == nullptr;
}
// Function to insert an item at a certain index
template <typename Item_Type>
    void SinglyLinkedList<Item_Type>::insert(size_t index, const Item_Type& item) {
        // Check if the index is out of range 
        if (index > num_items) { 
            std::cout << "Index out of range, pushed back to " << index << std::endl;
            
        }
        // Check if the list is empty or if the index is zero
        if (head == nullptr || index == 0) {
            push_front(item);
            return;
        } 
        // Create a new node 
        SNode<Item_Type>* newNode = new SNode<Item_Type>(item, nullptr); 
        
        // Traverse the list to find the node at the specified index 
        SNode<Item_Type>* current = head;
        for (int i = 0; i < index - 1; i++) {
            if (current->next == nullptr) {
                push_back(item);
                return;
            } 
            current = current->next; 
        }
        SNode<Item_Type>* new_node = new SNode<Item_Type>(item, current->next);
        current->next = new_node;
    }
// Function to remove an item at a certain index
template <typename Item_Type>
bool SinglyLinkedList<Item_Type>::remove(size_t index) {
        // Check if the index is out of range 
        if (index >= num_items) 
            throw std::out_of_range("Index out of range"); 
        // Check if the list is empty 
        if (empty()) {
            throw std::invalid_argument("Attempt to call remove() on an empty list");  
            return false;
        }
        SNode<Item_Type>*current = head;
        SNode<Item_Type>* previous = nullptr;
    int count = 0;

    // Traverse the list to find the node before the one to remove
    while (current != nullptr) {
        if (count == index) {
            previous->next = current->next; // Bypass the current node
            if (current == tail) { // If removing the tail
                tail = previous; // Update tail to previous
            }
            delete current; // Free memory
            num_items--; // Decrease item count
            return true; 
        }
        previous = current; // Move previous to current
        current = current->next; // Move current to next
        count++;
        }
        return false;
        }
    // Function to find a certain item and returns the index associated with the value
    template <typename Item_Type>
    size_t SinglyLinkedList<Item_Type>::find(const Item_Type& item) {
        if (empty()) {
            throw std::invalid_argument("Attempt to call remove() on an empty list");  
            return -1;
        }
            
        SNode<Item_Type>*current = head;
        size_t index = 0;
            
        
    
        // If key is present in current node, return true
        while (current != nullptr) {
            if (current->item == item)
                return index;
             SNode<Item_Type>*current = head;
             index++;
             current = current->next;
        }
        // Recur for remaining list
        return -1;
        }
// Function to print each element of a list for testing purposes
template <typename Item_Type>
void SinglyLinkedList<Item_Type>::printList() const {
    SNode<Item_Type>* current = head;
    while (current != nullptr) {
        std::cout << current->item << " ";
        current = current->next;
} 
    std::cout << std::endl;
}

//helps to separate .h and .cpp files
template class SinglyLinkedList<int>;
template class SinglyLinkedList<std::string>;
