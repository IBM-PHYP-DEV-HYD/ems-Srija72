#ifndef XyzEmpContractor_H
#define XyzEmpContractor_H

#include "XyzEmpBase.H"

class  XyzContractorEmployee : public XyzEmpBase {
private:
    Employee::Agency mEmpAgency;
public:
    XyzContractorEmployee(string nameParm,
                          string empIdParm,
                          Employee::Gender genderParm,
                          string dobParm,
                          string dojParm,
                          Employee::Agency agencyParm);
    void displayDetails();
    string getEmpType();
    void printAdditionalSummary();

};
#endif