#include "task.h"
#include <string>
#include <vector>

void Task::SetName(string name){
this->name = name;
}
void Task::SetDueDate(string dueDate){
    this->dueDate = dueDate;
}
void Task::SetTag(string tag){
    this->tag = tag;
}
void SetDescription(string description){
    this->description = description;
}
void SetPriority(int priority){
    this->priority = priority;
}
string Task::GetName(){
    return name;
}
string Task::GetDueDate(){
    return dueDate;
}
string Task::GetTag(){
    return tag;
}
string Task::GetDescription(){
    return description;
}
string Task::GetPriority(){
    return priority;
}