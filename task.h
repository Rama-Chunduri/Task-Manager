#pragma once
#include <string>
using namespace std;


class Task{
   public:
   Task();
   Task(string name, string description, string dueDate, string tag, int priority);
   void SetName(string name);
   void SetDueDate(string dueDate);
   void SetTag(string tag);
   void SetDescription(string description);
   void SetPriority(int priority);
   string GetName();
   string GetDueDate();
   string GetTag();
   string GetDescription();
   int GetPriority();
   private:
   string _name;
   string _dueDate;
   int _priority;
   string _tag;
   string _description;
};

