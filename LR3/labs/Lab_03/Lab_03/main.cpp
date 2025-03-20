#include "Header.h"
int main() {
	setlocale(LC_ALL, "RU");
	int year = 0; int currentYear = 0; int day = 0; int currentMonth = 0;
	int dayNum = 0; int currentDayNum = 0; int month = 0;
	int everymonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//findnextbirthd(dayNum, currentDayNum, everymonth, year, currentYear, day, month, currentMonth);
	holiday();
	return 0;
}
