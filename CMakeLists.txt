CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

project(TaskOrganizer)

ADD_SUBDIRECTORY(googletest)



ADD_EXECUTABLE(
    main.cpp
    task.cpp
    taskList.cpp
    Remind.cpp
    viewSchedule.cpp
    Menu.cpp
)

ADD_EXECUTABLE(runAllTests
    ./test/taskListtest.cpp
    ./test/test_rem.cpp
    ./test/testViewSchedule.cpp
    ./test/userTests.cpp
)

TARGET_LINK_LIBRARIES(runAllTests gtest)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE gtest_disable_pthreads=ON)