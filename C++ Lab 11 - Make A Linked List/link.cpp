/***************************************
Make A Linked List
Author: Taylor Reeves-Chavez
Date Completed: 3/9/2025
Description: A program that demostrates how a linked list works
***************************************/

#include <iostream>
using namespace std;

class SList
{
    // Note: Do not modify any code in the private section!
    private:

    // Node definition
    struct Node
    {
        Node* next;
        string data;

        Node(string d, Node* n) : data(d), next(n){}
    };

    // Node pointer to head (front) of list
    Node* head_;

    public:

    // Constructor
    // Initializes head to null
    SList() {

        head_ = nullptr;

    }

    // Ruturn true if the list is empty, otherwise false
    bool empty() {

        if (head_ == nullptr) {

            return true;

        } else {

            return false;

        }

    }

    // Return the number of nodes in the list
    int size() {

        int count = 0;
        Node* iter = head_;

        while (iter != nullptr) {

            count += 1;
            iter = iter->next;

        }

        return count;

    }

    // Create a new node to contain value and insert 
    // the node to the front of the list
    void pushFront(string value) {

        Node* front = new Node(value, head_);
        head_ = front;

    }

    // Create a new node to conatin value and insert
    // the node to the back of the list
    void pushBack(string value) {

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
    string at(int index) {

        Node* iter = head_;

        for (int i = 0; i < index; i++) {

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
    string popFront() {

        Node* temp = head_;
        head_ = head_->next;

        string tempD = temp->data;
        delete temp;

        return tempD;

    }

    // Remove the node at the specified list index.
    // Return true if the node at the specified index
    // could be removed, otherwise false
    bool removeAt(int index) {

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

            for (int i = 0; i < index - 1; i++) {

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
    ~SList() {

        clear();
    }
};



int main()
{
    cout<<"Starting program...\n\n";

    {
        SList list;

        cout<<"The size of the list is: "<<list.size();

        cout<<"\n\nPushing strings into the list...\n\n";
        list.pushFront("This should end up as index 2 in the list");
        list.pushFront("This should end up as index 1 in the list");
        list.pushBack("This should end up as index 3 in the list");
        list.pushBack("This should end up as index 4 in the list");
        list.pushFront("This should end up as index 0 in the list");

        cout<<"The size of the list is: "<<list.size();

        cout<<"\n\nThe string at index 1 is \""<<list.at(1)<<"\"\n";
        cout<<"The string at index 3 is \""<<list.at(3)<<"\"\n";

        cout<<"\nClearing the list...\n\n";
        list.clear();


        cout<<"Pushing four strings into the list...\n\n";
        list.pushBack("item 1");
        list.pushBack("item 2");
        list.pushBack("item 3");
        list.pushBack("item 4");

        if (list.removeAt(2))
        {
            cout<<"Successfully removed string at index 2 from list\n";
        }

        if (list.removeAt(3))
        {
            cout<<"Successfully removed string at index 3 from list\n";
        }

        cout<<"\nThe size of the list is: "<<list.size();

        cout<<"\n\nItems in the list:\n";
        while (!list.empty())
        {
            cout<<list.popFront()<<endl;
        }
    }

    cout<<"\nExiting program...\n";

    return 0;
}