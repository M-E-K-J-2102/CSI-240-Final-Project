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

#ifndef _DOCTOR_H
#define _DOCTOR_H

#include "Person.h"

class Doctor : public Person
{
private:
    int mIndex, mNumberOfPatient;

public:
    Doctor();
    Doctor(string, string, string, string, int, int);
    Doctor(const Doctor&);
    ~Doctor();

    //  assessor
    int getIndex();
    int getNumberOfPatient();

    //  mutator
    void setIndex(int);
    void setNumberOfPatient(int);

    Doctor operator++(int);
    Doctor operator--(int);

    // virtual function
    virtual void display();

    //  friend functions
    friend istream& operator>>(istream&, Doctor&);
    friend ostream& operator<<(ostream&, Doctor);
};


#endif