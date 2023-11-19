#pragma once
#include <string>
#include <vector>
#include "task.h"
#include "taskList.h"
using namespace std;


class taskList : public Task {
   public:
   void addTask(const string newTask);
   void removeTask(const string toRemove);
   void editTask(const string taskName);
   private:
   vector<Task*> tasks;
};

