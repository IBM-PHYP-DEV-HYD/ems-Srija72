#include "XyzEMSMenu.H"
EMSMenu::EMSMenu() {
    mManager = new XyzEmployeeManager();
}
EMSMenu::~EMSMenu() {
    delete mManager;
}

// functions to read the data from user
string EMSMenu :: readName(){
    string sName;
    while(true){
    cout<<"Enter the Name of Employee :";
    cin.ignore();
    getline(cin,sName);
    if(isNameValid(sName)){
        break;
    }
    cout<<"Invalid name , PLease enter valid name\n";
    }
    return sName;
}
Employee::Gender EMSMenu :: readGender(){
    int sChoice;
    while(true){
        cout<<"Select the Gender"<<endl;
        cout<<"1.Male\n2.Female\n3.Others"<<endl;
        cout<<"Enter choice:";
        cin>>sChoice;
        if(!inputHandle()){
            continue;
        }
        if (sChoice >= 1 && sChoice <= 3) {
            return Employee::GenderFromInt(sChoice);
        }
        cout<<"Invalid option\n";
    }
}
Employee::EmployeeType EMSMenu::readEmployeeType(){
    int sChoice;
    while(true){
        cout<<"Select Employee Type :\n";
        cout<<"1.Full Time\n2.Intern\n3.Contractor\n";
        cout<<"Enter choice:";
        cin>>sChoice;
        if(!inputHandle()){
            continue;
        }
        if (sChoice >= 1 && sChoice <= 3) {
            return Employee::EmployeeTypeFromInt(sChoice);
        }
        cout<<"Invalid option\n";
    }
}
Employee::College EMSMenu ::readCollege(){
    int sChoice;
    while(true){
        cout<<"Select the College of Intern :\n";
        cout<<"1.IIT_Delhi\n2.IT_Mumbai\n3.IIT_Kanpur\n4.IIT_Hyderabad\n5.NIT_Warangal\n6.NIT_Tiruchi\n7.IIIT_Hyderabad\n";
        cout<<"Enter choice:";
        cin>>sChoice;
        if(!inputHandle()){
            continue;
        }
        if (sChoice >= 1 && sChoice <= 7) {
            return Employee::CollegeFromint(sChoice);
        }
        cout<<"Invalid option\n";
    }
}
Employee::Branch EMSMenu ::readBranch(){
    int sChoice;
    while(true){
        cout<<"Select the branch of Intern :\n";
        cout<<"1.CSE\n2.CSIT\n3.ECE\n";
        cout<<"Enter choice:";
        cin>>sChoice;
        if(!inputHandle()){
            continue;
        }
        if (sChoice >= 1 && sChoice <= 3) {
            return Employee::BranchFromint(sChoice);
        }
        cout<<"Invalid option\n";        
    }
}
Employee::Agency EMSMenu :: readAgency(){
    int sChoice;
    while(true){
        cout<<"Select the Agency of Contractor :\n";
        cout<<"1.Avengers\n2.Justice_League\n3.X_Men\n";
        cout<<"Enter choice:";
        cin>>sChoice;
        if(!inputHandle()){
            continue;
        }
        if (sChoice >= 1 && sChoice <= 3) {
            return Employee::AgencyFromint(sChoice);
        }
        cout<<"Invalid option\n";
    }
}
// function to display Main Menu 
void EMSMenu :: mainMenu(){
    int sChoice = 0;
    while (sChoice != -1){
        cout<<"--------------------------------------------------------------\n"
            <<"                 Employee Management System                   \n"
            <<"--------------------------------------------------------------\n"
            <<"                     1.Add an Employee.                       \n"
            <<"                     2.Remove an Employee                     \n"
            <<"                     3.Get an Employee details                \n"
            <<"                     4.Others.                                \n"
            <<"                     -1.EXIT                                  \n"
            <<"--------------------------------------------------------------\n";
        cout<<"Enter your choice :";
        cin>>sChoice;
        if(!inputHandle()){
            continue;
        }
        if(sChoice == -1){
            cout<<"\033[32mExiting , Thank you .....\033[0m\n";
            break;
        }
        handleUserChoice(sChoice);
    }
}
// Function to handle user input 
void EMSMenu :: handleUserChoice(int parmChoice){
    switch(parmChoice){
        case Menu::Options::Add : 
            displayAddmenu();
            break;
        case Menu::Options::Remove :
            displayRemovemenu();
            break;
        case Menu::Options::Get :
            displayGetDetailsMenu();
            break;
        case Menu::Options::Other:
            displayOtherMenu();
            break;
        default :
            cout<<"Invalid choice\n";
            return;

    }
}
// function to display add employee menu
void EMSMenu :: displayAddmenu(){
    int sChoice = 0;
    string sName ;
    string sEmpId;
    string sDoB;
    string sDoJ;
    Employee::Agency sAgency;
    Employee::Branch sBranch;
    Employee::College sCollege;
    Employee::Gender sGender;
    Employee::EmployeeType sEmpType;
    while(sChoice != -1){
        cout<<"--------------------------------------------------------------\n"
            <<"                 Employee Management System                   \n"
            <<"--------------------------------------------------------------\n"
            <<"        Add an Employee :                                     \n"
            <<"               1.Add an Employee                              \n"
            <<"               2.Add an Employee at Random                    \n"
            <<"               -1.Main Menu.                                  \n"
            <<"--------------------------------------------------------------\n";
        cout<<"Enter your choice :";
        cin>>sChoice;
        if(!inputHandle()){
            continue;
        }
        if(sChoice == -1){
            cout<<"Redirecting to Main menu......\n";
            break;
        }
        switch(sChoice){
            case Menu::AddMenu::AddManually:{
                sName = readName();
                sGender = readGender();
                while(true){
                    cout<<"Enter DOB of the Employee(DD/MM/YY):";
                    cin>>sDoB;
                    if(!isDateValid(sDoB)) {
                        cin.clear();
                        cout << "Invalid DOB\n";
                        continue;
                    }
                    cout<<"Enter DOJ of the Employee(DD/MM/YY):";
                    cin>>sDoJ;
                    if(!isDateValid(sDoJ)) {
                        cin.clear();
                        cout << "Invalid DoJ\n";
                        continue;
                    }
                    int sDobYear = getYear(sDoB);
                    int sDojYear = getYear(sDoJ);

                    if(sDojYear - sDobYear < 18) {
                        cout << "Employee must be at least 18 years old\n";
                        continue;
                    }
                    break;
                }
                sEmpType = readEmployeeType();
                if(sEmpType==Employee::Full_Time){
                    double sSalary;
                    while(true){
                        cout<<"Enter the Employee Salary :";
                        cin>>sSalary;
                        if(!inputHandle()){
                            continue;
                        }
                        break;
                    }
                    sEmpId = "XYZ"+to_string(getRandomNumber(1000, 1999)) + "F";
                    mManager->addEmployee(sName, sEmpId, sGender, sDoB, sDoJ, sSalary);
    
                }
                else if(sEmpType==Employee::Intern){
                    sCollege = readCollege();
                    sBranch = readBranch();
                    sEmpId = "XYZ"+to_string(getRandomNumber(1000, 1999)) + "I";
                    mManager->addEmployee(sName, sEmpId, sGender, sDoB, sDoJ, sBranch, sCollege);

                }
                else if(sEmpType == Employee::Contractor){
                    sAgency = readAgency();
                    sEmpId = "XYZ"+to_string(getRandomNumber(1000, 1999)) + "C";
                    mManager->addEmployee(sName, sEmpId, sGender, sDoB, sDoJ, sAgency);
                }
                break;
                }

            case Menu::AddMenu :: Random:{
                mManager->addRandomEmployee();
                break;
            }

            default:
                cout<<"Invalid choice \n";
                break;
        }

    }
}
// function to display remove menu 
void EMSMenu :: displayRemovemenu(){
    int sChoice = 0;
    string sEmpId;
    string sLeavingDate;
    while(sChoice != -1){
        cout<<"--------------------------------------------------------------\n"
            <<"                 Employee Management System                   \n"
            <<"--------------------------------------------------------------\n"
            <<"        Remove an Employee :                                  \n"
            <<"              1.Remove an Employee                            \n"
            <<"              -1.Main Menu.                                   \n"
            <<"--------------------------------------------------------------\n";
        cout<<"Enter your choice :";
        cin>>sChoice;
        if(!inputHandle()){
            continue;
        }
        if(sChoice == -1){
            cout<<"Redirecting to Main menu......\n";
            break;
        }
        switch(sChoice){
            case Menu::RemoveMenu::RemoveById:
                cout<<"Enter the Employee ID :";
                cin>>sEmpId;
                while(true){
                    cout<<"Enter the date of Leaving : ";
                    cin>>sLeavingDate;
                    if(!isDateValid(sLeavingDate)) {
                        cin.clear();
                        cout << "Invalid DOL\n";
                        continue;
                    }
                    mManager->removeEmployeebyId(sEmpId,sLeavingDate);
                    break;
                }
                break;
            default:
                cout<<"Invalid choice \n";
                break;
        }
    }
}
// Function to display Employee details based on user given types
void EMSMenu :: displayGetDetailsMenu(){
    int sChoice = 0;
    int sChoiceStatus;
    Employee::EmployeeType sEmpType;
    while(sChoice != -1){
        cout<<"--------------------------------------------------------------\n"
            <<"                 Employee Management System                   \n"
            <<"--------------------------------------------------------------\n"
            <<"      Get Employee details :                                  \n"
            <<"             1.All Employees Summary.                         \n"
            <<"             2.Employee Summary (F/C/I)                       \n"
            <<"             3.Employee Summary (A/I/R)                       \n"
            <<"             -1.Main Menu.                                    \n"
            <<"--------------------------------------------------------------\n";
        cout<<"Enter your choice :";
        cin>>sChoice;
        if(!inputHandle()){
            continue;
        }
        if(sChoice == -1){
            cout<<"Redirecting to Main menu......\n";
            break;
        }
        switch(sChoice){
            case Menu::GetDetails :: All:
                mManager->printAllEmployees();
                break;
            case Menu::GetDetails :: Type:
                sEmpType = readEmployeeType();
                mManager->printEmpByType(sEmpType);
                break;
            case Menu::GetDetails :: Status:
                while(true){
                    cout<<"Select the Employee state to be displayed :\n";
                    cout<<"1.Active\n2.Inactive\n3.Resigend\n";
                    cout<<"Enter the choice:";
                    cin>>sChoiceStatus;
                    if(!inputHandle()){
                        continue;
                    }
                    Employee::EmpStatus status = Employee::EmpStatusFromint(sChoiceStatus);
                    mManager->printEmpbyStatus(status);
                    break;               
                }
            default:
                cout<<"Invalid Choice \n";
                break;
        }
    }
}
// Function to display other operations menu
void EMSMenu :: displayOtherMenu(){
    int sChoice = 0;
    int sLeaveAvailed;
    string sEmpId;
    string sName;
    double sSalary;
    while(sChoice != -1){
        cout<<"--------------------------------------------------------------\n"
            <<"                 Employee Management System                   \n"
            <<"--------------------------------------------------------------\n"
            <<"   Other :                                                    \n"
            <<" 1.Add ‘n’ number of leaves to the Full-Time employee         \n"
            <<" 2.Promote an employee to Full-Time                           \n"
            <<" 3.Search an Employee by ID                                   \n"
            <<" 4.Search an Employee by Name                                 \n"
            <<" 5.Change Assignment status to Completed.                     \n"
            <<" 6.Get the total number of Employees                          \n"
            <<" -1.Main Menu.                                                \n"
            <<"--------------------------------------------------------------\n";
        cout<<"Enter your choice :";
        cin>>sChoice;
        if(!inputHandle()){
            continue;
        }
        if(sChoice == -1){
            cout<<"Redirecting to Main menu......\n";
            break;
        }
        switch(sChoice){
            case Menu::Others:: Leaves:
                while(true){
                    cout<<"Enter Emp Id:";
                    cin>>sEmpId;
                    cout<<"Enter the number of leaves availed :";
                    cin>>sLeaveAvailed;
                    if(!inputHandle()){
                        continue;
                    }
                    if (sLeaveAvailed < 0 || sLeaveAvailed > 22){
                        cout << "Leaves should be between 0 and 22.\n";
                        continue;
                    }
                    break;
                }
                mManager->leavesAvailed(sEmpId,sLeaveAvailed);
                break;
            case Menu::Others:: Convert:
                cout<<"Enter Emp Id:";
                cin>>sEmpId;
                while(true){
                    cout<<"Enter salary:";
                    cin>>sSalary;
                    if(!inputHandle()){
                        continue;
                    }
                    break;
                }
                mManager->promoteEmployee(sEmpId,sSalary);
                break;
            case Menu::Others:: SeachById:
                cout<<"Enter Emp Id:";
                cin>>sEmpId;
                mManager->searchEmployeebyId(sEmpId);
                break;
            case Menu::Others:: SearchByname:
                sName = readName();
                mManager->searchEmployeebyName(sName);
                break;
            case Menu::Others:: Assignment:
                cout<<"Enter Emp Id:";
                cin>>sEmpId;
                mManager->updateAssignmentStatus(sEmpId);
                break;
            case Menu::Others:: Total:
                mManager->getTotalCountoEmp();
                break;
            default:
                cout<<"Invalid Choice\n"; 
                break;             
        }
    }
}
