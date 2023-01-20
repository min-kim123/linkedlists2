#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student {
    public:
    void setFirst(char newfirst[20]);
    void setLast(char newlast[20]);
    void setID(int newID);
    void setGPA(float newGPA);

    char* getFirst();
    char* getLast();
    int getID();
    float getGPA();


    char firstname[20];
    char lastname[20];
    int id;
    float gpa;
};

#endif