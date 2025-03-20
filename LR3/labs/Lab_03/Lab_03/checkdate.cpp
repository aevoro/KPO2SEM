#include "Header.h"
void checkdate(int &currentMonth) {
	string checkMonth[12] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
	for (int i = 1; i <= 12; i++) {
		if (currentMonth == i) {
			cout << "Порядковый номер текущего месяца: " << currentMonth << endl << "Месяц: " << checkMonth[i-1] << endl;
		}
	}
}