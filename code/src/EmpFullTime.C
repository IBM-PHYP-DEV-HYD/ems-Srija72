#include "EmpFullTime.H"

void XyzFullTimeEmployee:: getDetails() {
        XyzEmpBase::getDetails();
        while(true){
            cout<<"Enter leaves availed (between 1-22)";
            cin >>mLeavesAvailed;
            if(mLeavesAvailed >= 0 && mLeavesAvailed<=22){
                break;
            }
            cout<< "Invalid input .Please enter between 1-22\n";
        }
        mLeavesLeft=mLeavesLeft-mLeavesAvailed;
    }
void XyzFullTimeEmployee::displayDetails(){
        cout<<"----------Full Time Employee Details-------------\n";
        XyzFullTimeEmployee::displayDetails();
        cout<<"Leaves Availed   : "<<mLeavesAvailed<<endl;
        cout<<"Leaves Left      : "<<mLeavesLeft<<endl;

    }
string XyzFullTimeEmployee::getEmpType() {
        return "Full-Time";
    }


