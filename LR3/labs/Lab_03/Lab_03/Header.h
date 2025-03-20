#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
using namespace std;

bool checkyear(int currentYear);
bool checkyearbirthd(int year);
void separatedatebirthd(int& dayNum, int* everymonth, int& year, int& day, int& month);
void separatedate(int& currentDayNum, int* everymonth, int& currentYear, int& currentMonth);
void findnextbirthd(int& currentDayNum, int& dayNum, int* everymonth, int& currentYear, int& year, int& month, int& day, int& currentMonth);
void checkdate(int &currentMonth);
void checkdatebirthd(int& month);
void holiday();