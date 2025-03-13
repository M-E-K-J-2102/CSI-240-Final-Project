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

#include "patientOperations.h"

/* Function:   addPatient
*  Purpose:    adds a patient to the database
*  Pre:        patient 2d array must exist
*  Post:       new patient is added to the array
****************************************************************/
void addPatient(Patient**& patients, Doctor doctors[], int numberOfDoctor)
{
	string name, address, id, phone, docId;
	int doctorIndex = -1, numPatients;

	cout << "Adding patient..." << endl;

	// Prompt user for data
	cout << "Patient SSN: ";
	getline(cin, id);

	cout << "Patient name: ";
	getline(cin, name);

	cout << "Patient address: ";
	getline(cin, address);

	cout << "Patient phone number: ";
	getline(cin, phone);

	// Check SSN is unique and no other doctor is seeing patient
	if (isPatientExist(patients, doctors, numberOfDoctor, id))
	{
		return;
	}

	// Add patient if it does not already exist
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
		pause();
		return;
	}

	// Wei added
	int size = doctors[doctorIndex].getNumberOfPatient();
	Patient* newList = new Patient[size + 1];

	for (int i = 0; i < size; i++)
		newList[i] = patients[doctorIndex][i];
	newList[size] = Patient(id, name, address, phone, docId);

	delete[] patients[doctorIndex];

	patients[doctorIndex] = newList;
	doctors[doctorIndex]++;

	// Wei blocked
	//// increase the ammt of patients a doctor can hold
	//numPatients = doctors[doctorIndex].getNumberOfPatient() + 1;

	//// Create a new array to hold patients and update it later
	//Patient** newPatients = new Patient * [numberOfDoctor];

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
	//		newPatients[i][numPatients - 1] = Patient(id, name, address, phone, docId);

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

/* Function:   getPatientIndex
*  Purpose:    gets the index of specified patient
*  Pre:        patients must be initialized and populated
*  Post:       returns index of patient
****************************************************************/
void getPatientIndex(Patient** patients, Doctor doctors[], int numberOfDoctor,
	string id, int& patientIndex, int& doctorIndex)
	//int getPatientIndex(Patient** patients, Doctor doctors[], int numberOfDoctor, string id)
{
	//int patientIndex, doctorIndex;
	//if (!isPatientExist(patients, doctors, numberOfDoctor, id))
	//{
	//	cout << "Patient does not exist!" << endl;
	//	return -1;
	//}

	// Iterate through  patients array 
	for (int i = 0; i < numberOfDoctor; i++)
	{
		for (int j = 0; j < doctors[i].getNumberOfPatient(); j++)
		{
			// If the ID is found, store index and return
			if (id == patients[i][j].getId())
			{
				// patient object has the doctor attatched to it so i only need to return patient index
				doctorIndex = i;
				patientIndex = j;
				return;
			}
		}
	}

	doctorIndex = -1;
	patientIndex = -1;
	//return -1;
}

/* Function:   isPatientExist
*  Purpose:    checks to se if a patient already exists
*  Pre:        patients must be initialized and populated
*  Post:       returns true or false depending if patient exists or not
****************************************************************/
bool isPatientExist(Patient** patients, Doctor doctors[], int numberOfDoctor, string id)
{
	for (int i = 0; i < numberOfDoctor; i++) // iterates through each doctor
	{
		for (int j = 0; j < doctors[i].getNumberOfPatient(); j++) // iterates through each patient whithin a doctor
		{
			if (id == patients[i][j].getId())
			{
				return true;
			}
		}
	}

	return false;
}

/* Function:   loadPatient
*  Purpose:    loads patients from file into the array
*  Pre:        file must be populated
*  Post:       patients are now in the array and ready to be manipulated
****************************************************************/
//void loadPatient(Patient**& patients, Doctor* doctor)
void loadPatient(Patient**& patients, Doctor doctor)
{
	//ifstream doc, data;
	//string dSsn, junk, ssn, name, add, phone, docId;
	ifstream data;
	string filename;
	int docIndex, numPatients;

	//// Open data file and check it works
	//doc.open("doctors.txt");

	//if (doc.fail())
	//{
	//	cout << "Failed to open 'doctors.txt'" << endl;
	//	exit(1);
	//}

	//// use first line to use as size of array
	//doc >> numDocs;
	//doc.ignore();
	//patients = new Patient* [numDocs];

	//for (int docIndex = 0; docIndex < numDocs; docIndex++)
	//{
	//	getline(doc, junk);
	//	getline(doc, dSsn);
	//	doc >> index >> docPatients;
	//	doc.ignore();

	//	// Create row of size docPatients
	//	patients[docIndex] = new Patient[docPatients];

		// Open file for each doctor's patients and check it works
		//data.open(dSsn + ".txt");

	filename = doctor.getId() + ".txt";
	data.open(filename);

	if (data.fail())
	{
		cout << "Failed to open '" << filename << endl;
		exit(1);
	}

	numPatients = doctor.getNumberOfPatient();
	docIndex = doctor.getIndex();

	patients[docIndex] = new Patient[numPatients];

	for (int i = 0; i < numPatients; i++)
	{
		data >> patients[docIndex][i];
		//// Gather patient info
		//getline(data, ssn);
		//getline(data, name);
		//getline(data, add);
		//getline(data, phone);
		//getline(data, docId);

		//// Create patient object and store it in array
		//patients[docIndex][i] = Patient(ssn, name, add, phone, docId);
	}
	data.close();
	//}
	//doc.close();

	return;
}

/* Function:   patientOperations
*  Purpose:    allows user to chose what operation they want to do for the patient
*  Pre:        patients/doctors array must be declared and initialized
*  Post:       the user gets to execute whatever patient function they wish to
****************************************************************/
void patientOperations(Patient**& patients, Doctor doctors[], int numberOfDoctor)
{
	int choice;
	string junk;

	do {
		clearScreen();
		cout << "\t\t\tPATIENT OPERATIONS\n\n";
		cout << "1. \tAdd patient" << endl;
		cout << "2. \tSearch for patient" << endl;
		cout << "3. \tRemove patient" << endl;
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
			addPatient(patients, doctors, numberOfDoctor);
			break;
		}
		case 2:
		{
			clearScreen();
			searchPatient(patients, doctors, numberOfDoctor);

			break;
		}
		case 3:
		{
			clearScreen();
			removePatient(patients, doctors, numberOfDoctor);
			break;
		}
		case 4:
		{
			clearScreen();
			updatePatient(patients, doctors, numberOfDoctor);

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

/* Function:   removePatient
*  Purpose:    removes a patient from the array
*  Pre:        patient must be in the array
*  Post:       patient is no longer in array
****************************************************************/
void removePatient(Patient**& patients, Doctor doctors[], int numberOfDoctor)
{
	int doctorIndex = -1, patientIndex = -1, size, i, j;
	string ssn;
	Patient* newList;

	cout << "Removing Patient...\nPlease enter id for patient to remove: ";
	getline(cin, ssn);

	// Check if id exists
	getPatientIndex(patients, doctors, numberOfDoctor, ssn, patientIndex, doctorIndex);
	if (patientIndex == -1)
	{
		cout << "Patient does not exist!" << endl;
		return;
	}

	size = doctors[doctorIndex].getNumberOfPatient();

	newList = new Patient[size - 1];

	// Find the patient to remove
	for (i = 0, j = 0; i < size; i++)
	{
		if (i != patientIndex)
		{
			newList[j] = patients[doctorIndex][i];
			j++;
		}
	}

	delete[] patients[doctorIndex];

	patients[doctorIndex] = newList;

	doctors[doctorIndex]--;

	cout << "Patient successfully removed." << endl;
	pause();

	// Wei blocked
	//// Check if id exists
	//if (!isPatientExist(patients, doctors, numberOfDoctor, id))
	//{
	//	cout << "Patient does not exist!" << endl;
	//	return;
	//}

	//// Find the patient to remove
	//for (int i = 0; i < numberOfDoctor; i++)
	//{
	//	for (int j = 0; j < doctors[i].getNumberOfPatient(); j++) 
	//	{
	//		if (patients[i][j].getId() == id) 
	//		{
	//			doctorIndex = i;
	//			patientIndex = j;
	//			break;
	//		}
	//	}
	//		
	//	// Break outer loop if patient is found
	//	if (doctorIndex != -1)
	//	{
	//		break;
	//	}
	//}

	//// Check if the patient exists
	//if (doctorIndex == -1 || patientIndex == -1) 
	//{
	//	cout << "Patient not found." << endl;
	//	return;
	//}

	//// Remove the patient by shifting patients up one
	//for (int i = patientIndex; i < doctors[doctorIndex].getNumberOfPatient() - 1; i++) 
	//{
	//	patients[doctorIndex][i] = patients[doctorIndex][i + 1];
	//}

	//// Update number of patients for doctor
	//doctors[doctorIndex].setNumberOfPatient(doctors[doctorIndex].getNumberOfPatient() - 1);

	//// make new array that fits the size of updated patient count
	//Patient** newPatients = new Patient * [numberOfDoctor];

	//for (int i = 0; i < numberOfDoctor; i++) 
	//{
	//	int numPatients = doctors[i].getNumberOfPatient();
	//	newPatients[i] = new Patient[numPatients];

	//	for (int j = 0; j < numPatients; j++) 
	//	{
	//		newPatients[i][j] = patients[i][j];
	//	}
	//}

	//// Delete the old array
	//delete[] patients;

	//// Update the patients array
	//patients = newPatients;

	//cout << "Patient successfully removed." << endl;

	return;
}

/* Function:   searchPatient
*  Purpose:    looks for specified patient
*  Pre:        patients/doctors array must be declared and initialized
*  Post:       displays patient info
****************************************************************/
void searchPatient(Patient** patients, Doctor doctors[], int numberOfDoctor)
{
	string ssn;
	int patientIndex, doctorIndex;

	cout << "Searching for patient...\nPlease enter patient's ID: ";
	getline(cin, ssn);

	//// Iterate through the patients array to search for the specified ID
	//for (int i = 0; i < numberOfDoctor; i++)
	//{
	//	for (int j = 0; j < doctors[i].getNumberOfPatient(); j++)
	//	{
	//		// if the ID is found, display it for the user to see and exit function
	//		if (ssn == patients[i][j].getId())
	//		{
	//			patients[i][j].display();
	//			cout << "Doctor in charge of patient: " << doctors[i].getName() << endl;
	//			return;
	//		}
	//	}
	//}

	getPatientIndex(patients, doctors, numberOfDoctor, ssn, patientIndex, doctorIndex);

	if (patientIndex == -1)
		cout << "Patient could not be found." << endl;
	else
	{
		patients[doctorIndex][patientIndex].display();
	}
}

/* Function:   storePatient
*  Purpose:    stores the updated patients array after user is done
*  Pre:        patients must be initialized and populated
*  Post:       updates the files with any new, deleted or updated info
****************************************************************/
//void storePatient(Patient** patients, Doctor doctors[], int numberOfDoctor)
void storePatient(Patient patients[], Doctor doctors)
{
	ofstream data;

	data.open(doctors.getId() + ".txt");

	for (int i = 0; i < doctors.getNumberOfPatient(); i++)
	{
		data << patients[i];
	}

	data.close();

	//for (int i = 0; i < numberOfDoctor; ++i)
	//{
	//	 data.open(doctors[i].getId() + ".txt");

	//	if (!data.is_open())
	//	{
	//		cout << "Failed to open file for writing: " << doctors[i].getId() << ".txt" << endl;
	//		continue; // Move to the next doctor if file opening fails
	//	}

	//	for (int j = 0; j < doctors[i].getNumberOfPatient(); ++j)
	//	{
	//		data << patients[i][j].getId() << endl;
	//		data << patients[i][j].getName() << endl;
	//		data << patients[i][j].getAddress() << endl;
	//		data << patients[i][j].getPhoneNumber() << endl;
	//		data << doctors[i].getId() << endl; 
	//	}

	//	data.close();
	//}

	return; 
}

/* Function:   updatePatient
*  Purpose:    changes the name of the patient based on the ID entered
*  Pre:        patient must exist
*  Post:       patient has a new name
****************************************************************/
//void updatePatient(Patient** patients, Doctor doctors[], int numberOfDoctor, string id)
void updatePatient(Patient** patients, Doctor doctors[], int numberOfDoctor)
{
	string ssn;
	string name;
	int doctorIndex, patientIndex;

	cout << "Name change...\nPlease enter the ID of the patient you wish to rename: ";
	getline(cin, ssn);

	getPatientIndex(patients, doctors, numberOfDoctor, ssn, patientIndex, doctorIndex);

	if (patientIndex == -1)
	{
		cout << "Patient does not exist" << endl;
		return;
	}

	// Prompts user for new name
	cout << "Enter new patient name: ";
	getline(cin, name);

	patients[doctorIndex][patientIndex].setName(name);

	//// Makes sure patient exists
	//if (!isPatientExist(patients, doctors, numberOfDoctor, id))
	//{
	//	cout << "Patient does not exist" << endl;
	//	return;
	//}

	//// Prompts user for new name
	//cout << "Enter new patient name: ";
	//getline(cin, name);


	//for (int i = 0; i < numberOfDoctor; i++)
	//{
	//	for (int j = 0; j < doctors[i].getNumberOfPatient(); j++)
	//	{
	//		if (id == patients[i][j].getId())
	//		{
	//			patients[i][j].setName(name);
	//		}
	//	}
	//}

	pause();
	return;
}