#include <iostream>
#include <vector>
#include <stdexcept>

class KStacks {
private:
    int n; // Total size of array
    int k; // Number of stacks
    std::vector<int> arr; // Array to hold the k stacks
    std::vector<int> top; // Array to hold the indices of the top elements of the k stacks
    std::vector<int> next; // Array to hold the next entry in all stacks and free list

    int free; // To store the beginning index of the free list

public:
    KStacks(int k, int n) : k(k), n(n), arr(n), top(k, -1), next(n) {
        // Initialize all spaces as free
        for (int i = 0; i < n - 1; ++i) {
            next[i] = i + 1;
        }
        next[n - 1] = -1; // -1 indicates end of free list
        free = 0; // First free index
    }

    // Check if there is space available
    bool isFull() {
        return free == -1;
    }

    // Check if a stack is empty
    bool isEmpty(int sn) {
        return top[sn] == -1;
    }

    // Push an item to stack number 'sn'
    void push(int item, int sn) {
        if (isFull()) {
            throw std::overflow_error("Stack Overflow");
        }

        int i = free; // Get the first free index

        // Update free to index of the next slot in free list
        free = next[i];

        // Update next of i to current top of stack number 'sn'
        next[i] = top[sn];

        // Update top to new value
        top[sn] = i;

        // Put the item in array
        arr[i] = item;
    }

    // Pop an item from stack number 'sn'
    int pop(int sn) {
        if (isEmpty(sn)) {
            throw std::underflow_error("Stack Underflow");
        }

        // Find index of top item in stack number 'sn'
        int i = top[sn];

        // Update top to previous node in stack number 'sn'
        top[sn] = next[i];

        // Add this slot to free list
        next[i] = free;
        free = i;

        // Return the previous top item
        return arr[i];
    }

    // Peek at the top item of stack number 'sn'
    int peek(int sn) {
        if (isEmpty(sn)) {
            throw std::underflow_error("Stack Underflow");
        }
        return arr[top[sn]];
    }
};

int main() {
    int k = 3, n = 10;
    KStacks ks(k, n);

    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);

    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    std::cout << "Popped element from stack 2 is " << ks.pop(2) << std::endl;
    std::cout << "Popped element from stack 1 is " << ks.pop(1) << std::endl;
    std::cout << "Popped element from stack 0 is " << ks.pop(0) << std::endl;

    return 0;
}