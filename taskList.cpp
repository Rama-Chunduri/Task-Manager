#pragma once
#include "task.h"
#include "taskList.h"
#include "user.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

vector<Task> taskListEdit :: getTask(){
   return tasks;
}

void taskListEdit::addTask(Task*task){
   int name=user.GetName(); //this variable is for the user who is entering this task so we can implement the task
   //to the file
   //also create a vector and push back task
   tasks.push_back(task);
   //Open file
   string fileName;
   fileName = name + ".txt";//name of the file
   ofstream myFile(fileName);
   outFS<<tasks.size()<<", "<<task->GetName()<<", "<<task>GetStartDate()<<", "<<task->GetStartDate()<<", "<<task->GetDueDate()<<", "<<toAdd->GetDescription()
   <<", "<< task->GetTag()<<", "<<task->GetPriority()<<endl;
   myFile.close();
}
void taskListEdit::removeTask(int  toRemove){
  fileName = name + ".txt";//name of the file
  ifstream inFile(fileName); // reading the file with the user name
  ofstream temporaryFile("temp.txt");
  // Create a text string, which is used to output the text file
  string myText;
  // Read from the text file
  string line;
  int currentLineNum = 1; // Counter for current line number, tracking the number

    while (getline(inFile, line)) { // looking through each line
        if (currentLine != lineToRemove) {// if the line doesnt equal the line we want to remove
            temporaryFile << line << endl; // Write all other lines to temporary file if it's not the line to be removed with the same name
        }
        currentLineNum++; // keeps track of the numbers when moving the file over, numbers all change after removing that line
    }
   //we also need to remove the element from the vector
      if(toRemove<tasks.size()){
         tasks.erase(tasks.begin()+toRemove);
      }
      else{
         cout<<"Please enter a valid index to remove the task"<<endl;
      }
    inFile.close(); // lets close both files
    temporaryFile.close();
    remove(fileName.c_str()); // Remove the original file, dont need it
    rename(fileName, fileName.c_str()); // rename the temp file to the user name
}

