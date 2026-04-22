#ifndef EMSMenu_H
#define EMSMenu_H

#include"EmpManager.H"

class EMSMenu {
public:
    void mainMenu();
    void handleUserChoice(int parmChoice);
    void displayAddmenu();
    void displayRemovemenu();
    void displayGetDetailsMenu();
    void displayOtherMenu();

};

#endif