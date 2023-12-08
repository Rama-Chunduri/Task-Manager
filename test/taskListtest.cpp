#include <gtest/gtest.h>
#include "../include/taskList.h"

TEST(AddTasksTests, FileTest){
    ostringstream out;
    addTask(out, task, Sreeja);
    ASSERT_Q(out.str(), "1, Sreeja, Dec 2, Dec 8, Dec 9, fill out my phone data, work, 6");
}
TEST(AddTasksTests, FileTest1){
    ostringstream out;
    addTask(out, task, Shivani);
    ASSERT_Q(out.str(), "2, Shivani, Dec 2, Dec 8, Dec 9, smell my buttcrack, work, 6");
}
TEST(AddTasksTests, VectorTest1){
    ostringstream out;
    addTask(out);
    ASSERT_Q(out.str(), "2, Shivani, Dec 2, Dec 8, Dec 9, smell my buttcrack, work, 6");
}
TEST(DeleteTasks, VectorCheck){
    int size= tasks.size();
    removeTask(2,Sreeja);
    EXPECT_Q(size,size-1);
}

