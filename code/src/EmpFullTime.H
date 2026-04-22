#ifndef EmpFullTime_H
#define EmpFullTime_H

#include"EmpBase.H"
using namespace std;

class  XyzFullTimeEmployee : public XyzEmpBase {
private:
    int mLeavesAvailed ;
    int mLeavesLeft=22;
public:
    void getDetails();
    void displayDetails();
    string getEmpType() ;

};
#endif