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


#ifndef _PERSON_H
#define _PERSON_H


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Person
{
private:
    string mId;

protected:
    string mAddress, mName, mPhoneNumber;

public:
    Person();
    Person(string id, string name, string address, string phoneNumber);
    Person(const Person& obj);
    ~Person();

    //  assessor
    string getAddress();
    string getId();
    string getName();
    string getPhoneNumber();

    //  mutator
    void setAddress(string address);
    void setId(string id);
    void setName(string name);
    void setPhoneNumber(string phoneNumber);

    bool operator==(string rhs);
    bool operator==(Person rhs);
    friend bool operator==(string lhs, Person rhs);

    bool operator <(Person rhs);
    bool operator >(Person rhs);

    bool operator!=(string rhs);
    bool operator!=(Person rhs);
    friend bool operator!=(string lhs, Person rhs);

    // virtual function
    virtual void display();

    // friend functions
    friend istream& operator>>(istream& input, Person& obj);
    friend ostream& operator<<(ostream& output, Person obj);
};


#endif
