/*
Author:           Matthew Kane
Class:            CSI-240-04
Assignment:       Final Project Part 5
Date Assigned:    5/4/2024
Due Date:         26/4/2024 @ 1:00 PM

Description:
Part 5: Adds the appointment management portion

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff;
and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may
then retain a copy of this assignment on its database for the purpose of future
plagiarism checking)
-----------------------------------------------------------------------------------------
Sources:
*/

#include "header.h"

/* Function:   loadData
*  Purpose:    loads the data from the file into the mAccounts array
*  Pre:        file must have data
*  Post:       stores data into mAccounts
****************************************************************/
bool login(User& users)
{
    string username, password;
    bool validLogin = false;

    // Prompt user for login info
    cout << "\n\n\n\t\t\tUsername: ";
    getline(cin, username);

    cout << "\t\t\tPassword: ";
    getline(cin, password);

    Account acc(username, password);

    // Make sure login is correct
    validLogin = users.isUserExist(acc);

    if (validLogin)
    {
        clearScreen();
        cout << "\n\n\n\n\n\t\t\tLogin successful!\n\n";
    }
    else
    {
        cout << "\n\n\n\n\n\t\t\t\Invalid login!\n";
        pause();
        clearScreen();
    }

    return validLogin;
}

/* Function:   loadData
*  Purpose:    loads the data from the file into the mAccounts array
*  Pre:        file must have data
*  Post:       stores data into mAccounts
****************************************************************/
void addPatient()
{

    return;
}