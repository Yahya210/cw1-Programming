# Login & Registration System / Secure Password Storage / Strong Password Generator / Secure Password Manager
This system is a command-line application written in C++ with the following features:

## Features
* Registration: Users can provide usernames and choosing either their own password or generating a strong password.
* Strong Password Generation : this program provides strong pass generation of a password that contains 26 letters containing uppercase lowercase, special characters, and digits.
* Login: Registered users can log in by providing their username and password.
* Password Strength: The system enforces strong password requirements, including a minimum length of 6 characters, containing at least one uppercase letter, one lowercase letter, one digit, and one special character.
* Secure Password storage(Encryption): User passwords are encrypted using Caesar cipher before being stored in a file.
* Main Menu: Users are presented with a main menu upon running the program, offering options to log in, register, or exit.
* Password Manager: After Registering using a strong password and logging in, users can now use the password manager to securely store their credintials, by entering the username, password (or generating strong one), and the website link. 

## File Structure
* cw1.cpp: The main C++ source code file containing the implementation of the Registration, login, and password management system, along with the implementation of generating strong passwords and validating passwrods.
* records.txt: A text file where user registration information (usernames and encrypted passwords) is stored.
* passwords.txt: The text file containing credintials of the website (Password Manager)
* README.md: This README file providing an overview of the login system.

## Usage
1. Compilation: Compile the login_system.cpp file using a C++ compiler. For example, using g++: g++ cw1.cpp -o cw1.
2. Execution: Run the compiled executable file. For example: ./cw1.
3. Main Menu: Upon running the program, you will be presented with a main menu where you can choose to log in, register, or exit.
<img width="312" alt="Main Menu" src="https://github.com/Yahya210/cw1-Programming/assets/114566232/1c8c9a4a-6659-40b8-86b6-1a6a305b52f2">

4. Registration: If you choose to register, you will be prompted to enter your username and choose a password. You can either enter your own password(Ensuring you meet the strong password criteria) or generate a strong password.
<img width="408" alt="registration-secure-yahya-duplicates" src="https://github.com/Yahya210/cw1-Programming/assets/114566232/ff13c0ae-2a94-45c1-bde7-52f9fda7da55">

5. Login: If you choose to log in, you will be prompted to enter your username and password. If the provided credentials match those in the records, you will be successfully logged in.
<img width="262" alt="Login-Generated" src="https://github.com/Yahya210/cw1-Programming/assets/114566232/2048339d-24e6-4117-b5b2-962323c903ad">

6. Using password manager: Now after successful login, the user can now use the password manager, now the user has two options, either entering new credintials: username, password and link of website. The second option is retrieving credintials he previously inserted in our records.
   1. **Entering new credintials**
      If the user chooses 1, he has to enter the following:
      * His/her Username on the website
      * The password of the username (Either by entering strong password or generating a strong one)
      * The link of the website
      * <img width="437" alt="Screenshot 2024-03-14 at 10 39 02 PM" src="https://github.com/Yahya210/cw1-Programming/assets/114566232/1eed7fe0-be4f-4df7-9462-24d5b70d96c9">
    2. **Retrieving a password**
       * In the case of retrieving a password, the user has to only enter the link of the website he/she wants to retrieve credintials about, and because we authenticated the user in            previous steps, we fetch the credintials using the userID and website if he/she successfully logged in.
       * <img width="520" alt="Screenshot 2024-03-14 at 10 47 06 PM" src="https://github.com/Yahya210/cw1-Programming/assets/114566232/add2cf44-df4e-4058-9bef-a3a373f5b0ac">


7. Exiting: You can choose to exit the program at any time from the main menu.



## Dependencies
* This program uses standard C++ libraries for input/output operations and string manipulation.
* **It also utilizes the <unistd.h> library for the sleep() function, which may not work on all operating systems (Works only on Linux based systems).**

## Note
* Operating System Compatibility: Certain features of this program, such as the use of sleep(), may not work on all operating systems. Adjustments may be needed for cross-platform compatibility.

## Author
This login system was created by **Yahya Mohamed** as a simple demonstration of user authentication, secure password generation and storage in C++.
