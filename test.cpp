#include <gtest/gtest.h>
#include "../include/taskList.cpp"

TEST(AddTasksTests, FileTest){
    ostringstream out;
    addTask(out);
    ASSERT_Q(out.str(), "1, Sreeja, Dec 2, Dec 8, Dec 9, fill out my phone data, work, 6");
}

