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

#include "Doctor.h"

/*
Pre: A Doctor object is instantiated
Post: The Doctor object is initialized
Purpose: Intialize the Doctor object, rely on Person()
*/
Doctor::Doctor() : Person()
{
    mIndex = 0;
    mNumberOfPatient = 0;
}


/*
Pre:  ID, name, address, phone number, index and patient count of a doctor
Post: The Doctor object is initialized using provided data
Purpose: Intialize the Doctor object, rely on Person(string, string, string, string)
*/
Doctor::Doctor(string id, string name, string address, string phoneNumber, int index,
    int patientCount) : Person(id, name, address, phoneNumber)
{
    mIndex = index;
    mNumberOfPatient = patientCount;
}


/*
Pre: a Doctor object
Post: The current Doctor object is initialized with the object provided
Purpose: Intialize the Doctor object using another Doctor object,
         rely on Person(const Person &)
*/
Doctor::Doctor(const Doctor& obj) : Person(static_cast<Person>(obj))
{
    mIndex = obj.mIndex;
    mNumberOfPatient = obj.mNumberOfPatient;
}


/*
Pre: A Doctor object is instantiated
Post: None
Purpose: This is an empty destuctor
*/
Doctor::~Doctor()
{
    //  intentionally empty
}


/******************  assessor  ******************/

/*
Pre: A Doctor object is instantiated
Post: The doctor's index is returned
Purpose: Return doctor's index of the Doctor object
*/
int Doctor::getIndex()
{
    return mIndex;
}


/*
Pre: A Doctor object is instantiated
Post: The doctor's patient count is returned
Purpose: Return doctor's patient count of the Doctor object
*/
int Doctor::getNumberOfPatient()
{
    return mNumberOfPatient;
}


/******************  mutator  ******************/

/*
Pre: The value for doctor's index
Post: The doctor's index is updated
Purpose: Update the value for doctor's index with the provided value
*/
void Doctor::setIndex(int index)
{
    mIndex = index;
}


/*
Pre: The value for doctor's patient count
Post: The doctor's patient count is updated
Purpose: Update the value for doctor's patient count with the provided value
*/
void Doctor::setNumberOfPatient(int patientCount)
{
    mNumberOfPatient = patientCount;
}


/******************  member operator overloading  ******************/

/*
Pre: None, just a place holder
Post: The doctor's patient count increased by one
Purpose: Increase the patient count by one; Doctor++
*/
Doctor Doctor::operator++(int)
{
    mNumberOfPatient++;

    return *this;
}


/*
Pre: None, just a place holder
Post: The doctor's patient count decreased by one
Purpose: Decrease the patient count by one; Doctor--
*/
Doctor Doctor::operator--(int)
{
    mNumberOfPatient--;

    return *this;
}


/******************  friend functions  ******************/

/*
Pre: The Doctor object is instantiated
Post: Information for the Doctor object is displayed on the screen
Purpose: Display the information for the Doctor object to the screen
*/
void Doctor::display()
{
    cout << "               ID:  " << getId() << endl
        << "             Name:  " << mName << endl
        << "            Index:  " << mIndex << endl
        << "Number of Patient:  " << mNumberOfPatient << endl;
}


/******************  friend functions  ******************/

/*
Pre: The istream and Doctor objects
Post: Read the Doctor object using istream and the istream
      is returned to the caller
Purpose: Read Doctor object via the istream
*/
istream& operator>>(istream& input, Doctor& obj)
{
    string id, junk;


    getline(input, obj.mName);
    getline(input, id);

    obj.setId(id);

    input >> obj.mIndex >> obj.mNumberOfPatient;
    getline(input, junk);

    return input;
}


/*
Pre: The ostream and Doctor objects
Post: Output the Doctor object using ostream and the
      ostream is returned to the caller
Purpose: Output Doctor object via the ostream
*/
ostream& operator<<(ostream& output, Doctor obj)
{
    output << obj.mName << endl
        << obj.getId() << endl
        << obj.mIndex << " " << obj.mNumberOfPatient;

    return output;
}