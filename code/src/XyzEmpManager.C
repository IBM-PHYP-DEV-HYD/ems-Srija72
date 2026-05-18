#include "XyzEmpManager.H"


// To add Employees in the queue
void XyzEmployeeManager::addEmployee(string nameParm, string empIdParm, Employee::Gender genderParm, string dobParm, string dojParm, double salaryParm){
    XyzEmployeeIF* newEmployee = EmployeeCreator::createXYZFullTime(nameParm, empIdParm, genderParm, dobParm, dojParm, salaryParm);
    activeEmployees.pushBack(newEmployee);
    cout<<"\033[32mEmployee with Employee ID :"<<empIdParm<<" added succesfully\033[0m\n";
}

void XyzEmployeeManager::addEmployee(string nameParm, string empIdParm, Employee::Gender genderParm, string dobParm, string dojParm, Employee::Branch branchParm, Employee::College collegeParm){
    XyzEmployeeIF* newEmployee = EmployeeCreator::createXYZIntern(nameParm, empIdParm, genderParm, dobParm, dojParm, branchParm, collegeParm);
    activeEmployees.pushBack(newEmployee);
    cout<<"\033[32mEmployee with Employee ID :"<<empIdParm<<" added succesfully\033[0m\n";
}

void XyzEmployeeManager::addEmployee(string nameParm, string empIdParm, Employee::Gender genderParm, string dobParm, string dojParm, Employee::Agency agencyParm){
    XyzEmployeeIF* newEmployee = EmployeeCreator::createXYZContract(nameParm, empIdParm, genderParm, dobParm, dojParm, agencyParm);
    activeEmployees.pushBack(newEmployee);
    cout<<"\033[32mEmployee with Employee ID :"<<empIdParm<<" added succesfully\033[0m\n";
}
void XyzEmployeeManager::addEmployee(string nameParm, string empIdParm, Employee::Gender genderParm, string DOBParm, string DOJParm, string leavingDateParm ,Employee::AssignmentStatus assignmentStatusParm){
    XyzResignedEmployee* newEmployee = EmployeeCreator::createResignedEmployee(nameParm, empIdParm, genderParm, DOBParm, DOJParm , leavingDateParm , assignmentStatusParm);
    resignedEmployees.pushBack(newEmployee);
    cout<<"\033[32mEmployee with Employee ID :"<<empIdParm<<" removed succesfully\033[0m\n";
}

// Remove employee by ID
void XyzEmployeeManager::removeEmployeebyId(string empIdParm ,string leavingDateParm){
    if(!hasActiveEmployees()) return;
    bool sFound = false;
    for(int i = 0; i < activeEmployees.getSize(); i++){
        XyzEmployeeIF* emp = activeEmployees[i];
        if(emp->getId() == empIdParm){
            sFound = true;           
            string doj = emp->getDoj();
            int dojYear = getYear(doj);
            int leavingYear = getYear(leavingDateParm);            
            if(leavingYear < dojYear){
                cout << "\033[31mLeaving date cannot be before Date of Joining!\033[0m\n";
                return;
            }            
            if(leavingYear == dojYear && leavingDateParm <= doj){
                cout << "\033[31mLeaving date must be after Date of Joining!\033[0m\n";
                return;
            }            
            XyzResignedEmployee* resignedEmp = new XyzResignedEmployee(
                emp->getName(),
                emp->getId(),
                emp->getGender(),
                emp->getDob(),
                emp->getDoj(),
                leavingDateParm,
                emp->getAssignmentStatus()
            );           
            resignedEmployees.pushBack(resignedEmp);
            activeEmployees.removeAt(i);
            cout << "\033[32mEmployee " << empIdParm << " moved to resigned employees successfully!\033[0m\n";
            break;
        }
    }    
    if(!sFound){
        cout << "\033[31mEmployee with ID " << empIdParm << " not sFound in active employees!\033[0m\n";
    }
}
// Convert employee to full time
void XyzEmployeeManager::promoteEmployee(string empIdParm, double salaryParm){
    if(!hasActiveEmployees()) return;    
    bool sFound = false;
    for(int i = 0; i < activeEmployees.getSize(); i++){
        XyzEmployeeIF* emp = activeEmployees[i];
        if(emp->getId() == empIdParm){
            sFound = true;            
            if(emp->getEmpType() == "Full Time"){
                cout << "\033[31mEmployee " << empIdParm << " is already a Full-Time employee!\033[0m\n";
                return;
            }            
            XyzEmployeeIF* fullTimeEmp = EmployeeCreator::createXYZFullTime(
                emp->getName(),
                emp->getId(),
                emp->getGender(),
                emp->getDob(),
                emp->getDoj(),
                salaryParm
            );            
            if(emp->getAssignmentStatus() == Employee::AssignmentStatus::Completed){
                fullTimeEmp->completeAssignment();
            }            
            activeEmployees.removeAt(i);
            activeEmployees.pushBack(fullTimeEmp);
            
            cout << "\033[32mEmployee " << empIdParm << " promoted to Full-Time successfully!\033[0m\n";
            delete emp;
            break;
        }
    }    
    if(!sFound){
        cout << "\033[31mEmployee with ID " << empIdParm << " not sFound!\033[0m\n";
    }
}

// Update leaves availed
void XyzEmployeeManager:: leavesAvailed(string empIdParm,int leavesParm){
    if(!hasActiveEmployees()) return;
    bool sFound = false;
    for(int i = 0; i < activeEmployees.getSize(); i++){
        XyzEmployeeIF* emp = activeEmployees[i];
        if(emp->getId() == empIdParm){
            sFound = true;
            emp->updateLeaves(leavesParm);
            break;
        }
    }
    if(!sFound){
        cout << "\033[31mEmployee with ID " << empIdParm << " not sFound in active employees!\033[0m\n";
    }    
}
void XyzEmployeeManager::updateAssignmentStatus(string empIdParm){
     if(!hasActiveEmployees()) return;
    bool sFound = false;
    for(int i = 0; i < activeEmployees.getSize(); i++){
        XyzEmployeeIF* emp = activeEmployees[i];
        if(emp->getId() == empIdParm){
            sFound = true;
            emp->completeAssignment();
            cout << "\033[32mAssignment status updated to Completed for employee " << empIdParm << "!\033[0m\n";
            break;
        }
    }
    
    if(!sFound){
        cout << "\033[31mEmployee with ID " << empIdParm << " not sFound!\033[0m\n";
    }
}
// Prints all the employees
void XyzEmployeeManager::printAllEmployees(){
        if(activeEmployees.isEmpty() && resignedEmployees.isEmpty()){
        cout << "\033[31mNo employees found!\033[0m\n";
        return;
    }

    cout << left
         << setw(12) << "Emp ID"
         << setw(18) << "Name"
         << setw(14) << "Type"
         << setw(12) << "Status"
         << setw(10) << "Gender"
         << setw(15) << "Assignment"
         << setw(14) << "DOB"
         << setw(14) << "DOJ"
         << setw(12) << "Salary"
         << setw(16) << "Leaves Availed"
         << setw(13) << "Leaves Left"
         << setw(18) << "College"
         << setw(12) << "Branch"
         << setw(18) << "Agency"
         << setw(14) << "Leaving Date"
         << endl;

    cout << string(208, '-') << endl;

    for(int i = 0; i < activeEmployees.getSize(); i++){
        activeEmployees[i]->printSummary();
    }

    for(int i = 0; i < resignedEmployees.getSize(); i++){
        resignedEmployees[i]->printSummary();
    }
}

void XyzEmployeeManager::printEmpbyStatus(Employee::EmpStatus statusParm){
    string statusStr = Employee::toStringEmpStatus(statusParm);        
        bool sFound = false;        
        if(statusParm == Employee::EmpStatus::Active){
            if(!hasActiveEmployees()) return;          
            for(int i = 0; i < activeEmployees.getSize(); i++){
                sFound = true;
                activeEmployees[i]->displayDetails();
            }
        }
        else if(statusParm == Employee::EmpStatus::Resigned){
            if(resignedEmployees.isEmpty()){
                cout << "\033[31mNo resigned employees found!\033[0m\n";
                return;
            }
            
            for(int i = 0; i < resignedEmployees.getSize(); i++){
                sFound = true;
                resignedEmployees[i]->displayDetails();
            }
        }
            if(!sFound){
        cout << "No " << statusStr << " employees found.\n";
    }
}
void XyzEmployeeManager::printEmpByType(Employee::EmployeeType typeParm){
    if(!hasActiveEmployees()) return;  
    string typeStr = Employee::toStringEmployeeType(typeParm);    
    bool found = false;
    for(int i = 0; i < activeEmployees.getSize(); i++){
        XyzEmployeeIF* emp = activeEmployees[i];
        if(emp->getEmpType() == typeStr){
            found = true;
            emp->displayDetails();
        }
    }    
    if(!found){
        cout << "No " << typeStr << " employees found.\n";
    }
}
// Check if there are employees
bool XyzEmployeeManager::hasEmployees(){
    if(activeEmployees.isEmpty() && resignedEmployees.isEmpty()){
        cout << "\033[31mNo employees to search!\033[0m\n";
        return false;
    }
    return true;
}
// Search emp by Id
void XyzEmployeeManager::searchEmployeebyId(string empIdParm){
    if(!hasEmployees()) return;
    bool sFound = false;    
    for(int i = 0; i < activeEmployees.getSize(); i++){
        XyzEmployeeIF* emp = activeEmployees[i];
        if(emp->getId() == empIdParm){
            sFound = true;
            emp->displayDetails();
            break;
        }
    }    
    if(!sFound){
        for(int i = 0; i < resignedEmployees.getSize(); i++){
            XyzResignedEmployee* emp = resignedEmployees[i];
            if(emp->getId() == empIdParm){
                sFound = true;
                emp->displayDetails();
                break;
            }
        }
    }    
    if(!sFound){
        cout << "\033[31mEmployee with ID " << empIdParm << " not sFound!\033[0m\n";
    }   
}
// Search emp by name
void XyzEmployeeManager::searchEmployeebyName(string empNameparm){
    if(!hasEmployees()) return;   
    bool sFound = false;    
    for(int i = 0; i < activeEmployees.getSize(); i++){
        XyzEmployeeIF* emp = activeEmployees[i];
        if(emp->getName() == empNameparm){
            sFound = true;
            emp->displayDetails();
        }
    }    
    for(int i = 0; i < resignedEmployees.getSize(); i++){
        XyzResignedEmployee* emp = resignedEmployees[i];
        if(emp->getName() == empNameparm){
            sFound = true;
            emp->displayDetails();
        }
    }    
    if(!sFound){
        cout << "\033[31mEmployee with name " << empNameparm << " not sFound!\033[0m\n";
    }    
}
// Gives total count of Employees
void XyzEmployeeManager::getTotalCountoEmp(){
    int sActiveCount = activeEmployees.getSize();
    int sResignedCount = resignedEmployees.getSize();
    cout << "Active Employees    : " << sActiveCount << "\n";
    cout << "Resigned Employees  : " << sResignedCount << "\n";
    cout<<"----------------------------------------\n";
    cout << "Total Employees     : " << (sActiveCount + sResignedCount) << "\n";
}
// Check for Active employees
bool XyzEmployeeManager::hasActiveEmployees(){
    if(activeEmployees.isEmpty()){
        cout << "\033[31mNo active employees sFound!\033[0m\n";
        return false;
    }
    return true;
}
// Add a random employee
void XyzEmployeeManager::addRandomEmployee(){
    string sName = generateRandomName();
    Employee::Gender sGender = Employee::GenderFromInt(getRandomNumber(1, 3));
    
    string sDoB = generateRandomDate(1966, 2008);
    int sDobYear = getYear(sDoB);
    
    int minDojYear = sDobYear + 18;
    int maxDojYear = 2026;
    string sDoJ = generateRandomDate(minDojYear, maxDojYear);
    
    Employee::EmployeeType sEmpType = Employee::EmployeeTypeFromInt(getRandomNumber(1, 3));
    
    string sEmpId;
    
    if(sEmpType == Employee::Full_Time){
        double sSalary = getRandomNumber(30000, 150000);
        sEmpId = "XYZ" + to_string(getRandomNumber(1000, 1999)) + "F";
        addEmployee(sName, sEmpId, sGender, sDoB, sDoJ, sSalary);
    }
    else if(sEmpType == Employee::Intern){
        Employee::College sCollege = Employee::CollegeFromint(getRandomNumber(1, 7));
        Employee::Branch sBranch = Employee::BranchFromint(getRandomNumber(1, 3));
        sEmpId = "XYZ" + to_string(getRandomNumber(1000, 1999)) + "I";
        addEmployee(sName, sEmpId, sGender, sDoB, sDoJ, sBranch, sCollege);
    }
    else if(sEmpType == Employee::Contractor){
        Employee::Agency sAgency = Employee::AgencyFromint(getRandomNumber(1, 3));
        sEmpId = "XYZ" + to_string(getRandomNumber(1000, 1999)) + "C";
        addEmployee(sName, sEmpId, sGender, sDoB, sDoJ, sAgency);
    }
}
