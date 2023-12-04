#pragma once
#include <string>
using namespace std;


class Task{
   public:
      Task();
      Task(string name, string description, string startDate, string dueDate, string tag, int priority, double durationHours, bool completeStatus);
      
      void SetName(string name);
      void SetDescription(string description);
      void SetStartDate(string startDate);
      void SetDueDate(string dueDate);
      void SetTag(string tag);
      void SetPriority(int priority);
      void SetDurationHours(double durationHours);
      void SetComplete(bool check);

      string GetName() const;
      string GetDescription() const;
      string GetStartDate() const;
      string GetDueDate() const;
      string GetTag() const;
      int GetPriority() const;
      double GetDurationHours() const;
      bool GetComplete() const;

   private:
      string _name;
      string _description;
      string _startDate;
      string _dueDate;
      string _tag;
      int _priority;
      double _durationHours;
      bool _complete;
};
