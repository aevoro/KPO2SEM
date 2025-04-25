#include "call.h"
#include <iostream>

namespace Call {
    // cdecl: Аргументы передаются справа налево, стек очищается функцией вызывающей
    int _cdecl cdec(int a, int b, int c) {
        return a + b + c;
    }

    // stdcall: То же самое что и cdecl только стек очищается самой вызываемой функцией
    int _stdcall cstd(int& a, int b, int c) {
        return a * b * c;
    }

    // fastcall: Аргументы старается положить в регистры, для ускорения быстродействия(Отсюда и fast) стек очищает вызываемой
    int _fastcall cfst(int a, int b, int c, int d) {
        return a + b + c + d;
    }
}

int main() {
    int sum_cdecl = Call::cdec(1, 2, 3);
    std::cout << "cdecl result: " << sum_cdecl << std::endl << std::endl;

    int x = 2;
    int product_std = Call::cstd(x, 3, 4);
    std::cout << "stdcall result: " << product_std << std::endl;
    std::cout << "x after cstd: " << x << std::endl << std::endl;

    int sum_fastcall = Call::cfst(1, 2, 3, 4);
    std::cout << "fastcall result: " << sum_fastcall << std::endl;
}