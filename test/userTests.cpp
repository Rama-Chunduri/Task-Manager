#include <gtest/gtest.h>
#include "../include/taskList.h"

TEST(UserTest, LoadTasks) {
    // Create a test user
    User someUser("someUser", "Password123$", "Sammy");
    // Create a test file with a single task
    ofstream testFile("testUser.txt");
    testFile << "1, do hw, 12/12/12, 12/13/12, finish worksheets by 9 p.m., math, 1, 2.5, 0";
    testFile.close();
    // Call loadtasks function
    vector<Task> tasks = someUser.loadtasks();
    // Assert that the tasks vector is not empty
    ASSERT_FALSE(tasks.empty());
}

TEST(UserTest, VerifyLoadedTasks) {
    // Create a test user
    User someUser("someUser", "Password123$", "Sammy");

    // Create a test file with sample tasks
    ofstream testFile("testUser.txt");
    testFile << "1, do hw, 12/12/12, 12/13/12, finish worksheets by 9 p.m., math, 1, 2.5, 0";
    testFile << "2, do chores, 2/12/12, 2/13/12, do laundry, chores, 2, 1, 0";
    testFile.close();

    // Call loadtasks function
    vector<Task> tasks = someUser.loadtasks();

    // Verify the correctness of the loaded tasks
    ASSERT_EQ(tasks.size(), 2);

    // Assuming Task objects have appropriate equality comparison operators
    ASSERT_EQ(tasks[0], Task("do hw", "Description1", "2023-01-01", "2023-01-02", "Tag1", 1, 2.5, false));
    ASSERT_EQ(tasks[1], Task("Task2", "Description2", "2023-01-03", "2023-01-04", "Tag2", 2, 1.5, false));
}