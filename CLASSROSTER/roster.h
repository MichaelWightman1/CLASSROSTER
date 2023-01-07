#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class RosterClass {

public:

    //Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
    StudentClass* classRosterArray;
    RosterClass()
    {
        classRosterArray = new StudentClass[10]{};
    }

    /*  a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1and updates the roster.

        b.  public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.

        c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.

        d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.

        e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.


        Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').


        f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.*/

    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int classPeriod[], DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    int studentSize = 0;

    // Implement the destructor to release the memory that was allocated dynamically in Roster.
    ~RosterClass();
};


#endif