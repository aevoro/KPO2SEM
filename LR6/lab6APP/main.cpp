#include <iostream>
#include "D:\prog\���\lab6\lab6\dictionary.h"

int main() {
    setlocale(LC_ALL, "RU");
    try
    {
        Dictionary::Instance d1 = Dictionary::Create("�������������", 100);
        Dictionary::Entry e1 = { 1, "�������" }, e2 = { 2, "�������" }, e3 = { 3, "������" },
            e4 = { 4, "���������" }, e5 = { 5, "�����" };
        Dictionary::AddEntry(d1, e1);
        Dictionary::AddEntry(d1, e2);
        Dictionary::AddEntry(d1, e3);
        Dictionary::AddEntry(d1, e4);
        Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 4);
        Dictionary::DelEntry(d1, 2);
        Dictionary::Entry newentry1 = { 6, "�����" };
        Dictionary::UpdEntry(d1, 3, newentry1);
        std::cout << "----" << d1.name << "----" << std::endl;
        Dictionary::Print(d1);

        Dictionary::Instance d2 = Dictionary::Create("��������", 5);
        Dictionary::Entry s1 = { 1, "������" }, s2 = { 2, "������" }, s3 = { 3, "�������" };
        Dictionary::AddEntry(d2, s1);
        Dictionary::AddEntry(d2, s2);
        Dictionary::AddEntry(d2, s3);
        Dictionary::Entry newentry3 = { 3, "��������" };
        Dictionary::UpdEntry(d2, 3, newentry3);
        std::cout << "----" << d2.name << "----" << std::endl;
        Dictionary::Print(d2);
        Dictionary::Delete(d1);
        Dictionary::Delete(d2);
    }
    catch (const char* e)
    {
        std::cout << e << std::endl;
    }
    system("pause");
    return 0;
}