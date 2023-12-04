#include "Menu.h"
#include "User.h"
#include "taskList.h"

void Menu::printMenu(User user)
{
    taskList tasks;
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
    string menuOption = "x";
    //cin >> menuOption;
    while(menuOption != "q")
        cout << "MENU:" << endl;
        cout << "a - Create a Task" << endl;
        cout << "b - Edit a Task" << endl;
        cout << "c - Delete a Task" << endl;
        cout << "q - Exit to Homepage" << endl;
        cout << "Enter a valid input." << endl;
        cin >> menuOption;
        if(menuOption == "a")
        {
            string name_task;
            cout << "Please enter the name of the task" << endl;
            cin >> name_task;
            string start_date;
            cout << "Please enter the start date of the task"<<endl;
            cin >> start_date;
            //string end_date;
            //cout<<"Please enter the end date of the task"<<endl;
            //cin>>end_date;
            string due_date;
            cout << "Please enter the due date of the task" << endl;
            cin >> due_date;
            string description;
            cout<< "Please enter a description of the task" <<endl;
            cin >> description;
            string tag;
            cout << "Please enter a tag for the task" << endl;
            cin >> tag;
            string priority;
            cout << "Please enter the priority of the task" << endl;
            cin >> priority;
            int durationHours;
            cout << "Please enter the priority of the task" << endl;
            cin >> durationHours;

            Task* mytask= new Task(name_task, description, due_date, tag, priority, start_date, /*end_date*/, durationHours, 0);

            fileName = user_name + ".txt";//name of the file
            ofstream myFile(fileName);
            tasks.addTask(myFile, mytask, user_name);// need to properly get username
        }
        else if (menuOption == "b")
        {
            Task* currTask;
            cout << "Please enter the name of the task you want to edit" << endl
            string taskName;
            getline(cin, taskName);
            int i;
            for(i=0; i<user.GetTaskList().getTask().size(); ++i){
                if(user.GetTaskList().getTask().at(i).GetName() == taskName){
                    currTask = user.GetTaskList().getTask().at(i);
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
                currTask.SetName(new_name);
                cout << "The name of your task has been changed to " << new_name << endl; 
            }
            else if(choice == 2){
                cout << "Please enter the new description of the task" << endl;
                string new_desc;
                getline(cin, new_desc);
                currTask.SetDescription(new_desc);
                cout << "The description of your task has been changed to " << new_desc << endl; 
            }
            else if(choice == 3){
                cout << "Please enter the new due date of the task in MM/DD/YYYY format" << endl;
                string new_due_date;
                cin >> new_due_date ;
                currTask.SetDueDate(new_due_date);
                cout << "The due date of your task has been changed to " << new_due_date << endl; 
            }
            else if(choice == 4){
                cout << "Please enter the new tag of the task " << endl;
                string new_tag;
                cin >> new_tag;
                currTask.SetTag(new_tag);
                cout << "The tag of your task has been changed to " << new_tag << endl; 
            }
            else if(choice == 5){
                cout << "Please enter the new priority of the task " << endl;
                int new_priority;
                cin >> new_priority;
                currTask.SetTag(new_priority);
                cout << "The priority of your task has been changed to " << new_priority << endl; 
            }
            else if(choice == 6){
                cout << "Please enter the new start date of the task in MM/DD/YYYY format" << endl;
                string new_start_date;
                cin >> new_start_date ;
                currTask.SetStartDate(new_start_date);
                cout << "The start date of your task has been changed to " << new_start_date << endl; 
            }
            else if(choice == 7){
                cout << "Please enter the new duration of the task in hours " << endl;
                double new_duration;
                cin >> new_duration;
                currTask.SetDurationHours(new_priority);
                cout << "The duration of your task has been changed to " << new_duration << endl; 
            }
            else if(choice == 7){
                cout << "Please enter the new duration of the task in hours " << endl;
                double new_duration;
                cin >> new_duration;
                currTask.SetDurationHours(new_priority);
                cout << "The duration of your task has been changed to " << new_duration << endl; 
            }
            else if(choice == 8){
                cout << "Please enter '1' to mark your task as complete" << endl;
                cout << "If the task is not yet complete, please enter 0"
                int comp;
                cin >> comp;
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
            cin >> taskNUmber;
            tasks.removeTask(taskNumber);
        }

}


