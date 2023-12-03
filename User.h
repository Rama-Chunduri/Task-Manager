

#pragma once

#include "User.h"
#include "task.h"
#include "taskList.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>



using namespace std;
class User{
    private:
        string userName;
        string password;
        taskList list;
    public:
        User();
        User(string _userName, string _password);
        void SetUserName (string _userName);
        void SetPassword (string _password);
        string GetUserName();
        string GetPassword();
        vector<Task> loadtasks();

        taskList GetTaskList();
        void SetTaskList(vector<Task> tasks);
};
