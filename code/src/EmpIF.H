#ifndef EmpIF_H
#define EmpIF_H

#include <string>
#include<iostream>

using namespace std;

#include"Enums.H"

class XyzEmployeeIF{
public:
    // virtual ~XyzEmployeeIF();

    virtual void getDetails() = 0;
    virtual void displayDetails() = 0;

    virtual string getId()=0;
    virtual string getName() = 0;
    virtual string getEmpType()=0;
    virtual AssignmentStatus::Employee getAssignmentStatus() = 0;
    virtual Gender::Employee getGender()=0;

};

#endif