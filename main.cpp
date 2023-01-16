#include <iostream>
#include "student.h"
#include "node.h"
using namespace std;

/*
Author: Min Kim
Program Description: This is a student list program utilizing a linked list. 
You can add, print, and delete students, and also print the averages of all the gpa's.
Date: 1/27/23
*/

void add(Node* &head, Node* newnode) {//insert and sort
    Node* movingnode;//node pointer to travel through existing nodes
    
    if (head == NULL) {//first node
        cout << "head is null";
        head = newnode;
    }
    else {//node already exists
        cout << "head is not null";
        movingnode = head;//movingnode = very first node
        while (movingnode != NULL) {//move through all existing nodes
            movingnode = movingnode->getNext();
            cout << movingnode->student->id;
            //add(movingnode, newnode);//recursion
        }
        //movingnode->next = newnode;//after traveling through all nodes, set next node to newnode*/
    }
}

void print(Node* n) {
    if (n != NULL) {
        cout << n->getStudent()->id;
        n = n->getNext();
        print(n);//recursion
    }
}
/*
void delet() {

}
void average() {

}
*/
int main(){

    Node* head = NULL;
    char input[10];
    int id = 0;
    bool cont = true;

    while (cont == true) {
        cout << "Add, print, or quit? (add/print/quit): ";
        cin >> input;
        cin.ignore();
        if (strcmp(input, "add") == 0) {//user inputs "add"
            cout << "ID: ";
            cin >> id;
            Student* newstudent = new Student();
            newstudent->id = id;//set newstudent node id to value
            Node* newnode = new Node(newstudent);//put newstudent into new node
            //pass head, newnode
            add(head, newnode);
        }
        else if (strcmp(input, "print") == 0) {//user inputs "print"
            print(head);
        }
        /*else if (strcmp(input, "delete") == 0) {//user inputs "delete"
            delet();
        }*/
        else if (strcmp(input, "quit") == 0) {//user inputs "quit"
            cont = false;
        }
        else {//something else
            cout << "Invalid input." << endl;
        }
    }  
  return 0;
}