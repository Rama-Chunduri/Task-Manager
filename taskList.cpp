#pragma once
#include "task.h"
#include "taskList.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


void taskList::addTask(string newTask, string description, string dueDate, string tag, int priority){
   int name="check"; //this variable is for the user who is entering this task so we can implement the task
   //to the file
   Task* toAdd = new Task;
   //seting all the variables to the class so we can automatically upload it the designated file
   toAdd->SetName(newTask);
   toAdd->SetDescription(description);
   toAdd->SetDueDatedueDate(dueDate);
   toAdd->SetTag(tag);
   toAdd->SetPriority(priority);
   //also create a vector
   tasks.push_back(toAdd);
   //Open file
   string fileName;
   fileName = name + ".txt";//name of the file
   ifstream inFS;
   ofstream myFile(fileName);
   outFS << toAdd->GetName() << endl;
   outFS << toAdd->GetDescription() << endl;
   outFS << toAdd->GetTag() << endl;
   outFS << toAdd->GetDueDate() << endl;
   outFS << toAdd->GetPriority() << endl;
   myFile.close();
   
}
void taskList::removeTask(string toRemove){
   int i;
   for(i=0; i<tasks.size(); ++i){
       if((tasks.at(i))->GetName() == toRemove){
           tasks.erase(tasks.begin()+i-1);
           break;
       }
   }
}

