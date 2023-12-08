
#include "User.h"
#include "task.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

User::User(){
	this->userName = "";
	this->password = "";
    this-> name = "";

}

User::User(string _userName, string _password, string _name) {
    this->userName = _userName;
    this->password = _password;
    this->name = _name;
}

string User::GetUserName(){
    return this->userName;
}

string User::GetPassword(){
	return this->password;
}

string User::GetName()
{
    return this-> name;
}

void User::SetUserName (string _userName){
	this->userName = _userName;

}
void User::SetPassword (string _password){
    this->password = _password;

}
void User::SetName(string _name)
{
    this->name = _name;
}


vector<Task> User::loadtasks(){

    //attributes to read in
    vector<Task>tasks; //vector which stores all tasks

   // ofstream myFile(userName + ".txt");
   ifstream myFile;
   string comma;

    string TaskName;
    string TaskDescription;
    string TaskTag;
    string TaskDueDate;
    string TaskStartDate;
    int TaskPriority;
    bool TaskComplete;
    double TaskDuration;

    myFile.open(userName + ".txt");

    //seeing if file opens properly
    if(!(myFile.is_open()))
    {
        cout << "File failed to open." << endl;
        return tasks;
    }

   while(myFile >> TaskName >> comma >> TaskStartDate >> comma >> TaskDueDate >> comma >> TaskDescription >> comma >> TaskTag >> comma >> TaskPriority >> comma >> TaskDuration){
        Task someTask(TaskName, TaskDescription, TaskStartDate, TaskDueDate, TaskTag, TaskPriority, TaskDuration, TaskComplete);
        tasks.push_back(someTask);
   }
    
   
   
    /*string myText;
    ifstream MyReadFile(userName + ".txt");
    while (getline(MyReadFile, myText)) {
        tasks.push_back(myText);
   }
   */

   myFile.close();

   return tasks;
}

 void User::SetTaskList(vector<Task> tasks)
 {
    list.SetTasks(tasks);
 }
 
 taskList User::GetTaskList()
 {
    return this->list;
 }

