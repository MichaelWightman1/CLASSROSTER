#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

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

class StudentClass {
public:
    StudentClass() {}
    string studentID;
    string firstName;
    string lastName;
    int age;
    string emailAddress;
    int classPeriod[3] = {};
    DegreeProgram degreeProgram;


    /*
    Create each of the following functions in the StudentClass class:

            a.  an accessor (i.e., getter) for each instance variable from part D1

            b.  a mutator (i.e., setter) for each instance variable from part D1

            c.  All external access and changes to any instance variables of the StudentClass class must be done using accessor and mutator functions.

            d.  constructor using all of the input parameters provided in the table

            e.  print() to print specific student data

    */

    //constructor using all of the input parameters provided in the table
    StudentClass(string studentID, string firstName, string lastName, string emailAddress, int age, int* classPeriod, DegreeProgram degreeProgram);

    //an accessor (i.e., getter) for each instance variable from part D1
    string studentIDAccessor();
    string firstNameAccessor();
    string lastNameAccessor();
    string emailAddressAccessor();
    int ageAccessor();
    int* classPeriodAccessor();
    DegreeProgram degreeProgramAccessor();

    //a mutator (i.e., setter) for each instance variable from part D1
    void studentIDMutator(string studentID);
    void firstNameMutator(string firstName);
    void lastNameMutator(string lastName);
    void ageMutator(int age);
    void emailAddressMutator(string emailAddress);
    void classPeriodMutator(int classPeriod[]);
    void degreeProgramMutator(DegreeProgram degreeProgram);

    //print() to print specific student data
    string printAll();

    ~StudentClass();
};

#endif
