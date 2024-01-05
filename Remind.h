#pragma once
#include "User.h"
#include "task.h"
#include "taskList.h"
#include <ctime>
#include <chrono>
using namespace std;


class Remind{
   public:
   void remind(ostream& os, User user);
};
