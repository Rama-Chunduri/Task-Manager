#pragma once
#include "User.h"

using namespace std;

class ViewSchedule {
    private: 
        vector<Task> task;

    public: 
        // earliest to latest start date
        void printByStartDate(User* user);
        
        // earliest to latest start date 
        // also the default view 
        void printByDueDate(User* user);
        
        // longest to shortest duration
        void printByDuration(User* user);
        
        // complete vs incomplete
        void printByCompletion(User* user);
        
        // groups tasks of the same tag together
        void printByTag(User* user);

        // highest(1) to lowest priority(3)
        void printByPriority(User* user);
}