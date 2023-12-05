#pragma once

#include "task.h"
#include "taskList.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class User{
    private:
        string name;
        string userName;
        string password;
        taskList list;

    public:
        User();
        User(string _userName, string _password, string _name);

        void SetUserName (string _userName);
        void SetPassword (string _password);
        void SetName (string _name);

        string GetUserName();
        string GetPassword();
        string GetName();
        
        vector<Task> loadtasks();
        taskList* GetTaskList();
        void SetTaskList(vector<Task> tasks);

     

};
