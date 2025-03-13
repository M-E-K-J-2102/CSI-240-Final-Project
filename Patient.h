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
#ifndef _PATIENT_H
#define _PATIENT_H

#include "Person.h"

class Patient : public Person
{
private:
	string mDoctorId;

public:
	Patient();
	Patient(string, string, string, string, string);
	Patient(const Patient&);
	~Patient();

	string getDoctorId();
	void setDoctorId(string);

	virtual void display();

	friend istream& operator>>(istream&, Patient&);
	friend ostream& operator<<(ostream& lhs, Patient& rhs);
};
#endif