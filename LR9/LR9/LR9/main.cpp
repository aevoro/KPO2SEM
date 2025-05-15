#include <iostream>
#include "Varparm.h"
#include <cfloat>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    
    cout << "ivarparm:\n";
    cout << "1 ��������: " << Varparm::ivarparm(0) << endl;                  
    cout << "2 ���������: " << Varparm::ivarparm(1, 4) << endl;               
    cout << "3 ���������: " << Varparm::ivarparm(2, 6, 8) << endl;            
    cout << "7 ����������: " << Varparm::ivarparm(6, 2, 5, 3, 1, 6, 9) << endl; 

    
    cout << "\nsvarparm:\n";
    cout << "1 ��������: " << Varparm::svarparm(0) << endl;                   
    cout << "2 ���������: " << Varparm::svarparm(1, (short)4) << endl;        
    cout << "3 ���������: " << Varparm::svarparm(2, (short)6, (short)8) << endl; 
    cout << "7 ����������: " << Varparm::svarparm(6, (short)2, (short)5, (short)3, (short)1, (short)6, (short)9) << endl; 

    
    cout << "\nfvarparm:\n";
    cout << "1 ��������: " << Varparm::fvarparm(FLT_MAX) << endl;             
    cout << "2 ���������: " << Varparm::fvarparm(4.0f, FLT_MAX) << endl;      
    cout << "3 ���������: " << Varparm::fvarparm(6.0f, 8.0f, FLT_MAX) << endl; 
    cout << "7 ����������: " << Varparm::fvarparm(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, FLT_MAX) << endl;

    
    cout << "\ndvarparm:\n";
    cout << "1 ��������: " << Varparm::dvarparm(DBL_MAX) << endl;             
    cout << "2 ���������: " << Varparm::dvarparm(5.0, DBL_MAX) << endl;       
    cout << "3 ���������: " << Varparm::dvarparm(3.0, 4.0, DBL_MAX) << endl;  
    cout << "7 ����������: " << Varparm::dvarparm(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, DBL_MAX) << endl; 

    return 0;
}