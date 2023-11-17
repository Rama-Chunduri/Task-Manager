#include "task.h"
#include "taskListEdit.h"
using namespace std;

class EditTask : public taskListEdit{
    void editPriority(Task currTask, int newPriority);
    void editDueDate(Task currTask, string newDueDate);
    void editTag(Task currTask, string newTag);
    void editDescription(Task currTask, string newDesc);
    void editName(Task currTask, string newName);
};