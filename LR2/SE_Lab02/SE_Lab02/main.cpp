//X= 9+n, Y= 10+n, Z= 11+n, S= 1.0+n,
#include <iostream>

void printdata() {
	std::cout << "Это функция" << std::endl;
}

int main() {
	bool bool1 = false;
	bool bool2 = true;

	char sym1 = 'a';
	char sym2 = 'а';

	wchar_t sym3 = 'Л';
	wchar_t sym4 = 'L';

	short short1 = 12; // hex = C
	short short2 = -12; // hex = -C

	short short3 = 0x7FFF; // 32767
	short short4 = -0x8000; // -32768

	unsigned short short5 = 0xFFFF; // 65535
	unsigned short short6 = 0x0; // 0

	int int1 = 23; // hex = 17
	int int2 = -23; // hex = -17

	int int3 = 0x7FFFFFFF; // 2147483647 
	int int4 = -0x7FFFFFFF; // 2147483648

	unsigned int int5 = 0xFFFFFFFF; // 4294967295
	unsigned int int6 = 0x0; // 0

	long long1 = 24; // hex = 18
	long long2 = -24; // hex = -18

	long long3 = 0x7FFFFFFFL; // 2147483647
	long long4 = -0x7FFFFFFFL; // 2147483648

	unsigned long long5 = 0xFFFFFFFF; // 4294967295
	unsigned long long6 = 0x0; // 0

	float float1 = 14.0f; // hex = E
	float float2 = -14.0f; // hex = -E

	double d1 = 1;
	double d2 = 0;
	double double1 = -d1 / 0;
	double double2 = d1 / 0;
	double double3 = d2 / 0;

	char* charptr = &sym1;
	wchar_t* wcharptr = &sym3;
	short* shortptr = &short1;
	int* intptr = &int1;
	float* floatptr = &float1;
	double* doubleptr = &double1;

	void (*funcptr)() = printdata;

	int& ref = int1;

	std::cout << sizeof(long);

}