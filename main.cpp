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

void add(Node* &head, Node* newnode) {//insert done, working on sort
//for head:
//2 in front- works like regular
//1 in front- getnext getnext would be null
//0 in front (end of the list)- have to check if head is greater or not

//just redo add. does not make sense.
    if (head->getNext() != NULL) {//one or more node IN FRONT of head
        if ((head->getStudent()->id <= newnode->getStudent()->id) && (head->getNext()->getStudent()->id >= newnode->getStudent()->id)) {
            head->next = newnode;
        }
        else {
            head = head->getNext();
            add(head, newnode);
        }
    }
    else {//there is only one node.
        cout << "there is only one node" << endl;
        if (newnode->getStudent()->id >= head->getStudent()->id) {//newnode is greater or equal
            cout << "newnode is greater" << endl;
            head->next = newnode;
        }
        else {//newnode is less
            cout << "newnode is less" << endl;
            newnode->next = head;
        }
    }
}


/*
    if (head->getNext() != NULL) {//one or more node IN FRONT of head
    
        if (head->getNext()->getNext() != NULL) {//two or mode
            if ((head->getNext()->getStudent()->id <= newnode->getStudent()->id) && (head->getNext()->getNext()->getStudent()->id >= newnode->getStudent()->id)) {
                head->next = newnode;
            }
            else {
                head = head->getNext();
                add(head, newnode);
            }
        }
        else {
            if (newnode->getStudent()->id <= head->getNext()->getStudent()->id) {
                head->next = newnode;
            }
            else {
                head->next->next = newnode;
            }
        }
    }
    else {//there is only one node.
        if (newnode->getStudent()->id >= head->getStudent()->id) {//newnode is greater or equal
            head->next = newnode;
        }
        else {//newnode is less
            newnode->next = head;
        }
    }
*/

void print(Node* n) {//done
    cout << fixed << setprecision(2);//for gpa to have 2 decimal places
    if (n != NULL) {
        cout << "---------------------" << endl;
        cout << "ID: " << n->getStudent()->id << endl;
        n = n->getNext();
        print(n);//recursion
    }
}

void deleet(Node* &head, int id) {//works, just need to actually delete
    if (id == head->getStudent()->id) {//for the first one- just delete it no reconnecting
        //add code here to actually delete. need temp?
        head = head->getNext();//new head is next
    }
    else if (id == head->getNext()->getStudent()->id) {//if NEXT node is equal
        //add code here to actually delete//pointer being freed was not allocated
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