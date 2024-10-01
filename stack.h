

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>
#include <stdexcept>
#include <stack>
class Stack {
    private:
        std::vector<int> container;
    public:
    // Push an item onto the stack
    void push(const int& item) {
        container.push_back(item);
    }

    // Get the item at the top of the stack
    int& top() {
        if (empty()) {
            throw std::out_of_range("Stack is empty.");
        }
        return container.back();
    }

    const int& top() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty.");
        }
        return container.back();
    }

    // Remove the item at the top of the stack
    void pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty.");
        }
        container.pop_back();
    }

    // Check if the stack is empty
    bool empty() const {
        return container.empty();
    }

    // Get the number of items in the stack
    size_t size() const {
        return container.size();
    }

    // Calculate the average of the items in the stack
    double average() const {
        if (empty()) {
            throw std::runtime_error("Cannot calculate average of an empty stack.");
        }
        double total = 0;
        for (const int i : container)
            total += i;

        return static_cast<double>(total) / static_cast<double>(container.size());
    }

};
#endif //STACK_H
