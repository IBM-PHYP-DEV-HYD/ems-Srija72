#ifndef XyzEmpIF_H
#define XyzEmpIF_H

#include <string>
#include <iostream>

using namespace std;

#include "XyzEnums.H"

class XyzEmployeeIF{
public:
    virtual ~XyzEmployeeIF(){};

    virtual void displayCommonDetails() = 0;
    virtual void printSummary() = 0;
    virtual void displayDetails() = 0;

    virtual string getId()=0;
    virtual string getName() = 0;
    virtual string getEmpType()=0;
    virtual Employee::Gender getGender()=0;
    virtual Employee::EmpStatus getEmpStatus()=0;
    virtual string getDob()=0;
    virtual string getDoj()=0;

    virtual Employee::AssignmentStatus getAssignmentStatus() = 0;
    virtual void updateLeaves(int leavesParm) = 0;
    virtual void completeAssignment() = 0;
};

#endif