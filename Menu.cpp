#include "Menu.h"


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
        tasks.addTask();
    }
    else if (menuOption == "b")
    {
        cout << "Enter the name of the task you want to edit: " << endl;
        string taskName;
        getline(cin, taskName);
        tasks.editTask(taskName);
    }
    else if (menuOption == "c")
    {
        cout << "Enter the number of the task you want to delete:" << endl;
        int taskNumber;
        cin >> taskNUmber;
        tasks.removeTask(taskNumber);
    }





}


