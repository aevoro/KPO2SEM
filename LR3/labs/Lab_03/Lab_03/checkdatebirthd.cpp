#include "Header.h"
void checkdatebirthd(int& month) {
	string checkMonth[12] = { "������", "�������", "����", "������", "���", "����", "����", "������", "��������", "�������", "������", "�������" };
	for (int i = 1; i <= 12; i++) {
		if (month == i) {
			cout << "���������� ����� ������ � ���� ��������: " << month << endl << "�����: " << checkMonth[i-1] << endl;
		}
	}
}