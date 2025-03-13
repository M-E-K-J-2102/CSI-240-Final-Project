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
#ifndef _PATIENTOPERATIONS_H
#define _PATIENTOPERATIONS_H

#include <iostream>
#include <fstream>
#include <string>

#include "Patient.h"
#include "Doctor.h"
#include "commonOperations.h"


using namespace std;

void addPatient(Patient**&, Doctor[], int);
//int getPatientIndex(Patient** patients, Doctor doctors[], int numberOfDoctor, string id);
void getPatientIndex(Patient** patients, Doctor doctors[], int numberOfDoctor,
	string id, int& patientIndex, int& doctorIndex);
bool isPatientExist(Patient** patients, Doctor doctors[], int numberOfDoctor, string id);
//void loadPatient(Patient**& patients, Doctor* doctor);
void loadPatient(Patient**& patients, Doctor doctor);
void patientOperations(Patient**& patients, Doctor doctors[], int numberOfDoctor);
//void removePatient(Patient**& patients, Doctor doctors[], int numberOfDoctor, string id);
void removePatient(Patient**& patients, Doctor doctors[], int numberOfDoctor);
//void searchPatient(Patient** patients, Doctor doctors[], int numberOfDoctor, string ssn);
void searchPatient(Patient** patients, Doctor doctors[], int numberOfDoctor);
//void storePatient(Patient** patients, Doctor doctors[], int numberOfDoctor);
void storePatient(Patient patients[], Doctor doctors);
//void updatePatient(Patient** patients, Doctor doctors[], int numberOfDoctor, string id);
void updatePatient(Patient** patients, Doctor doctors[], int numberOfDoctor);

#endif



