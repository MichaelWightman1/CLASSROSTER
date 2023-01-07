#include "degree.h"
#include "roster.h"
#include "student.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

//public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
void RosterClass::add(string studentID, string firstName, string lastName, string emailAddress, int age, int classPeriod[], DegreeProgram degreeProgram) {
    const int arraySize = 3;
    int classPeriodArray[arraySize] = { classPeriod[0],classPeriod[1],classPeriod[2] };
    classRosterArray[studentSize] = StudentClass(studentID, firstName, lastName, emailAddress, age, classPeriodArray, degreeProgram);
    studentSize = studentSize + 1;
}

//public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
void RosterClass::remove(string studentID) {
    int x = 0;
    int switchRule = 0;
    for (int i = 0; i < studentSize; i++)
    {
        if (classRosterArray[i].studentIDAccessor() == studentID) {
            for (x = i; x < studentSize; x++)
                classRosterArray[x] = classRosterArray[x + 1];
            switchRule = 1;
            i = i - 1;
            studentSize = studentSize - 1;
        }
    }
    switch (switchRule) {
    case 0:
        cout << "No student to remove";
        break;
    case 1:
        cout << "Removing " << studentID << ":" << endl << endl;
        printAll();
        cout << endl << "Removing " << studentID << " again" << endl << endl;
        x = 0;
        switchRule = 0;
        for (int i = 0; i < studentSize; i++)
        {
            if (classRosterArray[i].studentIDAccessor() == studentID) {
                for (x = i; x < studentSize; x++)
                    classRosterArray[x] = classRosterArray[x + 1];
                switchRule = 1;
                i = i - 1;
                studentSize = studentSize - 1;
            }
        }
        switch (switchRule) {
        case 0:
            cout << "The student with the studentID: " << studentID << " was not found" << endl;
            break;
        case 1:
            cout << "Error removing " << studentID << ":" << endl;
            break;
        }
        break;
    }
}

//public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
void RosterClass::printAll() {
    for (int i = 0; i < studentSize; i++) {
        cout << classRosterArray[i].printAll();
        cout << endl;
    }
}

//public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
void RosterClass::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < studentSize; ++i) {
        if (classRosterArray[i].studentIDAccessor() == studentID) {
            const int daysCount = 3;
            int count = 0;
            int* days = classRosterArray[i].classPeriodAccessor();
            for (int i = 0; i < daysCount; i++) {
                count = count + days[i];
            }
            int average = count / daysCount;
            cout << "Sutdent studentID: " << classRosterArray[i].studentIDAccessor() << ", " << "average days in course is: " << average << endl;

        }
    }
}

//public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
void RosterClass::printInvalidEmails() {

    for (int i = 0; i < studentSize; i++) {

        string email = classRosterArray[i].emailAddressAccessor();
        const char emailRule1 = '@';
        const char emailRule2 = ' ';
        const char emailRule3 = '.';

        if (email.find(emailRule1) == string::npos) {
            cout << email << " - is invalid." << endl;
        }
        else if (email.find(emailRule2) != string::npos) {
            cout << email << " - is invalid." << endl;
        }
        else if (email.find(emailRule3) == string::npos) {
            cout << email << " - is invalid." << endl;
        }
        else {

        }
    }
}

//public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.
void RosterClass::printByDegreeProgram(DegreeProgram degreeProgram) {

    string search1 = "SECURITY";
    string search2 = "NETWORK";
    string search3 = "SOFTWARE";

    for (int i = 0; i < studentSize; i++) {

        string student = classRosterArray[i].printAll();
        switch (degreeProgram) {
        case SECURITY:
            if (student.find(search1) != string::npos) {
                cout << student << endl;
            };
            break;

        case NETWORK:
            if (student.find(search2) != string::npos) {
                cout << student << endl;
            };
            break;
        case SOFTWARE:
            if (student.find(search3) != string::npos) {
                cout << student << endl;
            };
            break;
        }
    }
    return;
}

//Implement the destructor to release the memory that was allocated dynamically in Roster.
RosterClass::~RosterClass() {}