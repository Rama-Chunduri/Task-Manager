
#include "User.h"
#include "task.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

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
   string whitespace;

    string TaskName;
    string TaskDescription;
    string TaskTag;
    string TaskDueDate;
    string TaskStartDate;
    int TaskPriority;
    bool TaskComplete;
    double TaskDuration;

   

    string nameOfFile = userName + ".txt";
    myFile.open(nameOfFile, ios::in | ios::app);
    //seeing if file opens properly
    if(!(myFile.is_open()))
    {
        cout << "File failed to open." << endl;
        return tasks;
    }


   
   
       // cout << "Read Task: " << TaskName << " task name " << TaskStartDate << " sd " << TaskDueDate << "  dd " << TaskDescription << " td  " << TaskTag << " tt  " << TaskPriority << " tp " << TaskDuration << " dur "<< TaskComplete << " bool " << endl;

   
   while(getline(myFile, TaskName, ',') && getline(myFile, TaskStartDate, ',') && getline(myFile, TaskDueDate, ',') && getline(myFile, TaskDescription, ',') && getline(myFile, TaskTag, ',')){
   
        string TaskPriorityStr;
        getline(myFile, TaskPriorityStr, ',');
        TaskPriority = stoi(TaskPriorityStr);

        string TaskDurationStr;
        getline(myFile, TaskDurationStr, ',');
        TaskDuration = stod(TaskDurationStr);

        int TaskCompleteInt;
        myFile >> TaskCompleteInt;

        TaskComplete = (TaskCompleteInt == 1);
        cout << "Read Task: " << TaskName << " " << TaskStartDate << " " << TaskDueDate << " " << TaskDescription << " " << TaskTag << " " << TaskPriority << " " << TaskDuration << endl;
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

