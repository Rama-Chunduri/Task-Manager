#include <iostream>
#include <fstream>
#include "User.h"
#include "task.h"
#include "viewSchedule.h"
#include "editTask.h"
#include "taskListEdit.h"
using namespace std;


int main(){
   string name;
   string password;
   string fileName;
   cout << "Please enter your name:" << endl;
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
   
   return 0;
}

