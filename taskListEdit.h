#pragma once
#include <string>
#include <vector>
#include "task.h"
#include "taskListEdit.h"
using namespace std;


class taskListEdit : public Task {
   public:
   void addTask(string newTask);
   void removeTask(string toRemove);
   void editTask(string taskName);
   private:
   vector<Task*> tasks;
};

