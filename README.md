# Login & Registration System / Secure Password Storage / Strong Password Generator
This login system is a simple command-line application written in C++ that allows users to register with a username and password, and then subsequently log in with those credentials.

## Features
Registration: Users can register by providing a username and choosing either their own password or generating a strong password.
Login: Registered users can log in by providing their username and password.
Password Strength: The system enforces strong password requirements, including a minimum length of 6 characters, containing at least one uppercase letter, one lowercase letter, one digit, and one special character.
Password Encryption: User passwords are encrypted using a simple Caesar cipher before being stored in a file.
Main Menu: Users are presented with a main menu upon running the program, offering options to log in, register, or exit.

## File Structure
login_system.cpp: The main C++ source code file containing the implementation of the login system.
records.txt: A text file where user registration information (usernames and encrypted passwords) is stored.
README.md: This README file providing an overview of the login system.
Usage
Compilation: Compile the login_system.cpp file using a C++ compiler. For example, using g++: g++ login_system.cpp -o login_system.
Execution: Run the compiled executable file. For example: ./login_system.
Main Menu: Upon running the program, you will be presented with a main menu where you can choose to log in, register, or exit.
Registration: If you choose to register, you will be prompted to enter a username and choose a password. You can either enter your own password or generate a strong password.
Login: If you choose to log in, you will be prompted to enter your username and password. If the provided credentials match those in the records, you will be successfully logged in.
Exiting: You can choose to exit the program at any time from the main menu.

## Dependencies
This program uses standard C++ libraries for input/output operations and string manipulation.
It also utilizes the <unistd.h> library for the sleep() function, which may not work on all operating systems.
Note
Security: While this login system demonstrates basic functionality, it may not be suitable for production use as it lacks advanced security measures such as secure password hashing and protection against common vulnerabilities like SQL injection or brute force attacks.
Operating System Compatibility: Certain features of this program, such as the use of sleep(), may not work on all operating systems. Adjustments may be needed for cross-platform compatibility.

## Author
This login system was created by [Your Name] as a simple demonstration of user authentication in C++.

## License
This project is licensed under the MIT License. Feel free to modify and distribute it according to your needs.
