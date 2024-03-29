// Importing necessary libraries
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>

// This library is used for sleep() function on Linux, which might not work on different operating systems
#include <unistd.h>

using namespace std;

// Declaring two functions, registration & login
void registration();
void login();

// Creating an array of uppercase & lowercase letters, digits, and special characters which will be used for generating strong passwords
static const char alphnum[] = "!@#$%&*()-_=+|~`"
                              "0123456789"
                              "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                              "abcdefghijklmnopqrstuvwxyz";

// strLen represents the length of the string stored in alphnum, which is a concatenation of special characters, digits, uppercase letters, and lowercase letters.
int strLen = sizeof(alphnum) - 1;

// Each time GenRand() is called, it will return a random character from the alphnum array, which consists of special characters, digits, uppercase letters, and lowercase letters.
char GenRand()
{
 return alphnum[rand() % strLen];
}

int main()
{
 int c;
 cout << "_______________________________________  \n\n\n";
 cout << "           Welcome to Login Page          \n\n\n";
 cout << "____________       MENU   ________________ \n\n";
 cout << "                                            \n\n";
 cout << "| Press 1 to Login           " << endl;
 cout << "| Press 2 to Register           " << endl;
 cout << "| Press 3 to EXIT           " << endl;
 cout << "\nPlease enter your choice: ";

 // Taking input from user to display his desired option
 cin >> c;
 cout << endl;

 // switch-case statement with 3 cases, 1st case for login, 2nd for registration, 3rd for exiting
 switch (c)
 {
 case 1:
  login();
  break;
 case 2:
  registration();
  sleep(5);
  main();
  break;
 case 3:
  cout << "\t\t\t Thank You! \n\n";
  break;
 default:
  cout << "\033[2J\033[1;1H";
  cout << "\t\t\t Please enter a valid choice \n";
  main();
 }
};

// Validate Password function, which validates wether the password entered or generated is strong enough or not (Password has to be atleast 6 characters, containing Uppercase, lowercase, digits, and special characters)
bool validatePassword(string input)
{
 if (input.length() < 6)
 {
  return false;
 }
 // Flags of false to check for letter
 bool hasUpper = false;
 bool hasLower = false;
 bool hasDigit = false;
 bool hasSpecial = false;

 // for loop that checks for each character in a string provided, if a certain condition is satisfied it sets the according flag to True
 for (char cha : input)
 {
  if (isupper(cha))
  {
   hasUpper = true;
  }
  else if (islower(cha))
  {
   hasLower = true;
  }
  else if (isdigit(cha))
  {
   hasDigit = true;
  }
  // Not in Alphabet or Number
  else if (!isalnum(cha))
  {
   hasSpecial = true;
  }
  // Check for conditions so if satisfied within first few characters to break the loop
  if (hasUpper && hasLower && hasDigit && hasSpecial)
  {
   break;
  }
 }
 return hasUpper && hasLower && hasDigit && hasSpecial;
}

// Login Function
void login()
{
 // Here, the user has to write his userId and Password which are then to be compared with records.txt ids and passwords and if matched the login is successful
 int option;
 int count = 0;
 string userID, password, id, pass, decrypt, encrypt, generatedPass;
 cout << "\033[2J\033[1;1H";
 cout << "Please enter the username and password: " << endl;
 cout << "Username: ";
 cin >> userID;
 cout << "Password: ";
 cin >> password;

 ifstream input("records.txt");

 // For loop that goes through each letter in the password in our records and for each character it subtracts 3 from it (caesar cipher)

 while (input >> id >> pass)
 {
  decrypt = "";

  for (int i = 0; i < pass.size(); i++)
  {
   char d = pass[i] - 3;
   decrypt += d;
  }

  // If condition that checks if userId entered by user matches first argument (id) in records.txt and password equals to the decrypted password from records.txt (as passwords are stored encrypted and have to be decrypted), count=1 if this succedes

  if (id == userID && password == decrypt)
  {
   count = 1;
   cout << "\033[2J\033[1;1H";
  }
 }
 input.close();
 // If count = 1 the user is successfully logged in
 if (count == 1)
 {
  string username, user, password, passw, webw, website, encryptU, encryptP, decryptU, decryptP, websites;
  cout << "Welcome " << userID << "\nSuccessful Login !\n";
  cout << "\n| Press 1 to Enter a new username and password in the password manager" << endl;
  cout << "| Press 2 to Retrieve a password           " << endl;
  cin >> option;
  // Switch case, to choose wether to enter new credentials or retrieve password
  switch (option)
  {
   // Nested Switch case to choose wether to choose own password or to generate strong password
  case 1:
  {
   cout << "Enter the username for your website: ";
   cin >> username;
   cout << "| Press 1 to Choose your own password           " << endl;
   cout << "| Press 2 to generate a strong password           " << endl;
   cin >> option;
   switch (option)
   {
   case 1:
   {
    // DO-While statement, which is responsible for repeating the password-entry process while validatePassword != true, which means it will be repeating the process until the user enters a strong password
    do
    {
     cout << "Your Password Has to contain the following: \n";
     cout << "~ 6 Characters or more\n~ Upper Case Letter\n~ Lower Case Letter\n~ Special Character\n~ Number\n";
     cout << "Enter Password : ";
     cin >> password;

     // Using the validatePassword function, and if !true, it means the password is weak, and the user has to enter a strong password
     if (validatePassword(password) != true)
     {
      cout << "\nPlease enter a strong password\n";
     }
     // while statement
    } while (validatePassword(password) != true);

    // Input the name of website
    cout << "Enter the name of your website: ";
    cin >> website;
    for (int i = 0; i < username.size(); i++)
    {
     char e = username[i] + 3;
     encryptU += e;
    }
    for (int i = 0; i < password.size(); i++)
    {
     char f = password[i] + 3;
     encryptP += f;
    }
    // Writing Results in passwords.txt (UserID, Encrypted Username in Website, Encrypted Password, Website Link)
    ofstream f0("passwords.txt", ios::app);
    f0 << userID << ' ' << encryptU << ' ' << encryptP << ' ' << website << endl;
    cout << "\033[2J\033[1;1H";
    cout << "\nYour Credintials have been stored successfully, Thanks for using our Password Manager.\n";
    exit(1);
   }
   case 2:
   {
    // Do while statement which ensures the generatedPass passes by the validatePassword function, following the same methodolgy as above
    do
    {
     /* This Upcoming Section is Responsible for generation of strong Password */

     // initializing the length of password(26), c(counter for digits), s(counter for special characters)
     int n = 26, c = 0, s = 0;

     srand(time(0));
    N:
     // generatedPass is now empty
     generatedPass = "";
     // character C initialization
     char C;

     // for loop which keeps doing the same process 26 times till it reaches length of our desired password(26)
     for (int z = 0; z < n; z++)
     {
      // First letter using GenRand()
      C = GenRand();
      // Adding Letter to the generatedPass
      generatedPass += C;
      // Two if statements which check if C character is digit or special character and implementing the counter accordingly
      if (isdigit(C))
      {
       c++;
      }
      if (C == '!' || C == '@' || C == '$' || C == '%' || C == '^' || C == '&' || C == '*' || C == '#' || C == '-' || C == '_' || C == '(' || C == ')')
      {
       s++;
      }
     }
     // This statement says if we reach two characters and the special counter and digits are still 0 to goto N which means repeating the same process again till we reach the desired password
     if (n > 2 && (s == 0 || c == 0))
     {
      goto N;
     }
    } while (validatePassword(generatedPass) != true);

    // This section we use ofstream which means this is a file we will be writing into
    ofstream f1("passwords.txt", ios::app);

    // For loop that goes through each letter in username and generated pass and for each character it adds 3 to it (caesar cipher)
    cout << "Enter the name of your website: ";
    cin >> website;
    for (int i = 0; i < username.size(); i++)
    {
     char e = username[i] + 3;
     encryptU += e;
    }
    for (int i = 0; i < generatedPass.size(); i++)
    {
     char f = generatedPass[i] + 3;
     encryptP += f;
    }
    // Writing Results in passwords.txt (UserID, Encrypted Username in Website, Encrypted Password, Website Link)
    ofstream f0("passwords.txt", ios::app);
    f0 << userID << ' ' << encryptU << ' ' << encryptP << ' ' << website << endl;
    cout << "\033[2J\033[1;1H";
    cout << "\nYour Credintials have been stored successfully, Thanks for using our Password Manager.\n";
    exit(1);
    break;
   }
   default:
    break;
   }
  }
  case 2:
  {
   ifstream input0("passwords.txt");

   cout << "Enter the name of the website you want to retireve credentials of: ";
   cin >> websites;
   // For loop that goes through each letter in generated pass and for each character it subtracts 3 from it (caesar cipher)

   // While loop that goes through the file, and takes each parameter (separated by a space in the file)
   while (input0 >> id >> user >> passw >> webw)
   {
    // If condition to check if (id in file matches current userID)
    if (id == userID)
    {
     decryptU = "";
     decryptP = "";

     for (int i = 0; i < user.size(); i++)
     {
      char d = user[i] - 3;
      decryptU += d;
     }

     for (int i = 0; i < passw.size(); i++)
     {
      char g = passw[i] - 3;
      decryptP += g;
     }

     // If condition that checks if id matches userID and website input matches website link in our records, if so it prints out credentials
    }
    if (id == userID && websites == webw)
    {
     cout << "Hello " << id;
     cout << "\nUsername: " << decryptU;
     cout << "\nPassword: " << decryptP;
     cout << "\nWebsite: " << webw << endl
          << endl;
    }
    // else statement
    else
    {
     cout << "Your User Doesn't have any credintials of this website \n";
     break;
    }
   }
  }
  default:
   break;
  }
 }
 // else login failed
 else
 {
  cout << "\nLogin Failed \nPlease check username and password\n";
  cout << "\nPress 1 to Return to Main Menu \n";
  cin >> option;
  switch (option)
  {
  case 1:
   main();
  }
 }
}
void registration()
{
 int option;
 string ruserId, rpassword, rid, rpass, generatedPass, encrypt;
 cout << "\033[2J\033[1;1H";
 cout << "Enter your Username : ";
 cin >> ruserId;

 // Check if the username already exists in the records
 ifstream check("records.txt");
 while (check >> rid >> rpass)
 {
  // if ruserId enetered by user matches an rid in records.txt it gives an "username already exists"
  if (rid == ruserId)
  {
   cout << rid << " Username already exists. Please choose a different username.\n";
   check.close();
   return;
  }
 }

 check.close();

 cout << "| Press 1 to Choose your own password           " << endl;
 cout << "| Press 2 to generate a strong password           " << endl;
 // Taking input from user using switch statement, if chooses 1 means choose his own password, if 2 it will generate a strong password
 cin >> option;
 switch (option)
 {
 case 1:
 {
  // DO-While statement, which is responsible for repeating the password-entry process while validatePassword != true, which means it will be repeating the process until the user enters a strong password
  do
  {
   cout << "Your Password Has to contain the following: \n";
   cout << "~ 6 Characters or more\n~ Upper Case Letter\n~ Lower Case Letter\n~ Special Character\n~ Number\n";
   cout << "Enter Password : ";
   cin >> rpassword;

   // Using the validatePassword function, and if !true, it means the password is weak, and the user has to enter a strong password
   if (validatePassword(rpassword) != true)
   {
    cout << "\nPlease enter a strong password\n";
   }
   // while statement
  } while (validatePassword(rpassword) != true);

  // For loop that goes through each letter in the provided password and for each character it adds 3 to it (caesar cipher)

  for (int i = 0; i < rpassword.size(); i++)
  {
   char e = rpassword[i] + 3;
   encrypt += e;
  }

  // If all is well, we use the ofstream class which opens a file and is supposed to write in it, and writing the userID and encrypted pass for future login use
  ofstream f1("records.txt", ios::app);
  f1 << ruserId << ' ' << encrypt << endl;
  cout << "\033[2J\033[1;1H";
  cout << "\nRegistration is Successful!\n\nYou'll be redirected to the main menu in 5 seconds\n";
  break;
 }
 case 2:
 {

  // Do while statement which ensures the generatedPass passes by the validatePassword function, following the same methodolgy as above
  do
  {
   /* This Upcoming Section is Responsible for generation of strong Password */

   // initializing the length of password(26), c(counter for digits), s(counter for special characters)
   int n = 26, c = 0, s = 0;

   srand(time(0));
  N:
   // generatedPass is now empty
   generatedPass = "";
   // character C initialization
   char C;

   // for loop which keeps doing the same process 26 times till it reaches length of our desired password(26)
   for (int z = 0; z < n; z++)
   {
    // First letter using GenRand()
    C = GenRand();
    // Adding Letter to the generatedPass
    generatedPass += C;
    // Two if statements which check if C character is digit or special character and implementing the counter accordingly
    if (isdigit(C))
    {
     c++;
    }
    if (C == '!' || C == '@' || C == '$' || C == '%' || C == '^' || C == '&' || C == '*' || C == '#' || C == '-' || C == '_' || C == '(' || C == ')')
    {
     s++;
    }
   }
   // This statement says if we reach two characters and the special counter and digits are still 0 to goto N which means repeating the same process again till we reach the desired password
   if (n > 2 && (s == 0 || c == 0))
   {
    goto N;
   }
  } while (validatePassword(generatedPass) != true);

  // This section we use ofstream which means this is a file we will be writing into
  ofstream f1("records.txt", ios::app);

  // For loop that goes through each letter in generated pass and for each character it adds 3 to it (caesar cipher)
  for (int i = 0; i < generatedPass.size(); i++)
  {
   char e = generatedPass[i] + 3;
   encrypt += e;
  }

  // Writing the userid and encrypted password to the records.txt file
  f1 << ruserId << ' ' << encrypt << endl;
  cout << "\033[2J\033[1;1H";
  cout << "Your Password is: " << generatedPass;
  cout << "\nRegistration is Successful!\n\nYou'll be redirected to the main menu in 5 seconds\n";
  break;
 }
 default:
  break;
 }
}