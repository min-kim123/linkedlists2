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


void add(Node* head, Node* newnode) {//done
    if (head->getNext() != NULL) {//one or more node IN FRONT of head
        if (newnode->getStudent()->id >= head->getNext()->getStudent()->id) {
            head = head->getNext();
            add(head, newnode);
        }
        else {
            Node* temp = head->next;
            head->next = newnode;
            newnode->next = temp;
        }
    }
    else {//there is only one node from the beginning/ went through all existing nodes and there is only last one left to compare
        if (newnode->getStudent()->id >= head->getStudent()->id) {//newnode is greater or equal
            Node* temp = head->next;
            head->next = newnode;
            newnode->next = temp;
        }
    }
}

void print(Node* n) {//done
    cout << fixed << setprecision(2);//for gpa to have 2 decimal places
    if (n != NULL) {
        cout << "---------------------" << endl;
        cout << "ID: " << n->getStudent()->id << endl;
        n = n->getNext();
        print(n);//recursion
    }
}

void deleet(Node* head, int id) {//DOESNT WORK.
    if (id == head->getNext()->getStudent()->id) {//if NEXT node is equal
        //add code here to actually delete//pointer being freed was not allocated
        head->next= NULL;
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

int main() {
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
            if (head == NULL) {
                cout << "head is null";
                head = newnode;
                cout << head->getStudent()->id;
            }
            else if (newnode->getStudent()->id <= head->getStudent()->id){//if it is smaller than first node (head) it is a special case since head is changing values
                newnode->next = head;
                head = newnode;
            }
            else {
                cout << "head is not null" << endl;
                add(head, newnode);
            }
        }
        else if (strcmp(input, "print") == 0) {//user inputs "print"
            print(head);
            cout << "---------------------" << endl;
        }
        else if (strcmp(input, "delete") == 0) {//user inputs "delete"
            cout << "ID: ";
            cin >> id;
            if (head == NULL) {
                cout << "Empty list. Nothing to delete" << endl;
            }
            else if (id == head->getStudent()->id){//when the first one is being deleted, special case since head is being changed.
                head = head->getNext();
                //add code to actually delete head

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
        cout << "HEAD: " << head->getStudent()->id << endl;
    }  
  return 0;
}