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

#include "Account.h"

// ------ Constructors/Destructors ------ 

// Default constructor
Account::Account()
{
	mId = "";
	mPassword = "";
}

// Constructor
Account::Account(string id, string pass)
{
	mId = id;
	mPassword = pass;
}

// Copy onstructor
Account::Account(Account& acc)
{
	mId = acc.mId;
	mPassword = acc.mPassword;
}

// Destructor
Account::~Account()
{

}

// ------ Overloads ------

/*Pre:     objects must be initialized
*Post:     if both objects have the same id and password, returns true
*Purpose:  Makes it easier to see if objects have the same id and password
******************************************************/
bool Account::operator==(Account acc)
{
	if (mId == acc.mId && mPassword == acc.mPassword)
	{
		return true;
	}
	return false;
}

/*Pre:     objects must be initialized
*Post:     if both objects have the same id and password, returns false
*Purpose:  Makes it easier to see if objects have the same id and password
******************************************************/
bool Account::operator!=(Account acc)
{
	if (mId == acc.mId && mPassword == acc.mPassword)
	{
		return false;
	}
	return true;
}

/*Pre:     objects must be initialized
*Post:     takes in an entire object
*Purpose:  Makes it easier to collect a whole object
******************************************************/
istream& operator>>(istream& lhs, Account& rhs)
{
	lhs >> rhs.mId;
	lhs >> rhs.mPassword;

	return lhs;
}

/*Pre:     objects must be initialized
*Post:     prints an entire object
*Purpose:  Makes it easier to print a whole object
******************************************************/
ostream& operator<<(ostream& lhs, Account& rhs)
{
	lhs << rhs.mId;
	lhs << rhs.mPassword;

	return lhs;
}