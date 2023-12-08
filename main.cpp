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


int main() {
   //opening userLogin.txt
   fstream userFile;

   //need to open input and output modes to write and read data
   //need to open append mode to avoid overwriting data since we want to store all usernames and passwords
   userFile.open("userLogin.txt", ios::in | ios::out | ios::app);

   // check that file opened properly 
   if(!(userFile.is_open()))
   {
      cout << "Error accessing userLogin data base." << endl;
   }

   string userName; // login userName 
   string password; // login password 
   string fileName; // name of file 
   string yourName; // name of user 

   //asking user if they are new or old user
   cout << "Are you an existing user (Press E) or new user (Press N)?" << endl;

   // userInput 
   char userInput;
   cin >> userInput;
   cin.ignore();
   cout << endl;

   // make sure input is valid 
   while(userInput != 'E' && userInput != 'N')
   {
      cout << "Input is not valid. Please enter a valid input:" << endl;
      cin >> userInput;
      cin.ignore(); // allows me to get username without reading in the endl from previous
      cout << endl;
   }

   //if user is creating an account
   if(userInput == 'N')
   {
      //asks new user for their name
      cout << "Enter your first name: " << endl;
      getline(cin, yourName);
      
      bool validUserName = false;
      
      do
      {
            bool userNameExists = false;

            cout << "Enter your username: " << endl;
            getline(cin,userName);

            string firstWord; //username
            string secondWord; //password
            string thirdWord; //their name 

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

        

         cout << "Please enter a password that meets these requirements: " << endl;
         cout << " - Needs to be at least 6 characters long" << endl;
         cout << " - Needs to have at least 1 capital letter" << endl;
         cout << " - Needs to have at least 1 number" << endl;
         cout << " - Needs to have at least 1 of the following characters: $ @ ! & #" << endl;
         cout << "Enter your password: " << endl;
         getline (cin, password);
         cout << endl;
         bool validPassword = false;
         bool capitalLetter = false;
         bool numberExists = false;
         bool passwordSize = false;
         bool specialChar = false;

      //do checks for password
         do{
         
               if(password.size() >= 6)
               {
                  passwordSize = true;
               }
               else
               {
                  cout << "Password needs to be at least 6 characters long." << endl;
               }
               
               for(unsigned int i = 0; i < password.size(); ++i)
               {
                  if(isupper(password.at(i)))
                  {
                     capitalLetter = true;
                  }
                  if(isdigit(password.at(i)))
                  {
                     numberExists = true;
                  }
                  if(password.at(i) == '$' || password.at(i) == '@' || password.at(i) == '!' || password.at(i) == '&' || password.at(i) == '#')
                  {
                     specialChar = true;
                  }
               }

            

               if(!numberExists)
               {
                  cout << "Password needs at least one number." << endl;
               }

               if(!capitalLetter)
               {
                  cout << "Password needs at least one capital letter." << endl;
               }

               if(!specialChar)
               {
                  cout << "Passwords needs to have at least 1 of the following characters: $ @ ! & # ." << endl;
               }
                 
               if(capitalLetter && numberExists && passwordSize && specialChar)
               {
                  validPassword = true;
               } 
               if(validPassword == false)
               {
                  cout << endl;
                  cout << "Make sure password meets all requirements. Please enter a valid password: " << endl;
                  getline(cin, password);
                  cout << endl;
               }
               
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
         do{
            if(userInput == 'Q')
            {
               return 0;
            }
            else if(userInput == 'E')
            {
               break;
            }
            else
            {
               cout << "Please enter a valid input. Press E to go to login and Q to quit: " << endl;
               cin >> userInput;
            }
      
         }
         while(userInput != 'Q' && userInput != 'E');
         
         userFile.open("userLogin.txt", ios::in | ios::out | ios::app); //reopen file so file cursor is reset and file can be read properly for login process
         string createFile = userName + ".txt";
          //creates file for user's schedule
         ifstream inFS;
         ofstream outFS(createFile);
      }

   //logging in after creating account
           
   //if user is trying to login
   if(userInput ==  'E')
   {

       bool loginWorks = false;

      do
      {
            bool loginUserNameExists = false;
            bool loginPasswordWorks = false;

            cout << "Please enter your Username:" << endl;
            getline(cin, userName);

            cout << endl;

            cout << "Please enter your Password: " << endl;
            getline(cin, password);
            
            cout << endl;
      
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
               cout << endl;
            }
         }

      while(loginWorks == false);

      cout << "Welcome " << yourName << "!" << endl;
      fileName = userName + ".txt";
      
      fstream loginFile;
      loginFile.open("userLogin.txt", ios::in | ios::out | ios::app);

      if(!(loginFile.is_open()))
      {
         cout << "Error accessing userLogin data base." << endl;
      }


   
      //setting the user name and password
      User person;
      person.SetUserName(userName);
      person.SetPassword(password);
      person.SetName(yourName);
      
      Menu menuPerson;
      menuPerson.printMenu(person);


      
      userFile.close();
   }



   
   return 0;
}








