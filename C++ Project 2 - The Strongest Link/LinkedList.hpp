#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <stdexcept>

template <typename T>
class LinkedList
{
    private:

    // Node definition
    struct Node
    {
        Node* next;
        T data;

        Node(T d, Node* n) : data(d), next(n){}

    }* head_;

    public:

    // Constructor
    // Initializes head to null
    LinkedList() : head_(nullptr){}

    // Ruturn true if the list is empty, otherwise false
    bool empty() {

        if (head_ == nullptr) {

            return true;

        } else {

            return false;

        }

    }

    // Return the number of nodes in the list
    size_t size() {

        size_t count = 0;
        Node* iter = head_;

        while (iter != nullptr) {

            count += 1;
            iter = iter->next;

        }

        return count;

    }

    // Create a new node to contain value and insert 
    // the node to the front of the list
    void pushFront(T value) {

        Node* front = new Node(value, head_);
        head_ = front;

    }

    // Create a new node to conatin value and insert
    // the node to the back of the list
    void pushBack(T value) {

        Node* back = new Node(value, nullptr);
        Node* iter = head_;

        if (head_ == nullptr) {

            head_ = back;

        } else {

            while (iter->next != nullptr) {

                iter = iter->next;
    
            }
    
            iter->next = back;

        }

    }

    // Retrieve the node value at the specified list index.
    // Note: Your implementation may assume that the value
    // passed into the index parameter is within the range
    // of the linked list size
    T at(size_t index) {

        Node* iter = head_;

        for (size_t i = 0; i < index; i++) {

            iter = iter->next;

        }

        return iter->data;

    }

    // Remove the head node in the list such that 
    // the second node in the list should become 
    // the new head node. Then return the previous 
    // head node's value.
    // Note: Your implementation may assume that the
    // size of the linked list is greater than zero
    T popFront() {

        Node* temp = head_;
        head_ = head_->next;

        T tempD = temp->data;
        delete temp;

        return tempD;

    }

    // Remove the node at the specified list index.
    // Return true if the node at the specified index
    // could be removed, otherwise false
    bool removeAt(size_t index) {

        Node* iter = head_;
        Node* temp;
        
        if (index >= size()) {

            return false;

        } 
        
        if (index == 0) {

            temp = head_;
            head_ = temp->next;
            delete temp;
            return true;

        } else if (index > 0) {

            for (size_t i = 0; i < index - 1; i++) {

                iter = iter->next;
    
            }
    
            temp = iter->next;
    
            iter->next = iter->next->next;
            delete temp;
            return true;

        } else {

            return true;

        }
        
    }

    // Remove all nodes in the list
    void clear() {

        while (head_ != nullptr) {

            Node* temp = head_;
            head_ = head_->next;
            delete temp;
            
        }

    }

    // Destructor
    // Remove any remaining nodes in the list
    ~LinkedList() {

        clear();

    }

    class Iterator
    {
        private:
        Node* current_;

        public:
        Iterator(Node* head) : current_(head){}

        // Get the address of current node's data
        T* current() {

            if (current_ == nullptr) {

                return nullptr;

            }

            return &current_->data;

        }

        // Move to the next node
        void next() {
            if (current_ != nullptr) {

            current_ = current_->next;

            }
        }

        // Return false if no node is next, otherwise true
        bool hasNext() {

            return current_ != nullptr;

        }

    };

    // Return a new Iterator object 
    Iterator generateIterator() {

        return Iterator(head_);

    }
};

#endif