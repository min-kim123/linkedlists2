#include "student.h"
#include <cstring>


void Student::setFirst(char* newfirst) {
    strcpy(firstname, newfirst);
}

void Student::setLast(char* newlast) {
    strcpy(lastname, newlast);
}

void Student::setID(int newID) {
    id = newID;
}

void Student::setGPA(float newGPA) {
    gpa = newGPA;
}

char* Student::getFirst() {
    return firstname;
}

char* Student::getLast() {
    return lastname;
}

int Student::getID() {
    return id;
}

float Student::getGPA() {
    return gpa;
}