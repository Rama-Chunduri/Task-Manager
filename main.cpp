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
   //need to open input and output modes to write and read data
   //need to open append mode to avoid overwriting data
   userFile.open("userLogin.txt", ios::in | ios::out | ios::app);

   if(!(userFile.is_open()))
   {
      cout << "Error accessing userLogin data base." << endl;
   }

   //asking user if they are new or old user
   string userName;
   string password;
   string fileName;
   cout << "Are you an existing user (Press E) or new user (Press N)?" << endl;

   string userInput;
   cin >> userInput;


   while(userInput != "E" && userInput != "N")
   {
      cout << "Input is not valid. Please enter a valid input:" << endl;
      cin >> userInput;
   }

   
   cin.ignore();//allows me to get username without reading in the endl from previous

   //if user is creating an account
   if(userInput == "N")
   {
   

      bool validUserName = false;
      
      do{

            bool userNameExists = false;

            cout << "Enter your username: " << endl;
            getline(cin,userName);
      
            string firstWord;
            string secondWord;
            //checks if userName exists
            while( userFile >> firstWord >> secondWord)
            {

               if(firstWord == userName)
               {
                  userNameExists = true;
                  break;
               }
               
            }

            if(userNameExists == false)
            {
               validUserName = true;
            }
            else
            {
               cout << "That username is taken, please enter a unique username." << endl;
              
            }
         }
         while(validUserName == false);

      
      //valid password

        

         cout << "Please enter a password: " << endl;
         getline (cin, password);
         bool validPassword = true;
        // bool capitalLetter;
        // bool number;

      //do checks for password
         do{
               if(validPassword == false)
               {
                  cout << "Please enter a valid password: " << endl;
                  getline(cin, password);
               }
            
            validPassword = true;
               
         }
         while(validPassword == false);

         
      
      userFile.clear(); //clear end of file flag
      userFile.seekg(0, ios::beg); // set position to beginning of the file

      //write username and password to file
         userFile << userName << endl;
         userFile << password << endl;
      

         cout << "Would you like to go to the Login page? Press E. If not, press Q to quit." << endl;
         cin >> userInput;
         if(userInput == "Q")
            {
               return 0;
            }
      }

      //logging in after creating account
           
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
      outFS << userName << "'s schedule: " << endl;
      //outFS << userName <<"'s password: " << password << endl;
   }


   
   userFile.close();
   
   return 0;
}








