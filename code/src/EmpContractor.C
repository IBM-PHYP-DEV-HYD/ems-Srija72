#include"EmpBase.H"

class  XyzContractorEmployee : XyzEmpBase{
private:
    Agency::Employee mEmpAgency;
public:
    void getDetails() override{
        int sChoiceAgency;
        XyzEmpBase::getDetails();
        while(true){
            cout<<"Select External Agency : \n";
            cout<<"1. Avengers\n2. Justice League\n3. X-Men";
            cin>>sChoiceAgency;
            if(sChoiceAgency>=1 && sChoiceAgency <=3) break;
            cout<<"Invalid Choice"<<endl;
        }
        mEmpAgency = static_cast<Agency::Employee>(sChoiceAgency);

    }
    void displayDetails(){
        cout<<"----------Contractor Employee------------\n";
        XyzContractorEmployee::displayDetails();
        cout<<"External Agency    : \n";

    }
    string getEmpType() override{
        return "Contractor ";
    }

};
