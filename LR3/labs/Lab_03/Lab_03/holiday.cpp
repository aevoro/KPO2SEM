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
		{"Новый год", 1},
		{"Православное рождество", 7 },
		{"День женщин", 67},
		{"Радуница",119  },
		{"Праздник труда ",121},
		{"День победы", 129},
		{"День независимости РБ", 184},
		{"День октябрьской революции", 311},
		{"Католическое рождество", 359}
	};

	month mon[12]{
		{"Январь", 31, 1},
		{"Февраль", 28, 2},
		{"Март", 31, 3},
		{"Апрель", 30, 4},
		{"Май", 31, 5},
		{"Июнь", 30, 6},
		{"Июль", 31, 7},
		{"Август", 31, 8},
		{"Сентябрь", 30, 9},
		{"Октябрь", 31, 10},
		{"Ноябрь", 30, 11},
		{"Декабрь", 31, 12}
	};

	cout << endl;

	int year;

	cout << "Введите год: "; cin >> year;
	cout << "Введите порядковый номер дня в году: "; cin >> currentDayNum;				

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
        cout << "Событие произошедшее в день: " << day << " " << mon[i].nameMonth << " ";
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