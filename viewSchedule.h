#pragma once
#include "User.h"
#include "task.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> 
#include <string>

using namespace std;

class viewSchedule {
        public: 
                void viewDefault(User * user);

                // groups tasks of the same tag together
                void viewByTag(User * user);

                // longest to shortest duration
                void viewByDuration(User* user);

                // complete vs incomplete
                void viewByCompletion(User* user);

                // highest(1) to lowest priority(3)
                void viewByPriority(User* user);
}