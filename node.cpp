#include "node.h"


Node::Node(Student* newstudent) {//constructor
    next = NULL;
    student = newstudent;
}

Node::~Node() {//destructor
    delete &student;
    next = NULL;
}

Student* Node::getStudent() {//get (set already done with constructor.)
    return student;
}

//get and set next
void Node::setNext(Node* newnext) {
    next = newnext;
}

Node* Node::getNext() {
    return next;
}

/*#include "node.h"

Node::Node(Student *student)
{
    this->next = nullptr;
    this->student = student;
}

Node::~Node()
{
    delete student;
}

Node *Node::getNext()//"expression is not assignable" error: deleted private from node.h and just did ->next to make it work.
{
    return this->next;
}

void Node::setNext(Node *next)
{
    this->next = next;
}

Student *Node::getStudent()
{
    return this->student;
}
*/