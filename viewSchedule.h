#pragma once
#include "task.h"
#include "User.h"

using namespace std;

class ViewSchedule {
    void printByStartDate(User* user);
    void printByDueDate(User* user);
    void printByDuration(User* user);
    void printByCompletion(User* user);
    void printByTag(User* user);
    void printByPriority(User* user);
}