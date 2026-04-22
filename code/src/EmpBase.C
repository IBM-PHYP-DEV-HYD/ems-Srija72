#include"EmpBase.H"

void XyzEmpBase::getDetails(){
    int sChoice;
    cout<<"Enter the Employee name : ";
    cin>>mName;
    cout<<"\n Select the Gender :\n1.Male\n2.Female\n3.Others\n";
    cout<<"Enter your choice :";
    cin>>sChoice;
    // switch(sChoice){
    //     case 1:
    //         mGender = Male;
    //         break;
    //     case 2:
    //         mGender = Female;
    //         break;
    //     case 3:
    //         mGender = Others;
    //         break;
    //     default:
    //         cout<<"Select valdid option\n";
    //         return;
    // }

    cout<<"Enter the Date of Birth in DD/MM/YY format:";
    getline(cin,mDOB);

    cout<<"Enter the Date Of Joining in DD/MM/YY format:";
    getline(cin,mDOJ);

}
void XyzEmpBase:: displayDetails(){
    cout<<"Employee Name    : "<<mName<<endl;
    cout<<"Employee ID      : "<<mEmpId<<endl;
    cout<<"Employee Type    : "<<getEmpType()<<endl;
    // cout<<"Employee Status  : "
    //     switch(mEmpStatus){
    //         case Active:cout<<"Active";break;
    //         case Inactive:cout<<"Inactive";break;
    //         case Resigned:cout<<"Resigned";break;
    //     };
    //     cout<<endl;
    // cout<<"Gender           : "
    //     switch(mGender){
    //         case Male:cout<<"Male";break;
    //         case Female:cout<<"Female";break;
    //         case Others:cout<<"Otheres";break;
    //     };
    //     cout<<endl;
    // cout<<"Assignment Status  : "
    //     switch(mAssignmentStatus){
    //         case In_Progress:cout<<"In Progress";break;
    //         case Completed:cout<<"Completed";break;

    //     };
    cout<<"Date of Birth    : "<<mDOB<<endl;
    cout<<"Date of Joing    : "<<mDOJ<<endl;
}

string XyzEmpBase::getName(){ return mName;}
string XyzEmpBase::getDob(){ return mDOB;}
string XyzEmpBase::getId(){ return mEmpId;}
string XyzEmpBase::getDoj(){return mDOJ;}

Gender::Employee XyzEmpBase::getGender(){return mGender;}
AssignmentStatus::Employee XyzEmpBase::getAssignmentStatus(){return mAssignmentStatus;}
EmpStatus::Employee XyzEmpBase::getEmpStatus(){return mEmpStatus;}

// void XyzEmpBase::setEmpStatus(EmpStatus EmpStatusParm){
//     mEmpStatus = EmpStatus::EmpStatusParm;
// }

void XyzEmpBase::completeAssignment(){
    mAssignmentStatus = AssignmentStatus::Completed;
}



