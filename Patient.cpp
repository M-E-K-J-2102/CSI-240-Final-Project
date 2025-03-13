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

#include "Patient.h"

// ------ Constructors/Destructors ------

// Default constructor
Patient::Patient() : Person()
{
	mDoctorId = "";
}

// Costructor
Patient::Patient(string id, string name, string address,
	string phoneNumber, string doctorID)
	: Person(id, name, address, phoneNumber)
{
	mDoctorId = doctorID;
}

// Copy constructor
Patient::Patient(const Patient& patient) : Person(patient)
{
	mDoctorId = patient.mDoctorId;
}

// Destructor
Patient::~Patient()
{

}


// ------ Getters/Setters ------

/* Function:   getDoctorId
*  Purpose:    returns the doctor's ID
*  Pre:        Patient object must be initialized
*  Post:       the ID of the doctor that is assigned to that patient is returned
****************************************************************/
string Patient::getDoctorId()
{
	return mDoctorId;
}

/* Function:   setDoctorId
*  Purpose:    sets the doctors id to a specified value
*  Pre:        Patient must be initialized
*  Post:       doctor's id is changed to specified value
****************************************************************/
void Patient::setDoctorId(string doctorId)
{
	mDoctorId = doctorId;
}


// ------ Member functions ------

/* Function:   display
*  Purpose:    displays the entire object
*  Pre:        Patient must be initialized
*  Post:       prints out the contents of Patient
****************************************************************/
void Patient::display()
{
	cout << "ID: " << getId() << endl;
	cout << "Name: " << mName << endl;
	cout << "Address: " << mAddress << endl;
	cout << "Phone number: " << mPhoneNumber << endl;
	cout << "Doctor's ID: " << mDoctorId << endl;
	cout << endl;
}


// ------ Overloads ------

/*Pre:     object must be initialized and populated
*Post:     object is stored in the lhs istream
*Purpose:  Makes it easier to update object
******************************************************/
istream& operator>>(istream& lhs, Patient& rhs)
{
	lhs >> static_cast<Person&>(rhs);
	getline(lhs, rhs.mDoctorId);

	return lhs;
}

/*Pre:     object must be initialized and populated
*Post:     object is able to be printed out
*Purpose:  Makes it easier to print the object
******************************************************/
ostream& operator<<(ostream& lhs, Patient& rhs)
{
	lhs << dynamic_cast<Person&>(rhs) << endl;
	lhs << rhs.mDoctorId << endl;

	return lhs;
}