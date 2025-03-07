#include "stdafx.h"
int separatedatebirthd(int& dayNum, int* everymonth, int& year, int &day, int& month) {
	setlocale(LC_ALL, "RU");
	int dayone = 0; int monthone = 0;
	int x = 0;
	string date;
	 do {
		cout << "Введите дату рождения в формате ДДММГГГГ: ";	
		cin >> date;
		if (size(date) != 8) {
			cout << "Дата введена не корректно" << endl;
			exit(0);
		}
		year = stoi(date.substr(4, 4));
		day = stoi(date.substr(0, 2));
		month = stoi(date.substr(2, 2));

		if (checkyearbirthd(year)) {
			int everymonth[1] = { 29 };
		}
		if (day < 10) {
			dayone = stoi(date.substr(1, 1));
			day = dayone;
		}
		for (int i = 0; i < 12; i++) {
			if (day >= 1 && day <= everymonth[i]) {
				break;
			}
			else {
				cout << "Данные введены неккоректно" << endl;
				exit(0);
			}
			
		}
		if (month < 10) {
			monthone = stoi(date.substr(3, 1));
			month = monthone;
		}
		if (month >= 1 && month <= 12) {

		}
		else {
			cout << "Данные введены неккоректно" << endl;
			exit(0);
		}	
		break;
	}
 while (true);
	for (int i = 0; i < month - 1; ++i) {
		dayNum += everymonth[i];
	}
	dayNum += day;
	cout << "Порядковый номер дня в год рождения: " << dayNum << endl;
	if (checkyearbirthd(year)) {
		cout << "Год рождения високосный" << endl;
	}
	else {
		cout << "Год рождения не високосный" << endl;
	}
	return x;
}
