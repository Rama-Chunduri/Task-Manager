#include "viewSchedule.h"

using namespace std;

// // earliest to latest start date
// void viewSchedule :: printByStartDate(User* user)  
// {
//     //vector<Task> tasks = user->GetTaskList().getTasks();
// }

// // earliest to latest start date 
// // also the default view 
// void viewSchedule :: printByDueDate(User* user) 
// { 
//     //vector<Task> tasks = user->GetTaskList().getTasks();

// }

// // longest to shortest duration
// void viewSchedule :: printByDuration(User* user)  
// {
//     vector<Task> tasks = user->GetTaskList().getTasks();

//     sort(tasks.begin(), tasks.end())

// }

// // complete vs incomplete
// void viewSchedule :: printByCompletion(User* user)  
// {
//     vector<Task> tasks = user->GetTaskList().getTasks();

// }

// groups tasks of the same tag together
void viewSchedule :: printByTag(User* user)  
{
    vector<Task> tasks = user->GetTaskList().getTasks();

}

// // highest(1) to lowest priority(3)
// void viewSchedule :: printByPriority(User* user) 
// {
//     vector<Task> tasks = user->GetTaskList().getTasks();

// }
