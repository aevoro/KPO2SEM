#include "Header.h"
#include <vector>

struct holidays{
	string holiday;
	int numHoliday;
};

struct month {
	string nameMonth;
	int numDay;
	int numMonth;
};

void holiday() {

	int currentDayNum = 0;
	
	holidays hol[9]{
		{"����� ���", 1},
		{"������������ ���������", 7 },
		{"���� ������", 67},
		{"��������",119  },
		{"�������� ����� ",121},
		{"���� ������", 129},
		{"���� ������������� ��", 184},
		{"���� ����������� ���������", 311},
		{"������������ ���������", 359}
	};

	month mon[12]{
		{"������", 31, 1},
		{"�������", 28, 2},
		{"����", 31, 3},
		{"������", 30, 4},
		{"���", 31, 5},
		{"����", 30, 6},
		{"����", 31, 7},
		{"������", 31, 8},
		{"��������", 30, 9},
		{"�������", 31, 10},
		{"������", 30, 11},
		{"�������", 31, 12}
	};

	cout << endl;

	int year;

	cout << "������� ���: "; cin >> year;
	cout << "������� ���������� ����� ��� � ����: "; cin >> currentDayNum;				

	int sumMon = 0;
	int day = 0;
	bool a = false;

	if (checkyear(year)) {
		if(currentDayNum>59)
		currentDayNum -= 1;
	}

	for (int i = 0; i < 12; i++) {
    if (sumMon < currentDayNum) {
        sumMon += mon[i].numDay;
    }
    if (sumMon > currentDayNum) {
        day = mon[i].numDay - (sumMon - currentDayNum);
        sumMon = sumMon - (sumMon - currentDayNum);
        cout << "������� ������������ � ����: " << day << " " << mon[i].nameMonth << " ";
        for (int j = 0; j < 9; j++) {
            if (sumMon == hol[j].numHoliday) {
                cout << hol[j].holiday;
                a = true;
                break;
            }
        }
    }
		if (a) {
			break;
		}
	}
}