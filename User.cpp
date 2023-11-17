#include "user.h"
#include "task.h" //aggregation has a relationship
                 //composition cannot exist parent dies, child dies
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

void User::loadtasks(){
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