# Schedule Organizer    
Authors: \[Shivani Nandakumar](https://github.com/snand021)\    
Authors: \[Varsha Kuppa](https://github.com/vkupp001)\  
Authors: \[Sreeja Pagireddy](https://github.com/spagi002)\  
Authors: \[Rama Chunduri](https://github.com/rchun043)\

## Project Description
### Purpose of the project:

The Weekly Task Organizer is designed to help users in efficiently managing their weekly tasks through a simple and user-friendly command-line interface. The primary goal is to provide a customizable and visually appealing platform for users to organize, prioritize, and track their tasks effectively.  

  
### Importance of the project: 

This task organizer is importance to us because it addresses a challenge faced by students and professionals alike — time management. As. Time management is crucial for productivity, this project provides a centralized platform for task organization. As computer science students, we all struggle with remembering the due dates for assignments and meetings. Designing this project would not only help us keep track of our priorities but can also be helpful to others. 

  
### Features:

**Create Account:** User are initially directed to create an account where they can sign up and enter their name and password. If they already have an account, they are directed to the login page.

**Login:** Existing user can log in and view, create, edit, delete their tasks, and set their schedule.

**Features within a Task:** Start Date, Due Date, Priority, Duration, Random Assigned Number, Name of Task, Description of Task. These are the items asked when a user creates a task. 

**View:** After a user logs in, they will be directed to the view feature where they can view all their tasks.

**Menu:** After viewing their schedule, they are directed toward the menu page where they can choose to print their schedule, delete tasks, and edit tasks.

**Edit:** If they choose to edit their task, they can make changes within a week. They can change any of the features within a task.

**Delete:** A user can delete their task from their weekly schedule. A number would be displayed next to the task and the user can enter the number to remove that certain task.

**Print Their Schedule:** User can choose to view and print their schedule. Their schedule can also be organized by their start date or priority or how important it is to them.

**Remind Feature:** User would also be reminded if their task is 24 hours before the due date or if the end of the week is approaching.

### Languages and Development:

-Description: The language that we will be using for this project will be C++. We will also be using Visual Studio Code, Valgrind, and the gdb debugger.

- Input: Name of user, password, name of task, description, due date, start date, task duration, completion status of task, tag, and priority of tasks.
  
- Output:
A visible schedule which is printed in order of due dates, first dates, end dates, duration, priority, or tag (the user may choose, although printing by due date is the default view) which shows all the tasks, descriptions, and all information about their tasks. They will also get automatic reminders which are displayed on the screen 24 hours before each task is due.
The main features of this project are: It allows the user to organize their schedule by adding different tasks and they will be notified 24 hours before the time of the task. They can add a description to their tasks, categorize them using tags, give them certain priorities, and set due dates for the tasks as well.

  
## User Interface Specification
(https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
><img width="676" alt="Screenshot 2023-11-20 at 10 01 23 PM" src="https://github.com/cs100/final-project-snand021/assets/130624276/cc910496-4659-4a1b-ac74-81058693d748">


### Screen Layouts

<img width="504" alt="Screenshot 2023-11-20 at 7 35 40 PM" src="https://github.com/cs100/final-project-snand021/assets/130624276/eb984441-b5ac-4b80-98f7-09a1efc49263">


<img width="406" alt="Screenshot 2023-11-15 at 10 43 17 PM" src="https://github.com/cs100/final-project-snand021/assets/146979206/e33d70a0-97b0-42b8-994d-1d4e66e57e18">

<img width="407" alt="Screenshot 2023-11-15 at 10 43 36 PM" src="https://github.com/cs100/final-project-snand021/assets/146979206/f02b10c4-724a-4e5a-9daa-1329188db167">

## Class Diagram

><img width="849" alt="Screenshot 2023-11-20 at 9 40 42 PM" src="https://github.com/cs100/final-project-snand021/assets/130624276/0444cadc-2ab1-4dfb-84f3-c33fb4cbfe7a">

 > ## Phase III

> ### What changes we made from the first UML diagram
> 
### Added the data types “bool complete,”  “string startDate,” and “int duration” to the Task class, and their respective setters and getters 

SOLID Principle(s): The Single Responsibility Principle (SRP)

Application: Single responsibility would be the best principle as it is inputted in the Task class and follows one responsibility of setting each task. We applied this change to the Task class so the user can input more information regarding their task so the view class is organized strategically. 

Benefits: This change helps us make our ideas more creative and help keep each task more organized with all the required information needed from the user.
>
> 
### Removed the editing the task and viewing functions from the Menu class and decided that we would just call the setters in the Task class to edit the tasks 

SOLID Principle(s): Single Responsibility Principle (SRP)

Application: By removing editing and viewing functions, the Menu class adheres more closely to SRP, focusing solely on menu-related logic.

Benefits: This change enhances maintainability. The Menu class is now dedicated to handling user interactions, while the task-related operations are delegated to the Task class. This separation ensures that each class has a well-defined responsibility.

Added the Remind class with the remind function in order to remind the user of their tasks’ due date 24 hours beforehand. 

SOLID Principle(s): Single Responsibility Principle (SRP)

Application: By adding the remind function, the Remind class follows the Single responsibility principle. This is because it only has one function which has one responsibility of reminding the user regarding their tasks’ due date 24 hours beforehand. 

Benefits: This change enhances maintainability and also increases the users’ convenience. The Remind class allows us to carry out the program efficiently and makes testing easier. 

Added the Menu class to our class diagram

SOLID Principle(s): Open Closed Principle

The menu class is also open for extension but closed for modification. Even if we add another class, the Menu class is closed for modification.

Benefits: This change enhances the classes and makes sure it's well organized while running the program efficiently.




> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
