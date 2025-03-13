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

#include "doctorOperations.h"

/* Function:   addDoctor
*  Purpose:    adds a new doctor to the array
*  Pre:        doctor array must be initialized
*  Post:       doctor is added to the array
****************************************************************/
void addDoctor(Doctor*& doctors, int& numberOfDoctor)
{
	string name, ssn, add, num;

	cout << "Adding doctor..." << endl;  // Wei

	// Prompt user for doctor's information
	cout << "Name: ";
	getline(cin, name);

	cout << "SSN: ";
	getline(cin, ssn);

	cout << "Address: ";
	getline(cin, add);

	cout << "Phone number: ";
	getline(cin, num);

	// Check if the name already exists
	if (isDoctorExist(doctors, numberOfDoctor, name))
	{
		cout << "Doctor already exists!" << endl;
		pause();
		return;
	}

	// Create new Doctor array with 1 more spot for the new one
	Doctor* doctors2 = new Doctor[numberOfDoctor + 1];

	// Copy existing doctors to the new array
	for (int i = 0; i < numberOfDoctor; i++)
	{
		doctors2[i] = doctors[i];
	}

	// Add the new doctor
	Doctor obj(ssn, name, add, num, numberOfDoctor, 0);
	doctors2[numberOfDoctor] = obj;

	// make room for the new number of doctors
	numberOfDoctor++;

	// Delete the old doctors array
	delete[] doctors;

	// Update the doctor array with the new array
	doctors = doctors2;

	cout << "Doctor added successfully." << endl;
	pause();
	
	return;
}

/* Function:   addPatient
*  Purpose:    adds a new patient to the array
*  Pre:        patient and doctor arrays must be initialized
*  Post:       patient is added to the array
****************************************************************/
void addPatient(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient& patientToAdd)
{
	string docId;
	int doctorIndex = -1, numPatients;

	// Add it to a doctor that is 'accepting patients' (has not reached max ammt of patients)
	for (int i = 0; i < numberOfDoctor; i++) // iterates through each doctor
	{
		if (doctors[i].getNumberOfPatient() < 5)
		{
			docId = doctors[i].getId();
			doctorIndex = i;
			break;
		}
	}
	// Tell user if no doctor can see a patient
	if (doctorIndex == -1)
	{
		cout << "No doctor is available to accept the patient." << endl;
		return;
	}

	// Wei added
	int size = doctors[doctorIndex].getNumberOfPatient();

	Patient* newList = new Patient[size + 1];

	for (int i = 0; i < size; i++)
		newList[i] = patients[doctorIndex][i];
	newList[size] = patientToAdd;

	doctors[doctorIndex]++;

	delete[] patients[doctorIndex];

	patients[doctorIndex] = newList;

	// Wei blocked
	// increase the ammt of patients a doctor has
	//numPatients = doctors[doctorIndex].getNumberOfPatient() + 1;

	//// Create a new array to hold patients and update it later
	//Patient** newPatients = new Patient* [numberOfDoctor];

	//// Copy existing patient arrays to the new array
	//for (int i = 0; i < numberOfDoctor; i++)
	//{
	//	if (i == doctorIndex)
	//	{
	//		// make array that can hold new ammt of patients
	//		newPatients[i] = new Patient[numPatients];

	//		// Copy existing patients to the new array for this doctor
	//		for (int j = 0; j < numPatients - 1; j++)
	//		{
	//			newPatients[i][j] = patients[i][j];
	//		}

	//		// Add new patient to array
	//		newPatients[i][numPatients - 1] = patientToAdd;

	//		// Delete the old array for this doctor
	//		delete[] patients[i];
	//	}
	//	else
	//	{
	//		// For other doctors, simply copy the existing patient array
	//		newPatients[i] = new Patient[doctors[i].getNumberOfPatient()];
	//		for (int j = 0; j < doctors[i].getNumberOfPatient(); j++)
	//		{
	//			newPatients[i][j] = patients[i][j];
	//		}
	//	}
	//}

	//// Delete the old patients array
	//delete[] patients;

	//// Update patients to the new array
	//patients = newPatients;

	//// Update the number of patients for the doctor that accepted the new patient
	//doctors[doctorIndex].setNumberOfPatient(numPatients);

	// Show confirmation message
	cout << "Patient added successfully." << endl;
	pause();

	return;
}

/* Function:   deleteDoctor
*  Purpose:    deletes a doctor from the arrya
*  Pre:        doctor must exist
*  Post:       doctor is removed from the array and their patients are moved to a different doctor
****************************************************************/
void deleteDoctor(Patient**& patientArr, Doctor*& doctors, int& numberOfDoctors)
{
	int deleteIndex = -1, numPatients;
	string nameToComp, file, ssn, pName, address, phone, junk;

	string name;

	cout << "Removing doctor...\nPlease enter the name of doctor to remove: ";
	getline(cin, name);

	// Wei added
	deleteIndex = getDoctorIndex(doctors, numberOfDoctors, name);  // Wei

	if (deleteIndex == -1)
	{
		cout << "Doctor could not be found." << endl;
	}
	else
	{
		// Create a new array of size one less than the current size
		Doctor* newDoctors = new Doctor[numberOfDoctors - 1];

		// Wei added
		// Copy doctors from the old array to the new array
		for (int i = 0, j = 0; i < numberOfDoctors; i++)
		{
			if (i != deleteIndex)
			{
				newDoctors[j] = doctors[i];
				j++;
			}
		}

		// Delete the old array
		delete[] doctors;

		// Update the doctors array with the new array
		doctors = newDoctors;

		Patient** newPatientList;

		newPatientList = new Patient * [numberOfDoctors - 1];

		for (int i = 0, j = 0; i < numberOfDoctors; i++)
		{
			if (i != deleteIndex)
			{
				newPatientList[j] = patientArr[i];
				patientArr[i] = NULL;
				j++;
			}
			else
			{
				delete[] patientArr[i];
			}
		}

		delete[] patientArr;

		patientArr = newPatientList;

		numberOfDoctors--;

		cout << "Doctor has been successfully deleted." << endl;
		pause();

		return;
	}

	// converts name to uppercase for compariosn
	//for (char& c : name)
	//{
	//	c = toupper(c);
	//}
	//
	//if (!isDoctorExist(doctors, numberOfDoctors, name))
	//{
	//	cout << "Doctor does not exist." << endl;
	//	return;
	//}

	// Create a new array of size one less than the current size
	Doctor* newDoctors = new Doctor[numberOfDoctors - 1];

	// search for doctor in the array
	for (int i = 0; i < numberOfDoctors; i++)
	{
		// Capitalizes all the letters of each doctor to compare them with name
		nameToComp = doctors[i].getName();
		for (char& c : nameToComp)
		{
			c = toupper(c);
		}

		if (nameToComp == name)
		{
			file = doctors[i].getId();
			deleteIndex = i;
			numPatients = doctors[i].getNumberOfPatient();
		}
	}

	//// Update the doctors array with the new array
	//doctors = newDoctors;

	// Wei blocked
	//// Copy doctors from the old array to the new array
	//for (int i = 0; i < numberOfDoctors - 1; i++)
	//{
	//	if (i < deleteIndex)
	//	{
	//		newDoctors[i] = doctors[i];
	//	}
	//	else if (i > deleteIndex)
	//	{
	//		newDoctors[i] = doctors[i++];
	//	}
	//}

	// Transfer patients from deleted doctor to a different doctor
	//ifstream data;
	//file += ".txt";
	//data.open(file);

	//if (data.fail())
	//{
	//	cout << "Error opening '" << file << "'.txt\n" << endl;
	//	exit(1);
	//}

	//// Create patient array for the patients of the deleted doctor
	//Patient* pArr = new Patient[numPatients];
	//for (int i = 0; i < numPatients; i++)
	//{
	//	// Read patient data from the file
	//	data.ignore();
	//	getline(data, ssn);
	//	getline(data, pName);
	//	getline(data, address);
	//	getline(data, phone);
	//	getline(data, junk); // Ignore doctor id since that will be replaced

	//	// Create a Patient object and store it in pArr
	//	pArr[i] = Patient(ssn, pName, address, phone, "");
	//}

	//data.close();

	//remove(file.c_str());

	//// Update the number of doctors
	//numberOfDoctors--;

	//// Delete the old array
	//delete[] doctors;

	//// Update the doctors array with the new array
	//doctors = newDoctors;

	//for (int i = 0; i < numPatients; i++)
	//{
	//	addPatient(patientArr, doctors, numberOfDoctors, pArr[i]);
	//}

	//delete[] pArr;

	//cout << "Doctor has been successfully deleted." << endl;

	return;
}

/* Function:   doctorOperations
*  Purpose:    shows a menu for doctor operations
*  Pre:        doctor array must be initialized and populated
*  Post:       executes a function
****************************************************************/
void doctorOperations(Patient**& patientArr, Doctor*& doctors, int& numberOfDoctor)
{
	int choice;
	string junk;

	do {
		clearScreen();
		cout << "\t\t\tDOCTOR OPERATIONS\n\n";
		cout << "1. \tAdd doctor" << endl;
		cout << "2. \tSearch for doctor" << endl;
		cout << "3. \tRemove doctor" << endl;
		cout << "4. \tChange name" << endl;
		cout << "0. \tBack" << endl;

		cin >> choice;
		getline(cin, junk);

		switch (choice)
		{
		case 0: // exits the menu of user operations
		{
			clearScreen();
			return;
			break;
		}
		case 1:
		{
			clearScreen();
			addDoctor(doctors, numberOfDoctor);
			break;
		}
		case 2:
		{
			clearScreen();
			searchDoctor(doctors, numberOfDoctor);

			break;
		}
		case 3:
		{
			clearScreen();
			deleteDoctor(patientArr, doctors, numberOfDoctor);

			break;
		}
		case 4:
		{
			clearScreen();
			updateDoctor(doctors, numberOfDoctor);

			break;
		}
		default:
		{
			clearScreen();
			cout << "Please enter a valid choice (0-4)" << endl;
			pause();
			break;
		}
		}
	} while (choice != 0);

	return;
}

/* Function:   getDoctorIndex
*  Purpose:    returns the index of chosen doctor
*  Pre:        file must have data
*  Post:       returns the index of chosen doctor
****************************************************************/
//int getDoctorIndex(Doctor doctors[], int numberOfDoctor, string doctorName)  Wei
int getDoctorIndex(Doctor* doctors, int numberOfDoctor, string doctorName)  // Wei
{
	string nameToComp;

	// converts name to uppercase for compariosn
	for (char& c : doctorName)
	{
		c = toupper(c);
	}

	for (int i = 0; i < numberOfDoctor; i++)
	{
		// Capitalizes all the letters of each doctor to compare them with name
		nameToComp = doctors[i].getName();
		for (char& c : nameToComp)
		{
			c = toupper(c);
		}

		if (nameToComp == doctorName)
		{
			return i;
		}
	}

	cout << nameToComp << endl;
	return -1;
}

/* Function:   isDoctorExist
*  Purpose:    Checks to se if a given doctor exists
*  Pre:        array must have data
*  Post:       returns true or false depending if the doctor is found or not
****************************************************************/
bool isDoctorExist(Doctor* arr, int size, string name)
{
	string nameToComp;

	// converts name to uppercase for compariosn
	for (char& c : name)
	{
		c = toupper(c);
	}

	for (int i = 0; i < size; i++)
	{
		// Capitalizes all the letters of each doctor to compare them with name
		nameToComp = arr[i].getName();
		for (char& c : nameToComp)
		{
			c = toupper(c);
		}

		if (name == nameToComp)
		{
			return true;
		}
	}

	return false;
}

/* Function:   loadDoctor
*  Purpose:    stores the data from doctor file into array
*  Pre:        file must have data
*  Post:       array is populated with doctors
****************************************************************/
int loadDoctor(Doctor*& arr)
{
	ifstream data;
	int size, index, numPatients;
	string name, id, junk;
	data.open("doctors.txt");

	if (data.fail())
	{
		cout << "could not open 'doctors.txt'" << endl;
		exit(1);
	}

	data >> size;
	arr = new Doctor[size];

	getline(data, junk); // Wei

	for (int i = 0; i < size; i++)
	{
		// Read data from file
		// Wei added
		data >> arr[i];

		// Wei Blocked
		//getline(data, name); 
		//getline(data, name);
		//getline(data, id);
		//data >> index >> numPatients;

		//// Stores data in array
		//arr[i].setName(name);
		//arr[i].setId(id);
		//arr[i].setIndex(index);
		//arr[i].setNumberOfPatient(numPatients);
	}
	data.close(); // Wei

	return size;
}

/* Function:   searchDoctor
*  Purpose:    looks for a specific doctor
*  Pre:        doctor array must be initialized and populated
*  Post:       displays the info of the doctor searched for
****************************************************************/
void searchDoctor(Doctor* doctors, int numberOfDoctors)
{
	string nameToComp;
	string name;
	int doctorIndex; // Wei

	cout << "Searching for doctor...\nPlease enter doctor's name: ";
	getline(cin, name);

	// Wei added
	doctorIndex = getDoctorIndex(doctors, numberOfDoctors, name);  // Wei

	if (doctorIndex == -1)
		cout << "Doctor could not be found." << endl;
	else
	{
		doctors[doctorIndex].display();
		cout << endl;
	}


	// Wei blocked
	//// converts name to uppercase for compariosn
	// for (char &c : name) 
	// {
	//	c = toupper(c);
	// }

	//// Iterate through the doctors array to search for the specified name
	//	for (int i = 0; i < numberOfDoctors; i++)
	//	{
	//		// Capitalizes all the letters of each doctor to compare them with name
	//		nameToComp = doctors[i].getName();
	//		for (char& c : nameToComp)
	//		{
	//			c = toupper(c);
	//		}

	//		// if the ID is found, display it for the user to see and exit function
	//		if (name == nameToComp)
	//		{
	//			doctors[i].display();
	//			cout << endl;
	//			return;
	//		}
	//	}

	cout << "Doctor could not be found." << endl;
	pause();

	return;
}

/* Function:   storeDoctor
*  Purpose:    stores the data from doctor array into file
*  Pre:        array must have data
*  Post:       file is populated with doctors from the array
****************************************************************/
void storeDoctor(Doctor* arr, int size)
{
	ofstream data;

	//data.open("doctors2.txt");
	data.open("doctors.txt");

	// Checks to see if file works
	if (data.fail())
	{
		cout << "could not open 'doctors2.txt'" << endl;
		exit(1);
	}

	data << size << endl;
	for (int i = 0; i < size; i++)
	{
		data << arr[i] << endl;
		// Wei blocked
		//data << arr[i].getName() << endl;
		//data << arr[i].getId() << endl;
		//data << arr[i].getIndex() << " " << arr[i].getNumberOfPatient() << endl;
	}

	data.close();

	//// replaces the old doctors file with the updated one
	//remove("doctors.txt");

	////informs the user if the update was successfull or not
	//if (rename("doctors2.txt", "doctors.txt") == 0)
	//{
		//cout << "Data stored successfully!\n";
	//}
	//else
	//{
	//	cout << "Error storing data from doctor array into doctor file!\n";
	//}

	return;
}

/* Function:   updateDoctor
*  Purpose:    changes the doctor's name to what the user wants
*  Pre:        doctor must be initialized and populated
*  Post:       doctor name is updated
****************************************************************/
void updateDoctor(Doctor doctors[], int numberOfDoctor)
{
	string name, newName;
	int doctorIndex, index;

	cout << "Name change...\nPlease enter the name of the doctor you wish to rename: ";
	cin.ignore();
	getline(cin, name);

	// Wei added
	doctorIndex = getDoctorIndex(doctors, numberOfDoctor, name);  // Wei

	if (doctorIndex == -1)
	{
		cout << "Doctor could not be found." << endl;
		pause();
		return;
	}
	else
	{
		// Prompts user for new name
		cout << "Enter new patient name: ";
		getline(cin, newName);

		index = getDoctorIndex(doctors, numberOfDoctor, newName);  // Wei

		if (index != -1)
		{
			cout << "The doctor is already in the system\n";
			pause();

			return;
		}

		doctors[doctorIndex].setName(newName);
	}

	// Wei blocked
	//// Finds name corresponding to ID in order to check for valididy
	//for (int i = 0; i < numberOfDoctor; i++)
	//{
	//	if (id == doctors[i].getId())
	//	{
	//		name = doctors[i].getName();
	//	}
	//}

	//// Makes sure doctor exists
	//if (!isDoctorExist(doctors, numberOfDoctor, name))
	//{
	//	cout << "Patient does not exist" << endl;
	//	return;
	//}

	//// Prompts user for new name
	//cout << "Enter new patient name: ";
	//getline(cin, name);


	//for (int i = 0; i < numberOfDoctor; i++)
	//{
	//	if (id == doctors[i].getId())
	//	{
	//		doctors[i].setName(name);
	//	}
	//}
	cout << "Doctor successfully updated." << endl;
	pause();

	return;
	return;
}