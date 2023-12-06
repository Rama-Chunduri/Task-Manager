#include <iostream>
#include <fstream>
#include <string>
#include "Menu.h"
#include "User.h"

#include "task.h"
#include "viewSchedule.h"
#include "editTask.h"
#include "taskList.h"
using namespace std;


int main(){


   //opening userLogin.txt

   fstream userFile;
   //need to open input and output modes to write and read data
   //need to open append mode to avoid overwriting data since we want to store all usernames and passwords
   userFile.open("userLogin.txt", ios::in | ios::out | ios::app);

   if(!(userFile.is_open()))
   {
      cout << "Error accessing userLogin data base." << endl;
   }

   //asking user if they are new or old user
   string userName;
   string password;
   string fileName;
   string yourName;
   cout << "Are you an existing user (Press E) or new user (Press N)?" << endl;

   char userInput;
   cin >> userInput;
   cin.ignore();


   while(userInput != 'E' && userInput != 'N')
   {
      cout << "Input is not valid. Please enter a valid input:" << endl;
      cin >> userInput;
      cin.ignore();
   }

   
  // cin.ignore() allows me to get username without reading in the endl from previous

   //if user is creating an account
   if(userInput == 'N')
   {
      //asks new user for their name
      cout << "Enter your first name: " << endl;
      getline(cin, yourName);
      

   
      bool validUserName = false;
      
      do{
            bool userNameExists = false;

            cout << "Enter your username: " << endl;
            getline(cin,userName);

      
            string firstWord; //username
            string secondWord; //password
            string thirdWord; //their anme
            //checks if userName exists
            while( userFile >> firstWord >> secondWord >> thirdWord)
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
         userFile << yourName << endl;

         userFile.close(); //close the file

         cout << "Would you like to go to the Login page? Press E. If not, press Q to quit." << endl;
         cin >> userInput;
         cin.ignore();
         if(userInput == 'Q')
            {
               return 0;
            }
         
         userFile.open("userLogin.txt", ios::in | ios::out | ios::app); //reopen file so file cursor is reset and file can be read properly for login process
      }

   //logging in after creating account
           
   //if user is trying to login
   if(userInput ==  'E')
   {

       bool loginWorks = false;

      do{

            bool loginUserNameExists = false;
            bool loginPasswordWorks = false;

            cout << "Please enter your Username:" << endl;
            getline(cin, userName);
            cout << "Please enter a Password: " << endl;
            getline(cin, password);
            
      
            string readUserName;
            string readPassword;
            string readName;
            //checks if userName exists
            while( userFile >> readUserName >> readPassword >> readName)
            {

               if(readUserName == userName && readPassword == password)
               {
                  loginUserNameExists = true;
                  loginPasswordWorks = true;
                  break;
               }
               
            }

            if(loginPasswordWorks == true && loginUserNameExists == true)
            {
               loginWorks = true;
               cout << "Login Successful!" << endl;
            }
            else{
               cout << "Username or Passoword is incorrect. Please try again." << endl;
                userFile.clear(); //clear end of file flag
               userFile.seekg(0, ios::beg); // set position to beginning of the file

            }

            
         }
         while(loginWorks == false);




      //User user = User(name, password);
      cout << "Welcome " << userName << "!" << endl;
      fileName = userName + ".txt";


//creates file for user's schedule
      ifstream inFS;
      ofstream outFS(fileName);
      outFS << userName << endl;
      outFS << userName <<"'s password: " << password << endl;
   }


   //setting the user name and password
   User person;
   person.SetUserName(userName);
   person.SetPassword(password);
   person.SetName(yourName);
   
   Menu menuPerson;
   menuPerson.printMenu(person);


   
   userFile.close();



   
   return 0;
}








