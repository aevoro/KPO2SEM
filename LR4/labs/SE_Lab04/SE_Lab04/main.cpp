#include <iostream>
#include <Tchar.h>
using namespace std;
typedef unsigned char day;
typedef unsigned char month;
typedef unsigned char year;
struct date
{
	day dd;
	month mm;
	year yyyy;
	
	bool operator<(const date& other) const {
		if (yyyy != other.yyyy) return yyyy < other.yyyy;
		if (mm != other.mm) return mm < other.mm;
		return dd < other.dd;
	}

	bool operator>(const date& other) const {
		if (yyyy != other.yyyy) return yyyy > other.yyyy;
		if (mm != other.mm) return mm > other.mm;
		return dd > other.dd;
	}

	bool operator==(const date& other) const {
		return yyyy == other.yyyy && mm == other.mm && dd == other.dd;
	}
};
int _tmain(int argc, _TCHAR* argv[]) {

	setlocale(LC_ALL, "RU");
	
	date date1 = { 7,1 ,1980 };
	date date2 = { 7,2,1993 };
	date date3 = { 7,1, 1980 };
	
	if (date1 < date2) {
		cout << "Истина" << endl;
	}
	else {
		cout << "Ложь" << endl;
	}
	
	if (date1 > date2) {
		cout << "Истина" << endl;
	}
	else {
		cout << "Ложь" << endl;
	}
	
	if (date1 == date2) {
		cout << "Истина" << endl;
	}
	else {
		cout << "Ложь" << endl;
	}
	
	if (date1 == date3) {
		cout << "Истина" << endl;
	}
	else {
		cout << "Ложь" << endl;
	}
}
