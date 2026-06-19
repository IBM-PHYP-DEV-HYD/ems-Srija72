#ifndef XyzEmpFullTime_H
#define XyzEmpFullTime_H

#include "XyzEmpBase.H"

class  XyzFullTimeEmployee : public XyzEmpBase {
private:
    double mSalary;
    int mLeavesAvailed=0 ;
    int mLeavesLeft=22;
public:
    XyzFullTimeEmployee(string nameParm,
                        string empIdParm,
                        Employee::Gender genderParm,
                        string DOBParm,
                        string DOJParm,
                        double salaryParm);
    void displayDetails();
    void printAdditionalSummary();
    string getEmpType();
    void updateLeaves(int leavesParm);

};
#endif