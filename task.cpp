#include "task.h"
#include <string>
#include <vector>

Task::Task(){}
Task::Task(string name, string description, string dueDate, string tag, int priority){
   vector<Task>tasks;
   _name = name;
   _description = description;
   _dueDate = dueDate;
   _tag = tag;
   _priority = priority;
}
void Task::SetName(string name){
this->_name = name;
}
void Task::SetDueDate(string dueDate){
   this->_dueDate = dueDate;
}
void Task::SetTag(string tag){
   this->_tag = tag;
}
void Task::SetDescription(string description){
   this->_description = description;
}
void Task::SetPriority(int priority){
   this->_priority = priority;
}
string Task::GetName(){
   return _name;
}
string Task::GetDueDate(){
   return _dueDate;
}
string Task::GetTag(){
   return _tag;
}
string Task::GetDescription(){
   return _description;
}
int Task::GetPriority(){
   return _priority;
}


