#include "Remind.h"
#include "task.h"
#include "taskList.h"
#include "User.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

void Remind::remind(User user){
    taskList taskList = user.getTaskList();
    vector<Task> tasks = taskList.getTasks();
    int tm_mday;
    int tm_mon;
    int tm_year;
    int i;
    cout << "Tasks Due in 24 hrs: " << endl;
    for(i=0; i<tasks.size(); ++i){
        string currDate = tasks.at(i).GetDueDate();
        int currYr = atoi((currDate.substr(0, 4)).c_str());
        int currMn = atoi((currDate.substr(4, 2)).c_str());
        int currDt = atoi((currDate.substr(7, 2)).c_str());
        chrono::system_clock::time_point now = chrono::system_clock::now();
        time_t currTime = chrono::system_clock::to_time_t(now);
        tm* localTime = localtime(&currTime);
        if(localTime->tm_year+1900 == currYr && localTime->tm_mon+1 == currMn && localTime->tm_mday == currDt){
            cout << "Task Name: " << tasks.at(i).GetName() << endl;
            cout << "Tag: " << tasks.at(i).GetTag() << endl;
            cout << "Description: " << tasks.at(i).GetDescription() << endl;
            cout << "Due Date: " << tasks.at(i).GetDueDate() << endl;
            cout << "Priority: " << tasks.at(i).GetPriority() << endl;
            cout << "Start Date: " << tasks.at(i).GetStartDate() << endl;
            cout << "End Date: " << tasks.at(i).GetEndDate() << endl;
            cout << "Duration Hours: " << tasks.at(i).GetDurationHours() << endl;
        }
    }
}