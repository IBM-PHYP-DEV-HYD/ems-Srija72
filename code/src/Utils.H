#ifndef UTILS_H
#define UTILS_H

#include <random>
#include <set>
#include <iostream>
using namespace std;

bool inputHandle();
bool isNameValid(string nameParm);
bool isDateValid(string DoJParm);
int getYear(string yearParm);
int getRandomNumber(int startNumParm,
                    int endNumParm);

#endif