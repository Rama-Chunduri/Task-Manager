#include "viewPages.h"
#include <iomanip> 

using namespace std;


void viewPages :: viewCreateAccount(User * user) {

}

void viewPages :: viewLogin(User * user) {

}
        
void viewPages:: viewHome(User * user) {

}

void viewPages ::viewToDo(User * user) {

}

void viewPages :: viewAddTask(User * user) {

}
        
void viewPages :: viewRemoveTask(User * user) {

}
        
void viewPages :: viewEditTask(User * user) {

}









// // groups tasks of the same tag together
// void viewSchedule :: printByTag(User* user)  
// {
//     vector<Task> tasks = user->getTaskList().getTasks();

//     //get unique tags 
//     vector<string>uniqueTags;
//     Task taskIterator = tasks.at(0);

//     for (int i = 0; i < tasks.size(); ++i) {
    
//         // if tag is not found in uniqueTags
//         if (find(uniqueTags.begin(), uniqueTags.end(), iterator.getTag()) == uniqueTags.end()) {
//             uniqueTags.push_back(task.getTag());
//         }
//     }

//     //iterate over unique tags and print tasks for each tag 
//     string tagIterator = uniqueTag.at(0);
//     taskIterator - tasks.at(0);

//     for (int i = 0; i < uniqueTag.size(); ++i) {
//         cout << "+--------------------- " << tagIterator << " ---------------------+" << endl;

//         //iterate over tasks and print details for tasks with the current tag
//         for (int i = 0; i < uniqueTasks.size(); ++i) {
//             if (task.getTag() == tagIterator)
//                 //print task details as needed 
//                 cout << "| " << task.getDueDate() << " - " << task.getName() << endl;
//         }
//     }

//     cout << "+---------------------------------------------------+" << endl;

// }

