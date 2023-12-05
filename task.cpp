#include "task.h"
#include <string>
#include <vector>


Task::Task(){}


Task::Task(string name, string description, string startDate, string dueDate, string tag, int priority, double durationHours, bool completeStatus){
  //vector<Task>tasks;
  _name = name;
  _description = description;
  _startDate = startDate;
  _dueDate = dueDate;
  _tag = tag;
  _priority = priority;
  _durationHours = durationHours;
  _complete = completeStatus;
}


void Task::SetName(string name){
  this->_name = name;
}
string Task::GetName() const{
  return _name;
}






void Task::SetDescription(string description){
  this->_description = description;
}
string Task::GetDescription() const{
  return _description;
}






void Task::SetStartDate(string startDate){
  _startDate = startDate;
}
string Task::GetStartDate() const{
  return _startDate;
}










void Task::SetDueDate(string dueDate){
  this->_dueDate = dueDate;
}
string Task::GetDueDate() const{
  return _dueDate;
}






void Task::SetTag(string tag){
  this->_tag = tag;
}
string Task::GetTag() const{
  return _tag;
}






void Task::SetPriority(int priority){
  this->_priority = priority;
}
int Task::GetPriority() const{
  return _priority;
}






double Task::GetDurationHours() const{
  return _durationHours;
}
void Task::SetDurationHours(double durationHours){
  _durationHours = durationHours;
}






void Task::SetComplete(bool check){
  this->_complete = check;
}
bool Task::GetComplete() const{
  return _complete;
}
