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

#include "schedulerOperations.h"

/* Function:   addPatient
*  Purpose:    adds a patient to the database
*  Pre:        patient 2d array must exist
*  Post:       new patient is added to the array
****************************************************************/
void addAppointment(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient***& scheduler)
{
	string id;
	Patient patient;
	Doctor doc;
	int day, slot;
	bool taken, exists = false;

	// Prompt user for patient ID
	cout << "Id of patient: ";
	cin.ignore();
	getline(cin, id);

	// Get entire patient object based on ID
	for (int i = 0; i < numberOfDoctor; i++)
	{
		for (int j = 0; j < doctors[i].getNumberOfPatient(); j++)
		{
			if (id == patients[i][j].getId())
			{
				patient = patients[i][j];
				exists = true;
			}
		}
	}

	if (!exists)
	{
		cout << "Patient ID not found." << endl;
		pause();
		return;
	}

	// get doctor object for patient
	id = patient.getDoctorId();
	
	for (int i = 0; i < numberOfDoctor; i++)
	{
		if (id == doctors[i].getId())
		{
			doc = doctors[i];
		}
	}
	// Display available slots for patient's doctor
	displaySchedule(doc.getIndex(), scheduler);

	// Check whether patient's choice is valid. reprompt if not
	do {

		taken = false;
		cout << "Day of desired appointment(1-5): ";
		cin >> day;
		day -= 1;

		cout << "Time slot of desired appointment(1-32):";
		cin >> slot;
		slot -= 1;

		// Check if the slot is already taken
		if (scheduler[doc.getIndex()][day][slot].getId() != "") 
		{
			taken = true;
		}
	} while ((day < 0 || day > 4) || (slot < 0 || slot > 31) || taken);

	// store patient in desired slot
	scheduler[doc.getIndex()][day][slot] = patient;

	cout << "Appointment successfully added." << endl;

	pause();

	return;
}

/* Function:   appointmentSearch
*  Purpose:    helps user search for a patient's appointment
*  Pre:        appointment must exist
*  Post:       displays the appointment info for the desired patient
****************************************************************/
void appointmentSearch(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient***& scheduler)
{
	string pId, dId;
	Patient patient, deletedPatient;
	Doctor doc;
	bool exists = false, taken = false;
	int slot, docIndex, hour, min, day = 1;


	cout << "Id of the patient of the appointment to search for: ";
	cin >> pId;

	// Store patient when found
	for (int i = 0; i < numberOfDoctor; i++)
	{
		for (int j = 0; j < doctors[i].getNumberOfPatient(); j++)
		{
			if (pId == patients[i][j].getId())
			{
				patient = patients[i][j];
				exists = true;
			}
		}
	}

	// Let user know if ID is invalid and exit function
	if (!exists)
	{
		cout << "Invalid patient ID." << endl;
		pause();
		return;
	}

	// get doctor object for patient
	dId = patient.getDoctorId();
	for (int i = 0; i < numberOfDoctor; i++)
	{
		if (dId == doctors[i].getId())
		{
			doc = doctors[i];
		}
	}

	docIndex = doc.getIndex();

	// Display patient's appointments to chose from
	cout << patient.getName() << "'s Appointments are listed below." << endl << endl;

	for (int i = 0; i < DAYS; i++)
	{
		hour = 9;
		min = 0;

		cout << "\t\t" << i + 1 << ". " << DAY[i] << endl << endl;

		for (int j = 0; j < MAX_APPTS; j++)
		{
			if (scheduler[docIndex][i][j].getId() == pId)
			{
				cout << j + 1 << ". " << hour << ":" << min;

				// Add extra zero for o'clock times
				if (min == 0)
				{
					cout << "0";
				}
				cout << endl;
			}

			//increment time variables
			min += 15;

			if (min >= 60)
			{
				min = 0;
				hour++;

				if (hour > 17)
				{
					break;
				}
			}
		}
	}

	pause();
	return;
}

/* Function:   changeAppointment
*  Purpose:    changes the time of an appointment
*  Pre:        appointment must exist
*  Post:       appointment time slot/day is changed
****************************************************************/
void changeAppointment(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient***& scheduler)
{
	string pId, dId;
	Patient patient, deletedPatient;
	Doctor doc;
	bool exists = false, taken = false;
	int slot, docIndex, hour, min, day = 1;


	cout << "Id of the patient of the appointment to be rescheduled: ";
	cin >> pId;

	// Store patient when found
	for (int i = 0; i < numberOfDoctor; i++)
	{
		for (int j = 0; j < doctors[i].getNumberOfPatient(); j++)
		{
			if (pId == patients[i][j].getId())
			{
				patient = patients[i][j];
				exists = true;
			}
		}
	}

	// Let user know if ID is invalid and exit function
	if (!exists)
	{
		cout << "Invalid patient ID." << endl;
		pause();
		return;
	}

	// get doctor object for patient
	dId = patient.getDoctorId();
	for (int i = 0; i < numberOfDoctor; i++)
	{
		if (dId == doctors[i].getId())
		{
			doc = doctors[i];
		}
	}

	docIndex = doc.getIndex();

	// Display patient's appointments to chose from
	cout << patient.getName() << "'s Appointments are listed below. Which one would you like to change?" << endl << endl;

	for (int i = 0; i < DAYS; i++)
	{
		hour = 9;
		min = 0;

		cout << "\t\t" << i + 1 << ". " << DAY[i] << endl << endl;

		for (int j = 0; j < MAX_APPTS; j++)
		{
			if (scheduler[docIndex][i][j].getId() == pId)
			{
				cout << j + 1 << ". " << hour << ":" << min;

				// Add extra zero for o'clock times
				if (min == 0)
				{
					cout << "0";
				}
				cout << endl;
			}

			//increment time variables
			min += 15;

			if (min >= 60)
			{
				min = 0;
				hour++;

				if (hour > 17)
				{
					break;
				}
			}
		}
	}

	do {

		taken = false;
		cout << "Day of desired appointment to change(1-5): ";
		cin.ignore();
		cin >> day;
		day -= 1;

		cout << "Time slot of desired appointment to change(1-32):";
		cin.ignore();
		cin >> slot;
		slot -= 1;

		// Check if the slot is already taken
		if (scheduler[doc.getIndex()][day][slot].getId() != "")
		{
			taken = true;
			break;
		}

	} while ((day < 0 || day > 4) || (slot < 0 || slot > 31) || !taken);

	// remove patient from that slot
	scheduler[doc.getIndex()][day][slot] = deletedPatient;

	// Display available slots for patient's doctor
	displaySchedule(doc.getIndex(), scheduler);

	// Check whether patient's choice is valid. reprompt if not
	do {

		taken = false;
		cout << "Day of new appointment(1-5): ";
		cin >> day;
		day -= 1;

		cout << "Time slot of new appointment(1-32):";
		cin >> slot;
		slot -= 1;

		// Check if the slot is already taken
		if (scheduler[doc.getIndex()][day][slot].getId() != "")
		{
			taken = true;
		}
	} while ((day < 0 || day > 4) || (slot < 0 || slot > 31) || taken);

	// store patient in desired slot
	scheduler[doc.getIndex()][day][slot] = patient;

	cout << "Appointment successfully changed." << endl;
	pause();
	return;
}

/* Function:   displaySchedule
*  Purpose:    prints out all available and taken appointments a doctor has
*  Pre:        appointment 3d array must exist
*  Post:       the list is displayed
****************************************************************/
void displaySchedule(int doctorIndex, Patient***& scheduler)
{
	int hour, min, day = 1;

	for (int i = 0; i < DAYS; i++)
	{
		// reset 
		hour = 9; 
		min = 0;

		cout << "\t\t" << i + 1  << ". " << DAY[i] << endl << endl;

		for (int j = 0; j < MAX_APPTS; j++)
		{
			cout << j + 1 << ". " << hour << ":" << min;
			
			// Add extra zero for o'clock times
			if (min == 0)
			{
				cout << "0";
			}

			// Display status of appointment slot
			if (scheduler[doctorIndex][i][j].getId() != "")
			{
				cout << " TAKEN\n";
			}
			else
			{
				cout << endl;
			}

			//increment time variables
			min += 15;

			if (min >= 60)
			{
				min = 0;
				hour++;

				if (hour > 17)
				{
					break;
				}
			}
		}

		day++;
	}
}

/* Function:   loadSchedule
*  Purpose:    adds the stuff from schedule file into array
*  Pre:        patients, doctors, and schedule array must exist
*  Post:       schedules are added into the array
****************************************************************/
void loadSchedule(Patient***& scheduler, Doctor doctor[], int numberOfDoctor)
{
	ifstream data;
	string ssn, name, address, num, docId;
	int i = 0, j = 0, docIndex;

	// Open file and make sure it works
	data.open("schedule.txt");
	if (data.fail())
	{
		cout << "Failed to open 'schedule.txt'" << endl;
		exit(1);
	}

	
	while (!data.eof())
	{
		getline(data, ssn);
		getline(data, name);
		getline(data, address);
		getline(data, num);
		getline(data, docId);

		Patient obj(ssn, name, address, num, docId);

		docIndex = -1;

		// Gets index of doctor 
		for (int k = 0; k < numberOfDoctor; k++) 
		{
			if (doctor[k].getId() == docId)
			{
				docIndex = doctor[k].getIndex();
				break;
			}
		}

		// add patient to array
		if (docIndex != -1)
		{
			scheduler[docIndex][i][j] = obj;
		}
		else // If the slot is empty, go to next time slot
		{
			if (j == 32)
			{
				i++;
				j = 0;
			}
			else
			{
				j++;
			}
		}
		

		if (i > 5)
		{
			break;
		}

	}
	
	data.close();

	return;
}

/* Function:   removeAppointment
*  Purpose:    removes a patient from the appointment list
*  Pre:        patient must be in the appointment list
*  Post:       patient is removed from apointment list
****************************************************************/
void removeAppointment(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient***& scheduler)
{
	string pId, dId;
	Patient patient, deletedPatient;
	Doctor doc;
	bool exists = false, taken = false;
	int slot, docIndex, hour, min, day = 1;
	

	cout << "Id of the patient of the appointment to be removed: ";
	cin >> pId;

	// Store patient when found
	for (int i = 0; i < numberOfDoctor; i++)
	{
		for (int j = 0; j < doctors[i].getNumberOfPatient(); j++)
		{
			if (pId == patients[i][j].getId())
			{
				patient = patients[i][j];
				exists = true;
			}
		}
	}

	// Let user know if ID is invalid and exit function
	if (!exists)
	{
		cout << "Invalid patient ID." << endl;
		pause();
		return;
	}

	// get doctor object for patient
	dId = patient.getDoctorId();
	for (int i = 0; i < numberOfDoctor; i++)
	{
		if (dId == doctors[i].getId())
		{
			doc = doctors[i];
		}
	}
	
	docIndex = doc.getIndex();

	// Display patient's appointments to chose from
	cout << patient.getName() << "'s Appointments are listed below. Please chose one to remove." << endl << endl;

	for (int i = 0; i < DAYS; i++)
	{
		hour = 9;
		min = 0;

		cout << "\t\t" << i + 1 << ". " << DAY[i] << endl << endl;

		for (int j = 0; j < MAX_APPTS; j++)
		{
			if (scheduler[docIndex][i][j].getId() == pId)
			{
				cout << j + 1 << ". " << hour << ":" << min;

				// Add extra zero for o'clock times
				if (min == 0)
				{
					cout << "0";
				}
				cout << endl;
			}

			//increment time variables
			min += 15;

			if (min >= 60)
			{
				min = 0;
				hour++;

				if (hour > 17)
				{
					break;
				}
			}
		}
	}

	do {

		taken = false;
		cout << "Day of desired appointment(1-5): ";
		cin.ignore();
		cin >> day;
		day -= 1;

		cout << "Time slot of desired appointment(1-32):";
		cin.ignore();
		cin >> slot;
		slot -= 1;

		// Check if the slot is already taken
		if (scheduler[doc.getIndex()][day][slot].getId() != "")
		{
			taken = true;
			break;
		}

	} while ((day < 0 || day > 4) || (slot < 0 || slot > 31) || !taken);

	
	scheduler[doc.getIndex()][day][slot] = deletedPatient;

	cout << "Patient successfully deleted from appointments list.\n";
	pause();
	return;
}

/* Function:   schedulerMenu
*  Purpose:    displays the different operations the user can do with scheduling
*  Pre:        shcedule must be loaded
*  Post:       the desired function gets executed
****************************************************************/
int schedulerMenu()
{
	int choice;
	clearScreen();
	cout << "\t\t\tSCHEDULER OPERATIONS\n\n";
	cout << "1. \tAdd appointment" << endl;
	cout << "2. \tDisplay schedules" << endl;
	cout << "3. \tRemove appointment" << endl;
	cout << "4. \tMove appointment" << endl;
	cout << "5. \tSearch for existing appointment" << endl;
	cout << "0. \tBack" << endl;

	cin >> choice;

	return choice;
}

/* Function:   schedulerOperations
*  Purpose:    executes the chosen operation after calling schedulerMenu
*  Pre:        schedulerMenu must be called and return a value
*  Post:       the desired function gets executed
****************************************************************/
void schedulerOperations(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient***& scheduler)
{
	int picker;
	do {
		 picker = schedulerMenu();
		switch (picker)
		{
			case 0: // exits the menu of schedule operations
			{
				clearScreen();
				break;
			}
			case 1:
			{
				clearScreen();
				addAppointment(patients, doctors, numberOfDoctor, scheduler);
				break;
			}
			case 2:
			{
				clearScreen();
				viewSchedule(doctors, numberOfDoctor, scheduler);

				break;
			}
			case 3:
			{
				clearScreen();
				removeAppointment(patients, doctors, numberOfDoctor, scheduler);
				break;
			}
			case 4:
			{
				clearScreen();
				changeAppointment(patients, doctors, numberOfDoctor, scheduler);
				break;
			}
			case 5:
			{
				clearScreen();
				appointmentSearch(patients, doctors, numberOfDoctor, scheduler);
				break;
			}
			default:
			{
				clearScreen();
				cout << "Please enter a valid choice (0-5)" << endl;
				pause();
				break;
			}
		}
	} while (picker != 0);
}

/* Function:   storeSchedule
*  Purpose:    saves the updated list of patient schedules into the file
*  Pre:        array must be initialized
*  Post:       appointments are stored and the program can safely be exited
****************************************************************/
void storeSchedule(Patient***& scheduler, int numberOfDoctor)
{
	ofstream data;

	data.open("schedule.txt");

	if (data.fail())
	{
		cout << "Failed to open 'schedule.txt'\n";
		exit(1);
	}

	for (int i = 0; i < DAYS; i++)
	{
		for (int j = 0; j < MAX_APPTS; j++)
		{
			for (int k = 0; k < numberOfDoctor; k++)
			{
				if (scheduler[k][i][j].getId() != "")
				{
					data << scheduler[k][i][j];
				}
			}

			// Stores empty patient object to signify change of appt slot
			data << Patient() << endl << endl;
		}
	}

	data.close();

	return;
}

/* Function:   viewSchedule
*  Purpose:    displays all available slots and appointments
*  Pre:        array must be initialized
*  Post:       appointments are displayed 
****************************************************************/
void viewSchedule(Doctor doctors[], int numberOfDoctor, Patient***& scheduler)
{
	for (int i = 0; i < numberOfDoctor; i++)
	{
		// Display doctor's name
		cout << "\t\t\tDr. " << doctors[i].getName() << endl;

		for (int j = 0; j < DAYS; j++)
		{
			// Display day
			cout << "\t" << DAY[j] << endl;

			int hour = 9;
			int min = 0;

			for (int k = 0; k < MAX_APPTS; k++)
			{
				cout << k + 1 << ". " << hour << ":" << min;

				// Display second zero after first for o'clock times
				if (min == 0)
				{
					cout << "0";
				}

				// Show appointment status if it is taken
				if (scheduler[i][j][k].getId() != "")
				{
					cout << " TAKEN\n";
				}
				else
				{
					cout << endl;
				}

				// increment counters
				min += 15;

				if (min >= 60)
				{
					min = 0;
					hour++;

					if (hour > 17)
					{
						break;
					}
				}
			}
		}

		cout << endl;
	}

	pause();

	return;
}