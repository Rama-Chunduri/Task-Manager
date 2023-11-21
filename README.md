# Schedule Organizer

 > Authors: \[Shivani Nandakumar](https://github.com/snand021)\
 > Authors: \[Varsha Kuppa](https://github.com/vkupp001)\
 > Authors: \[Sreeja Pagireddy](https://github.com/spagi002)\
 > Authors: \[Rama Chunduri](https://github.com/rchun043)\

## Project Description
- This project is important to us because time management is a crucial step in being productive. As computer science students, we all struggle with remembering due dates for assignments and meetings. Designing this project would not only help us keep track of our priorities but can also be helpful to others. 
-The languages that we will be using for this project would be C++ and Visual Studio Code.
- Input: Name of user, password, name of task, description, due dates, tags, and priority of tasks.
- Output: A visible schedule which is printed in order of due dates which shows all the tasks , due dates, priorities, tags, descriptions and all information about their tasks. They will also get automatic remainders which are displayed on the screen 24 hours before each task is due.
The main features of this project are: It allows the user to organize their schedule by adding different tasks and they will be notified 24 hours before the time of the task. They can add a description to their tasks, categorize them using tags, give them certain priorities and set due dates for the tasks as well.

## User Interface Specification
(https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
><img width="713" alt="Screenshot 2023-11-15 at 10 22 17 PM" src="https://github.com/cs100/final-project-snand021/assets/130624276/4fde7713-10c5-4951-b580-ef8a4266bed0">


### Screen Layouts

<img width="408" alt="Screenshot 2023-11-15 at 10 43 02 PM" src="https://github.com/cs100/final-project-snand021/assets/146979206/3e22f49b-b33d-4c06-9362-7eaa4af8b3c3">

<img width="406" alt="Screenshot 2023-11-15 at 10 43 17 PM" src="https://github.com/cs100/final-project-snand021/assets/146979206/e33d70a0-97b0-42b8-994d-1d4e66e57e18">

<img width="407" alt="Screenshot 2023-11-15 at 10 43 36 PM" src="https://github.com/cs100/final-project-snand021/assets/146979206/f02b10c4-724a-4e5a-9daa-1329188db167">

## Class Diagram

><img width="869" alt="Screenshot 2023-11-16 at 8 54 40 AM" src="https://github.com/cs100/final-project-snand021/assets/130624276/a794efc4-a3d3-49c2-806e-9412dcca38cc">

UML Diagram Descriptions:

This is the UML diagram for our project which is called “Schedule Organizer”. This project consists of six classes: Task, TaskList, User, Menu, Remind, and ViewSchedule.
Task Class


The Task class is responsible for getting and setting the following attributes for every task: name, due date, start date, priority, tag, description, status, and duration. This implementation is important as it creates the task itself and allows the user to customize it. 


TaskList Class

The TaskList class has an addTask function that adds tasks to a vector of the task object (a private variable of TaskList), a removeTask function that removes a task from the vector of tasks, and a getTasks function that gets the vector of tasks. 


User Class

The User task has setters and getters for username and password as well as additional functions that help the user create an account and login. These functions also allow an existing user to log in and view their saved schedule. 
This class also has a loadTask function that reads input from the user’s file and puts their tasks into a vector, a getTaskList function that gets the taskList object, and a setTaskList function that sets the vector of tasks in the taskList object. 


Menu Class

The Menu class contains a single function that prints the menu containing multiple options such as adding a task, deleting a task, and editing a task. This class improves the user interface and accessibility while also making the creation of the schedule more flexible.


ViewSchedule Class

The ViewSchedule class consists of 6 functions. These functions allow the user to view their schedule sorted by due date, start date, duration, completion, tag, and priority. This implementation allows the user to view their schedule according to their personal preference. 


Remind Class 

The Remind class has a function called remind that outputs a message to the user on terminal, reminding the user of the tasks that are due in 24 hours. The Remind class also notifies the user when it is approaching the end of the week to complete the tasks.





 > ## Phase III

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
 
