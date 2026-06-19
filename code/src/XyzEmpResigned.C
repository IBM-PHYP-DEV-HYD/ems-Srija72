#include "XyzEmpResigned.H"
XyzResignedEmployee::XyzResignedEmployee(string nameParm,
                                        string empIdParm,
                                        Employee::Gender genderParm,
                                        string DOBParm,
                                        string DOJParm,
                                        string leavingDateParm,
                                        Employee::AssignmentStatus assignmentStatusParm)
                                        :XyzEmpBase(nameParm,
                                                    empIdParm,
                                                    genderParm,
                                                    DOBParm,
                                                    DOJParm)
                                {
                                    mLeavingDate=leavingDateParm;
                                    mAssignmentStatus = assignmentStatusParm;
                                    mEmpStatus = Employee::EmpStatus::Resigned;
                                }
void XyzResignedEmployee::displayDetails(){
    cout<<"---------Resigned Employee Details-----------\n";
    displayCommonDetails();
    cout<<"Leaving date     : "<<getLeavingDate()<<endl;
}
void XyzResignedEmployee::printAdditionalSummary(){
    cout << setw(12) << "NA"
         << setw(16) << "NA"
         << setw(13) << "NA"
         << setw(18) << "NA"
         << setw(12) << "NA"
         << setw(18) << "NA"
         << setw(14) << getLeavingDate()
         << endl;
}
string XyzResignedEmployee::getEmpType(){
    return "Resigned";
}
string XyzResignedEmployee::getLeavingDate(){
    return mLeavingDate;
}