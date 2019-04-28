// unit5-6Prog.cpp : written by Bryan Smith
#include <iostream>
using namespace std;
struct AddressNode {
public:
	string name;
	AddressNode* next = NULL;
	AddressNode* prev = NULL;
};
class ABook {
private: 
	AddressNode *topPtr, *tail, *prev, *next, *current;
public:
	int size;
	ABook() { //empty constructor
		topPtr = NULL;
		tail = NULL;
		prev = NULL;
		next = NULL;
		current = NULL;
	}
	~ABook() { //descructor will destroy the list
		AddressNode* temp = topPtr;
		while (topPtr != NULL) {
			temp = topPtr;
			topPtr = topPtr->next;
			delete temp;
		}
	}
	void Insert(string name) { //insert new node at beginning
		size++;
		AddressNode* NewNode = new AddressNode();
		NewNode->name = name;
		NewNode->prev = NULL;
		NewNode->next = topPtr;
		if (topPtr != NULL) {
			topPtr->prev = NewNode;
		}
		topPtr = NewNode;
	}
	void Display() { //print list
		AddressNode* ptr;
		ptr = topPtr;
		int sizeCpy = size;
		while (sizeCpy != 0) {
			cout << ptr->name << "\n";
			ptr = ptr->next;
			sizeCpy--;
		}
	}
	void SortedInsert(string name) {
		size++;
		AddressNode* temp = new AddressNode();
		if (topPtr == NULL) {  //if list is empty, create node
			temp->name = name;
			temp->prev = NULL;
			temp->next = topPtr;
			topPtr = temp;
			return;
		}
		else {  
			if (name < topPtr->name) {  //if name should be inserted at front
				temp->name = name;
				temp->prev = NULL;
				temp->next = topPtr;
				if (topPtr != NULL) {
					topPtr->prev = temp;
				}
				topPtr = temp;
				return;
			}
			while (topPtr->next != NULL) {
				if (name > topPtr->next->name) {
					temp->next = topPtr->next;
				}
				else {
					temp->name = name; //insert when name is less than next name
					temp->next = topPtr->next;
					topPtr->next = temp;
					return;
				}
			}
			if (name > topPtr->name) { //insert at end if need be
				AddressNode* node = new AddressNode();
				node->name = name;
				node->prev = topPtr;
				node->next = NULL;
				topPtr->next = node;
				topPtr = node;
			}
		}
	}
	void Remove(string name) {
		size--;
		AddressNode* temp = topPtr;
		while (name.compare(temp->name) != 0 && temp) { //find match
			temp = temp->next;
		}
		if (temp) { 
			if (temp->prev == NULL) { //beginning node
				topPtr = topPtr->next;
			}
			//middle of list
			if (temp->next) { 
				temp->next->prev = temp->prev;
			}
			if (temp->prev) {
					temp->prev->next = temp->next;
				}
			if (!temp->next) { //end of list
				
				temp->prev->next == NULL;
			}
			cout << "Deleted " << temp->name << "\n";
			delete temp; //delete node
		}
	}
};
int main()
{
		ABook *book = new ABook();
		book->Insert("Precious");
		book->SortedInsert("Ken");
		book->SortedInsert("Eileen");
		book->SortedInsert("Frank");
		book->Display();
		book->Remove("Eileen");
		book->Remove("Precious");
		book->Remove("Ken");
		book->Remove("Frank");
		book->Display();
		system("PAUSE");
}