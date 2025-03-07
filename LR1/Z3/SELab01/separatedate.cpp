#include "stdafx.h"
void separatedate(int& currentDayNum, int *everymonth, int &currentYear, int &currentMonth) {
	setlocale(LC_ALL, "RU");
	string currentdate;
	int currentDay = 0;
	int currentDayOne = 0, currentMonthOne = 0;
	while (true) {
		cout << "Введите сегодняшнюю дату в формате ДДММГГГГ: ";
		cin >> currentdate;
	
	    if (size(currentdate) != 8) {
			
			cout << "Дата введена не корректно" << endl;
			exit(0);
		}
		currentDay = stoi(currentdate.substr(0, 2));
		currentMonth = stoi(currentdate.substr(2, 2));
		currentYear = stoi(currentdate.substr(4, 4));
		if (checkyear(currentYear)) {
			everymonth[1] = 29;
		}
		if (checkyear(currentYear)) {	
		}
		if (currentDay < 10) {
			currentDayOne = stoi(currentdate.substr(1, 1));
			currentDay = currentDayOne;
		}
		for (int i = 0; i < 12; i++) {
			if (currentDay >= 1 && currentDay <= everymonth[i]) {
				break;
			}
			else {
				cout << "Данные введены неккоректно" << endl;
				exit(0);
			}
		}
		if (currentMonth < 10) {
			currentMonthOne = stoi(currentdate.substr(3, 1));
			currentMonth = currentMonthOne;
		}
		if (currentMonth >= 1 && currentMonth <= 12) {

		}
		else {
			cout << "Данные введены неккоректно" << endl;
			exit(0);
		}
		break;
	}
	for (int i = 0; i < currentMonth - 1; ++i) {
		currentDayNum += everymonth[i];
	}
	currentDayNum += currentDay;
	cout << "Порядковый номер дня в этом году: " << currentDayNum << endl;
	if (checkyear(currentYear)) {
		cout << "Текущий год високосный" << endl;
	}
	else {
		cout << "Текущий год не високосный" << endl;
	}

}