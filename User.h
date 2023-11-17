#pragma once
#include <string>
using namespace std;
class User{
    public:
    User();
    void SetName(string name);
    void SetPassword(string password);
    void loadtasks();
    private:
    string Name;
    string Password

};