#ifndef XyzEMSMenu_H
#define XyzEMSMenu_H

#include "XyzEmpManager.H"
#include "Utils.H"
#include "XyzEnums.H"
#include "XyzEmpContractor.H"
#include "XyzEmployeeCreator.H"

class EMSMenu {
private:
    XyzEmployeeManager* mManager; 
public:
    EMSMenu(); 
    ~EMSMenu(); 
    void mainMenu();
    string readName();
    void handleUserChoice(int choiceParm);
    void displayAddmenu();
    void displayRemovemenu();
    void displayGetDetailsMenu();
    void displayOtherMenu();
    Employee::Gender readGender();
    Employee::EmployeeType readEmployeeType();
    Employee::EmpStatus readEmpStatus();
    Employee::College readCollege();
    Employee::Branch readBranch();
    Employee::Agency readAgency();
};

#endif