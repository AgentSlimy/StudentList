#include <iostream>
#include <vector>

using namespace std;

struct student {
  char firstName[21];
  char lastName[21];
  int studentID;
  float GPA;
};


int main() {
  char action[7];
  bool running = true;
  cout << "ADD, PRINT, DELETE, or QUIT" << endl;
  while (running == true) {
    cin >> action;
    if (action[0] == 'A' && action[1] == 'D' && action[2] == 'D') {
      cout << "Adding new student" << endl;

      running = false;
    }
    else if (action[0] == 'P' && action[1] == 'R' && action[2] == 'I' && action[3] == 'N' && action [4] == 'T') {
      cout << "Printing all students" << endl;

      //running = false;
    }
    else if (action[0] == 'D' && action[1] == 'E' && action[2] == 'L' && action[3] == 'E' && action[4] == 'T' && action[5] == 'E') {
      cout << "You are about to delete a student. Confirm? 'Y' for yes 'N' for no" << endl;
      char deleteCheck[2];
      cin >> deleteCheck;
      bool deleteChecking = true;
      while (deleteChecking == true) {
	if (deleteCheck[0] == 'Y') {
	  cout << "Deleting student" << endl;
	  deleteChecking = false;
	  //running = false;
	}
	else if (deleteCheck[0] == 'N') {
	  cout << "Back to main menu" << endl;
	  cout << "ADD, PRINT, DELETE, or QUIT" << endl;
	  deleteChecking = false;
	  running = true;
	}
	else {
	  cout << "Invalid input. Ensure that your response is capitalized and is a 'Y' or 'N'" << endl;
	  deleteChecking = true;
	}
      }
    }
    else if (action[0] == 'Q' && action[1] == 'U' && action[2] == 'I' && action[3] == 'T') {
      cout << "Quitting program" << endl;
      running = false;
    }
    else {
      cout << "Invalid input. Ensure that all commands are in all capital letters." << endl;
      running = true;
    }
  }


  
}//end of main()
