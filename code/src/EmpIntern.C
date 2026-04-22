#include"EmpBase.H"

class  XyzInternEmloyee : public XyzEmpBase {
private:
    College::Employee mCollegeName;
    Branch::Employee mBranchname;
public:
    void getDetails() override{
        int sCollegeChoice,sBranchChoice;

        XyzEmpBase::getDetails();
        while(true){
            cout<<"Select the name of the college "<<endl;
            cout<<"1. IIT Delhi\n2. IT Mumbai\n3. IIT Kanpur\n4. IIT Hyderabad\n5. NIT Warangal\n6. NIT Tiruchi\n7. IIIT Hyderabad,"<<endl;
            cout<<"Enter the choice :";
            cin>>sCollegeChoice;
            if(sCollegeChoice>=1 && sCollegeChoice<=7){
                break;
            }
            cout<<"Invalid option \n";
        
        }
        mCollegeName = static_cast<College::Employee>(sCollegeChoice);

        while(true){
            cout<<"Select the branch"<<endl;
            cout<<"1.2CSE\n2. CSIT\n3. ECE\n";
            cout<<"Enter the choice :";
            cin>>sBranchChoice;   
            if(sBranchChoice>=1 && sBranchChoice<=3){
                break;
            }
            cout<<"Invalid Option \n";

        }
        mBranchname=static_cast<Branch::Employee>(sBranchChoice);
     
    }    
    void displayDetails(){
        cout<<"---------Intern Employee Details-----------\n";
        XyzInternEmloyee::displayDetails();
        cout<<"College Name     :"<<endl;
        cout<<"Branch Name      :"<<endl;
    }
    string getEmpType() override{
        return "Intern";
    }

};