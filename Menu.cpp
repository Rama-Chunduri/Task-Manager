#include "Menu.h"
#include "User.h"
#include "task.h"
#include "taskList.h"
#include "viewSchedule.h"
#include "Remind.h"

#include <string>


void Menu::printMenu(User& user)
{
   vector<Task> someTask = user.loadtasks();
   cout << someTask.size() << endl;
   user.SetTaskList(someTask);
   taskList tasks = user.GetTaskList();

   for(unsigned int i = 0; i < someTask.size(); ++i)
   {
        cout << someTask.at(i).GetName() << endl;
   }

   //Remind rem;
   //cout << "apple" << endl;
  // rem.remind(cout, user);
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
    string due_date;
    string menuOption = "";
    //cin >> menuOption;
    while(menuOption != "x"){
            cout << "MENU:" << endl;
            cout << "a - Create a Task" << endl;
            cout << "b - Edit a Task" << endl;
            cout << "c - Delete a Task" << endl;
            
            cout << "d - View by Tag" << endl;
            cout << "e - View by Duration" << endl;
            cout << "f - View by Completion" << endl;
            cout << "g - View by Priority" << endl;

            cout << "x - Logout" << endl;
            cout << "Enter a valid input." << endl;
            cin >> menuOption;
            cin.ignore();
           

            while(menuOption != "a" && menuOption != "b" && menuOption != "c" && menuOption != "d" && menuOption != "e" && menuOption != "f" && menuOption != "g" && menuOption != "x")
            {
                cout << "Invalid input. Please enter a valid option: " << endl;
                cin >> menuOption;
            
            }  

            if(menuOption == "a")
            {
                //task name
                string name_task;
                cout << "Please enter the name of the task: " << endl;
                getline(cin, name_task);
                //cin.ignore();
                while(name_task.size() > 46)
                {
                    cout << "Please enter a task name that is less than 46 characters or less: " << endl;
                    getline(cin, name_task);
                   // cin.ignore();
                }
            
                
                //start_date
                cout << "Start Date:"<< endl;
                //month
                int startMonth;
                cout << "Enter the month (from 1 to 12): " << endl;
                cin >> startMonth;
                while(startMonth > 12 || startMonth < 1 || isalpha(startMonth))
                {
                    cout << "Please enter a valid month: " << endl;
                    cin >> startMonth;
                }

                //day
                int startDay;
                cout << "Enter the day (from 1 to 31): " << endl;
                cin >> startDay;
                while(startDay > 31 || startDay < 1)
                {
                    cout << "Please enter a valid day: " << endl;
                    cin >> startDay;
                }

                //year
                int startYear; 
                cout << "Please enter the year (format: YYYY): " << endl;
                cin >> startYear;
                while(startYear > 9999 || startYear < 1)
                {
                    cout << "Please enter a valid year: " << endl;
                    cin >> startYear;
                }

                string start_date = to_string(startMonth) + "/" + to_string(startDay) + "/" + to_string(startYear);

                cout << "Entered start date: " << start_date << endl;

            
               cin.ignore();
                //due_date

                int dueMonth;
                int dueDay;
                int dueYear;

            do{

                cout << "Due Date:"<< endl;
                    //month
                   
                    cout << "Enter the month (from 1 to 12): " << endl;
                    cin >> dueMonth;
                    while(dueMonth > 12 || dueMonth < 1)
                    {
                        cout << "Please enter a valid month: " << endl;
                        cin >> dueMonth;
                    }

                    //day
                   
                    cout << "Enter the day (from 1 to 31): " << endl;
                    cin >> dueDay;
                    while(dueDay > 31 || dueDay < 1)
                    {
                        cout << "Please enter a valid day: " << endl;
                        cin >> dueDay;
                    }

                    //year
                   
                    cout << "Please enter the year (format: YYYY): " << endl;
                    cin >> dueYear;
                    while(dueYear > 9999 || dueYear < 1)
                    {
                        cout << "Please enter a valid year: " << endl;
                        cin >> dueYear;
                    }

                    due_date = to_string(dueMonth) + "/" + to_string(dueDay) + "/" + to_string(dueYear);

                    cout << "Entered due date: " << due_date << endl;

                    if(startYear == dueYear && ((startMonth > dueMonth) || (startMonth == dueMonth && startDay > dueDay)))
                    {
                        cout << "Error: start date is after the due date. Please re-enter the dates:" << endl;
                    }
            }
            while((startYear == dueYear && ((startMonth > dueMonth) || (startMonth == dueMonth && startDay > dueDay))));
            
                
                //description
                cin.ignore();
                string description;
                cout<< "Please enter a short description of the task: " <<endl;
                getline(cin, description);

                //tag
                string tag;
                cout << "Please enter a tag for the task: " << endl;
                getline(cin,tag);
            

                while(tag.size() > 11)
                {
                    cout << "Please enter a tag for the task that is less than 10 characters: " << endl;
                    getline(cin, tag);
                    cin.ignore();
                }
                

                //priority
                int priority;
                cout << "Please enter the priority of the task: (1 - Very Important, 2 - Neutral, 3 - Low Priority) " << endl;
                cin >> priority;
                cin.ignore();

                while(priority != 1 && priority != 2 && priority != 3)
                {
                    cout << "Please enter a valid priority that ranges from (1 - Very Important, 2 - Neutral, 3 - Low Priority): " << endl;
                    cin >> priority;
                    cin.ignore();
                }

                //duration
                double durationHours;
                cout << "Please enter the duration of the task in hours: " << endl;
                cin >> durationHours;
                cin.ignore();

                while(durationHours < 0)
                {
                    cout << "Please enter a valid duration: " << endl;
                    cin >> durationHours;
                    cin.ignore();
                }

                //status for complete/incomplete
                cout << "Status for this task is set to incomplete by default." << endl;

                //creating task
                Task mytask= Task(name_task, description, start_date, due_date, tag, priority,  durationHours, false);
                string fileName = user.GetUserName() + ".txt";//name of the file
                string nameOfUser= user.GetUserName();
                vector<Task>taskss;
                taskss=user.loadtasks();
                mytask.SetName(name_task);
                ofstream myFile(fileName, ios::app);
                tasks.addTask(myFile, mytask, nameOfUser,taskss);// need to properly get username
            
            }
            else if (menuOption == "b")
            {
                Task currTask;
                cout << "Please enter the name of the task you want to edit" << endl;
                string taskName;
                getline(cin, taskName);
                int i;
                for(i=0; i<user.GetTaskList().GetTasks().size(); ++i){
                    if(user.GetTaskList().GetTasks().at(i).GetName() == taskName){
                        currTask = user.GetTaskList().GetTasks().at(i);
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
                cin.ignore();

                if(choice == 1){
                    cout << "Please enter the new name of the task" << endl;
                    string new_name;
                    getline(cin, new_name);
                    while(new_name.size() > 46)
                    {
                        cout << "Please enter a task name that is less than 46 characters or less: " << endl;
                        getline(cin, new_name);
                    }
                    currTask.SetName(new_name);
                    cout << "The name of your task has been changed to " << new_name << endl; 
                }
                else if(choice == 2){
                    cout << "Please enter the new description of the task: " << endl;
                    string new_desc;
                    getline(cin, new_desc);
                    currTask.SetDescription(new_desc);
                    cout << "The description of your task has been changed to " << new_desc << endl; 
                }
                else if(choice == 3){
                    cout << "Please enter the new due date of the task in MMDDYYYY format." << endl;
                    cout << "Example: June 15, 2023 should be entered as 06152023." << endl;
                    string new_due_date;
                    cin >> new_due_date;
                    while(new_due_date.size() != 8)
                    {
                        cout << "Please enter a valid due date in the form of MMDDYYYY: " << endl;
                        cin >> new_due_date;
                    }   
                    currTask.SetDueDate(new_due_date);
                    cout << "The due date of your task has been changed to " << new_due_date << endl; 
                }
                else if(choice == 4){
                    cout << "Please enter the new tag of the task " << endl;
                    string new_tag;
                    cin >> new_tag;
                    while(new_tag.size() > 11)
                    {
                        cout << "Please enter a tag for the task that is 11 characters or less: " << endl;
                        cin >> new_tag;
                    }

                    currTask.SetTag(new_tag);
                    cout << "The tag of your task has been changed to " << new_tag << endl; 
                }
                else if(choice == 5){
                    cout << "Please enter the new priority of the task that ranges from (1 - Very Important, 2 - Neutral, 3 - Low Priority): " << endl;
                    int new_priority;
                    cin >> new_priority;
                    while(new_priority != 1 && new_priority != 2 && new_priority != 3)
                    {
                        cout << "Please enter a valid priority that ranges from (1 - Very Important, 2 - Neutral, 3 - Low Priority): " << endl;
                        cin >> new_priority;
                    }

                    currTask.SetPriority(new_priority);
                    cout << "The priority of your task has been changed to " << new_priority << endl; 
                }
                else if(choice == 6){
                    string new_start_date;
                    cout << "Start Date:"<< endl;
                    //month
                    int new_startMonth;
                    cout << "Enter the month (from 1 to 12): " << endl;
                    cin >> new_startMonth;
                    while(new_startMonth > 12 || new_startMonth < 1)
                    {
                        cout << "Please enter a valid month: " << endl;
                        cin >> new_startMonth;
                    }

                    //day
                    int new_startDay;
                    cout << "Enter the day (from 1 to 31): " << endl;
                    cin >> new_startDay;
                    while(new_startDay > 31 || new_startDay < 1)
                    {
                        cout << "Please enter a valid day: " << endl;
                        cin >> new_startDay;
                    }

                    //year
                    int new_startYear; 
                    cout << "Please enter the year (format: YYYY): " << endl;
                    cin >> new_startYear;
                    while(new_startYear > 9999 || new_startYear < 1)
                    {
                        cout << "Please enter a valid year: " << endl;
                        cin >> new_startYear;
                    }

                    string start_dateNew = to_string(new_startMonth) + "/" + to_string(new_startMonth) + "/" + to_string(new_startYear);

                
                    cin.ignore();
                    currTask.SetStartDate(new_start_date);
                    cout << "The start date of your task has been changed to " << new_start_date << endl; 
                }
                else if(choice == 7){
                    cout << "Please enter the new duration of the task in hours " << endl;
                    double new_duration;
                    cin >> new_duration;

                     while(new_duration < 0)
                    {
                        cout << "Please enter a valid duration: " << endl;
                        cin >> new_duration;
                        cin.ignore();
                    }
                    currTask.SetDurationHours(new_duration);
                    cout << "The duration of your task has been changed to " << new_duration << endl; 
                }
                else if(choice == 8){
                    cout << "Please enter '1' to mark your task as complete" << endl;
                    cout << "If the task is not yet complete, please enter 0" << endl;
                    int comp;
                    cin >> comp;
                    while(comp!= 1 && comp != 0)
                    {
                        cout << "Please enter a valid input. Enter '1' to mark your task complete and '0' to mark your task incomplete." << endl;
                        cin >> comp;
                    }
                    currTask.SetComplete(comp);
                    cout << "The completion status of your task has been changed to " << currTask.GetComplete() << endl; 
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
            else if (menuOption == "x"){
                cout << "Logging out!" << endl;
            }
    }

}


