#include "XyzEmpIntern.H"

XyzInternEmployee::XyzInternEmployee(string nameParm,
                                    string empIdParm,
                                    Employee::Gender genderParm,
                                    string DOBParm,
                                    string DOJParm,
                                    Employee::Branch branchParm,
                                    Employee::College collegeParm)
                                    :XyzEmpBase(nameParm,
                                                empIdParm,
                                                genderParm,
                                                DOBParm,
                                                DOJParm)
                                    {
                                        mBranchName = branchParm;
                                        mCollegeName = collegeParm;

                                    }
void XyzInternEmployee::displayDetails(){
    cout<<"---------Intern Employee Details-----------\n";
    displayCommonDetails();
    cout<<"College Name      : "<<toStringCollege(mCollegeName)<<endl;
    cout<<"Branch Name       : "<<toStringBranch(mBranchName)<<endl;
}
void XyzInternEmployee::printAdditionalSummary(){
    cout << setw(12) << "NA"
         << setw(16) << "NA"
         << setw(13) << "NA"
         << setw(18) << toStringCollege(mCollegeName)
         << setw(12) << toStringBranch(mBranchName)
         << setw(18) << "NA"
         << setw(14) << "NA"
         << endl;
}
string XyzInternEmployee::getEmpType() {
    return "Intern";
}
