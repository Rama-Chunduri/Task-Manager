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

    string currDueDate = "";

    for (int i = 0; i < tasks.size(); ++i) {

        Task task = tasks[i];

        if (tasks.at(i).GetDueDate() != currDueDate) {
            // start a new due date section 
            currDueDate = tasks.at(i).GetDueDate();
            //cout << endl << endl;
            cout << "+---------------------------------------------------------------+" << endl;
            cout << " Date: " << currDueDate << endl;
            cout << "+---------------------------------------------------------------+" << endl;
        }

        cin.clear();

        // print priority 
        cout << "\033[38;2;241;176;241m" << "     " << left << setw(3) << tasks.at(i).GetPriority() << "\033[0m" << "  | ";

        // print name of task 
        cout << "\033[38;2;165;219;255m" << left << setw(19) << tasks.at(i).GetName() << "\033[0m" << "| ";

        // print duration
        cout << "\033[38;2;170;155;253m" << left << setw(9) << tasks.at(i).GetDurationHours() << "\033[0m" << "| ";

        // print tag
        cout << "\033[38;2;255;229;153m" << left << setw(12) << tasks.at(i).GetTag() << "\033[0m" << "| ";

        // print status 
        if (tasks.at(i).GetComplete() == true) { // completed 
            cout << " \033[32m[√]\033[0m" << endl;
        } else // incomplete 
        {
            cout << " \033[31m[X]\033[0m" << endl;
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

   cout << " \e[38;2;175;97;255mDuration\e[0m  | ";
   cout << "\033[38;5;33mTask\033[0m" << endl;
   cout << "+----------------------------------------------------+" << endl;

    for (int i = 0; i < tasks.size(); ++i) {
        cout << "\033[38;2;170;155;253m" << "   " << left << setw(8) << tasks.at(i).GetDurationHours() << "\033[0m" << "| ";
        cout <<  "\033[38;2;165;219;255m" << left << setw(19) << tasks.at(i).GetName() << "\033[0m" << endl;
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

    cout << " Date        | ";
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

            cout <<  "\033[38;2;165;219;255m" << tasks.at(i).GetName() << "\033[0m" << endl;
        }

    cout << endl << endl;
}






void ViewSchedule::viewByPriority(User* user) {
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

    cout << " Date        | ";
    cout << "\033[38;5;33mTask\033[0m" << endl;

    cout << "+----------------------------------------------------+" << endl;
    cout << "\033[38;2;206;30;206mPriority \033[0m" << "\033[38;2;241;176;241m1\033[0m" << endl;
    cout << "+----------------------------------------------------+" << endl;

    Task taskIterator = tasks.at(0);

    // priority 1 
    for (int i = 0; i < tasks.size(); ++i) {
        taskIterator = tasks.at(i);
        // Print task details
        if (taskIterator.GetPriority() == 1) {
            cout  << " " << left << setw(11) << tasks.at(i).GetDueDate() << " | ";
            cout <<  "\033[38;2;165;219;255m" << tasks.at(i).GetName() << "\033[0m";
        }
    }

    cout << endl;

    cout << "+----------------------------------------------------+" << endl;
    cout << "\033[38;2;206;30;206mPriority \033[0m" << "\033[38;2;241;176;241m2\033[0m" << endl;
    cout << "+----------------------------------------------------+" << endl;

    // priority 2
    for (int i = 0; i < tasks.size(); ++i) {
        taskIterator = tasks.at(i);
        // Print task details
        if (taskIterator.GetPriority() == 2) {
            cout  << " " << left << setw(11) << tasks.at(i).GetDueDate() << " | ";
            cout <<  "\033[38;2;165;219;255m" << tasks.at(i).GetName() << "\033[0m";
        }
    }

    cout << endl;

    cout << "+----------------------------------------------------+" << endl;
    cout << "\033[38;2;206;30;206mPriority \033[0m" << "\033[38;2;241;176;241m3\033[0m" << endl;
    cout << "+----------------------------------------------------+" << endl;


    // priority 3
    for (int i = 0; i < tasks.size(); ++i) {
        taskIterator = tasks.at(i);
        // Print task details
        if (taskIterator.GetPriority() == 3) {
            cout  << " " << left << setw(11) << tasks.at(i).GetDueDate() << " | ";
            cout <<  "\033[38;2;165;219;255m" << tasks.at(i).GetName() << "\033[0m";
        }
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

    cout << " Date    | ";
    cout << "\033[38;5;33mTask\033[0m" << endl;

    // Iterate over unique tags and print tasks for each tag
    for (int i = 0; i < uniqueTags.size(); ++i) {
        const string& currentTag = uniqueTags[i];
        cout << "+----------------------------------------------------+" << endl;
        cout << "\033[38;2;255;229;153m" << currentTag << "\033[0m" << endl;
        cout << "+----------------------------------------------------+" << endl;

        // Iterate over tasks and print details for tasks with the current tag
        for (int j = 0; j < tasks.size(); ++j) {
            const Task& currentTask = tasks[j];
            if (currentTask.GetTag() == currentTag) {
                // Print task details as needed 
                cout << " " << left << setw(11) << currentTask.GetDueDate() << " | ";
                cout <<  "\033[38;2;165;219;255m" << currentTask.GetName() << "\033[0m" << endl;
            }
        }
    }

    cout << endl << endl;
}

