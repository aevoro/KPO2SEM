#include "Header.h"
void checkdate(int &currentMonth) {
	string checkMonth[12] = {"������", "�������", "����", "������", "���", "����", "����", "������", "��������", "�������", "������", "�������"};
	for (int i = 1; i <= 12; i++) {
		if (currentMonth == i) {
			cout << "���������� ����� �������� ������: " << currentMonth << endl << "�����: " << checkMonth[i-1] << endl;
		}
	}
}