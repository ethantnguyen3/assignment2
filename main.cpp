#include "assignment.h" 
#include <iostream>
#include <string>
#include <stdexcept>
//NAME: Ethan Nguyen 

int main() {
    // Create a SinglyLinkedList object 
   
    SinglyLinkedList<int> list; 
    // Insert elements at the front of the list 
    list.push_front(1); 
    list.push_front(2);
    list.insert(1, 5);
    list.push_front(3); 
    list.printList();
   
    list.remove(1);
    //std::cout << list.front() << std::endl;
    //std::cout << list.back() << std::endl;
    list.printList();
   
    list.pop_front();
    list.printList();
    
    list.pop_back();
    list.printList();
    
    list.push_back(0); 
    list.printList();
    std::cout << list.find(5);
    // Insert elements at the back of the list
  return 0;
}
