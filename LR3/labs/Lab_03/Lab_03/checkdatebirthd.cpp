#include "Header.h"
void checkdatebirthd(int& month) {
	string checkMonth[12] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
	for (int i = 1; i <= 12; i++) {
		if (month == i) {
			cout << "Порядковый номер месяца в день рождения: " << month << endl << "Месяц: " << checkMonth[i-1] << endl;
		}
	}
}