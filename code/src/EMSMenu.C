#include"Utils.H"
#include"Enums.H"

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
            cout<<"Exiting , Thank you .....\n";
            break;
        }
        handleUserChoice(sChoice);
    }
}

void EMSMenu :: handleUserChoice(int parmChoice){
    switch(parmChoice){
        case SubMenu::Add : 
            displayAddmenu();
            break;
        case SubMenu::Remove :
            displayRemovemenu();
            break;
        case SubMenu::Get :
            displayGetDetailsMenu();
            break;
        case SubMenu::Other:
            displayOtherMenu();
            break;
        default :
            cout<<"Invalid choice\n";
            return;

    }
}
void EMSMenu :: displayAddmenu(){
    int sChoice = 0;
    while(sChoice != -1){
        cout<<"--------------------------------------------------------------\n"
            <<"                 Employee Management System                   \n"
            <<"--------------------------------------------------------------\n"
            <<"        Add an Employee :                                     \n"
            <<"               1.Add an Employee at Random                    \n"
            <<"               2.Add an Employee                              \n"
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
            case AddMenu :: Add:{
                cout<<"Adding Employee \n";
                XyzEmployeeManager manager;
                manager.addFulltimeEmployee(); 
                break;
            }
            case AddMenu :: Random:{
                cout<<"Adding Random Employee \n";
                break;
            }
            default:
                cout<<"Invalid choice \n";
                break;
        }

    }
}
void EMSMenu :: displayRemovemenu(){
    int sChoice = 0;
    while(sChoice != -1){
        cout<<"--------------------------------------------------------------\n"
            <<"                 Employee Management System                   \n"
            <<"--------------------------------------------------------------\n"
            <<"        Remove an Employee :                                  \n"
            <<"              1.Remove an Employee at Random                  \n"
            <<"              2.Remove an Employee                            \n"
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
            case RemoveMenu :: Remove :
                cout<<"Removing an Employee \n";
                break;
            case RemoveMenu :: Random :
                cout<<"Removing Random Employee \n";
                break;
            default:
                cout<<"Invalid choice \n";
                break;
        }

    }
}
void EMSMenu :: displayGetDetailsMenu(){
    int sChoice = 0;
    while(sChoice != -1){
        cout<<"--------------------------------------------------------------\n"
            <<"                 Employee Management System                   \n"
            <<"--------------------------------------------------------------\n"
            <<"      Get Employee details :                                  \n"
            <<"             1.All Employees Summary.                         \n"
            <<"             2.Employee Summary (F/C/I)                       \n"
            <<"             3.Employee Summary (A/I/R)                       \n"
            <<"             4.Employee Summary (M/F)                         \n"
            <<"             5.Display Employee Details                       \n"
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
            case GetDetails :: All:
                cout<<"All Employees Summary\n";
                break;
            case GetDetails :: Type:
                cout<<"All Employees Summary based on type\n";
                break;
            case GetDetails :: Status:
                cout<<"All Employees Summary based on state\n";
                break;
            case GetDetails :: Gender:
                cout<<"All Employees Summary based on gender\n";
                break;
            case GetDetails :: Display:
                cout<<"Display all Employees Summary\n";
                break;
            default:
                cout<<"Invalid Choice \n";
                break;
        }
    }


}
void EMSMenu :: displayOtherMenu(){
    int sChoice = 0;
    while(sChoice != -1){
        cout<<"--------------------------------------------------------------\n"
            <<"                 Employee Management System                   \n"
            <<"--------------------------------------------------------------\n"
            <<"   Other :                                                    \n"
            <<" 1.Add ‘n’ number of leaves to all the Full-Time employees    \n"
            <<" 2.Convert an Intern to Full-Time employee.                   \n"
            <<" 3.Search an Employee by ID                                   \n"
            <<" 4.Search an Employee by Name                                 \n"
            <<" 5.Change Assignment status to Completed.                     \n"
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
            case Others:: Leaves:
                cout<<"Add ‘n’ number of leaves to all the Full-Time employees\n";
                break;
            case Others:: Convert:
                cout<<"Convert an Intern to Full-Time employee\n";
                break;
            case Others:: SeachById:
                cout<<"Search an Employee by ID\n";
                break;
            case Others:: SearchByname:
                cout<<"Search an Employee by Name\n";
                break;
            case Others:: Assignment:
                cout<<"Change Assignment status to Completed\n";
                break;
            default:
                cout<<"Invalid Choice\n"; 
                break;             
        }

    }

}