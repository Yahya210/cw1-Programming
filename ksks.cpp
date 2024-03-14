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
