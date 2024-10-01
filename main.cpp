#include "assignment.h"
#include "stack.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <stack>
// NAME: Ethan Nguyen

int main() {
    try {
        // Create a SinglyLinkedList object
        SinglyLinkedList<int> list1;
        SinglyLinkedList<std::string> list2;
        // Create a Stack object
        Stack s;
        std::string option1;
        //user chooses for linked list or stack
        while (true) {
            std::cout << "Press L for (Singly Linked) List or S for Stack or Q to Quit\n";
            std::cin >> option1;

            if (option1 == "q" || option1 == "Q") break;

            if (option1 == "L" || option1 == "l") {
                std::string option2;
                int listChoice = 0;
                while (listChoice != 10) {
                    std::cout << "Press S for string list, I for integer list, or Q to quit\n"; //user chooses between a string or integer list
                    std::cin >> option2;

                    if (option2 == "Q" || option2 == "q") break;


                    if (option2 == "I" || option2 == "i") {

                        while (listChoice != 10) {
                            std::cout << "Choose action:\n1. Add to front\n2. Add to back\n3. Delete 1st element\n4. Delete last element\n5. Check 1st element\n6. Check last element\n7. Insert element\n8. Remove element\n9. Find element\n10. Quit\n";
                            std::cin >> listChoice;
                            //user is presented options to choose from
                            if (listChoice == 1) {
                                int element;
                                std::cout << "Enter an integer: ";
                                std::cin >> element;
                                list1.push_front(element); //adds element as the head
                                std::cout << element << " has been added to the front of the integer list.\n";
                            } else if (listChoice == 2) {
                                int element;
                                std::cout << "Enter an integer: ";
                                std::cin >> element;
                                list1.push_back(element); //adds element as the tail
                                std::cout << element << " has been added to the back of the integer list.\n";
                            } else if (listChoice == 3) {
                                list1.pop_front(); //deletes the head
                                std::cout << "1st element has been removed from the front of the integer list.\n";
                            } else if (listChoice == 4) {
                                list1.pop_back(); //deletes the tail
                                std::cout << "Last element has been removed from the integer list.\n";
                            } else if (listChoice == 5) {
                                std::cout << list1.front() << " is the first element of the integer list.\n"; //identifies head
                            } else if (listChoice == 6) {
                                std::cout << list1.back() << " is the last element of the integer list.\n"; //identifies tail
                            } else if (listChoice == 7) {
                                int element;
                                size_t index;
                                std::cout << "Enter an integer to insert: ";
                                std::cin >> element;
                                std::cout << "Enter a valid index: ";
                                std::cin >> index;
                                list1.insert(index, element); //adds element to the index user inputs
                                std::cout << element << " has been added to the integer list at index " << index << "\n";
                            } else if (listChoice == 8) {
                                size_t index;
                                std::cout << "Enter an index to remove the integer: ";
                                std::cin >> index;
                                list1.remove(index); //removes the element associated with the index
                                std::cout << "Removed value at index " << index << "\n";
                            } else if (listChoice == 9) {
                                int element;
                                std::cout << "Enter an integer to find the index: ";
                                std::cin >> element;
                                size_t index = list1.find(element); //finds index of element
                                if (index != static_cast<size_t>(-1)) {
                                    std::cout << element << " has been found in the integer list at index " << index << "\n"; //error message
                                } else {
                                    std::cout << element << " has not been found in the integer list.\n";
                                }
                            } else {
                                std::cout << "Invalid choice, try again.\n";
                            }
                            if (list1.empty() == false)
                                list1.printList(); //testing
                        }
                    } else if (option2 == "S" || option2 == "s") {

                        while (listChoice != 10) {
                            std::cout << "Choose action:\n1. Add to front\n2. Add to back\n3. Delete 1st element\n4. Delete last element\n5. Check 1st element\n6. Check last element\n7. Insert element\n8. Remove element\n9. Find element\n10. Quit\n";
                            std::cin >> listChoice;
                            //for string linked list, all options are the same with the same functions
                            if (listChoice == 1) {
                                std::string element;
                                std::cout << "Enter a string: ";
                                std::cin >> element;
                                list2.push_front(element);
                                std::cout << element << " has been added to the front of the string list.\n";
                            } else if (listChoice == 2) {
                                std::string element;
                                std::cout << "Enter a string: ";
                                std::cin >> element;
                                list2.push_back(element);
                                std::cout << element << " has been added to the back of the string list.\n";
                            } else if (listChoice == 3) {
                                list2.pop_front();
                                std::cout << "1st element has been removed from the front of the string list.\n";
                            } else if (listChoice == 4) {
                                list2.pop_back();
                                std::cout << "Last element has been removed from the string list.\n";
                            } else if (listChoice == 5) {
                                std::cout << list2.front() << " is the first element of the string list.\n";
                            } else if (listChoice == 6) {
                                std::cout << list2.back() << " is the last element of the string list.\n";
                            } else if (listChoice == 7) {
                                std::string element;
                                size_t index;
                                std::cout << "Enter a string to insert: ";
                                std::cin >> element;
                                std::cout << "Enter a valid index: ";
                                std::cin >> index;
                                list2.insert(index, element);
                                std::cout << element << " has been added to the string list at index " << index << "\n";
                            } else if (listChoice == 8) {
                                size_t index;
                                std::cout << "Enter an index to remove the string: ";
                                std::cin >> index;
                                list2.remove(index);
                                std::cout << "Removed value at index " << index << ".\n";
                            } else if (listChoice == 9) {
                                std::string element;
                                std::cout << "Enter a string to find the index: ";
                                std::cin >> element;
                                if (list2.find(element) != -1) {
                                    std::cout << element << " has been found in the string list at index " << list2.find(element) << "\n";
                                } else {
                                    std::cout << element << " has not been found in the string list.\n";
                                }
                            } else {
                                std::cout << "Invalid choice, try again.\n";
                            }
                        }
                    } else {
                        std::cout << "Invalid option, try again.\n";
                    }
                    if (list2.empty() == false)
                        list2.printList();
                }
            } else if (option1 == "S" || option1 == "s") {
                while (true) {
                    int stackOption;
                    std::cout << "Stack Menu:\n1. Add element to top\n2. Delete topmost element\n3. Find topmost element\n4. Find average value\n5. Quit\n";
                    std::cin >> stackOption;
                    //presents options to manipulate stack
                    if (stackOption == 1) {
                        int element;
                        std::cout << "Enter an integer: ";
                        std::cin >> element;
                        s.push(element); //adds to the top of stack
                        std::cout << element << " has been added to the stack.\n";
                    } else if (stackOption == 2) {
                        s.pop(); // Call pop to remove the topmost element
                        std::cout << "Topmost element has been removed from the stack.\n";
                    } else if (stackOption == 3) {
                        std::cout << s.top() << " is the topmost element.\n"; //identifies top of stack
                    } else if (stackOption == 4) {
                        std::cout << s.average() << " is the average value of the stack.\n"; //finds average of all values in stack
                    } else if (stackOption == 5) {

                    break;

                } else { continue; }
                    
                    }
            }
        }




        }
        //error messages in case user runs into an error
    catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl; // Handle runtime errors
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << std::endl; // Handle out of range errors
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch(...) {
        std::cerr << "Unknown error." << std::endl;
    }
    /* Test:
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
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top item: " << s.top() << std::endl; // Outputs: 30
    std::cout << "Average: " << s.average() << std::endl; // Outputs: 20.0

    s.pop();
    std::cout << "Top item after pop: " << s.top() << std::endl; */
  return 0;
}
