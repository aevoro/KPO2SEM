#include "stdafx.h"
bool checkyear(int currentYear) {
	if (currentYear % 4 == 0) {
		if (currentYear % 100 == 0) {
			if (currentYear % 400 == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}