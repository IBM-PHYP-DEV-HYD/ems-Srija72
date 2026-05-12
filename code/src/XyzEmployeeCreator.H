#ifndef XyzEmployeeCreator_H
#define XyzEmployeeCreator_H

#include "XyzEmpIF.H"
#include "XyzEnums.H"
#include "XyzEmpResigned.H" 
class EmployeeCreator {
public:
    static XyzEmployeeIF* createXYZFullTime(string nameParm,string empIdParm,Employee::Gender genderParm,string DOBParm,string DOJParm,double salaryParm);        
    static XyzEmployeeIF* createXYZIntern(string nameParm,string empIdParm,Employee::Gender genderParm,string dobParm,string dojParm,Employee::Branch branchParm,Employee::College collegeParm);
    static XyzEmployeeIF* createXYZContract(string nameParm,string empIdParm,Employee::Gender genderParm,string dobParm,string dojParm,Employee::Agency agencyParm);  
    static XyzResignedEmployee* createResignedEmployee(string nameParm,string empIdParm,Employee::Gender genderParm,string DOBParm,string DOJParm,string leavingDate ,Employee::AssignmentStatus assignmentStatusParm);    
    static XyzEmployeeIF* createPromotedFullTime(XyzEmployeeIF* oldEmployee,double salary); 
};
#endif