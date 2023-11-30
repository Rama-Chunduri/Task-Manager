#pragma once
#include "User.h"
#include <iostream>
#include <vector.h>
#include <algorithm.h>
#include <iomanip.h> 
#include <string.h>
#include <ncurses.h>

using namespace std;

class viewSchedule {
        public: 
                void viewDefault(User * user);

                // groups tasks of the same tag together
                void viewByTag(User * user);

                // longest to shortest duration
                 oid viewByDuration(User* user);

                // complete vs incomplete
                void viewByCompletion(User* user);

                // highest(1) to lowest priority(3)
                void viewByPriority(User* user);

        private: 
                void printCentered(const string * text); // helper function to print centered text 
}