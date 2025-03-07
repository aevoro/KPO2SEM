#include "stdafx.h"
void findnextbirthd(int& currentDayNum, int& dayNum, int* everymonth, int& year, int& currentYear, int &month, int &day, int &currentMonth) {
	separatedatebirthd(dayNum, everymonth, year, day, month);
	separatedate(currentDayNum, everymonth, currentYear, currentMonth);
	int a = 0;
	int difference = 0;
	int noLeapYear = 365;
	int leapYear = 366;
	if (!checkyear(currentYear) && !checkyearbirthd(year)) {
		difference = dayNum - currentDayNum;
		cout << "ƒо следующего дн€ рождени€ осталось: " << difference << " дней" << endl;
	}
	else if (checkyearbirthd(year)) {
		if (day == 29 && month == 2 && month < currentMonth) {
			while (true) {
				if (currentYear % 4 != 0) {
					currentYear++;
					a++;
				}
				else {
					break;
				}
			}
				if (currentYear == year) {
					difference = 4 * noLeapYear + dayNum - currentDayNum;
					cout << "ƒо следующего дн€ рождени€ осталось: " << difference << " дней" << endl;
					
				}
				else{ 
					difference = a * noLeapYear + dayNum - currentDayNum;
					cout << "ƒо следующего дн€ рождени€ осталось: " << difference << " дней" << endl;
					
				}
		}
		else {
			difference = dayNum - currentDayNum;
			cout << "ƒо следующего дн€ рождени€ осталось: " << difference << " дней" << endl;
		}
	}
	else if (checkyear(currentYear)) {
		difference = noLeapYear + currentDayNum - dayNum;
		cout << "ƒо следующего дн€ рождени€ осталось: " << difference << endl;
	}
}
	

