#include <gtest/gtest.h>
#include "../User.h"
#include "../task.h"
#include "../taskList.h"


  TEST(UserTest, SetUserName)
{
	User someUser;
	someUser.SetUserName("Sam1");
	EXPECT_EQ(someUser.GetUserName(), "Sam1");
}

TEST(UserTest, SetPassword)
{
	User someUser1;
	someUser1.SetPassword("Password123$");
	ASSERT_EQ(someUser1.GetPassword(), "Password123$");
}

TEST(UserTest, SetName)
{
	User someUser2;
	someUser2.SetName("Samantha");
	ASSERT_EQ(someUser2.GetName(), "Samantha");
}

TEST(TaskTest, SetComplete)
{
Task task8;
task8.SetComplete(false);
EXPECT_EQ(task8.GetComplete(), false);
}
TEST(TaskTest, SetTag)
{
Task task5;
task5.SetTag("chores");
EXPECT_EQ(task5.GetTag(), "chores");
}

TEST(TaskTest, SetName)
{
	Task task1;
task1.SetName("Hw");
EXPECT_EQ(task1.GetName(), "Hw");
}
TEST(TaskTest, SetDescription)
{
	Task task2;
task2.SetDescription("desc");
EXPECT_EQ(task2.GetDescription(), "desc");
}

TEST(TaskTest, SetStartDate)
{
Task task3;
task3.SetStartDate("12/09/2023");
EXPECT_EQ(task3.GetStartDate(), "12/09/2023");
}

TEST(TaskTest, SetDueDate)
{
	Task task4;
task4.SetDueDate("12/10/2023");
EXPECT_EQ(task4.GetDueDate(), "12/10/2023");
}
TEST(TaskTest, SetPriority)
{
	Task task6;
task6.SetPriority(1);
EXPECT_EQ(task6.GetPriority(), 1);
}
TEST(TaskTest, SetDurationHours)
{
	Task task7;
task7.SetDurationHours(2.5);
EXPECT_EQ(task7.GetDurationHours(), 2.5);
}







