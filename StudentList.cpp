//Author: Nathan Zou
//Date: 11/7/2021
//This is Student List, a program that uses structs, pointers, and vectors
//Creates a list of students with their first names, last name, their student ID number, and their GPA's
//Vector commands: https://www.geeksforgeeks.org/vector-in-cpp-stl/
//Vector iteration: https://stackoverflow.com/questions/36826165/iterating-through-a-vector-of-pointers-and-printing-out-values
//GPA Rounding: https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct student {
    char firstName[51];
    char lastName[51];
    int studentID;
    float GPA;
};

student* ADD();
void PRINT(vector<student*> studentList);
void DELETE(vector<student*>* studentList, int id);

int main() {
    char action[7]; //Array for commands
    bool running = true;
    vector<student*> studentList;
    cout << "Welcome to Student List." << endl;
    while (running == true) {
        cout << "ADD, PRINT, DELETE, or QUIT" << endl;
        cin >> action;
        //ADD, add a new student
        if (action[0] == 'A' && action[1] == 'D' && action[2] == 'D') {
            cout << "Adding new student:" << endl;
            running = true;
            studentList.push_back(ADD());
        }
        //PRINT, prints out all students 
        else if (action[0] == 'P' && action[1] == 'R' && action[2] == 'I' && action[3] == 'N' && action[4] == 'T') {
            cout << "Printing all students:" << endl;
            running = true;
            PRINT(studentList);
        }
        //DELETE, user chooses student to delete from list
        else if (action[0] == 'D' && action[1] == 'E' && action[2] == 'L' && action[3] == 'E' && action[4] == 'T' && action[5] == 'E') {
            cout << "You are about to delete a student. Confirm? 'Y' for yes 'N' for no." << endl;
            char deleteCheck[2];
            bool deleteChecking = true;
            while (deleteChecking == true) {
                cin >> deleteCheck;
                if (deleteCheck[0] == 'Y' || deleteCheck[0] == 'y') { //Double checks to ensure you want to delete
                    cout << "Deleting student." << endl;
                    deleteChecking = false;
                    cout << "Enter the student ID you want to delete: " << endl;
                    int IDdel;
                    cin >> IDdel;
                    running = true;
                    DELETE(&studentList, IDdel);
                }
                else if (deleteCheck[0] == 'N' || deleteCheck[0] == 'n') { //Returns user to "main menu"
                    cout << "Back to main menu" << endl;
                    deleteChecking = false;
                    running = true;
                }
                else { //If input is invalid
                    cout << "Invalid input. Ensure that your response is a 'Y' or 'N'" << endl;
                    deleteChecking = true;
                }
            }
        }
        //QUIT, exits the program
        else if (action[0] == 'Q' && action[1] == 'U' && action[2] == 'I' && action[3] == 'T') { 
            cout << "Quitting program" << endl;
            running = false;
        }
        //Input invalid
        else {
            cout << "Invalid input. Ensure that all commands are in all capital letters." << endl;
            running = true;
        }
    }
}

//Adding a student, with assistance from Jeffrey Teh
student* ADD() {
    student* ns = new student();
    cout << "Enter first name: " << endl;
    cin >> ns->firstName;
    cout << "Enter last name: " << endl;
    cin >> ns->lastName;
    cout << "Enter the student ID" << endl;
    cin >> ns->studentID;
    cout << "Enter the GPA" << endl;
    cin >> ns->GPA;
    return ns; //Return new student pointer
}

//Printing out all students that have been added (PRINT)
void PRINT(vector<student*> studentList) {
    vector<student*>::iterator print; //Iterator
    for (print = studentList.begin(); print != studentList.end(); print++) {
        cout << (*print)->firstName << ", ";
        cout << (*print)->lastName << ", ";
        cout << (*print)->studentID << ", ";
        cout << fixed << setprecision(2) << (*print)->GPA << endl; //Rounds GPA to 2 decimal places 
    }
}

//Deleting a student (DELETE)
void DELETE(vector<student*>* studentList, int id) {
    vector<student*>::iterator del; //Iterator
    for (del = studentList->begin(); del != studentList->end(); del++) {
        if ((*del)->studentID == id) {
            cout << "Deleted student ID #: " << id << endl;
            delete* del;
            studentList->erase(del);
            //If the student ID is valid
            return;
        }
    }
    //If the student ID is invalid
    cout << "Invalid ID." << endl;
}
