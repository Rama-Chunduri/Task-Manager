#include <iostream>
#include "../Remind.h"
#include "../task.h"
#include "../User.h"
#include "gtest/gtest.h"
using namespace std;

TEST(RemindTests, remindTesting1){
    ostringstream oss;
    User user;
    Task task1("Homework1", "Zybooks readings from Chapter 2", "12/10/2023", "12/15/2023", "Math", 1, 7, 1);
    vector<Task> userTasks = user.GetTaskList().GetTasks();
    userTasks.push_back(task1);
    Remind reminds;
    reminds.remind(oss, user);
    EXPECT_EQ(oss.str() , "");
}
TEST(RemindTests, remindTesting2){
    ostringstream oss;
    User user;
    Task task1("Homework2", "Zybooks readings from Chapter 3", "12/11/2023", "12/18/2023", "Science", 1, 9, 0);
    vector<Task> userTasks = user.GetTaskList().GetTasks();
    userTasks.push_back(task1);
    Remind reminds;
    reminds.remind(oss, user);
    EXPECT_EQ(oss.str() , "");
}
TEST(RemindTests, remindTesting3){
    ostringstream oss;
    User user;
    Task task1("Homework3", "Zybooks readings from Chapter 4", "12/17/2023", "12/27/2023", "CS", 1, 4.5, 0);
    vector<Task> userTasks = user.GetTaskList().GetTasks();
    userTasks.push_back(task1);
    Remind reminds;
    reminds.remind(oss, user);
    EXPECT_EQ(oss.str() , "");
}
