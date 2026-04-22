#ifndef ENUMS_H
#define ENUMS_H

//enum for Sub Menu
namespace SubMenu{
    enum Operations{
        Add=1,
        Remove,
        Get,
        Other,
    };
}
namespace AddMenu{
    enum Operations{
        Add = 1,
        Random = 2,
    };
}
namespace RemoveMenu{
    enum Operations{
        Remove =1,
        Random,
    };
}
namespace GetDetails{
    enum Operations{
        All=1,
        Type,
        Status,
        Gender,
        Display,
    };
}
namespace Others{
    enum Operations{
        Leaves =1,
        Convert,
        SeachById,
        SearchByname,
        Assignment,
    };
}

//Employee enums 
namespace Gender{
    enum Employee{
        Male=1,
        Female,
        Others,
    };
}
namespace EmpStatus{
    enum Employee{
        Active=1,
        Inactive,
        Resigned,
    };
}
namespace AssignmentStatus{
    enum Employee{
        In_Progress=1,
        Completed,
    };
}

//interns details
namespace College{
    enum Employee{
        IIT_Delhi=1,
        IT_Mumbai,
        IIT_Kanpur,
        IIT_Hyderabad,
        NIT_Warangal,
        NIT_Tiruchi,
        IIIT_Hyderabad,
    };
}
namespace Branch{
    enum Employee{
        CSE,
        CSIT,
        ECE,
    };
}
//Contractor Agency 
namespace Agency{
    enum Employee{
        Avengers=1,
        Justice_League,
        X_Men,
    };
}
#endif