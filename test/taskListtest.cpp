#include <gtest/gtest.h>
#include "../include/taskList.h"

TEST(AddTasksTests, FileTest){
    ostringstream out;
    addTask(out, task, vkupp);
    ASSERT_Q(out.str(), "task 4, 3/3/3, 4/4/4, desc5, tag5, 2, 5.5, 1");
}
TEST(AddTasksTests, FileTest1){
    ostringstream out;
    addTask(out, task, vkupp);
    ASSERT_Q(out.str(), "task 3, 3/3/3, 4/4/4, desc4, tag4, 3, 4.4, 0");
}
TEST(DeleteTasks, VectorCheck){
    int size= tasks.size();
    removeTask(2,vkupp);
    EXPECT_Q(size,size-1);
}
TEST(DeleteTasks, VectorCheck){
    int size= tasks.size();
    removeTask(1,vkupp);
    EXPECT_Q(size,size-1);
}

