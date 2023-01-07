#include "student.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>

/*
Create each of the following functions in the StudentClass class:

        a.  an accessor (i.e., getter) for each instance variable from part D1

        b.  a mutator (i.e., setter) for each instance variable from part D1

        c.  All external access and changes to any instance variables of the StudentClass class must be done using accessor and mutator functions.

        d.  constructor using all of the input parameters provided in the table

        e.  print() to print specific student data

*/

//an accessor (i.e., getter) for each instance variable from part D1
string StudentClass::studentIDAccessor() { return studentID; }
string StudentClass::firstNameAccessor() { return firstName; }
string StudentClass::lastNameAccessor() { return lastName; }
int StudentClass::ageAccessor() { return age; }
string StudentClass::emailAddressAccessor() { return emailAddress; }
int* StudentClass::classPeriodAccessor() { return classPeriod; }
DegreeProgram StudentClass::degreeProgramAccessor() { return SECURITY; }

//a mutator (i.e., setter) for each instance variable from part D1
void StudentClass::studentIDMutator(string studentID) { this->studentID = studentID; return; }
void StudentClass::firstNameMutator(string firstName) { this->firstName = firstName; return; }
void StudentClass::lastNameMutator(string lastName) { this->lastName = lastName; return; }
void StudentClass::ageMutator(int age) { this->age = age; return; }
void StudentClass::emailAddressMutator(string emailAddress) { this->emailAddress = emailAddress; return; }
void StudentClass::classPeriodMutator(int classPeriod[]) { this->classPeriod[0] = classPeriod[0]; this->classPeriod[1] = classPeriod[1]; this->classPeriod[2] = classPeriod[2]; }
void StudentClass::degreeProgramMutator(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

/*
Create the class StudentClass  in the files student.h and student.cpp, which includes each of the following variables:

        •  student ID

        •  first name

        •   last name

        •  email address

        •  age

        •  array of number of days to complete each course

        •  degree program

*/

StudentClass::StudentClass(string studentID, string firstName, string lastName, string emailAddress, int age, int classPeriod[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->emailAddress = emailAddress;
    this->classPeriod[0] = classPeriod[0];
    this->classPeriod[1] = classPeriod[1];
    this->classPeriod[2] = classPeriod[2];
    this->degreeProgram = degreeProgram;
}

//print() to print specific student data
string StudentClass::printAll() {
    string printNew = studentID + "\t" + firstName + "\t" + lastName + "\t" + to_string(age) + "\t" + "{" + to_string(classPeriod[0]) + "," + to_string(classPeriod[1]) + "," + to_string(classPeriod[2]) + "}" + "\t";
    string degreeString;
    switch (degreeProgram) {
    case SECURITY:
        degreeString = "SECURITY";
        break;
    case NETWORK:
        degreeString = "NETWORK";
        break;
    case SOFTWARE:
        degreeString = "SOFTWARE";
        break;
    }
    printNew = printNew + degreeString;
    return printNew;
}


StudentClass::~StudentClass() {}