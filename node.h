#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "student.h"

class Node {
    public:
    //constructor and destructor
    Node(Student* student);
    ~Node();
    //get student
    Student* getStudent();
    //set and get next
    void setNext(Node* newnext);
    Node* getNext();

    //private:
    Student* student;
    Node* next;
};
#endif




/*#ifndef NODE_H
#define NODE_H

#include "student.h"

class Node
{
public:
    Node(Student *student);
    ~Node();
    Node *getNext();
    void setNext(Node *next);
    Student *getStudent();


    Node *next;
    Student *student;
};

#endif // NODE_H

This is the Node class!  
It represents a Node in the linked list.  
It contains a Student pointer and another Node pointer, which points to the next Node in the series.
*/
