#ifndef XyzEnums_H
#define XyzEnums_H

// Menu Related Enums 
namespace Menu{
    enum Options{
        Add=1,
        Remove,
        Get,
        Other,
    };
    enum AddMenu{
        AddManually = 1,
        Random = 2,
    };
    enum RemoveMenu{
        RemoveById =1,
    };
    enum GetDetails{
        All=1,
        Type,
        Status,
    };
    enum Others{
        Leaves =1,
        Convert,
        SeachById,
        SearchByname,
        Assignment,
        Total,
    };
};

//Employee enums 
namespace Employee{
    enum EmployeeType{
        Full_Time = 1,
        Intern,
        Contractor,
    };
    enum Gender{
        Male=1,
        Female,
        Others,
    };
    enum EmpStatus{
        Active=1,
        Inactive,
        Resigned,
    };

    enum AssignmentStatus{
        In_Progress=1,
        Completed,
    };
// Intern Details 
    enum College{
        IIT_Delhi=1,
        IT_Mumbai,
        IIT_Kanpur,
        IIT_Hyderabad,
        NIT_Warangal,
        NIT_Tiruchi,
        IIIT_Hyderabad,
    };

    enum Branch{
        CSE=1,
        CSIT,
        ECE,
    };
// Contractor Agency 
    enum Agency{
        Avengers=1,
        Justice_League,
        X_Men,
    };
// Functions to convert to string
    inline string toStringEmployeeType(EmployeeType typeParm){
        switch(typeParm){
            case Full_Time: return "Full Time";
            case Intern: return "Intern";
            case Contractor: return "Contractor";
            default:return "Unknown EmployeeType";

        }
    }
    inline string toStringGender(Gender genderParm){
        switch(genderParm){
            case Male: return "Male";
            case Female: return "Female";
            case Others: return "Others";
            default:return "Unknown Gender";

        }
    }
    inline string toStringAssignmentStatus(AssignmentStatus statusParm){
        switch(statusParm){
            case In_Progress: return "In_Progress";
            case Completed: return "Completed";
            default:return "Unknown Assignment Status";

        }
    }
    inline string toStringEmpStatus(EmpStatus empStatusParm){
        switch(empStatusParm){
            case Active: return "Active";
            case Inactive: return "Inactive";
            case Resigned: return "Resigned";
            default: return "Unknown Assignment Status";

        }
    }
    inline string toStringCollege(College collegeParm){
        switch(collegeParm){
            case IIT_Delhi: return "IIT_Delhi";
            case IT_Mumbai: return "IT_Mumbai";
            case IIT_Kanpur: return "IIT_Kanpur";
            case IIT_Hyderabad: return "IIT_Hyderabad";
            case NIT_Warangal: return "NIT_Warangal";
            case NIT_Tiruchi: return "NIT_Tiruchi";
            case IIIT_Hyderabad: return "IIIT_Hyderabad";
            default: return "Unknown College";

        }
    }
    inline string toStringBranch(Branch branchParm){
        switch(branchParm){
            case CSE: return "CSE";
            case CSIT: return "CSIT";
            case ECE: return "ECE";
            default: return "Unknown Branch";

        }
    }
    inline string toStringAgency(Agency agencyParm){
        switch(agencyParm){
            case Avengers: return "Avengers";
            case Justice_League: return "Justice_League";
            case X_Men: return "X_Men";
            default:return "Unknown Agency";
        }
    }

//Functions to convert from int 
    inline Employee::EmployeeType EmployeeTypeFromInt(int choiceParm){
        switch(choiceParm){
            case 1: return Full_Time;
            case 2: return Intern;
            case 3: return Contractor;
            default: return Full_Time;
        }
    }
    inline Employee::Gender GenderFromInt(int choiceParm){
        switch(choiceParm){
            case 1: return Male;
            case 2: return Female;
            case 3: return Others;
            default: return Others;
        }
    }
    inline Employee::AssignmentStatus AssignmentStatusFromint(int choiceParm){
        switch(choiceParm){
            case 1: return In_Progress;
            case 2: return Completed;
            default:return In_Progress;
        }
    }
    inline Employee::EmpStatus EmpStatusFromint(int choiceParm){
        switch(choiceParm){
            case 1: return Active;
            case 2: return Inactive;
            case 3: return Resigned;
            default: return Active;
        }
    }
    inline Employee::College CollegeFromint(int choiceParm){
        switch(choiceParm){
            case 1: return IIT_Delhi;
            case 2: return IT_Mumbai;
            case 3: return IIT_Kanpur;
            case 4: return IIT_Hyderabad;
            case 5: return NIT_Warangal;
            case 6: return NIT_Tiruchi;
            case 7: return IIIT_Hyderabad;
            default: return IIT_Hyderabad;

        }
    }
    inline Employee::Branch BranchFromint(int choiceParm){
        switch(choiceParm){
            case 1: return CSE;
            case 2: return CSIT;
            case 3: return ECE;
            default:return ECE;
        }
    }
    inline Employee::Agency AgencyFromint(int choiceParm){
        switch(choiceParm){
            case 1: return Avengers;
            case 2: return Justice_League;
            case 3: return X_Men;
            default:return Avengers;
        }
    }
};

#endif