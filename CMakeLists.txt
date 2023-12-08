CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

project(TaskOrganizer)

ADD_SUBDIRECTORY(googletest)



ADD_EXECUTABLE(
    main.cpp
    task.cpp
    taskList.cpp
    remind.cpp
    editTask.cpp
    viewSchedul.cpp
    Menu.cpp
)

ADD_EXECUTABLE(runAllTests
    ./test/taskListtest.cpp
    ./test/test_rem.cpp
    ./test/testViewSchedule.cpp
    ./test/userTests.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)




















ADD_EXECUTABLE(main
    main.cpp
)

ADD_EXECUTABLE(runAllTests
    ./test/taskListtest.cpp
    ./test/test_rem.cpp
    ./test/testViewSchedule.cpp
    ./test/userTests.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
