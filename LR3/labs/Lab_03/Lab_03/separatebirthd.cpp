#include "Header.h"
void separatedatebirthd(int& dayNum, int* everymonth, int& year, int& day, int& month) {
	setlocale(LC_ALL, "RU");
	int dayone = 0; int monthone = 0;
	int x = 0;
	string date;
	do {
		cout << "������� ���� �������� � ������� ��������: ";
		cin >> date;
		if (size(date) != 8) {
			cout << "���� ������� �� ���������" << endl;
			exit(0);
		}
		year = stoi(date.substr(4, 4));
		day = stoi(date.substr(0, 2));
		month = stoi(date.substr(2, 2));

		if (checkyearbirthd(year)) {
			int everymonth[1] = { 29 };
		}
		else {
			if (day == 29) {
				cout << "������ ������� �����������. " << endl;
				exit(0);
			}
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
				cout << "������ ������� �����������" << endl;
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
			cout << "������ ������� �����������" << endl;
			exit(0);
		}
		break;
	} while (true);
	for (int i = 0; i < month - 1; ++i) {
		dayNum += everymonth[i];
	}
	dayNum += day;
	cout << "���������� ����� ��� � ��� ��������: " << dayNum << endl;
	if (checkyearbirthd(year)) {
		cout << "��� �������� ����������" << endl;
	}
	else {
		cout << "��� �������� �� ����������" << endl;
	}
	checkdatebirthd(month);
}
