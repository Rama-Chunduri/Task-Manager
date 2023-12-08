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
    //cout << "Entered remind" << endl;
   //taskList tasksList = user.GetTaskList();
   //cout << "Created tasklist object" << endl;
   //vector<Task> tasks = tasksList.GetTasks(); //causing error - probably 
   vector<Task> tasks = user.loadtasks();
   //cout << "Got the vector of tasklist" << endl;
   int tm_mday;
   int tm_mon;
   int tm_year;
   int i;
   cout << endl;
   cout << "Tasks Due in 24 hrs: " << endl;
   //if(tasks.at(0).GetName() == "NoName"){
    //cout << "You do not have anything due in the next 24 hours" << endl << endl;
   // return;
   //}
   for(i=0; i<tasks.size(); ++i){
       string currDate = tasks.at(i).GetDueDate();
       //cout << currDate << endl;
       int currYr = atoi((currDate.substr(7, 4)).c_str());
       //cout << currYr << endl;
       int currMn = atoi((currDate.substr(1, 2)).c_str());
       //cout << currMn << endl;
       int currDt = atoi((currDate.substr(4, 2)).c_str());
       //cout << currDt << endl;
       chrono::system_clock::time_point now = chrono::system_clock::now();
       time_t currTime = chrono::system_clock::to_time_t(now);
       tm* localTime = localtime(&currTime);
       //cout << localTime->tm_mday << endl;
       //cout << localTime->tm_mon + 1 << endl;
       //cout << localTime->tm_year + 1900 << endl;

       //cout << *localTime << endl;
       if(localTime->tm_mday == currDt - 1 && localTime->tm_mon + 1 == currMn && localTime->tm_year+1900 == currYr){//localTime->tm_year+1900 == currYr && localTime->tm_mon+1 == currMn && localTime->tm_mday == currDt){
           os << "Task Name: " << tasks.at(i).GetName() << endl;
           os << "Tag: " << tasks.at(i).GetTag() << endl;
           os << "Description: " << tasks.at(i).GetDescription() << endl;
           os << "Due Date: " << tasks.at(i).GetDueDate() << endl;
           os << "Priority: " << tasks.at(i).GetPriority() << endl;
           os << "Start Date: " << tasks.at(i).GetStartDate() << endl;
           os << "Duration Hours: " << tasks.at(i).GetDurationHours() << endl;
           os << "Completion Status: " << tasks.at(i).GetComplete() << endl;
       }
       else if(localTime->tm_mday == 31 && localTime->tm_mon == 12 && localTime->tm_year == currYr - 1 && currMn == 1 && currDt == 1){
           os << "Task Name: " << tasks.at(i).GetName() << endl;
           os << "Tag: " << tasks.at(i).GetTag() << endl;
           os << "Description: " << tasks.at(i).GetDescription() << endl;
           os << "Due Date: " << tasks.at(i).GetDueDate() << endl;
           os << "Priority: " << tasks.at(i).GetPriority() << endl;
           os << "Start Date: " << tasks.at(i).GetStartDate() << endl;
           os << "Duration Hours: " << tasks.at(i).GetDurationHours() << endl;
           os << "Completion Status: " << tasks.at(i).GetComplete() << endl;
       }
       else{
            //cout << "xxx" << endl;
           //os << "You do not have anything due in the next 24 hours." << endl;
           continue;
       }
   }
}