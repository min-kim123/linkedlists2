#include <iostream>
#include <iomanip>//include for setprecision thing
#include "student.h"
#include "node.h"
using namespace std;
/*
Author: Min Kim
Program Description: This is a student list program utilizing a basic linked list. 
You can add, print, and delete students, and also print the averages of all the gpa's.
Date: 1/27/23
*/

void add(Node* n, Node* newnode) {//done
    if (n->getNext() != NULL) {//one or more node IN FRONT of n
        if (newnode->getStudent()->getID() >= n->getNext()->getStudent()->getID()) {
            n = n->getNext();
            add(n, newnode);
        }
        else {
            Node* temp = n->next;
            n->next = newnode;
            newnode->next = temp;
        }
    }
    else {//there is only one node from the beginning/ went through all existing nodes and there is only last one left to compare
        if (newnode->getStudent()->getID() >= n->getStudent()->getID()) {//newnode is greater or equal
            Node* temp = n->next;
            n->next = newnode;
            newnode->next = temp;
        }
    }
}

void print(Node* n) {//done
    cout << fixed << setprecision(2);//for gpa to have 2 decimal places
    if (n != NULL) {
        cout << "---------------------" << endl;
        cout << "Name: " << n->getStudent()->getFirst() << " " << n->getStudent()->getLast() << endl;
        cout << "ID: " << n->getStudent()->getID() << endl;
        cout << "GPA: " << n->getStudent()->getGPA() << endl;
        n = n->getNext();
        print(n);//recursion
    }
}

void deleet(Node* n, int id) {//done
    Node* h = n;
    if (id == n->getNext()->getStudent()->id) {//if NEXT node is equal
        Node* temp = n->next;
        n->next = n->next->next;
        delete temp;
    }
    else {
        n = n->getNext();
        deleet(n, id);
    }
}

void average(Node* n, float total, int count) {//done
    cout << fixed << setprecision(2);//for gpa to have 2 decimal places
    if (n->getNext() != NULL) {
        n = n->getNext();
        total = total + n->getStudent()->getGPA();
        count++;
        average(n, total, count);
    }
    else {
        cout << "Average GPA: " << total/count << endl;
    }
}

int main() {
    Node* head = NULL;
    char input[10];
    bool cont = true;

    char firstname[20];
    char lastname[20];
    int id = 0;
    float gpa;

    while (cont == true) {
        cout << "Add, print, delete, average, or quit? (add/print/delete/average/quit): ";
        cin >> input;
        cin.ignore();
        if (strcmp(input, "add") == 0) {//user inputs "add"
            cout << "First Name: ";
            cin >> firstname;
            cin.ignore();
            cout << "Last Name: ";
            cin >> lastname;
            cin.ignore();
            cout << "ID: ";
            cin >> id;
            cout << "GPA" ;
            cin >> gpa;            

            Student* newstudent = new Student();
            newstudent->setFirst(firstname);
            newstudent->setLast(lastname);
            newstudent->setID(id);//set newstudent node id to value
            newstudent->setGPA(gpa);
            Node* newnode = new Node(newstudent);//put newstudent into new node

            if (head == NULL) {
                head = newnode;
            }
            else if (newnode->getStudent()->id <= head->getStudent()->id){//if it is smaller than first node (head) it is a special case since head is changing values
                newnode->next = head;
                head = newnode;
            }
            else {
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
            else if (id == head->student->id) {//when the first one is being deleted, special case since head is being changed.
                Node* temp = head;
                if (head->next == NULL) {//there is only one node
                    head = NULL;
                }
                else {
                    cout << "else  changing head" << endl;
                    head = head->next;
                    delete temp;
                }
            }
            else {
                deleet(head, id);
            }
        }
        else if (strcmp(input, "average") == 0) {//user inputs "average"
            float total = head->getStudent()->getGPA();
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