#include <iostream>
#include <fstream>
#include <string>

//#include "User.h"
//#include "task.h"
//#include "viewSchedule.h"
//#include "editTask.h"
//#include "taskListEdit.h"
using namespace std;


int main(){


   //opening userLogin.txt

   fstream userFile;
   userFile.open("userLogin.txt");

   if(!(userFile.is_open()))
   {
      cout << "Error accessing userLogin data base." << endl;
   }

   //asking user if they are new or old user
   string userName;
   string fileName;
   cout << "Are you an existing user (Press E) or new user (Press N)?" << endl;

   string userInput;
   cin >> userInput;


   while(userInput != "E" || userInput != "N")
   {
      cout << "Input is not valid. Please enter a valid input." << endl;
      cin >> userInput;
   }

   //if user is creating an account
   if(userInput == "N")
   {
      
      cout << "Enter your username: " << endl;
      getline(cin,userName);

      bool validUserName = false;
      
      do{

         bool userNameExists;
   
         string firstWord;
         string secondWord;
         //checks if userName exists
         while( userFile >> firstWord >> secondWord || userNameExists == true)
         {

            if(firstWord == userName)
            {
               userNameExists = true;
            }

            userNameExists = false;
            
         }

         if(userNameExists == false)
         {
            validUserName == true;
         }
         else
         {
            cout << "That username is taken, please enter a valid username." << endl;
            getline(cin, userName);
         }
         }
         while(validUserName == false);

         //valid password

         string password;

         cout << "Please enter a password: " << endl;
         getline (cin, password);
         bool validPassword = false;
         bool capitalLetter;
         bool number;

   //do checks for password
         do{
               if(validPassword == false)
               {
                  cout << "Please enter a valid password: " << endl;
                  getline(cin, password);
               }
            
            validPassword = true;
               
         }
         while(validPassword == false)

         


         //write username and password to file
      

      }
     
      
   //if user is trying to login
   if(userInput ==  "E")
   {


      cout << "Please enter your Username:" << endl;
      getline(cin, userName);
      cout << "Please enter a password: " << endl;
      getline(cin, password);


      //User user = User(name, password);
      cout << "Welcome " << userName << "!" << endl;
      fileName = userName + ".txt";


//creates file for user's schedule
      ifstream inFS;
      ofstream outFS(fileName);
      outFS << userName << endl;
      outFS << userName <<"'s password: " << password << endl;
   }


   
   userFile.close();
   
   return 0;
}




