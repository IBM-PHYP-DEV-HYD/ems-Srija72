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
bool isNameValid(string nameParm){
    for (int i = 0; i < nameParm.length(); i++) {
        if (nameParm[i]>='A' && nameParm[i]<='Z')
            continue;
        if (nameParm[i]>='a' && nameParm[i]<='z')
            continue;
        if (nameParm[i]==' ')
            continue;
        return false;
    }
    return true;
}
bool isDateValid(string DoJParm){
    if (DoJParm.length() != 10)
        return false;
    if (DoJParm[2] != '/' || DoJParm[5] != '/')
        return false;
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5)
            continue;
        if (DoJParm[i] < '0' || DoJParm[i] > '9')
            return false;
    }
    int sDay =
        (DoJParm[0]-'0')*10 + (DoJParm[1]-'0');

    int sMonth =
        (DoJParm[3]-'0')*10 + (DoJParm[4]-'0');

    int sYear =
        (DoJParm[6]-'0')*1000 +
        (DoJParm[7]-'0')*100 +
        (DoJParm[8]-'0')*10 +
        (DoJParm[9]-'0');
    if (sYear >= 2027)
        return false;

    if (sMonth < 1 || sMonth > 12)
        return false;

    int sDays[] = {31,28,31,30,31,30,31,31,30,31,30,31 };

    if (sYear%4==0|| sYear%400==0)
        sDays[1] = 29;
    if (sDay < 1 || sDay > sDays[sMonth-1])
        return false;
    return true;
}

int getYear(string yearParm){
    return (yearParm[6]-'0')*1000+(yearParm[7]-'0')*100+(yearParm[8]-'0')*10+(yearParm[9]-'0');
}

int getRandomNumber(int startNumParm,
                    int endNumParm)
{
    std::random_device sRandomDevice;
    std::mt19937 sRandomNumberGenerator(sRandomDevice());
    std::uniform_int_distribution<int> sGenerate(startNumParm, endNumParm);
    int sRandomNumber = sGenerate(sRandomNumberGenerator);
    return sRandomNumber;
}
string generateRandomName() {
    string firstNames[] = {"Aarav", "Vivaan", "Aditya", "Vihaan", "Arjun",
                          "Sai", "Arnav", "Ayaan", "Krishna", "Ishaan",
                          "Ananya", "Diya", "Aadhya", "Saanvi", "Kiara",
                          "Anika", "Navya", "Angel", "Pari", "Sara"};
    
    string lastNames[] = {"Sharma", "Verma", "Patel", "Kumar", "Singh",
                         "Reddy", "Gupta", "Joshi", "Nair", "Iyer",
                         "Mehta", "Desai", "Rao", "Pillai", "Menon"};
    
    int firstNameIndex = getRandomNumber(0, 19);
    int lastNameIndex = getRandomNumber(0, 14);
    
    return firstNames[firstNameIndex] + " " + lastNames[lastNameIndex];
}
string generateRandomDate(int minYear, int maxYear) {
    int year = getRandomNumber(minYear, maxYear);
    int month = getRandomNumber(1, 12);
    
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29;
    }
    
    int day = getRandomNumber(1, daysInMonth[month - 1]);
    
    string dayStr = (day < 10 ? "0" : "") + to_string(day);
    string monthStr = (month < 10 ? "0" : "") + to_string(month);
        
    return dayStr + "/" + monthStr + "/" + to_string(year);
}



   
       
