#pragma once
#include <string>
using namespace std;


class Task{
   public:
   Task();
   Task(string name, string description, string dueDate, string tag, int priority, string startDate, string endDate, double durationHours);
   void SetName(string name);
   void SetDueDate(string dueDate);
   void SetTag(string tag);
   void SetDescription(string description);
   void SetPriority(int priority);
   void SetStartDate(string startDate);
   void SetEndDate(string endDate);
   void SetDurationHours(double durationHours);
   string GetStartDate();
   string GetEndDate();
   double GetDurationHours();
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
   string _startDate;
   string _endDate;
   double _durationHours;

};

