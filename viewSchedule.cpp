#include "viewSchedule.h"

using namespace std;

void ViewSchedule :: viewDefault(User * user) {
   vector<Task> tasks = user->GetTaskList().GetTasks();

    // sort tasks by due date and then by priority 
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        
        // Compare by due date (earliest to latest)
        if (a.GetDueDate() != b.GetDueDate()) {
            return a.GetPriority() < b.GetPriority();
        }

        // If dues dates (earliest to latest) are equal, compare by priority
        return a.GetPriority() < b.GetPriority();
    });

    cout << " Priority | Task                                           | Tag         | Status    " << endl;
    cout << "+------------------------------------------------------------------------------------+" << endl;

    string currDueDate = "";

    for (int i = 0; i < tasks.size(); ++i) {
        const Task& task = tasks[i];

        if (task.GetDueDate() != currDueDate) {
            // start a new due date section 
            currentDueDate = task.GetDueDate();
            cout << " Due Date " << currentDueDate << endl;
            cout << "+------------------------------------------------------------------------------------+" << endl;
        }

        cout << "    " << task.GetPriority() << "     | ";
        cout << task.GetName() << "     | ";
        cout << task.GetTag() << "     | ";
        cout << task.GetStatus();
        if (task.GetStatus == true) { // completed 
            cout << "Complete" << endl;
        } else // incomplete 
        {
            cout << "Incomplete" << endl;
        } 
    }
}






// groups tasks of the same tag together
void ViewSchedule :: viewByTag(User* user)  
{
    vector<Task> tasks = user->GetTaskList().GetTasks();

    //get unique tags 
    vector<string>uniqueTags;
    Task taskIterator = tasks.at(0);

    for (int i = 0; i < tasks.size(); ++i) {
    
        // if tag is not found in uniqueTags
        if (find(uniqueTags.begin(), uniqueTags.end(), taskIterator.GetTag()) == uniqueTags.end()) {
            uniqueTags.push_back(taskIterator.GetTag());
        }
    }

    cout << " Due Date    | Task " << endl;
    cout << "+----------------------------------------------------+" << endl;

    //iterate over unique tags and print tasks for each tag 
    string tagIterator = uniqueTags.at(0);
    taskIterator = tasks.at(0);

    for (int i = 0; i < uniqueTag.size(); ++i) {
        cout << tagIterator << endl;
        cout << "+----------------------------------------------------+" << endl;

        //iterate over tasks and print details for tasks with the current tag
        for (int i = 0; i < uniqueTasks.size(); ++i) {
            if (task.GetTag() == tagIterator)
                //print task details as needed 
                cout << " " << task.GetDueDate() << " | " << task.GetName() << endl;
        }
        cout << endl << endl;
    }
}






// shortest to longest duration
// Might change the way this is viewed later - get the duration in intervals
void ViewSchedule :: viewByDuration(User* user) {
   vector<Task> tasks = user->GetTaskList().GetTasks();


   // sort tasks by duration from shortest to longest
   sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
       return a.GetDurationHours() < b.GetDurationHours();
   });


   cout << " Duration    | Task " << endl;
   cout << "+----------------------------------------------------+" << endl;


   for (int i = 0; o < tasks.size(); ++i) {
       // Print task details
       cout << " " << task.GetDuration() << " | " << task.GetName() << endl;
   }

   cout << endl << endl;
}






// complete vs incomplete
void ViewSchedule :: viewByCompletion(User* user) {
    vector<Task> tasks = user->getTaskList().getTasks();

    // Sort tasks by completion status and then by due date within each status
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        // Compare by completion status
        if (a.isCompleted() != b.isCompleted()) {
            return a.isCompleted() > b.isCompleted();
        }

        // If completion status is equal, compare by due date (earliest to latest)
        return a.GetDueDate() < b.GetDueDate();
    });

    cout << " Due Date    | Task " << endl;
    cout << "+----------------------------------------------------+" << endl;

    bool currentCompletionStatus = true; // assuming true means completed

        for (int i = 0; i < tasks.size(); ++i) {
            const Task& task = tasks[i];

            if (task.isCompleted() != currentCompletionStatus) {

            // Start a new completion status group
            if (i != 0) {
                if (currentCompletionStatus == true) { // task complete 
                    cout << "Complete" << endl;

                } else { // task incomplete 
                    cout << "Incomplete" << endl;

                }

                cout << "+----------------------------------------------------+" << endl;
            }

            currentCompletionStatus = task.isCompleted();
        }

            // print task details 
            if (currentCompletionStatus == true) { // task complete 
                    cout << [√] << " ";

                } else { // task incomplete 

                    cout << [X] << " ";
                }

            cout << " "<< task.GetDueDate() << " | " << task.GetName() << endl;
        }

    cout << endl << endl;
}






// highest(1) to lowest priority(3)
void ViewSchedule :: viewByPriority(User* user) {
     vector<Task> tasks = user->GetTaskList().GetTasks();

    // Sort tasks by priority and then by due date within each priority
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        
        // Compare by priority
        if (a.GetPriority() != b.GetPriority()) {
            return a.GetPriority() > b.GetPriority();
        }

        // If priorities are equal, compare by due date (earliest to latest)
        return a.GetDueDate() < b.GetDueDate();
    });

    cout << " Due Date    | Task " << endl;
    cout << "+----------------------------------------------------+" << endl;

    int currentPriority = -1;

    for (int i = 0; i < tasks.size(); ++i) {
        const Task& task = tasks[i];

        if (task.GetPriority() != currentPriority) {
            
            // Start a new priority group
            if (currentPriority != -1) {
                cout << "Priority " << currentPriority << endl;
                cout << "+----------------------------------------------------+" << endl;
            }

            currentPriority = task.GetPriority();
        }

            // Print task details
            cout << " " << task.GetDueDate() << " | " << task.GetName() << endl;
    }
}





