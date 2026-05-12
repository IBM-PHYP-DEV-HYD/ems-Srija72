#include "XyzEmpBase.H"
XyzEmpBase::XyzEmpBase(string nameParm,string empIdParm,Employee::Gender genderParm,string DOBParm,string DOJParm){
                mName = nameParm;
                mEmpId = empIdParm;
                mGender = genderParm;
                mDOJ = DOJParm;
                mDOB = DOBParm;
                mEmpStatus = Employee::EmpStatus::Active;
                mAssignmentStatus = Employee::AssignmentStatus::In_Progress;
               }
void XyzEmpBase:: displayCommonDetails(){
    cout<<"Employee Name     : "<<getName()<<endl;
    cout<<"Employee ID       : "<<getId()<<endl;
    cout<<"Employee Type     : "<<getEmpType()<<endl;
    cout<<"Employee Status   : "<<toStringEmpStatus(mEmpStatus)<<endl;
    cout<<"Gender            : "<<toStringGender(mGender)<<endl;
    cout<<"Assignment Status : "<<toStringAssignmentStatus(mAssignmentStatus)<<endl;
    cout<<"Date of Birth     : "<<getDob()<<endl;
    cout<<"Date of Joing     : "<<getDoj()<<endl;
}
void XyzEmpBase::printSummary(){
    cout << left
         << setw(12) << getId()
         << setw(18) << getName()
         << setw(14) << getEmpType()
         << setw(12) << toStringEmpStatus(getEmpStatus())
         << setw(10) << toStringGender(getGender())
         << setw(15) << toStringAssignmentStatus(getAssignmentStatus())
         << setw(14) << getDob()
         << setw(14) << getDoj();

    printAdditionalSummary();
}

string XyzEmpBase::getName(){ return mName;}
string XyzEmpBase::getDob(){ return mDOB;}
string XyzEmpBase::getId(){ return mEmpId;}
string XyzEmpBase::getDoj(){ return mDOJ;}

Employee::Gender XyzEmpBase::getGender(){return mGender;}
Employee::AssignmentStatus XyzEmpBase::getAssignmentStatus(){return mAssignmentStatus;}
Employee::EmpStatus XyzEmpBase::getEmpStatus(){return mEmpStatus;}

void XyzEmpBase::completeAssignment(){
    mAssignmentStatus = Employee::AssignmentStatus::Completed;
}
void XyzEmpBase::updateLeaves(int leavesParm){
    cout << "\033[31mLeave management is only available for Full-Time employees!\033[0m\n";
}


