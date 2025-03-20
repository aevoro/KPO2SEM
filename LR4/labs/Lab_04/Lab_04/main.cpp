#include <iostream>
#include <Tchar.h>
#include <complex>
using namespace std;

typedef int Integer;
typedef double Real;
typedef complex<double> Complex;

enum numberType
{

INTEGER,
REAL,
COMPLEX
	
};

struct number {
	numberType type; 

	union {
		Integer intNum;
		Real realNum;
		Complex complexNum;
	};

	number(Integer value) : type(INTEGER), intNum(value){}
	number(Real value) : type(REAL), realNum(value){}
	number(Complex value) : type(COMPLEX), complexNum(value){}

	number operator+(const number& other) const {

		if (type != other.type) {
			cout << "������ ���������� ����� ������ �����." << endl;
		}

		switch (type)
		{
		case INTEGER: {
			return number(intNum + other.intNum);
		}

		case REAL: {
			return number(realNum + other.realNum);
		}

		case COMPLEX: {
			return number(complexNum + other.complexNum);
		}
		
		default: {
			throw invalid_argument("����������� ��� ������.");
		}
		}
	}

	number operator* (const number& other) const {

		if (type != other.type) {
			cout << "������ �������� ����� ������ �����." << endl;
		}

		switch (type) 
		{
		case INTEGER: {
			return number(intNum * other.intNum);
		}

		case REAL: {
			return number(realNum * other.realNum);
		}

		case COMPLEX: {
			return number(complexNum * other.complexNum);
		}

		default: {
			throw invalid_argument("����������� ��� ������.");
		}
		}
	}

	void print() const {
		switch (type) {
		case INTEGER:
			cout << "����� �����: " << intNum << endl;
			break;
		case REAL:
			cout << "�������������� �����: " << realNum << endl;
			break;
		case COMPLEX:
			cout << "����������� �����: " << complexNum << endl;
			break;
		default:
			cout << "����������� ��� �����" << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "RU");

	number intnum(9);
	number realnum(5.6);
	number complexnum(complex<double>(3, 2));
	
	number sum = intnum + number(10);
	sum.print();

	number multiplication = realnum * number(4.3);
	multiplication.print();

	number complexSum = complexnum + number(complex<double>(2, 3));
	complexSum.print();

	return 0;
}