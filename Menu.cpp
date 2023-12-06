#include "Menu.h"
#include "User.h"
#include "taskList.h"
#include "viewSchedule.h"
#include "Remind.h"


void Menu::printMenu(User user)
{
   taskList tasks;
   Remind rem;
   //cout << "apple" << endl;
   rem.remind(cout, user);
   // cout << "MENU:" << endl;
   // cout << "a - Create a Task" << endl;
   // cout << "b - Edit a Task" << endl;
   // cout << "c - Delete a Task" << endl;
   // cout << "q - Exit to Homepage" << endl;
   // cout << "Enter a valid input." << endl;

    
    //while(menuOption != "a" || menuOption != "b" || menuOption != "c" || menuOption != "q")
    //{
        //cout << "Enter a valid input." << endl;
        //cin >> menuOption;
    //}
    string menuOption = "q";
    //cin >> menuOption;
    while(menuOption != "q")
        cout << "MENU:" << endl;
        cout << "a - Create a Task" << endl;
        cout << "b - Edit a Task" << endl;
        cout << "c - Delete a Task" << endl;
        
        cout << "d - View by Tag" << endl;
        cout << "e - View by Duration" << endl;
        cout << "f - View by Completion" << endl;
        cout << "g - View by Priority" << endl;

        cout << "q - Exit to Homepage" << endl;
        cout << "Enter a valid input." << endl;
        cin >> menuOption;
        if(menuOption == "a")
        {
            //task name
            string name_task;
            cout << "Please enter the name of the task: " << endl;
            getline(cin, name_task);
            while(name_task.size() > 46)
            {
                cout << "Please enter a task name that is less than 46 characters or less: " << endl;
                getline(cin, name_task);
            }

            //start_date
            string start_date;
            cout << "Please enter the start date of the task in MMDDYYYY format. "<< endl;
            cout << "Example: June 15, 2023 should be entered as 06152023." << endl;
            cin >> start_date;
            while(start_date.size() != 6)
            {
                cout << "Please enter a valid start date in the form of MMDDYYYY: " << endl;
                cin >> start_date;
            }
            
            //due_date
            string due_date;
            cout << "Please enter the due date of the task in MMDDYYYY format: " << endl;
            cout << "Example: June 15, 2023 should be entered as 06152023." << endl;
            cin >> due_date;
            while(due_date.size() != 6)
            {
                cout << "Please enter a valid start date in the form of MMDDYYYY: " << endl;
                cin >> due_date;
            }

            //description
            string description;
            cout<< "Please enter a short description of the task: " <<endl;
            getline(cin, description);

            //tag
            string tag;
            cout << "Please enter a tag for the task: " << endl;
            cin >> tag;
            while(tag.size() > 11)
            {
                cout << "Please enter a tag for the task that is 11 characters or less: " << endl;
                cin >> tag;
            }

            //priority
            int priority;
            cout << "Please enter the priority of the task: (1 - Very Important, 2 - Neutral, 3 - Low Priority) " << endl;
            cin >> priority;
            while(priority != 1 && priority != 2 && priority != 3)
            {
                cout << "Please enter a valid priority that ranges from (1 - Very Important, 2 - Neutral, 3 - Low Priority): " << endl;
                cin >> priority;
            }

            //duration
            double durationHours;
            cout << "Please enter the priority of the task: " << endl;
            cin >> durationHours;

            //status for complete/incomplete
            cout << "Status for this task is set to incomplete by default." << endl;

            //creating task
            Task* mytask= new Task(name_task, description, start_date, due_date, tag, priority,  durationHours, false);
            string fileName = user.GetUserName() + ".txt";//name of the file
            string name= user.GetUserName();
            ofstream myFile(fileName);
            tasks.addTask(myFile, *mytask, name);// need to properly get username
        }
        else if (menuOption == "b")
        {
            Task* currTask;
            cout << "Please enter the name of the task you want to edit" << endl;
            string taskName;
            getline(cin, taskName);
            int i;
            for(i=0; i<user.GetTaskList()->GetTasks().size(); ++i){
                if(user.GetTaskList()->GetTasks().at(i)->GetName() == taskName){
                    currTask = user.GetTaskList()->GetTasks().at(i);
                }
            }
            cout << "Choose an option: " << endl;
            cout << "1 - Edit the name of the task " << endl;
            cout << "2 - Edit the description of the task" << endl;
            cout << "3 - Edit the due date of the task" << endl;
            cout << "4 - Edit the tag of the task" << endl;
            cout << "5 - Edit the priority of the task" << endl;
            cout << "6 - Edit the start date of the task" << endl;
            cout << "7 - Edit the duration of the task" << endl;
            cout << "8 - Edit the completion status of the task" << endl;
            int choice;
            cin >> choice;
            if(choice == 1){
                cout << "Please enter the new name of the task" << endl;
                string new_name;
                getline(cin, new_name);
                currTask->SetName(new_name);
                cout << "The name of your task has been changed to " << new_name << endl; 
            }
            else if(choice == 2){
                cout << "Please enter the new description of the task" << endl;
                string new_desc;
                getline(cin, new_desc);
                currTask->SetDescription(new_desc);
                cout << "The description of your task has been changed to " << new_desc << endl; 
            }
            else if(choice == 3){
                cout << "Please enter the new due date of the task in MM/DD/YYYY format" << endl;
                string new_due_date;
                cin >> new_due_date ;
                currTask->SetDueDate(new_due_date);
                cout << "The due date of your task has been changed to " << new_due_date << endl; 
            }
            else if(choice == 4){
                cout << "Please enter the new tag of the task " << endl;
                string new_tag;
                cin >> new_tag;
                currTask->SetTag(new_tag);
                cout << "The tag of your task has been changed to " << new_tag << endl; 
            }
            else if(choice == 5){
                cout << "Please enter the new priority of the task " << endl;
                int new_priority;
                cin >> new_priority;
                currTask->SetPriority(new_priority);
                cout << "The priority of your task has been changed to " << new_priority << endl; 
            }
            else if(choice == 6){
                cout << "Please enter the new start date of the task in MM/DD/YYYY format" << endl;
                string new_start_date;
                cin >> new_start_date ;
                currTask->SetStartDate(new_start_date);
                cout << "The start date of your task has been changed to " << new_start_date << endl; 
            }
            else if(choice == 7){
                cout << "Please enter the new duration of the task in hours " << endl;
                double new_duration;
                cin >> new_duration;
                currTask->SetDurationHours(new_duration);
                cout << "The duration of your task has been changed to " << new_duration << endl; 
            }
            else if(choice == 8){
                cout << "Please enter '1' to mark your task as complete" << endl;
                cout << "If the task is not yet complete, please enter 0" << endl;
                int comp;
                cin >> comp;
                currTask->SetComplete(comp);
                cout << "The completion status of your task has been changed to " << currTask->GetComplete() << endl; 
            }
            else{
                cout << "Invalid input" << endl;
            }
           
            //cout << "Enter the number of the task you want to edit: " << endl;
            //int taskNum;
            //cin>>taskNum;
            //tasks.editTask(taskName, user_name);
        }
        else if (menuOption == "c")
        {
            cout << "Enter the number of the task you want to delete:" << endl;
            int taskNumber;
            cin >> taskNumber;
            string name= user.GetUserName();
            tasks.removeTask(taskNumber,name);
        }
        else if (menuOption == "d") // View by Tag
        {
            ViewSchedule view;
            view.viewByTag(&user);
        }
        else if (menuOption == "e") // View by Duration
        
        {
            ViewSchedule view;
           view.viewByDuration(&user);
        }
        else if (menuOption == "f") // View by Completion
        {
            ViewSchedule view;
            view.viewByCompletion(&user);
        }
        else if (menuOption == "g") // View by Priority
        {
            ViewSchedule view;
            view.viewByPriority(&user);
        }
        else {
            cout << "Invalid option. Please enter a valid option: ";
        }

}


