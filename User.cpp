
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
    this->name = "";

}

User::User(string _userName, string _password, string _name), {
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
    return this->name;
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
    vector<Task>tasks;
    ofstream myFile(fileName);
    string Taskname;
    string Description;
    string Tag;
    string Duedate;
    string Priority;
    ifstream MyReadFile("filename.txt");
    while (getline (MyReadFile, myText)) {
        tasks.push_back(myText);
   }
   MyReadFile.close();
}

 void User::SetTaskList(vector<Task> tasks)
 {
    this->list = tasks;
 }
 
 taskList* User::GetTaskList()
 {
    return this->list;
 }

