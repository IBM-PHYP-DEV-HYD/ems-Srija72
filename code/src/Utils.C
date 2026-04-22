// To validate the input entered by user 
#include"Utils.H"

bool inputHandle(){
    if(cin.fail()){
        cout << "Invalid input, please enter valid input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    else if(cin.peek() != '\n' ){
        cout<<"Invalid input , extra characters detected "<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max() ,'\n');
        return false;
    }
    return true;
}