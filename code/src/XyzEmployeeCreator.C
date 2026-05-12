#include "XyzEmployeeCreator.H"

#include "XyzEmpFullTime.H"
#include "XyzEmpIntern.H"
#include "XyzEmpContractor.H"
#include "XyzEmpResigned.H"

XyzEmployeeIF* EmployeeCreator::createXYZFullTime(string nameParm,string empIdParm,Employee::Gender genderParm,string DOBParm,string DOJParm,double salaryParm){
    return new XyzFullTimeEmployee(nameParm,empIdParm,genderParm,DOBParm,DOJParm,salaryParm);
}

XyzEmployeeIF* EmployeeCreator::createXYZIntern(string nameParm,string empIdParm,Employee::Gender genderParm,string DOBParm,string DOJParm,Employee::Branch branchParm,Employee::College collegeParm){
    return new XyzInternEmployee(nameParm,empIdParm,genderParm,DOBParm,DOJParm,branchParm,collegeParm);

}

XyzEmployeeIF* EmployeeCreator::createXYZContract(string nameParm,string empIdParm,Employee::Gender genderParm,string DOBParm,string DOJParm,Employee::Agency agencyParm){
    return new XyzContractorEmployee(nameParm,empIdParm,genderParm,DOBParm,DOJParm,agencyParm);
}

XyzResignedEmployee* EmployeeCreator::createResignedEmployee(string nameParm, string empIdParm, Employee::Gender genderParm, string DOBParm, string DOJParm, string leavingDate, Employee::AssignmentStatus assignmentStatusParm){
    return new XyzResignedEmployee(nameParm,empIdParm, genderParm, DOBParm, DOJParm, leavingDate, assignmentStatusParm);
}

XyzEmployeeIF* EmployeeCreator::createPromotedFullTime(XyzEmployeeIF* oldEmployee,double salary){
    return new XyzFullTimeEmployee(
        oldEmployee->getId(),
        oldEmployee->getName(),
        oldEmployee->getGender(),
        oldEmployee->getDob(),
        oldEmployee->getDoj(),
        salary
    );
}