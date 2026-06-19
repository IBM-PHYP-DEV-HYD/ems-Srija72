#ifndef XyzEmpIntern_H
#define XyzEmpIntern_H

#include "XyzEmpBase.H"

class  XyzInternEmployee : public XyzEmpBase {
private:
    Employee::College mCollegeName;
    Employee::Branch mBranchName;
public:
    XyzInternEmployee(string nameParm,
                    string empIdParm,
                    Employee::Gender genderParm,
                    string dobParm,
                    string dojParm,
                    Employee::Branch branchParm,
                    Employee::College collegeParm);
    void displayDetails();
    string getEmpType();
    void printAdditionalSummary();

};
#endif