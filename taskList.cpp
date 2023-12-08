#include "taskList.h"
#include "task.h"
#include "User.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

taskList::taskList(){}
taskList::taskList(vector<Task> tasksN){
  tasks = tasksN;
}
void taskList::SetTasks(vector<Task>Tasks){
  tasks=Tasks;
}

vector<Task> taskList :: GetTasks(){
  return tasks;
}

void taskList::addTask(ostream & out,  Task task, const string& name){// pass ofstream into function  ////
  Task taskPtr = task; //changed
  tasks.push_back(taskPtr);
  out<<tasks.size()<<", "<<task.GetName()<<", "<<task.GetStartDate()<<", "<<task.GetDueDate()<<", "<<task.GetDescription()
  <<", "<< task.GetTag()<<", "<<task.GetPriority()<<", "<<task.GetDurationHours()<<", "<<task.GetComplete()<<endl;
  //out.close();
}
void taskList::removeTask(int toRemove, string name){
 ofstream temporaryFile("temp.txt");
 string fileName = name + ".txt";//name of the file
 ifstream inFile(fileName); // reading the file with the user name
 // Read from the text file
 string checkline;
 string line;
 int currentLineNum = 1; // Counter for current line number, tracking the number
   while (getline(inFile, line)) { // looking through each line
       if (currentLineNum != toRemove) {// if the line doesnt equal the line we want to remove
           temporaryFile << line << endl; // Write all other lines to temporary file if it's not the line to be removed with the same name
       }
       if(currentLineNum!=0){
          currentLineNum++; // keeps track of t  he numbers when moving the file over, numbers all change after removing that line
       }
   }
  //we also need to remove the element from the vector, edge case
     if(toRemove<tasks.size()){
        tasks.erase(tasks.begin()+toRemove);
     }
     else{
        cout<<"Please enter a valid index to remove the task"<<endl;
     }
   inFile.close(); // lets close both files
   temporaryFile.close();
   remove(fileName.c_str()); // Remove the original file, dont need it
   rename("temp.txt", fileName.c_str()); // rename the temp file to the user name
}


