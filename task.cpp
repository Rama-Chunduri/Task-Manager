#pragma once
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
string Task::GetStartDate(){
   return _startDate;
}
string Task::GetEndDate(){
   return _endDate;
}
double Task::GetDurationHours(){
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

