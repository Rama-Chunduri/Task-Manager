#include <iostream>
#include "task.h"
#include "taskListEdit.h"
using namespace std;

int main(){
    string task1 = "eat";
    taskListEdit* x = new taskListEdit;
    x->addTask(task1);
    return 0;
}