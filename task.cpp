#include "task.h"
#include <string>
#include <vector>

Task::Task(){}
Task::Task(string name, string description, string dueDate, string tag, int priority, string startDate, string endDate, double durationHours){
   vector<Task>tasks;
   _name = name;
   _description = description;
   _dueDate = dueDate;
   _tag = tag;
   _priority = priority;
   _startDate = startDate;
   _endDate = endDate;
   _durationHours = durationHours;
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
bool Task::GetComplete() const{
   return _complete;
}
void Task::SetComplete(bool check){
   this->_complete = check;
}
string Task::GetName() const{
   return _name;
}
string Task::GetDueDate() const{
   return _dueDate;
}
string Task::GetTag() const{
   return _tag;
}
string Task::GetDescription() const{
   return _description;
}
int Task::GetPriority() const{
   return _priority;
}
string Task::GetStartDate() const{
   return _startDate;
}
string Task::GetEndDate() const {
   return _endDate;
}
double Task::GetDurationHours() const{
   return _durationHours;
}

void Task::SetStartDate(string startDate){
   _startDate = startDate;
}
void Task::SetEndDate(string endDate){
   _endDate = endDate;
}
void Task::SetDurationHours(double durationHours){
   _durationHours = durationHours;
}

