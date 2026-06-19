#ifndef XyzEmpBase_H
#define XyzEmpBase_H

#include "XyzEmpIF.H"
#include <iomanip>

class XyzEmpBase : public XyzEmployeeIF{
protected:
    string mName;
    string mEmpId;
    Employee::Gender mGender;
    string mDOJ;
    string mDOB;
    Employee::AssignmentStatus mAssignmentStatus;
    Employee::EmpStatus mEmpStatus;
    
public:
    XyzEmpBase(string nameParm,string empIdParm,Employee::Gender genderParm,string DOBParm,string DOJParm);

    void displayCommonDetails();
    void printSummary();
    virtual void printAdditionalSummary() = 0;
    
    string getName();
    string getId();
    string getDob();
    string getDoj();

    Employee::EmpStatus getEmpStatus();
    Employee::AssignmentStatus getAssignmentStatus();
    Employee:: Gender getGender();
    void completeAssignment();

    virtual string getEmpType() = 0;
    void updateLeaves(int leavesParm);

};
#endif