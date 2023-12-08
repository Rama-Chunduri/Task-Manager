#include "viewSchedule.h"
#include "User.h"
#include "task.h"
#include "taskList.h"

#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void ViewSchedule :: viewDefault(User user) {
    vector<Task> tasks = user.GetTaskList().GetTasks(); //changed by Rama L Chunduri from '->' to '.' and from <Task*> to <Task>

    // sort tasks by due date and then by priorities
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        
        // Compare by due date (earliest to latest)
        if (a.GetDueDate() != b.GetDueDate()) {
            return a.GetPriority() < b.GetPriority();
        }

        // If dues dates (earliest to latest) are equal, compare by priority
        return a.GetPriority() < b.GetPriority();
    });

    cout << " \033[38;2;206;30;206mPriority\033[0m | \033[38;2;0;153;255mTask\033[0m               | \033[38;2;175;97;255mDuration\033[0m | \033[38;2;241;194;50mTag\033[0m         | \033[38;2;40;179;176mStatus\033[0m     " << endl;
    cout << "+-------------------------------------------------------------------+" << endl;

    string currDueDate = "";

    for (int i = 0; i < tasks.size(); ++i) {

        Task task = tasks[i];

        if (tasks.at(i).GetDueDate() != currDueDate) {
            // start a new due date section 
            currDueDate = tasks.at(i).GetDueDate();
            cout << endl << endl;
            cout << " \033[38;5;222mDue Date: \033[0m " << currDueDate << endl;
            cout << "+-------------------------------------------------------------------+" << endl;
        }

        cin.clear();

        // print priority 
        cout << "     " << left << setw(3) << tasks.at(i).GetPriority() << "  | ";

        // print name of task 
        cout << left << setw(19) << tasks.at(i).GetName() << "| ";

        // print duration
        cout<< left << setw(9) << tasks.at(i).GetDurationHours() << "| ";

        // print tag
        cout << left << setw(12) << tasks.at(i).GetTag() << "| ";

        // print status 
        if (tasks.at(i).GetComplete() == true) { // completed 
            cout << "Complete" << endl;
        } else // incomplete 
        {
            cout << "Incomplete" << endl;
        } 
    }
    cout << endl << endl << endl;
}






// shortest to longest duration
// Might change the way this is viewed later - get the duration in intervals
void ViewSchedule :: viewByDuration(User* user) {
    vector<Task> listOfTasks = user->GetTaskList().GetTasks();  //changed by Rama L Chunduri from '->' to '.' and from <Task*> to <Task>

    vector<Task> tasks;
    // Make a copy of the vector 
    for (int i = 0; i < listOfTasks.size(); ++i) {
        //if (listOfTasks[i] != nullptr) {
            tasks.push_back(listOfTasks[i]); // changed by Rama L Chunduri from tasks.push_back(*listOfTasks[i]) to tasks.push_back(listOfTasks[i])
        //}
    }

    // sort tasks by duration from shortest to longest
    sort(tasks.begin(), tasks.end(), [](Task& a, Task& b) {
       return a.GetDurationHours() < b.GetDurationHours();
    });

   cout << " \e[0;36mDuration\e[0m    | ";
   cout << "\033[38;5;33mTask\033[0m" << endl;
   cout << "+----------------------------------------------------+" << endl;

    for (int i = 0; i < tasks.size(); ++i) {
        cout << "   " << left << setw(8) << tasks.at(i).GetDurationHours() << "| ";
        cout << left << setw(19) << tasks.at(i).GetName() << endl;
    }

   cout << endl << endl;
}






// complete vs incomplete
void ViewSchedule :: viewByCompletion(User* user) {
    vector<Task> listOfTasks = user->GetTaskList().GetTasks();  //changed by Rama L Chunduri from '->' to '.' and from <Task*> to <Task>

    vector<Task> tasks;
    // Make a copy of the vector 
    for (int i = 0; i < listOfTasks.size(); ++i) {
        //if (listOfTasks[i] != nullptr) {
            tasks.push_back(listOfTasks[i]);   // changed by Rama L Chunduri from tasks.push_back(*listOfTasks[i]) to tasks.push_back(listOfTasks[i])
       // }
    }

    // Sort tasks by completion status and then by due date within each status
    sort(tasks.begin(), tasks.end(), [](Task& a, Task& b) {
        // Compare by completion status
        if (a.GetComplete() != b.GetComplete()) {
            return a.GetComplete() > b.GetComplete();
        }

        // If completion status is equal, compare by due date (earliest to latest)
        return a.GetDueDate() < b.GetDueDate();
    });

    cout << " \033[38;5;222mDue Date\033[0m    | ";
    cout << "\033[38;5;33mTask\033[0m" << endl;
    cout << "+--------------------------------------------------------+" << endl;

    bool currentCompletionStatus = true; // assuming true means completed

        for (int i = 0; i < tasks.size(); ++i) {
            Task& task = tasks[i];

            if (task.GetComplete() != currentCompletionStatus) {
                currentCompletionStatus = task.GetComplete();
            }

            cout << " " << left << setw(11) << tasks.at(i).GetDueDate() << " | ";

            // print task details 
            if (currentCompletionStatus == true) { // task complete 
                    cout << "\033[32m[√]\033[0m" << " ";

                } else { // task incomplete 

                    cout << "\033[31m[X]\033[0m" << " ";
                }

            cout << tasks.at(i).GetName() << endl;
        }

    cout << endl << endl;
}






// highest(1) to lowest priority(3)
void ViewSchedule :: viewByPriority(User* user) {
    vector<Task> listOfTasks = user->GetTaskList().GetTasks(); //changed by Rama L Chunduri from '->' to '.' and from <Task*> to <Task>

    vector<Task> tasks;
    // Make a copy of the vector 
    for (int i = 0; i < listOfTasks.size(); ++i) {
        //if (listOfTasks[i] != nullptr) {   //changed by Rama L Chunduri
            tasks.push_back(listOfTasks[i]); // changed by Rama L Chunduri from tasks.push_back(*listOfTasks[i]) to tasks.push_back(listOfTasks[i])
        //}
    }

    // Sort tasks by priority and then by due date within each priority
    sort(tasks.begin(), tasks.end(), [](Task& a, Task& b) {
        
        // Compare by priority
        if (a.GetPriority() != b.GetPriority()) {
            return a.GetPriority() > b.GetPriority();
        }

        // If priorities are equal, compare by due date (earliest to latest)
        return a.GetDueDate() < b.GetDueDate();
    });

    cout << " \033[38;5;222mDue Date\033[0m    | ";
    cout << "\033[38;5;33mTask\033[0m" << endl;
    cout << "+----------------------------------------------------+" << endl;

    int currentPriority = -1;

    for (int i = 0; i < tasks.size(); ++i) {
        Task& task = tasks[i];

        if (task.GetPriority() != currentPriority) {
            
            // Start a new priority group
            if (currentPriority != -1) {
                cout << endl << endl;
                cout << "Priority " << currentPriority << endl;
                cout << "+----------------------------------------------------+" << endl;
            }

            currentPriority = task.GetPriority();
        }

            // Print task details
            cout << " " << left << setw(11) << tasks.at(i).GetDueDate() << " | ";
            cout << tasks.at(i).GetName();

    }

    cout << endl << endl;
}





void ViewSchedule::viewByTag(User user) {
    vector<Task> tasks = user.GetTaskList().GetTasks();
    vector<string> uniqueTags;

    // Populate uniqueTags
    for (int i = 0; i < tasks.size(); ++i) {
        const Task& task = tasks[i];
        if (find(uniqueTags.begin(), uniqueTags.end(), task.GetTag()) == uniqueTags.end()) {
            uniqueTags.push_back(task.GetTag());
        }
    }

    cout << " \033[38;5;222mDue Date\033[0m    | ";
    cout << "\033[38;5;33mTask\033[0m" << endl;
    cout << "+----------------------------------------------------+" << endl;

    // Iterate over unique tags and print tasks for each tag
    for (int i = 0; i < uniqueTags.size(); ++i) {
        const string& currentTag = uniqueTags[i];
        cout << currentTag << endl;
        cout << "+----------------------------------------------------+" << endl;

        // Iterate over tasks and print details for tasks with the current tag
        for (int j = 0; j < tasks.size(); ++j) {
            const Task& currentTask = tasks[j];
            if (currentTask.GetTag() == currentTag) {
                // Print task details as needed 
                cout << " " << left << setw(11) << currentTask.GetDueDate() << " | ";
                cout << currentTask.GetName() << endl;
            }
        }

        cout << endl << endl;
    }
}

