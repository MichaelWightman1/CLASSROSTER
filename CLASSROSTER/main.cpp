#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>   
#include <iterator>     
#include <regex> 
#include <map>
#include <unordered_map>
#include "roster.h"
#include "degree.h"

using namespace std;

vector<string> parseText(vector<string>& studentDataTempVector) {
    //Modify the “studentData Table” to include your personal information as the last item.
    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY,", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK,", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE,", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY,", "A5,Michael,Wightman,mwigh14@wgu.edu,26,50,58,40,SOFTWARE," };
    string studentDataTemp[5];
    copy(begin(studentData), end(studentData), begin(studentDataTemp));
    string text;
    string newText;
    const string delimit = ",";
    for (int i = 0; i < 5; i++) {
        text = studentDataTemp[i];
        int index = 0;
        while ((index = text.find(delimit)) != string::npos) {
            newText = text.substr(0, index);
            text.erase(0, index + delimit.length());
            studentDataTempVector.push_back(newText);
        }
    }
    return studentDataTempVector;
}

static map< string, DegreeProgram> convENUM = {
{"SECURITY", SECURITY},
{"NETWORK", NETWORK},
{"SOFTWARE", SOFTWARE},
};

void main()
{
    const int studentNumber = 5;
    //Create an instance of the Roster class called classRoster.
    RosterClass* classRoster = new RosterClass();

    //Add each student to classRoster.
    vector<string> studentDataTempVector(0);
    vector<string> studentDataTempVector2 = parseText(studentDataTempVector);

    int classPeriodArray[] = { stoi(studentDataTempVector[5]),stoi(studentDataTempVector[6]),stoi(studentDataTempVector[7]) };
    int classPeriodArray2[] = { stoi(studentDataTempVector[14]),stoi(studentDataTempVector[15]),stoi(studentDataTempVector[16]) };
    int classPeriodArray3[] = { stoi(studentDataTempVector[23]),stoi(studentDataTempVector[24]),stoi(studentDataTempVector[25]) };
    int classPeriodArray4[] = { stoi(studentDataTempVector[32]),stoi(studentDataTempVector[33]),stoi(studentDataTempVector[34]) };
    int classPeriodArray5[] = { stoi(studentDataTempVector[41]),stoi(studentDataTempVector[42]),stoi(studentDataTempVector[43]) };

    classRoster->add(studentDataTempVector[0], studentDataTempVector[1], studentDataTempVector[2], studentDataTempVector[3], stoi(studentDataTempVector[4]), classPeriodArray, convENUM[studentDataTempVector[8]]);
    classRoster->add(studentDataTempVector[9], studentDataTempVector[10], studentDataTempVector[11], studentDataTempVector[12], stoi(studentDataTempVector[13]), classPeriodArray2, convENUM[studentDataTempVector[17]]);
    classRoster->add(studentDataTempVector[18], studentDataTempVector[19], studentDataTempVector[20], studentDataTempVector[21], stoi(studentDataTempVector[22]), classPeriodArray3, convENUM[studentDataTempVector[26]]);
    classRoster->add(studentDataTempVector[27], studentDataTempVector[28], studentDataTempVector[29], studentDataTempVector[30], stoi(studentDataTempVector[31]), classPeriodArray4, convENUM[studentDataTempVector[35]]);
    classRoster->add(studentDataTempVector[36], studentDataTempVector[37], studentDataTempVector[38], studentDataTempVector[39], stoi(studentDataTempVector[40]), classPeriodArray5, convENUM[studentDataTempVector[44]]);

    //Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
    cout << "C867-Scripting & Programming: Applications" << endl << "Language: C++" << endl << "StudentClass studentID: 010681877" << endl << "Name: Michael Wightman" << endl << endl;


    /* Convert the following pseudo code to complete the rest of the  main() function:

        classRoster.printAll();

        classRoster.printInvalidEmails();



        //loop through classRosterArray and for each element:

        classRoster.printAverageDaysInCourse
        Note: For the current_object's student id, use an accessor (i.e., getter) for the classRosterArray to access the student id.



        classRoster.printByDegreeProgram(SOFTWARE);

        classRoster.remove("A3");

        classRoster.printAll();

        classRoster.remove("A3");

        //expected: the above line should print a message saying such a student with this ID was not found.

        */

    cout << "Displaying all students:" << endl;
    classRoster->printAll();
    cout << endl;


    cout << "Displaying invalid emails:" << endl;
    classRoster->printInvalidEmails();
    cout << endl;

    for (int i = 0; i <= studentNumber; i++) {
        string student = "A" + to_string(i);
        classRoster->printAverageDaysInCourse(student);
    }
    cout << endl;

    cout << "Showing student(s) in degree program: SOFTWARE" << endl << endl;
    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl << endl;

    classRoster->remove("A3");
    cout << endl;

}

