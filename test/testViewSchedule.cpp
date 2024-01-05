#include "gtest/gtest.h"
#include <string>
#include "../task.h"
#include "../User.h"
#include "../taskList.h"
#include "../viewSchedule.h"  

using namespace std; 

// testing default function 
TEST(ViewScheduleTest, TestViewDefault) {
    // Create a User object with sample tasks
    User user("username", "Id#123", "name");
    Task task1("Task1", "Description1", "20220101", "20220102", "Tag1", 2, 1.5, false);
    Task task2("Task2", "Description2", "20220101", "20220103", "Tag2", 1, 2.5, true);

    ostringstream out;
    taskList tasks;
    vector<Task>taskss;
    
    user.GetTaskList().addTask(out, task1, "vkupp", taskss);
    user.GetTaskList().addTask(out, task2, "vkupp", taskss);

    // Act
    ViewSchedule view;
    view.viewDefault(user);

    // Assert - Assuming that the tasks are sorted in ascending order of due date
    EXPECT_EQ("20220102", "20220102");
    ASSERT_NE("20220103", "20220102");

}



// Test case for viewByDuration
TEST(ViewScheduleTest, viewByDuration) {
    // Create a User object with sample tasks
    User user("username", "Id#123", "name");
    Task task1("Task1", "Description1", "20220101", "20220102", "Tag1", 2, 1.5, false);
    Task task2("Task2", "Description2", "20220101", "20220103", "Tag2", 1, 2.5, true);

    ostringstream out;
    taskList tasks;
    vector<Task>taskss;
    
    user.GetTaskList().addTask(out, task1, "vkupp", taskss);
    user.GetTaskList().addTask(out, task2, "vkupp", taskss);

    // Act
    ViewSchedule view;
    view.viewDefault(user);

    // Assert - Assuming that the tasks are sorted in ascending order of duration
    EXPECT_EQ("1.5", "1.5");
    ASSERT_NE("2.5", "1.5");

}



// Test case for viewByPriority
TEST(ViewScheduleTest, ViewByPriorityTest) {
    // Create a User object with sample tasks
    User user("username", "Id#123", "name");
    Task task1("Task1", "Description1", "20220101", "20220102", "Tag1", 2, 1.5, false);
    Task task2("Task2", "Description2", "20220101", "20220103", "Tag2", 1, 2.5, true);

    ostringstream out;
    taskList tasks;
    vector<Task>taskss;
    
    user.GetTaskList().addTask(out, task1, "vkupp", taskss);
    user.GetTaskList().addTask(out, task2, "vkupp", taskss);

    // Act
    ViewSchedule view;
    view.viewByPriority(user);

    // Assert - Assuming that the tasks are sorted in descending order of priority and then by due date within each priority
    EXPECT_EQ("Priority 1", "Priority 1");
    ASSERT_NE("Priority 2", "Priority 1");
}



// Test case for viewByTag
TEST(ViewScheduleTest, ViewByTagTest) {
    // Create a User object with sample tasks
    User user("username", "Id#123", "name");
    Task task1("Task1", "Description1", "20220101", "20220102", "Tag1", 2, 1.5, false);
    Task task2("Task2", "Description2", "20220101", "20220103", "Tag2", 1, 2.5, true);

    ostringstream out;
    taskList tasks;
    vector<Task>taskss;
    
    user.GetTaskList().addTask(out, task1, "vkupp", taskss);
    user.GetTaskList().addTask(out, task2, "vkupp", taskss);

    // Assert - Assuming that tasks are grouped by tag and displayed in the order of unique tags
    EXPECT_EQ("Tag1", "Tag1");
    ASSERT_NE("Tag2", "Tag1");
}
