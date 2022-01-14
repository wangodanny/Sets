#include <iostream>
using namespace std;

//Setup Node
class Node {
  public:
    string names;
    Node *next;
    Node(){
      next = NULL;
    }
};

class LinkedList {
  Node *head;
  public:
    LinkedList (){
      head = NULL;
    }

  //Function to allow inserting nodes at the start of the list
  void insertNodeHead(string n){
    struct Node *newNode = new Node;
    newNode -> names = n;
    newNode -> next = head;
    head = newNode;
  }

  //Function to allow inserting nodes in the middle of the list
  void insertNodeMid (string n, int p){
    Node *tempVal = new Node();
    tempVal -> names = n;
    if (p == 0) {
      tempVal -> next = head;
      head = tempVal;
    }
    else {
      Node *ptr = head;
      while (p > 1) {
        ptr = ptr -> next;
        --p;
      }
      tempVal -> next = ptr -> next;
      ptr -> next = tempVal;
    }
  }

  void insertNodeEnd(string n){
    Node *tempVal = new Node();
    tempVal -> names = n;
    if (head == NULL){
      head = tempVal;
      //If the list is empty then make the temp value the new head
    }
    else {
      Node *ptr = head; //ptr means pointer (I got confused)
      //If the list is not empty then head to the last node of the list.
      while (ptr -> next != NULL){
        ptr = ptr -> next;
        //ptr now points to the last node and stores the temp address in the next ptr address
      }
      ptr -> next = tempVal;
    }
  }

  //Functions to display all nodes
  void display(){
      if(head == NULL){
          cout<<"We couldn't find any items.";
      }
      struct Node *temp = head;
      while(temp != NULL){
          cout<< temp -> names << ", ";
          temp = temp -> next;
      }
  }

  //Function to allow deleting nodes at the start of the list
  void deleteItemHead(){
    if (head == NULL){
      cout << "We couldn't find any items.";
    }
    cout << head -> names << " has been removed";
    head = head -> next;
  }

  //Function to allow deleting nodes in the middle of the list
  void deleteItemMid(int p) {
    if (head == NULL){
      cout << "We couldn't find any items.";
    }
    else {
      Node *tempVal, *ptr;
      if (p == 0) {
        cout << head -> names << " has been removed";
        ptr = head;
        head = head -> next;
        delete (ptr);
      }
      else {
        tempVal = ptr = head;
        while (p > 0){
          --p;
          tempVal = ptr;
          ptr = ptr -> next;
       }
        cout << ptr -> names << " has been removed";

        tempVal -> next = ptr -> next;
        free(ptr);
      }
    }
  }

  //Function to allow deleting nodes at the end of the list
  void deleteItemEnd() {
    if (head == NULL){
      cout << "We couldn't find any items.";
    }
    else if (head -> next == NULL) {
      cout << head -> names << " has been removed";
      delete(head);
      head = NULL;
    }
    else {
      Node *tempVal = head;
      while (tempVal -> next -> next !=   NULL) {
        tempVal = tempVal -> next;
      }
      cout << tempVal -> next -> names << " has been removed";
    }
  }
};

int main() {
  printf("1 to Insert at the beginning");
	printf("\n2 to Insert at the end");
	printf("\n3 to Insert at mid");
	printf("\n4 to Delete from beginning");
	printf("\n5 to Delete from the end");
	printf("\n6 to Delete from mid");
	printf("\n7 to Display");
	printf("\n0 to Exit");
	
	int choice,p;
  string n;
	LinkedList ll;
	do {
		cout<<"\nEnter Your Choice: ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				cout<<"Enter Name: ";
				cin>>n;
				ll.insertNodeHead(n);
				break;
				
			case 2:
				cout<<"Enter Name: ";
				cin>>n;
				ll.insertNodeEnd(n);
				break;
				
			case 3:
				cout<<"Enter Name: ";
				cin>>n;
				cout<<"Enter Position ( zero-indexed ): ";
				cin>>p;
				ll.insertNodeMid(n,p);
				break;
				
			case 4:
				ll.deleteItemHead();
				break;
				
			case 5:
				ll.deleteItemEnd();
				break;
				
			case 6:
				cout<<"Enter Position ( zero-indexed ): ";
				cin>>p;
				ll.deleteItemMid(p);
				break;
				
			case 7:
				ll.display();
				break;
				
		}
	} while (choice != 0);

}