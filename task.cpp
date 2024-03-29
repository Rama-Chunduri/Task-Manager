#include "task.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Task::Task(){}


Task::Task(string name = "NoName", string description  = "NoDesc", string startDate = "NoDate", string dueDate = "NoDate", string tag = "NoTag", int priority = 0, double durationHours = 0, bool completeStatus = false){
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
  _name = name;
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
  this->_startDate = startDate;
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
