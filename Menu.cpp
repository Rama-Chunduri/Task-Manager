#include "Menu.h"
#include "User.h"
#include "taskList.h"

void Menu::printMenu(string user_name)
{
    taskList tasks;
    cout << "MENU:" << endl;
    cout << "a - Create a Task" << endl;
    cout << "b - Edit a Task" << endl;
    cout << "c - Delete a Task" << endl;
    cout << "q - Exit to Homepage" << endl;


    string menuOption;
    cin >> menuOption;
    while(menuOption != "a" || menuOption != "b" || menuOption != "c" || menuOption != "q")
    {
        cout << "Enter a valid input." << endl;
        cin >> menuOption;
    }


    if(menuOption == "a")
    {
        string name_task;
        cout<<"Please enter the name of the task"<<endl;
        cin>>name_task;
        string start_date;
        cout<<"Please enter the start date of the task"<<endl;
        cin>>start_date;
        string end_date;
        cout<<"Please enter the end date of the task"<<endl;
        cin>>end_date;
        string due_date;
        cout<<"Please enter the due date of the task"<<endl;
        cin>>due_date;
        string description;
        cout<<"Please enter a description of the task"<<endl;
        cin>>description;
        string tag;
        cout<<"Please enter the tag of the task"<<endl;
        cin>>tag;
        string priority;
        cout<<"Please enter the priority of the task"<<endl;
        cin>>priority;
        int durationHours;
        cout<<"Please enter the priority of the task"<<endl;
        cin>>durationHours;

        Task * mytask= new Task(name_task, description, due_date, tag, priority, start_date, end_date, durationHours);

        fileName = user_name + ".txt";//name of the file
        ofstream myFile(fileName);
        tasks.addTask(myFile, mytask, user_name);// need to properly get username
    }
    else if (menuOption == "c")
    {
        cout << "Enter the number of the task you want to delete:" << endl;
        int taskNumber;
        cin >> taskNUmber;
        tasks.removeTask(taskNumber);
    }
      else if (menuOption == "b")
    {
        //rama
        cout << "Enter the number of the task you want to edit: " << endl;
        int taskNum;
        cin>>taskNum;
        tasks.editTask(taskName, user_name);
    }

}


