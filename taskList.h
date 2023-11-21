#pragma once
#include <string>
#include <vector>
#include "task.h"
#include "taskListEdit.h"
using namespace std;


class taskList : public Task {
   public:
   void addTask(Task*task);
   void removeTask(int toRemove);
   void editTask(string taskName);
   vector<Tasl> * getTask();
   private:
   vector<Task*> tasks;
};

