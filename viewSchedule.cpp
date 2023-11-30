#include "viewSchedule.h"

using namespace std;

// longest to shortest duration
void viewByDuration(User* user) {

}






// complete vs incomplete
void viewByCompletion(User* user) {

}






// highest(1) to lowest priority(3)
void viewByPriority(User* user) {

}






// groups tasks of the same tag together
void ViewSchedule :: viewByTag(User* user)  
{
    vector<Task> tasks = user->getTaskList().getTasks();

    //get unique tags 
    vector<string>uniqueTags;
    Task taskIterator = tasks.at(0);

    for (int i = 0; i < tasks.size(); ++i) {
    
        // if tag is not found in uniqueTags
        if (find(uniqueTags.begin(), uniqueTags.end(), iterator.getTag()) == uniqueTags.end()) {
            uniqueTags.push_back(task.getTag());
        }
    }

    cout << " Due Date    | Task " << endl;
    cout << "+----------------------------------------------------+" << endl;


    //iterate over unique tags and print tasks for each tag 
    string tagIterator = uniqueTags.at(0);
    taskIterator = tasks.at(0);

    for (int i = 0; i < uniqueTag.size(); ++i) {
        cout << tagIterator << endl;
        cout << "+----------------------------------------------------+" << endl;

        //iterate over tasks and print details for tasks with the current tag
        for (int i = 0; i < uniqueTasks.size(); ++i) {
            if (task.getTag() == tagIterator)
                //print task details as needed 
                cout << " " << task.getDueDate() << " | " << task.getName() << endl;
        }
        cout << endl;
    }
}






void viewPages :: printCentered(const string text) {
    int x;
    int y; 

    getmaxyx(stdscr, y, x); // gets dimensions of the terminal window 
    
    int len = strlen(text);
    int centeredX = (x - len) / 2;
    int centeredY = y / 2;

    mvprintw(centeredY, centeredX, "%s", text);
    refresh();
}