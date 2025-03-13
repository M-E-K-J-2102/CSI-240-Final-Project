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

#ifndef _SCHEDULEROPERATIONS_H
#define _SCHEDULEROPERATIONS_H

#include "Doctor.h"
#include "Patient.h"
#include "commonOperations.h"

const int MAX_APPTS = 32;
const int DAYS = 5;
const string DAY[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

void addAppointment(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient***& scheduler);
void appointmentSearch(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient***& scheduler);
void changeAppointment(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient***& scheduler);
void displaySchedule(int doctorIndex, Patient***& scheduler);
void loadSchedule(Patient***& scheduler, Doctor doctor[], int numberOfDoctor);
void removeAppointment(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient***& scheduler);
int schedulerMenu();
void schedulerOperations(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient***& scheduler);
void storeSchedule(Patient***& scheduler, int numberOfDoctor);
void viewSchedule(Doctor doctors[], int numberOfDoctor, Patient***& scheduler);

#endif
