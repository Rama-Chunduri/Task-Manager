#include "task.h"
#include "taskListEdit.h"
#include <vector>
#include <string>
using namespace std;

void taskListEdit::addTask(string newTask){
    Task* toAdd = new Task;
    toAdd->SetName(newTask);
    tasks.push_back(toAdd);
}
void taskListEdit::removeTask(string toRemove){
    int i;
    for(i=0; i<tasks.size(); ++i){
        if((tasks.at(i))->GetName() == toRemove){
            tasks.erase(tasks.begin()+i-1);
            break;
        }
    }
}