#include <gtest/gtest.h>
#include "../include/taskList.h"

TEST(AddTasksTests, FileTest){
    ostringstream out;
    addTask(out, task, Sreeja);
    ASSERT_Q(out.str(), (1, "Sreeja", 1/1/2004, 1/2/2004, "check phone", "look", 2, 2, 0));
}
TEST(DeleteTasks, VectorCheck){
    int size= tasks.size();
    removeTask(2,Sreeja);
    EXPECT_Q(size,size-1);
}
TEST(DeleteTasks, VectorCheck2){
    int size= tasks.size();
    removeTask(1,Sreeja);
    EXPECT_Q(size,size-1);
}

