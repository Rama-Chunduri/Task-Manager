#pragma once
#include <string>
#include <vector>
#include "task.h"
using namespace std;


class taskList : public Task {
   public:
   void addTask(ostream & out,  Task& task, const string& name);
   void removeTask(int toRemove, string name);
   //void editTask(string taskName);
   vector<Task>getTask();
   private:
   vector<Task> tasks;
};

