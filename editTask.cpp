#pragma once
#include "editTask.h"
using namespace std;

void EditTask::editPriority(Task currTask, int newPriority){
    currTask.SetPriority(newPriority);
}
void EditTask::editDueDate(Task currTask, string newDueDate){
    currTask.SetDueDate(newDueDate);
}
void EditTask::editTag(Task currTask, string newTag){
    currTask.SetTag(newTag);
}
void EditTask::editDescription(Task currTask, string newDesc){
    currTask.SetDescription(newDesc);
}
void EditTask::editName(Task currTask, string newName){
    currTask.SetName(newName);
}