#ifndef LINKLIST_H
#define LINKLIST_H

class LinkList {

private:
    // structure for a Node
    struct Node {
        int value;        
        struct Node* next;  // pointer to another node
    };

    Node* head; // pointer to the start of the list
    Node* tail; // pointer to the end of the list
    int size;

public:
    LinkList() {
        head = nullptr;
        tail = nullptr;
        size = 0; // embedded size variable in each operation to actively track size
    }

    // Destructor
    ~LinkList();

    void printList() const; // output list
    void appendNode(int); // add node to end
    void prepend(int); //add node to beginning
    void deleteNode(int); // delete the first node that equals the user input
    void insertInOrder(int); // insert new node in order
    void checkSize(); // find list size and return without size variable
    void returnSize(); // return list size using size variable
    void insertAt(int,int); // insert new node at position specified by input, position first, and then value
    void removeAt(int); // delete node at position specified by input
    void findItem(int); // find the first value that equals the input in the list and return the position

    
};
#endif
