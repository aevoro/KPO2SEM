#include "Varparm.h"
#include <cstdarg>
#include <climits>
#include <cfloat>

namespace Varparm {

    int ivarparm(int count, ...) {
        if (count <= 0) return 0;
        va_list args;
        va_start(args, count);
        int product = 1;
        for (int i = 0; i < count; ++i) {
            product *= va_arg(args, int);
        }
        va_end(args);
        return product;
    }

    int svarparm(short count, ...) {
        if (count <= 0) return 0;
        va_list args;
        va_start(args, count);
        int max_val = INT_MIN;
        for (short i = 0; i < count; ++i) {
            int num = va_arg(args, int);
            if (num > max_val) max_val = num;
        }
        va_end(args);
        return max_val;
    }

    double fvarparm(float first, ...) {
        va_list args;
        va_start(args, first);
        double sum = 0.0;
        double current = first;
        while (current != static_cast<double>(FLT_MAX)) {
            sum += current;
            current = va_arg(args, double);
        }
        va_end(args);
        return sum;
    }

    double dvarparm(double first, ...) {
        va_list args;
        va_start(args, first);
        double sum = 0.0;
        double current = first;
        while (current != DBL_MAX) {
            sum += current;
            current = va_arg(args, double);
        }
        va_end(args);
        return sum;
    }

} 