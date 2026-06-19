#ifndef XyzEmpResigned_H
#define XyzEmpResigned_H

#include "XyzEmpBase.H"

class  XyzResignedEmployee : public XyzEmpBase {
private:
    string mLeavingDate;
public:
    XyzResignedEmployee(string nameParm,
                        string empIdParm,
                        Employee::Gender genderParm,
                        string DOBParm,
                        string DOJParm,
                        string leavingDate,
                        Employee::AssignmentStatus assignmentStatusParm);
    string getEmpType();
    void displayDetails();
    string getLeavingDate(); 
    void printAdditionalSummary(); 
};
#endif