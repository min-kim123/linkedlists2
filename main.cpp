#include <iostream>
#include <iomanip>//include for setprecision thing
#include "student.h"
#include "node.h"
using namespace std;
/*
Author: Min Kim
Program Description: This is a student list program utilizing a linked list. 
You can add, print, and delete students, and also print the averages of all the gpa's.
Date: 1/27/23
*/

void add(Node* head, Node* newnode) {//insert done, working on sort
    if (head->getNext() != NULL) {
        head = head->getNext();
        //cout << head->getStudent()->id;//test to see if it moves through all previous inputs
        add(head, newnode);//recursion, move through all existing nodes
    }
    else {//only accessed after recursion
        head->next = newnode;//for some reason this only works if it's "next" and not "getNext()"
    }
}

void print(Node* n) {//done
    cout << fixed << setprecision(2);//for gpa to have 2 decimal places
    if (n != NULL) {
        cout << n->getStudent()->id;
        n = n->getNext();
        print(n);//recursion
    }
}

void deleet(Node* head, int id) {//doesn't work if it's the first one.
//make a temp pointer
    if (id == head->getStudent()->id) {//for the first one- just delete it no reconnecting
    }
    else if (id == head->getNext()->getStudent()->id) {//if NEXT node is equal
        //delete head;//pointer being freed was not allocated
        head->next = head->getNext()->getNext();//reconnecting nodes after deletion
    }
    else {
        head = head->getNext();
        deleet(head, id);
    }
}

void average(Node* head, float total, int count) {//done
    cout << fixed << setprecision(2);//for gpa to have 2 decimal places
    if (head->getNext() != NULL) {
        head = head->getNext();
        total = total + head->getStudent()->id;//CHANGE TO GPA
        count++;
        average(head, total, count);
    }
    else {
        cout << "Average GPA: " << total/count << endl;
    }
}

int main(){

    Node* head = NULL;
    char input[10];
    int id = 0;
    bool cont = true;

    while (cont == true) {
        cout << "Add, print, delete, average, or quit? (add/print/delete/average/quit): ";
        cin >> input;
        cin.ignore();
        if (strcmp(input, "add") == 0) {//user inputs "add"
            cout << "ID: ";
            cin >> id;
            Student* newstudent = new Student();
            newstudent->id = id;//set newstudent node id to value
            Node* newnode = new Node(newstudent);//put newstudent into new node
            //pass head, newnode

            if (head == NULL) {
                cout << "head is null";
                head = newnode;
                cout << head->getStudent()->id;
            }
            else {
                cout << "head is not null" << endl;
                add(head, newnode);
            }
        }
        else if (strcmp(input, "print") == 0) {//user inputs "print"
            print(head);
        }
        else if (strcmp(input, "delete") == 0) {//user inputs "delete"
            cout << "ID: ";
            cin >> id;
            if (head == NULL) {
                cout << "Empty list. Nothing to delete" << endl;
            }
            else {
                deleet(head, id);
            }
        }
        else if (strcmp(input, "average") == 0) {//user inputs "average"
            float total = head->getStudent()->id;
            int count = 1;
            average(head, total, count);
        }
        else if (strcmp(input, "quit") == 0) {//user inputs "quit"
            cont = false;
        }
        else {//something else
            cout << "Invalid input." << endl;
        }
    }  
  return 0;
}