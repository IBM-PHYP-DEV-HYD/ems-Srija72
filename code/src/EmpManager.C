#include"EmpManager.H"

void XyzEmployeeManager::addFulltimeEmployee(){
    XyzFullTimeEmployee *emp = new XyzFullTimeEmployee();
    emp -> getDetails();
    fullTimeEmpQ.pushBack(emp);
    emp -> getDetails();

}
