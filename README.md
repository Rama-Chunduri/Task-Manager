# Schedule Organizer    
Authors: [Shivani Nandakumar](https://github.com/snand021), [Varsha Kuppa](https://github.com/vkupp001), [Sreeja Pagireddy](https://github.com/spagi002), [Rama Chunduri](https://github.com/rchun043)

## Project Description
### Purpose:
The Weekly Task Organizer is designed to help users in efficiently managing their weekly tasks through a simple and user-friendly command-line interface. The primary goal is to provide a customizable and visually appealing platform for users to organize, prioritize, and track their tasks effectively.  
\
\
\

### Importance: 
This task organizer is importance to us because it addresses a challenge faced by students and professionals alike — time management. As. Time management is crucial for productivity, this project provides a centralized platform for task organization. As computer science students, we all struggle with remembering the due dates for assignments and meetings. Designing this project would not only help us keep track of our priorities but can also be helpful to others. 


### Languages/Tools/Technologies
[C++](https://cplusplus.com/) - This project is programmed mainly using C++.

[Visual Studio Code](https://code.visualstudio.com/) - An integrated development environment (IDE) used for coding, debugging, and version control. 

[Git](https://git-scm.com/) - A distributed version control system employed to track changes in the source code during the development process. Git facilitates collaboration and helps manage different versions of the code.

[Valgrind](https://valgrind.org/) - A programming tool used for memory debugging, memory leak detection, and profiling. Valgrind ensures memory integrity and helps identify potential issues related to memory management.

[GitHub](https://github.com/) - A web-based platform for hosting and collaborating on Git repositories. GitHub serves as a central hub for project code, issues, and documentation, enabling efficient teamwork.

[CMake](https://cmake.org/) - A cross-platform build system that simplifies the build process for C++ projects. CMake generates platform-specific build files from a high-level configuration, promoting portability.

[Google Test Framework](https://github.com/google/googletest) -  A testing framework for C++ projects that enables the creation and execution of unit tests. Google Test aids in verifying the correctness and robustness of the codebase through automated testing.

  

### Features:
**Create Account:** User are initially directed to create an account where they can sign up and enter their name and password. If they already have an account, they are directed to the login page.

**Login:** Existing user can log in and view, create, edit, delete their tasks, and set their schedule.

**Features within a Task:** Start Date, Due Date, Priority, Duration, Random Assigned Number, Name of Task, Description of Task. These are the items asked when a user creates a task. 

**View:** After a user logs in, they will be directed to the view feature where they can view all their tasks.

**Menu:** After viewing their schedule, they are directed toward the menu page where they can choose to print their schedule, delete tasks, and edit tasks.

**Edit:** If they choose to edit their task, they can make changes within a week. They can change any of the features within a task.

**Delete:** A user can delete their task from their weekly schedule. A number would be displayed next to the task and the user can enter the number to remove that certain task.

**Add:** A user can add a task to their weekly schedule. 
**Print Their Schedule:** User can choose to view and print their schedule onto the terminal. Their schedule can also be organized by their start date, due date, duration, completion, tag, and priority.

**Remind Feature:** User will also be reminded if their task is 24 hours before the due date or if the end of the week is approaching.



### Program Inputs/Outputs:
- Input: Name of user, password, name of task, description, due date, start date, task duration, completion status of task, tag, and priority of tasks.
  
- Output:
A visible schedule which is printed in order of due dates, first dates, end dates, duration, priority, or tag (the user may choose, although printing by due date is the default view) which shows all the tasks, descriptions, and all information about their tasks. They will also get automatic reminders which are displayed on the screen 24 hours before each task is due.
The main features of this project are: It allows the user to organize their schedule by adding different tasks and they will be notified 24 hours before the time of the task. They can add a description to their tasks, categorize them using tags, give them certain priorities, and set due dates for the tasks as well.



## User Interface Specification
(https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))
>
>
### Navigation Diagram
><img width="676" alt="Screenshot 2023-11-20 at 10 01 23 PM" src="https://github.com/cs100/final-project-snand021/assets/130624276/cc910496-4659-4a1b-ac74-81058693d748">
>
>
### Screen Layouts

<img width="504" alt="Screenshot 2023-11-20 at 7 35 40 PM" src="https://github.com/cs100/final-project-snand021/assets/130624276/eb984441-b5ac-4b80-98f7-09a1efc49263">

<img width="406" alt="Screenshot 2023-11-15 at 10 43 17 PM" src="https://github.com/cs100/final-project-snand021/assets/146979206/e33d70a0-97b0-42b8-994d-1d4e66e57e18">

<img width="407" alt="Screenshot 2023-11-15 at 10 43 36 PM" src="https://github.com/cs100/final-project-snand021/assets/146979206/f02b10c4-724a-4e5a-9daa-1329188db167">


### Class Diagram
><img width="849" alt="Screenshot 2023-11-20 at 9 40 42 PM" src="https://github.com/cs100/final-project-snand021/assets/130624276/0444cadc-2ab1-4dfb-84f3-c33fb4cbfe7a">

## UML Diagram Descriptions:
This is the UML diagram for our project which is called “Schedule Organizer”. This project consists of six classes: Task, TaskList, User, Menu, Remind, and ViewSchedule.

**Task Class**
The Task class is responsible for getting and setting the following attributes for every task: name, due date, start date, priority, tag, description, status, and duration. This implementation is important as it creates the task itself and allows the user to customize it. 

**TaskList Class**
The TaskList class has an addTask function that adds tasks to a vector of the task object (a private variable of TaskList), a removeTask function that removes a task from the vector of tasks, and a getTasks function that gets the vector of tasks. 

**User Class**
The User task has setters and getters for username and password as well as additional functions that help the user create an account and login. These functions also allow an existing user to log in and view their saved schedule. 
This class also has a loadTask function that reads input from the user’s file and puts their tasks into a vector, a getTaskList function that gets the taskList object, and a setTaskList function that sets the vector of tasks in the taskList object. 

**Menu Class**
The Menu class contains a single function that prints the menu containing multiple options such as adding a task, deleting a task, and editing a task. This class improves the user interface and accessibility while also making the creation of the schedule more flexible.

**ViewSchedule Class**
The ViewSchedule class consists of 6 functions. These functions allow the user to view their schedule sorted by due date, start date, duration, completion, tag, and priority. This implementation allows the user to view their schedule according to their personal preference. 

**Remind Class**
The Remind class has a function called remind that outputs a message to the user on terminal, reminding the user of the tasks that are due in 24 hours. The Remind class also notifies the user when it is approaching the end of the week to complete the tasks.
>
>
## What changes we made from the first UML diagram and SOLID
Added the data types “bool complete,”  “string startDate,” and “int duration” to the Task class, and their respective setters and getters 
- SOLID Principle(s): The Single Responsibility Principle (SRP)
- Application: Single responsibility would be the best principle as it is inputted in the Task class and follows one responsibility of setting each task. We applied this change to the Task class so the user can input more information regarding their task so the view class is organized strategically.
- Benefits: This change helps us make our ideas more creative and help keep each task more organized with all the required information needed from the user.

Removed the editing the task and viewing functions from the Menu class and decided that we would just call the setters in the Task class to edit the tasks 
- SOLID Principle(s): Single Responsibility Principle (SRP)
- Application: By removing editing and viewing functions, the Menu class adheres more closely to SRP, focusing solely on menu-related logic.
- Benefits: This change enhances maintainability. The Menu class is now dedicated to handling user interactions, while the task-related operations are delegated to the Task class. This separation ensures that each class has a well-defined responsibility.

Added the Remind class with the remind function in order to remind the user of their tasks’ due date 24 hours beforehand. 
- SOLID Principle(s): Single Responsibility Principle (SRP)
- Application: By adding the remind function, the Remind class follows the Single responsibility principle. This is because it only has one function which has one responsibility of reminding the user regarding their tasks’ due date 24 hours beforehand.
- Benefits: This change enhances maintainability and also increases the users’ convenience. The Remind class allows us to carry out the program efficiently and makes testing easier. 

Added the Menu class to our class diagram
- SOLID Principle(s): Single Responsibility Principle (SRP)
- The menu class has one responsibility which would be to print the schedule and the main focus of the menu class deals with one responsibility.
- Benefits: This change enhances the classes and makes sure it's well organized while running the program efficiently.

Changed the relationship from the Menu class to the Task class from inheritance to not having a relationship (not aggregation, composition, control, or inheritance)
- SOLID Principle(s): Dependency Inversion Principle (DIP).
- Application: The removal of the relationship between the Menu and Task classes aligns with DIP by reducing direct dependencies.
- Benefits: This change improves flexibility. The User class, acting as a central class, can interact with the Task class without being tightly coupled to the specifics of the Menu class, allowing for easier modifications and extensions.

Made a ViewSchedule class (control class to User) so that we can output the schedule in different ways
- SOLID Principle(s): Single Responsibility Principle (SRP)
- Application: The introduction of the ViewSchedule class follows SRP by assigning the responsibility of displaying the user's schedule to a dedicated class.
- Benefits: This change enhances code organization and readability. The ViewSchedule class encapsulates the logic related to presenting the schedule, ensuring that this responsibility is isolated from other parts of the system.

Changed the TaskListEdit to TaskList and added a getTask function (outputs the vector of tasks) 
- SOLID Principle(s): Single Responsibility Principle (SRP)
- Application: Renaming and refactoring TaskListEdit to TaskList, and adding a getTask function, aligns with SRP by ensuring that the class has a single responsibility.
- Benefits: This change improves code clarity. The TaskList class now focuses on managing tasks, and the addition of getTask provides a clear interface for retrieving tasks, promoting a more cohesive and understandable design.

Added an int parameter to removeTask so that the task at that point in the list can be deleted
- SOLID Principle(s): Single Responsibility Principle (SRP)
- Application: Adding the int parameter to RemoveTask has the same responsibility as editing the task which follows the SRP rule. It's extending the responsibility.
- Benefits: This change makes sure that the class is following the SOLID principle and has a clear interface which makes the responsibility of each class clear.

Changed the relationship between TaskList class to Task class from inheritance to composition 
- SOLID Principle(s): Dependency Inversion Principle (DIP)
- Application: By changing the relationship from inheritance to composition, the code adheres to DIP. The TaskList class now relies on the abstraction   of the Task class without being directly coupled to its concrete implementation.
- Benefits: This change fosters flexibility and maintainability. TaskList depends on the interface provided by Task (abstraction) rather than inheriting specific implementations. This reduces the dependency on concrete details, making it easier to extend and modify the system.

Added a User class that is sort of the central class of the program. It enables the user to login, puts the user’s tasks into a vector from a file, and sets and gets the list of tasks 
- SOLID Principle(s): Single Responsibility Principle (SRP)
- Application: The introduction of the User class follows SRP by centralizing user-related functionalities.
- Benefits: This change enhances modularity and maintainability. The User class serves as a central hub for user-specific actions, such as login and task retrieval, providing a clear and coherent interface for managing user-related concerns.
 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
>
> 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
