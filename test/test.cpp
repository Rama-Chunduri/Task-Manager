#include "viewSchedule.h"

#include "gtest/gtest.h"

// Test case for printByTag function
TEST_F(ViewScheduleTest, PrintByTagTest) {
    // Arrange: Set up your User and tasks
    User user;  

    // Add tasks with different tags
    user.getTaskList().addTask(Task("Task1", "Description", "2023-12-01", "Tag1", 1, false, "", "", 0.0));
    user.getTaskList().addTask(Task("Task2", "Description", "2023-12-02", "Tag2", 1, false, "", "", 0.0));
    user.getTaskList().addTask(Task("Task3", "Description", "2023-12-03", "Tag1", 1, false, "", "", 0.0));

    // Act: Call the function
    ViewSchedule viewSchedule;
    ::testing::internal::CaptureStdout();  // Capture the output
    viewSchedule.printByTag(&user);
    string output = ::testing::internal::GetCapturedStdout();  // Get the captured output

    // Assert: Check if the output contains expected information
    EXPECT_THAT(output, ::testing::HasSubstr("Tag1"));
    EXPECT_THAT(output, ::testing::HasSubstr("Tag2"));
    EXPECT_THAT(output, ::testing::HasSubstr("Task1"));
    EXPECT_THAT(output, ::testing::HasSubstr("Task2"));
    EXPECT_THAT(output, ::testing::HasSubstr("Task3"));
}
