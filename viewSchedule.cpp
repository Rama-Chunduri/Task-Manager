#include "viewSchedule.h"
#include "User.h"
#include "task.h"
#include "taskList.h"

#include <string>
#include <iomanip>

using namespace std;

void ViewSchedule :: viewDefault(User * user) {
    vector<Task> listOfTasks = user->GetTaskList().GetTasks(); //changed by Rama L Chunduri from '->' to '.' and from <Task*> to <Task>

    vector<Task> tasks;
    // Make a copy of the vector 
    for (int i = 0; i < listOfTasks.size(); ++i) {
        //if (listOfTasks[i] != nullptr) {
            tasks.push_back(listOfTasks[i]); // changed by Rama L Chunduri from tasks.push_back(*listOfTasks[i]) to tasks.push_back(listOfTasks[i])
        //}
    }

    // sort tasks by due date and then by priorities
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        
        // Compare by due date (earliest to latest)
        if (a.GetDueDate() != b.GetDueDate()) {
            return a.GetPriority() < b.GetPriority();
        }

        // If dues dates (earliest to latest) are equal, compare by priority
        return a.GetPriority() < b.GetPriority();
    });

    cout << " Priority | Task                                           | Tag         | Status     " << endl;
    cout << "+-------------------------------------------------------------------------------------+" << endl;

    string currDueDate = "";

    for (int i = 0; i < tasks.size(); ++i) {
        const Task& task = tasks[i];

        if (tasks.at(i).GetDueDate() != currDueDate) {
            // start a new due date section 
            currDueDate = tasks.at(i).GetDueDate();
            cout << " Due Date " << currDueDate << endl;
            cout << "+-------------------------------------------------------------------------------------+" << endl;
        }

        // print priority 
        cout << "    " << task.GetPriority() << "     | ";
        
        // print name of task 
        cout<< left << setw(45) << tasks.at(i).GetName() << "| ";

        // print tag
        cout<< left << setw(12) << tasks.at(i).GetName() << "| ";

        // print status 
        if (tasks.at(i).GetComplete() == true) { // completed 
            cout << "Complete" << endl;
        } else // incomplete 
        {
            cout << "Inomplete" << endl;
        } 
    }
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


   cout << " Duration    | ";
   cout << "\033[38;5;205mTask\033[0m" << endl;
   cout << "+----------------------------------------------------+" << endl;

    for (int i = 0; i < tasks.size(); ++i) {
        cout << " " << left << setw(12) << tasks.at(i).GetDurationHours() << "| ";
        cout << tasks.at(i).GetName() << endl;
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

    cout << " Due Date    | ";
    cout << "\033[38;5;205mTask\033[0m" << endl;
    cout << "+----------------------------------------------------+" << endl;

    bool currentCompletionStatus = true; // assuming true means completed

        for (int i = 0; i < tasks.size(); ++i) {
            Task& task = tasks[i];

            if (task.GetComplete() != currentCompletionStatus) {

            // Start a new completion status group
            if (i != 0) {
                if (currentCompletionStatus == true) { // task complete 
                    cout << "Complete" << endl;

                } else { // tasl incomplete 
                    cout << "Incomplete" << endl;

                }

                cout << "+--------------------------------------------------------+" << endl;
            }

            currentCompletionStatus = task.GetComplete();
        }

        cout << " " << left << setw(11) << tasks.at(i).GetDueDate() << " | ";

            // print task details 
            if (currentCompletionStatus == true) { // task complete 
                    cout << "[√]" << " ";

                } else { // task incomplete 

                    cout << "[X]" << " ";
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

    cout << " Due Date    | ";
    cout << "\033[38;5;205mTask\033[0m" << endl;
    cout << "+----------------------------------------------------+" << endl;

    int currentPriority = -1;

    for (int i = 0; i < tasks.size(); ++i) {
        Task& task = tasks[i];

        if (task.GetPriority() != currentPriority) {
            
            // Start a new priority group
            if (currentPriority != -1) {
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






// groups tasks of the same tag together
void ViewSchedule :: viewByTag(User* user)  
{
    vector<Task> listOfTasks = user->GetTaskList().GetTasks(); //changed by Rama L Chunduri from '->' to '.' and from <Task*> to <Task>

    vector<Task> tasks;
    // Make a copy of the vector 
    for (int i = 0; i < listOfTasks.size(); ++i) {
        //if (listOfTasks[i] != nullptr) {    //changed by Rama L Chunduri
            tasks.push_back(listOfTasks[i]); // changed by Rama L Chunduri from tasks.push_back(*listOfTasks[i]) to tasks.push_back(listOfTasks[i])
        //}
    }

    //get unique tags 
    vector<string>uniqueTags;
    Task taskIterator = tasks.at(0);

    for (int i = 0; i < tasks.size(); ++i) {
    
        // if tag is not found in uniqueTags
        if (find(uniqueTags.begin(), uniqueTags.end(), taskIterator.GetTag()) == uniqueTags.end()) {
            uniqueTags.push_back(taskIterator.GetTag());
        }
    }

    cout << " Due Date    | ";
    cout << "\033[38;5;205mTask\033[0m" << endl;
    cout << "+----------------------------------------------------+" << endl;

    //iterate over unique tags and print tasks for each tag 
    string tagIterator = uniqueTags.at(0);
    taskIterator = tasks.at(0);

    for (int i = 0; i < uniqueTags.size(); ++i) {
        cout << tagIterator << endl;
        cout << "+----------------------------------------------------+" << endl;

        //iterate over tasks and print details for tasks with the current tag
        for (int i = 0; i < uniqueTags.size(); ++i) {
            if (taskIterator.GetTag() == tagIterator)
                //print task details as needed 
                cout << " " << left << setw(11) << tasks.at(i).GetDueDate() << " | ";
                cout << tasks.at(i).GetName();        
        }
        
        cout << endl << endl;
    }
}




