#include <iostream>
#include <fstream>
#include "User.h"
#include "task.h"
#include "viewSchedule.h"
#include "editTask.h"
#include "taskListEdit.h"
using namespace std;


int main(){
   string userName;
   string password;
   string fileName;
   cout << "Are you an existing user (Press E) or new user (Press N)?" << endl;

   string userInput;
   cin >> userInput;

   while(userInput != "E" || userInput != "N")
   {
      cout << "Input is not valid. Please enter a valid input." << endl;
      cin >> userInput;
   }

   if(userInput ==  "E")
   {

      cout << "Please enter your Username:" << endl;
      getline(cin, name);
      cout << "Please enter a password: " << endl;
      getline(cin, password);

      //User user = User(name, password);
      cout << "Welcome " << name << "!" << endl;
      fileName = name + ".txt";

      ifstream inFS;
      ofstream outFS(fileName);
      outFS << name << endl;
      outFS << name <<"'s password: " << password << endl;
   }
   
   return 0;
}

