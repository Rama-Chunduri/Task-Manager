#pragma once
#include <string> 
#include "task.h"
using namespace std;

class menu : public Task{
    public: 
    string editName();
    string editDescription();
    string editDueDate();
    string editTags();
    string editPriority();
    void viewSchedule();
};