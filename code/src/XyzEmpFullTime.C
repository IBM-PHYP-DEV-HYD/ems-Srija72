#include "XyzEmpFullTime.H"

XyzFullTimeEmployee::XyzFullTimeEmployee(string nameParm,
                                        string empIdParm,
                                        Employee::Gender genderParm,
                                        string DOBParm,
                                        string DOJParm,
                                        double salaryParm)
                                        :XyzEmpBase(nameParm,
                                                    empIdParm,
                                                    genderParm,
                                                    DOBParm,
                                                    DOJParm)
{
                                        mSalary = salaryParm;

}

void XyzFullTimeEmployee::displayDetails(){
        cout<<"----------Full Time Employee Details-------------\n";
        displayCommonDetails();
        cout<<"Leaves Availed     : "<<mLeavesAvailed<<endl;
        cout<<"Leaves Left        : "<<mLeavesLeft<<endl;
        cout<<"Salary             : "<<mSalary<<endl;

    }
void XyzFullTimeEmployee::printAdditionalSummary(){
    cout << setw(12) << mSalary
         << setw(16) << mLeavesAvailed
         << setw(13) << mLeavesLeft
         << setw(18) << "NA"
         << setw(12) << "NA"
         << setw(18) << "NA"
         << setw(14) << "NA"
         << endl;
}
string XyzFullTimeEmployee::getEmpType() {
        return "Full Time";
    }

void XyzFullTimeEmployee::updateLeaves(int leavesParm){
    if(leavesParm > mLeavesLeft){
        cout << "\033[31mError: Cannot avail " << leavesParm << " leaves. Only " << mLeavesLeft << " leaves remaining!\033[0m\n";
        return;
    }
    mLeavesAvailed = mLeavesAvailed + leavesParm;
    mLeavesLeft = mLeavesLeft-leavesParm;
    cout << "\033[32m" << leavesParm << " leaves updated successfully!\033[0m\n";
    cout << "Leaves Availed: " << mLeavesAvailed <<endl<< "Leaves Left: " << mLeavesLeft << endl;

}
