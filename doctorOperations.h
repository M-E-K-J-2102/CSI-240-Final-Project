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
#ifndef _DOCTOROPERATIONS_H
#define _DOCTOROPERATIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include "Doctor.h"
#include "Patient.h"
#include "commonOperations.h"

//#include <cstdio>

using namespace std;

void addDoctor(Doctor*& doctors, int& numberOfDoctor);
void addPatient(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient& patientToAdd);
//void deleteDoctor(Patient **& patientArr, Doctor*& doctors, int& numberOfDoctors, string& name);
void deleteDoctor(Patient**& patientArr, Doctor*& doctors, int& numberOfDoctors);
void doctorOperations(Patient**& patientArr, Doctor*& doctors, int& numberOfDoctor);
int getDoctorIndex(Doctor*, int, string);
bool isDoctorExist(Doctor*, int, string);
//void loadDoctor(Doctor*&);
int loadDoctor(Doctor*&);
//void searchDoctor(Doctor *, int, string);
void searchDoctor(Doctor*, int);
void storeDoctor(Doctor*, int);
//void updateDoctor(Doctor doctors[], int numberOfDoctor, string id);
void updateDoctor(Doctor doctors[], int numberOfDoctor);

#endif

