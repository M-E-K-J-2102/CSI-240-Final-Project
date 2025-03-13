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
#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class Account
{
public:
	string mId;
	string mPassword;

	Account();
	Account(string, string);
	Account(Account&);
	~Account();

	bool operator==(Account);
	bool operator!=(Account);

	friend istream& operator>>(istream&, Account&);
	friend ostream& operator<<(ostream&, Account&);
};

#endif

