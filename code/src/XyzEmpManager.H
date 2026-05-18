#ifndef XyzEmpManager_H
#define XyzEmpManager_H
#include <iomanip>
#include "Deque.H"
#include "XyzEmpIF.H"
#include "XyzEmpResigned.H"
#include "XyzEmployeeCreator.H"
#include "Utils.H"

class XyzEmployeeManager{
private:
    MyDeque<XyzEmployeeIF* > activeEmployees;
    MyDeque<XyzResignedEmployee* > resignedEmployees;

public:

    void addEmployee(string nameParm, string empIdParm, Employee::Gender genderParm, string dobParm, string dojParm, double salaryParm);
    void addEmployee(string nameParm, string empIdParm, Employee::Gender genderParm, string dobParm, string dojParm, Employee::Branch branchParm, Employee::College collegeParm);
    void addEmployee(string nameParm, string empIdParm, Employee::Gender genderParm, string dobParm, string dojParm, Employee::Agency agencyParm);
    void addEmployee(string nameParm, string empIdParm, Employee::Gender genderParm, string DOBParm, string DOJParm, string leavingDateParm , Employee::AssignmentStatus assignmentStatusParm);

    void removeEmployeebyId(string empIdParm ,string leavingDateParm);
    void promoteEmployee(string empIdParm,double salaryParm);
    void leavesAvailed(string empIdParm,int leavesParm);
    void updateAssignmentStatus(string empIdParm);

    void printAllEmployees();
    void printEmpbyStatus(Employee::EmpStatus statusParm);
    void printEmpByType(Employee::EmployeeType typeParm);
    
    void searchEmployeebyId(string empIdParm);
    void searchEmployeebyName(string empNameparm);

    bool hasEmployees(); 
    void getTotalCountoEmp();
    bool hasActiveEmployees(); 

    void addRandomEmployee();
 

};

#endif