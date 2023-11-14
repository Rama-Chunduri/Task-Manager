#pragma once
#include <string>
using namespace std;


class Task{
   public:
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
   string name;
   string dueDate;
   int priority;
   string tag;
   string description;
};

