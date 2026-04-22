#ifndef EmpManager_H
#define EmpManager_H

#include"Deque.H"
#include "EmpFullTime.H"

class XyzEmployeeManager{
private:
    MyDeque<XyzFullTimeEmployee* > fullTimeEmpQ;
public:
    void addFulltimeEmployee();
    // void printFulltimeEmployee();
    
};

#endif