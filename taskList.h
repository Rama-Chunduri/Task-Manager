#pragma once
#include <string>
#include <vector>
#include "task.h"
using namespace std;


class taskList {
  public:
  taskList();
  taskList(vector<Task> tasksN);
  void addTask(ostream & out,  Task task, const string& name);
  void removeTask(int toRemove, string name);
  //void editTask(string taskName);
  vector<Task>GetTasks();
  void SetTasks(vector<Task>Tasks);
  private:
  vector<Task> tasks = {Task("NoName", "NoDesc", "NoDate", "NoDate", "NoTag", 0, 0, false)};
};

