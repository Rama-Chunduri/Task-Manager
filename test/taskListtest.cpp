#include <gtest/gtest.h>
#include "../task.h"
#include "../taskList.h"
#include "../User.h"

TEST(AddTasksTests, FileTest){
    ostringstream out;
    Task task = Task("task 4", "desc5", "3/3/3", "4/4/4", "tag5", 2,  5.5, true);
    taskList tasks;
    vector<Task>taskss;
    tasks.addTask(out, task, "vkupp", taskss);
    ASSERT_EQ(out.str(), "task 4, 3/3/3, 4/4/4, desc5, tag5, 2, 5.5, 1\n");
}


TEST(DeleteTasks, VectorCheck){
    ostringstream out;
    Task task = Task("task 4", "desc5", "3/3/3", "4/4/4", "tag5", 2,  5.5, true);
    taskList tasks;
    vector<Task>taskss;
    tasks.addTask(out, task, "vkupp", taskss);
    int size= taskss.size();
    //ASSERT_EQ(size,1);
    tasks.removeTask(1,"vkupp");
    size= taskss.size();
    ASSERT_EQ(size,0);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
