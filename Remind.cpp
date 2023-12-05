#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <ctime>
#include "Remind.h"
#include "task.h"
#include "taskList.h"


using namespace std::chrono;


void Remind::remind(ostream& os, User user){
   taskList* tasksList = user.GetTaskList();
   vector<Task*> tasks = tasksList->GetTasks();
   int tm_mday;
   int tm_mon;
   int tm_year;
   int i;
   cout << "Tasks Due in 24 hrs: " << endl;
   for(i=0; i<tasks.size(); ++i){
       string currDate = tasks.at(i)->GetDueDate();
       int currYr = atoi((currDate.substr(0, 4)).c_str());
       int currMn = atoi((currDate.substr(4, 2)).c_str());
       int currDt = atoi((currDate.substr(7, 2)).c_str());
       chrono::system_clock::time_point now = chrono::system_clock::now();
       time_t currTime = chrono::system_clock::to_time_t(now);
       tm* localTime = localtime(&currTime);
       if(localTime->tm_mday == currDt - 1 && localTime->tm_mon == currMn && localTime->tm_year == currYr){//localTime->tm_year+1900 == currYr && localTime->tm_mon+1 == currMn && localTime->tm_mday == currDt){
           os << "Task Name: " << tasks.at(i)->GetName() << endl;
           os << "Tag: " << tasks.at(i)->GetTag() << endl;
           os << "Description: " << tasks.at(i)->GetDescription() << endl;
           os << "Due Date: " << tasks.at(i)->GetDueDate() << endl;
           os << "Priority: " << tasks.at(i)->GetPriority() << endl;
           os << "Start Date: " << tasks.at(i)->GetStartDate() << endl;
           os << "Duration Hours: " << tasks.at(i)->GetDurationHours() << endl;
           os << "Completion Status: " << tasks.at(i)->GetComplete() << endl;
       }
       else if(localTime->tm_mday == 31 && localTime->tm_mon == 12 && localTime->tm_year == currYr - 1 && currMn == 1 && currDt == 1){
           os << "Task Name: " << tasks.at(i)->GetName() << endl;
           os << "Tag: " << tasks.at(i)->GetTag() << endl;
           os << "Description: " << tasks.at(i)->GetDescription() << endl;
           os << "Due Date: " << tasks.at(i)->GetDueDate() << endl;
           os << "Priority: " << tasks.at(i)->GetPriority() << endl;
           os << "Start Date: " << tasks.at(i)->GetStartDate() << endl;
           os << "Duration Hours: " << tasks.at(i)->GetDurationHours() << endl;
           os << "Completion Status: " << tasks.at(i)->GetComplete() << endl;
       }
       else{
           os << "You do not have anything due in the next 24 hours." << endl;
       }
   }
}