#include "Header.h"
void findnextbirthd(int& currentDayNum, int& dayNum, int* everymonth, int& year, int& currentYear, int& month, int& day, int& currentMonth) {
	separatedatebirthd(dayNum, everymonth, year, day, month);
	separatedate(currentDayNum, everymonth, currentYear, currentMonth);
	if (currentYear < year) {
		cout << "Ошибка ввода года рождения." << endl;
		exit(0);
	}
	int a = 0;
	int difference = 0;
	int noLeapYear = 365;
	int leapYear = 366;
	if (!checkyear(currentYear) and !checkyearbirthd(year)) {
		if (currentDayNum > day) {
			difference = dayNum - currentDayNum;
			cout << "До следующего дня рождения осталось: " << difference << " дней" << endl;
		}
		else {
			difference = noLeapYear + dayNum - currentDayNum;
			cout << "До следующего дня рождения осталось: " << difference << " дней" << endl;
		}
	}
	else if (checkyearbirthd(year)) {
		if (day == 29 && month == 2) {
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
				cout << "До следующего дня рождения осталось: " << abs(difference) << " дней" << endl;

			}
			else {
				if (currentDayNum > dayNum) {
					a = 1;
				}
				difference = a * noLeapYear + dayNum - currentDayNum;
				cout << "До следующего дня рождения осталось: " << abs(difference) << " дней" << endl;

			}
		}
		else {
			if (currentDayNum < day) {
				difference = dayNum - currentDayNum;
				cout << "До следующего дня рождения осталось: " << abs(difference) << endl;
			}
			else {
				difference = noLeapYear - dayNum - currentDayNum;
				cout << "До следующего дня рождения осталось: " << abs(difference) << " дней" << endl;
			}
		}
	}
	else if (checkyear(currentYear)) {
		if (currentDayNum > day) {
			difference = dayNum - currentDayNum;
			cout << "До следующего дня рождения осталось: " << abs(difference) << endl;
		}
		else {
			difference = noLeapYear - dayNum - currentDayNum;
			cout << "До следующего дня рождения осталось: " << abs(difference) << " дней" << endl;
		}
	}
}

