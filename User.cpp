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

#include "User.h"

// ------ Constructors/Destructors ------

// Default constructor
User::User()
{
	mAccounts = NULL;
	mAccountInUsed = 0;
}

//  Copy Constructor
User::User(User& obj)
{
	if (obj.mAccountInUsed != NULL)
	{
		delete[] mAccounts;
	}

	mAccounts = new Account[obj.mAccountInUsed];

	for (int i = 0; i < obj.mAccountInUsed; ++i)
	{
		mAccounts[i] = obj.mAccounts[i];
	}
}

// Destructor
User::~User()
{
	if (mAccounts != NULL)
	{
		delete[] mAccounts;
		mAccounts = NULL;
	}
	mAccountInUsed = 0;
}

// Getters/Setters

/* Function:   getAccount
*  Purpose:    gets desired account
*  Pre:        accounts must be initialized
*  Post:       returns account object at desired index
****************************************************************/
Account User::getAccount(int index)
{
	return mAccounts[index];
}

/* Function:   getAccountInUsed
*  Purpose:    gets the ammount of accounts
*  Pre:        Account must be initialized
*  Post:       returns number of accounts being used
****************************************************************/
int User::getAccountInUsed()
{
	return mAccountInUsed;
}

/* Function:   getId
*  Purpose:    gets desired id
*  Pre:        accounts must be initialized
*  Post:       returns Id of specified index
****************************************************************/
string User::getId(int index)
{
	return mAccounts[index].mId;
}

/* Function:   getPassword
*  Purpose:    gets desired password
*  Pre:        accounts must be initialized
*  Post:       returns password of specified index
****************************************************************/
string User::getPassword(int index)
{
	return mAccounts[index].mPassword;
}

/* Function:   setAccount
*  Purpose:    sets account to the desired value
*  Pre:        accounts must be initialized
*  Post:       updates the value of account
****************************************************************/
void User::setAccount(int index, Account obj)
{
	mAccounts[index] = obj;
}

/* Function:   setId
*  Purpose:    sets id to the desired value
*  Pre:        accounts must be initialized
*  Post:       updates the value of id
****************************************************************/
void User::setId(int index, string id)
{
	mAccounts[index].mId = id;
}

/* Function:   setPassword
*  Purpose:    sets password to the desired value
*  Pre:        accounts must be initialized
*  Post:       updates the value of password
****************************************************************/
void User::setPassword(int index, string password)
{
	mAccounts[index].mPassword = password;
}

// ------ Member functions ------

/* Function:   isUserExist
*  Purpose:    checks wether a user exists or not
*  Pre:        accounts must be initialized
*  Post:       updates the value of id
****************************************************************/
bool User::isUserExist(Account obj)
{
	for (int i = 0; i < mAccountInUsed; i++)
	{
		if (mAccounts[i] == obj)
		{
			return true;
		}
	}

	return false;
}

/* Function:   loadData
*  Purpose:    loads the data from the file into the mAccounts array
*  Pre:        file must have data
*  Post:       stores data into mAccounts
****************************************************************/
void User::loadData(string dataFile)
{
	ifstream data(dataFile);
	int size;

	// checks that the datafile works
	if (data.fail())
	{
		cout << "Failed to open '" << dataFile << "'\n";
		exit(1);
	}

	// Reads first line and sets the size of the array to the value in that line
	data >> size;
	mAccounts = new Account[size];
	mAccountInUsed = size;

	for (int i = 0; i < size; i++)
	{
		data >> mAccounts[i].mId >> mAccounts[i].mPassword;
	}

	data.close();

	return;
}

/* Function:   storeData
*  Purpose:    stores desired data into the output file
*  Pre:        mAccounts must be populated
*  Post:       data is stored into output file
****************************************************************/
void User::storeData(string dataFile)
{
	ofstream data;

	int i = 0;

	// opens file and checks it works
	data.open(dataFile);
	if (data.fail())
	{
		cout << "Failed to open '" << dataFile << "'\n";
		exit(1);
	}

	// stores the first line of the file (size of the data) then stores the actual data
	data << mAccountInUsed << endl;

	while (!data.eof())
	{
		data << mAccounts[i] << endl;
		i++;
	}

	data.close();

	return;
}

/* Function:   validateLogin
*  Purpose:    makes sure user exists
*  Pre:        mAccounts must be populated
*  Post:       returns true if an account exists and false if otherwise
****************************************************************/
bool User::validateLogin(Account obj) const
{
	for (int i = 0; i < mAccountInUsed; i++)
	{
		if (mAccounts[i] == obj)
		{
			return true;
		}
	}

	return false;
}