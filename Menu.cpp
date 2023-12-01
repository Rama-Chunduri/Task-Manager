#include "Menu.h"
#include "User.h"

void Menu::printMenu()
{
    taskListEdit tasks;
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
        string name;
        cout<<"Please enter the name of the task"<<endl;
        cin>>name;
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

        Task * mytask= new Task(name, description, due_date, tag, priority, start_date, end_date, durationHours);

        fileName = user->GetUserName() + ".txt";//name of the file
        ofstream myFile(fileName);
        addTask(myFile, task);
        tasks.addTask(myFile, mytask);
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
        cout << "Enter the name of the task you want to edit: " << endl;
        string taskName;
        getline(cin, taskName);
        tasks.editTask(taskName);
    }

}


