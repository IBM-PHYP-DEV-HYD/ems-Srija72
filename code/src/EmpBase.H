#ifndef EmpBase_H
#define EmpBase_H

#include"EmpIF.H"

class XyzEmpBase : public XyzEmployeeIF{
protected:
    string mName;
    string mEmpId;
    Gender::Employee mGender;
    string mDOJ;
    string mDOB;
    AssignmentStatus::Employee mAssignmentStatus;
    EmpStatus::Employee mEmpStatus;
    
public:
    // XyzEmpBase();

    void getDetails();
    void displayDetails();

    string getName();
    string getId();
    string getDob();
    string getDoj();

    EmpStatus::Employee getEmpStatus();
    AssignmentStatus::Employee getAssignmentStatus();
    Gender::Employee getGender();

    void setEmpStatus(EmpStatus::Employee s);
    void completeAssignment();

    virtual string getEmpType() = 0;


};
#endif