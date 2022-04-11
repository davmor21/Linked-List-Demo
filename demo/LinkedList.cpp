#include <iostream>
#include "LinkedList.h"
using namespace std;

/* printList traverses the list and displays the 
** value of each node
*/
void LinkList::printList() const {
    Node* nodePtr;  // Node to traverse the list

    // Start at the beginnging of the list
    nodePtr = head;

    // Traverse the list until nodePtr is at the end
    while (nodePtr) {
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;  //advance to the next node
    }
}


/* appendNode creates a new Node and then adds the node
** at the end of the list
*/
void LinkList::appendNode(int num) {

   Node* newNode;  // pointer for node to append

   // Creat a new Node and store the value
   newNode = new Node;
   newNode->value = num;
   newNode->next = nullptr;
   size++;

   if (!head) {        //if the list is empty, the new Node becomes the head and tail
       head = newNode;
       tail = newNode;
       
   }
   else {                     //otherwise, add the node to the end of the list
      tail->next = newNode;  //link the end of the list to the new node
      tail = newNode;
       //make the new node the new tail
    }
}

/* prepend creates a new Node and then adds the node
** at the front of the list
*/
void LinkList::prepend(int num) {
    Node* newNode;  // pointer for node to append

  // Creat a new Node and store the value
    newNode = new Node;
    newNode->value = num;
    newNode->next = nullptr;
    size++;

    if (!head) {        //if the list is empty, the new Node becomes the head and tail
        head = newNode;
        tail = newNode;
        
    }
    else {                     
        newNode->next = head;
        head = newNode;
        
    }
}


/*  insertInOrder will add a node based on its sorted value
 ** assumes the List is sorted
 */
void LinkList::insertInOrder(int num) {
    Node* newNode;  // pointer for node to append
    Node* nodePtr;
    Node* previous;

    // Creat a new Node and store the value
    newNode = new Node;
    newNode->value = num;
    newNode->next = nullptr;
    size++;

    if (!head) {        //if the list is empty, the new Node becomes the head and tail
        head = newNode;
        tail = newNode;
       

    }
    else {
        nodePtr = head;
        previous = nullptr;

        while (nodePtr != nullptr && nodePtr->value < num) {
            previous = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (!previous) { // is it the first node in the list
            newNode->next = nodePtr;
            head = newNode;
        }
        else {
            previous->next = newNode;
            newNode->next = nodePtr;
            if (!nodePtr) {             // is it the last thing in the list
                tail = newNode;
            }
        }

        

    }
}


/* deleteNode traverses the list searching for a value
** if the value is found, delete that node
*/
void LinkList::deleteNode(int num) {
   Node* nodePtr;    // Node for travrsing the list
   Node* previous;   // Node for tracking the previous node in the list 

   nodePtr = head;  //Set the traversing pointer to the head of the list
   size--;
   if (!head) {       //if the list is empty, stop
       return;
   }
   else if (head->value == num) {   //The Node is the first value in the list
      nodePtr = head->next;         //Set head to the next item in the list
      if (head == tail)             //if the node is the only item in the list
          tail = nullptr;           //set the tail to null
      delete head;
      head = nodePtr;
   }
   else {
      // Traverse the list until the number to delete is found 
      previous = head;
      while (nodePtr != nullptr && nodePtr->value != num) {
        previous = nodePtr;
        nodePtr = nodePtr->next;
      }
     
      // if the value was found (we are not at the end of list), delete the node
      if (nodePtr) {
         previous->next = nodePtr->next; //connect the previous node to the one after the node to delete

         if (nodePtr == tail)     //if the item is the last node
             tail = previous;     //move the tail to the previous node

         delete nodePtr;          //delete the node  
       }
   }
}

/* The destructor traverses the list and deletes each node
*/
LinkList::~LinkList() {
   Node* nodePtr;   // Node for travrsing the list
   Node* nextNode;  // Node for tracking the next node in the list
   size = 0;
   //Set the traversing pointer to the head of the list
   nodePtr = head;

   // Traverse the list until at the end 
   while (nodePtr) {
      nextNode = nodePtr->next;  //Save pointer to next Node 
      delete nodePtr;            //Delete the current node
      nodePtr = nextNode;        //Move traversing pointer to the next Node
      
   }
}
void LinkList::returnSize() { // each operation includes the size integer
    cout << size << endl;
}

 // /* 
void LinkList::checkSize() { // if you want a separate program to detect size, I chose a size variable because of preference but this is an option as well
    Node* curNode;
    int counter = 0;
    curNode = head;
    while (curNode != NULL) {
        counter++;
        curNode = curNode->next;
    }
    cout << counter << endl;
}
// */

  void LinkList::insertAt(int pos, int newVal) {
    Node* newNode = new Node;
    newNode->value = newVal;
    newNode->next = NULL;
    Node* nodePtr = head;
    Node* previous = head;
    
    if (pos<1 || pos > size + 1) { // check if the node actually has a spot to be moved to
        cout << "Invalid position!" << endl;
    }
    // if so 
    else {
        while (pos--) { // subtract until pos is 0
            if (pos == 0) { // if the pos is found
                previous->next = newNode; // previous points to newNode 
                newNode->next = nodePtr;  // newNode points to the previous ptr in the chosen position

            }
        
            else{
                previous = nodePtr; // traverse the list
                nodePtr = nodePtr->next;

            }
        }
    }
   
}
  void LinkList::removeAt(int pos) { // traverse the list to the position in the list and delete the node holding it
      Node* nodePtr = head;
      Node* previous = head;
      if (pos<1 || pos > size + 1) { // if there isn't a list or if the position isn't available due to size
          cout << "Invalid position!" << endl;
      }
      else {
          while (pos--) { // subtract until the pos variable equals 0, as its going it moves previous and nodePtr to make sure they are traversing with pos
              if (pos == 0) {
                  previous->next = nodePtr->next;
                  delete nodePtr;


              }

              else { // move to next item in the list, previous holding the previous item to make sure we can change its point when the selected variable gets deleted
                  previous = nodePtr;
                  nodePtr = nodePtr->next;

              }
          }

      }
  }
  void LinkList::findItem(int item) { // find an item in the list and return the position
      Node* nodePtr = head;  // start at first node
      Node* previous = head; // start at first node
      int counter = 1; 
      if (!head) { // if there is no list
          return;
      }
      else if (head->value == item) { // if it is the first item in the list
          cout << "Number was at position " << counter << endl;
      }
      else {
          while (nodePtr != nullptr && nodePtr->value != item) { // increase the counter to match the position until the item is found
              counter++;
              previous = nodePtr;
              nodePtr = nodePtr->next;
          }
          cout << "Number was at position " << counter << endl; // after counter is finalized, return the counter as the position

      }
  }

    



