#include "gtest/gtest.h"
#include "ViewSchedule.h"  // Assuming the header file containing the ViewSchedule class is included

sing namespace std; 

TEST(ViewScheduleTest, TestViewDefault) {
    // Create a User object with sample tasks
    User user("TestUser");
    Task task1("Task1", "Description1", "20220101", "20220102", "Tag1", 2, 1.5, false);
    Task task2("Task2", "Description2", "20220101", "20220102", "Tag2", 1, 2.5, true);
    Task task3("Task3", "Description3", "20220103", "20220104", "Tag3", 3, 3.5, false);
    
    user.GetTaskList().addTask(task1);
    user.GetTaskList().addTask(task2);
    user.GetTaskList().addTask(task3);

    // Redirect cout to a stringstream to capture the output
    stringstream capturedOutput;
    streambuf* originalCout = cout.rdbuf();
    cout.rdbuf(capturedOutput.rdbuf());

    // Call the function to be tested
    ViewSchedule view;
    view.viewDefault(&user);

    // Restore cout to the original buffer
    scout.rdbuf(originalCout);

    // Check the captured output against the expected result
    string expectedOutput =
        " Priority | Task                                     | Tag          | Status     \n"
        "+-------------------------------------------------------------------------------------+\n"
        " Due Date 20220102\n"
        "+-------------------------------------------------------------------------------------+\n"
        "    1     | Task1                                    | Task1        | Inomplete\n"
        "    2     | Task2                                    | Task2        | Complete\n"
        "+-------------------------------------------------------------------------------------+\n"       
        " Due Date 20220104\n"
        "+-------------------------------------------------------------------------------------+\n"
        "    3     | Task3                                    | Task3        | Inomplete\n";

    ASSERT_EQ(capturedOutput.str(), expectedOutput);
}



// Test case for viewByDuration
TEST_F(ViewScheduleTest, ViewByDurationTest) {
    // Arrange
    std::ostringstream oss;  // Capture cout output
    ViewSchedule view;

    // Create a mock user with tasks
    MockUser user;
    user.GetTaskList().addTask(Task("Task1", "Description1", "20230101", "20230102", "Tag1", 1, 2.5, false));
    user.GetTaskList().addTask(Task("Task2", "Description2", "20230201", "20230203", "Tag2", 2, 1.5, false));
    user.GetTaskList().addTask(Task("Task3", "Description3", "20230301", "20230304", "Tag3", 3, 3.0, false));

    // Act
    view.viewByDuration(&user);
    std::string actualOutput = oss.str();

    // Assert - Assuming that the tasks are sorted in ascending order of duration
    ASSERT_NE(actualOutput.find("1.5"), std::string::npos);
    ASSERT_NE(actualOutput.find("2.5"), std::string::npos);
    ASSERT_NE(actualOutput.find("3.0"), std::string::npos);
    ASSERT_LT(actualOutput.find("1.5"), actualOutput.find("2.5"));
    ASSERT_LT(actualOutput.find("2.5"), actualOutput.find("3.0"));
}



// Test case for viewByPriority
TEST_F(ViewScheduleTest, ViewByPriorityTest) {
    // Arrange
    std::ostringstream oss;  // Capture cout output
    ViewSchedule view;

    // Create a mock user with tasks
    MockUser user;
    user.GetTaskList().addTask(Task("Task1", "Description1", "20230101", "20230102", "Tag1", 1, 2.5, false));
    user.GetTaskList().addTask(Task("Task2", "Description2", "20230201", "20230203", "Tag2", 2, 1.5, false));
    user.GetTaskList().addTask(Task("Task3", "Description3", "20230301", "20230304", "Tag3", 1, 3.0, false));

    // Act
    view.viewByPriority(&user);
    std::string actualOutput = oss.str();

    // Assert - Assuming that the tasks are sorted in descending order of priority and then by due date within each priority
    ASSERT_NE(actualOutput.find("Priority 1"), std::string::npos);
    ASSERT_NE(actualOutput.find("Priority 2"), std::string::npos);
    ASSERT_LT(actualOutput.find("Priority 1"), actualOutput.find("Priority 2"));

    ASSERT_NE(actualOutput.find("20230102"), std::string::npos);
    ASSERT_NE(actualOutput.find("20230304"), std::string::npos);
    ASSERT_LT(actualOutput.find("20230102"), actualOutput.find("20230304"));
}



