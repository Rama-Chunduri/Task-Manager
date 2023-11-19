#pragma once
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

}

User::User(string _userName, string _password){
    this->userName = _userName;
    this->password = _password;
}

string User::GetUserName(){
    return this->userName;
}

string User::GetPassword(){
	return this->password;
}
	
void User::SetUserName (string _userName){
	this->userName = _userName;

}
void User::SetPassword (string _password){
    this->password = _password;

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