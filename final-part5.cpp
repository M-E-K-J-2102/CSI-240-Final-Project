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

int main()
{
	const string DATA = "users.txt";
	User users;

	bool validLogin = false;

	// Load data from data file
	users.loadData(DATA);

	do {
		validLogin = login(users);
	} while (!validLogin);

	// After user logs in

	// Create populated patient object
	Patient obj("123-456-789", "Jimmy brickson", "123 apple blvd.", "(802) 234 2345", "111-111-111");
	Patient obj2;

	/*// Check object info is correct
	//obj.display();

	// Test insertion into a file
	fstream file;

	// Open data.txt and check it works
	file.open("data.txt", ios::out);
	if (file.fail())
	{
		cout << "could not open 'data.txt'\n";
		exit(1);
	}

	// Write the object into the file
	cout << "OBJECT 1\n";
	obj.display();
	file << obj;
	file.close();

	cout << "\nData successfully written into file\n" << endl;

	// Open data.txt and check it works 
	file.open("data.txt", ios::in);
	if (file.fail())
	{
		cout << "Failed to open 'data.txt'" << endl;
		exit(1);
	}

	// read the data from the file into the new object
	file >> obj2;

	// Display the new object to check it worked
	cout << "OBJECT 2\n";
	obj2.display();


	// Test the == and != overloads
	cout << endl;
	//obj2.setId("1234");
	cout << "Id 1: " << obj.getId() << endl;
	cout << "ID 2: " << obj2.getId() << endl;

	if (obj == obj2)
	{
		cout << "IDs are equal (==)" << endl;
	}

	if (obj != obj2)
	{
		cout << "IDs are NOT equal (!=)" << endl;

	}*/

	// Doctor implementation
	Doctor doc1, doc2("111-11-1111", "John Doe", "348 maple st.", "(424) 247 2947", 0, 2);
	Doctor doc3(doc2);

	/*cout << "ob1 = \n";
	cout << doc1 << endl;

	cout << "ob2 = \n";
	cout << doc2 << endl;

	cout << "ob3 = \n";
	cout << doc3 << endl;*/

	// ------ Part 4 ------
	// Doctor stuff: 
	//ifstream data;
	int size;

	//// Gathers size of how many doctors there are
	//data.open("doctors.txt");

	//// Cheecks file works
	//if (data.fail())
	//{
	//	cout << "could not open 'doctors.txt'" << endl;
	//	exit(1);
	//}
	//data >> size;
	//data.close();

	// Creates doctor array based on the first line of doctor file
	//Doctor* dArr = new Doctor[size];
	Doctor* dArr;

	// Populates doctor array
	size = loadDoctor(dArr);

	// Create 2d array for doctors' patients
	Patient** pArr = new Patient * [size];

	// Load patient data into array
	for (int i = 0; i < size; i++)
	{
		loadPatient(pArr, dArr[i]);
	}

	//string name = "Jane Doe";

	//// Checks whether a doctor exists or not
	//cout << "Does " << name << " exist?: " << isDoctorExist(dArr, size, name) << endl;

	////Gets a doctor's Index
	//cout << name << "'s Index is: " << getDoctorIndex(dArr, size, name) << endl;

	// Display user operations
	//doctorOperations(pArr, dArr, size);

	/*
	// Displays doctors after operations have been executed to make sure everything is in ordeer
	for (int i = 0; i < size; i++)
	{
		dArr[i].display();
	}


	// Patient stuff:
	cout << "\n\n Patient Operations\n\n";

	// Find a patient's index
	//cout << "Patient 128-348-298's index: " << getPatientIndex(pArr, dArr, size, "128-348-298") << endl <<  endl;

	// Displays the user's menu
	/*do {
		patientOperations(pArr, dArr, size);
		cout << "would you like to exit the program? ";
		cin >> choice;
	} while (toupper(choice) != 'Y');

	//Displays new user data to make sure the files are correctly being updated
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < dArr[i].getNumberOfPatient(); j++)
		{
			pArr[i][j].display();
		}
	}

	// Update files 
	cout << "Saving data...\n";
	storeDoctor(dArr, size);

	// Store patient data into array
	for (int i = 0; i < size; i++)
		storePatient(pArr[i], dArr[i]);
	//storePatient(pArr, dArr, size); */


	// ------ Part 5 ------
	
	int picker, choice; 

	// Create schedule array
	Patient*** sArr;
		
	sArr = new Patient** [size];

	for (int i = 0; i < size; i++)
	{
		sArr[i] = new Patient* [DAYS];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < DAYS; j++)
		{
			sArr[i][j] = new Patient[MAX_APPTS];
		}
	}			

	// load data from file into program
	loadSchedule(sArr, dArr, size);

	//display schedule options
	clearScreen();
	do {
		cout << "\t\t\tMAIN MENU\n\n";
		cout << "1. \tPatient Operations" << endl;
		cout << "2. \tDoctor Operations" << endl;
		cout << "3. \tScheduler Operations" << endl;
		cout << "0. \tTerminate Program" << endl; 

		cin >> choice;
		switch (choice)
		{
		case 0:
		{
			clearScreen();
			break;

		}
		case 1:
		{
			clearScreen();
			patientOperations(pArr, dArr, size);
			break;
		}
		case 2:
		{
			clearScreen();
			doctorOperations(pArr, dArr, size);
			break;
		}
		case 3:
		{
			clearScreen();
			schedulerOperations(pArr, dArr, size, sArr);
			break;
		}
		default:
		{
			clearScreen();
			cout << "Enter a valid choice (0-2): ";
		}
		}
	} while (choice != 0);
	

	// Update files 
	cout << "Saving data...\n";
	storeDoctor(dArr, size);

	for (int i = 0; i < size; i++)
	{
		storePatient(pArr[i], dArr[i]);
	}

	// Save updated schedule into file
	storeSchedule(sArr, size);

	// Delete dynamic arrays

	// delete pArr[]
	for (int i = 0; i < size; i++)
	{
		delete[] pArr[i];
	}

	delete[] pArr;

	// delete sArr[]
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < DAYS; j++)
		{
			delete[] sArr[i][j];
		}

		delete[] sArr[i];
	}

	delete[] sArr;

	cout << "Successfully stored all data!" << endl;

	return 0;
}