#include "XyzEmpContractor.H"
XyzContractorEmployee::XyzContractorEmployee(string nameParm,
                    string empIdParm,
                    Employee::Gender genderParm,
                    string DOBParm,
                    string DOJParm,
                    Employee::Agency agencyParm)
                    :XyzEmpBase(nameParm,
                                empIdParm,
                                genderParm,
                                DOBParm,
                                DOJParm)
                    
                    {
                        mEmpAgency = agencyParm;
                    }
void XyzContractorEmployee::displayDetails(){
    cout<<"----------Contractor Employee------------\n";
    displayCommonDetails();
    cout<<"External Agency   : "<<toStringAgency(mEmpAgency)<<endl;

}
void XyzContractorEmployee::printAdditionalSummary(){
    cout << setw(12) << "NA"
         << setw(16) << "NA"
         << setw(13) << "NA"
         << setw(18) << "NA"
         << setw(12) << "NA"
         << setw(18) << toStringAgency(mEmpAgency)
         << setw(14) << "NA"
         << endl;
}
string XyzContractorEmployee::getEmpType() {
    return "Contractor";
}

