#include <iostream>
#include "Remind.h"

#include "gtest/gtest.h"
using namespace std;

TEST(RemindTests, remindTesting){
    ostringstream oss;
    User user;
    Task task1("Homework", "Zybooks readings from Chapter 1", "12/10/2023", "12/13/2023", "CS", 1, 4.5, 0);
    vector<Task> userTasks = user.getTaskList().getTasks();
    userTasks.push_back(task1);
    remind(oss, user);
    assert(oss && oss.str() == "Task name: Homework\n" + "Tag: CS\n" + "Description: Zybooks readings from Chapter 1\n" + "Due Date: 12/13/2023\n" + "Priority: 1\n" + "Start Date: 12/10/2023\n" + "Duration Hours: 4.5\n" + "Completion Status: Not Complete\n");
}