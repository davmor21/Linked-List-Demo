#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	LinkList list;  //Declare a LinkList object
	int num, num2;
	char choice;  //user menu selection


	cout << "Welcome to the Linked List Demo" << endl << endl;

	do {
		//display menu
		cout << endl;
		cout << "1. Append a node" << endl;
		cout << "2. Delete a node" << endl;
		cout << "3. Print the list" << endl;
		cout << "4. Prepend" << endl;
		cout << "5. Insert a node in order" << endl;
		cout << "6. Check the size of the list" << endl;
		cout << "7. Insert a node at a position" << endl;
		cout << "8. Remove a node at a position" << endl;
		cout << "9. Find an item in the list" << endl;
		cout << "0. Quit" << endl;

		cout << endl << "Enter your selection: ";
		cin >> choice;

		//perform the selected menu option
		switch (choice) {

		case '1':
			cout << "Enter a number to append to the list: ";
			cin >> num;
			list.appendNode(num);
			break;
		case '2':
			cout << "Enter a number to delete from the list: ";
			cin >> num;
			list.deleteNode(num);
			break;
		case '3':
			list.printList();
			break;
		case '4':
			cout << "Enter a number to prepend to the list: ";
			cin >> num;
			list.prepend(num);
			break;
		case '5':
			cout << "Enter a number to insert to the list: ";
			cin >> num;
			list.insertInOrder(num);
			break;
		case '6':
			cout << "The list size is : ";
			list.returnSize();
			break;
		case '7':
			cout << "Enter a position and number to add to the list: ";
			cin >> num;
			cin >> num2;
			list.insertAt(num, num2);
			break;
		case '8':
			cout << "Enter a position to delete from the list: ";
			cin >> num;
			list.removeAt(num);
			break;
		case '9':
			cout << "Enter a number to find from the list: ";
			cin >> num;
			list.findItem(num);
			break;
		
		case '0':
			break;
		default:
			cout << "That is not a valid option, please try again." << endl;
		} // of of switch
	} while (choice != '0');

	cout << endl << "Goodbye" << endl << endl;
	return 0;
}