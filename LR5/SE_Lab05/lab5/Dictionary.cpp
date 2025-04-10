#include "Dictionary.h"
#include <iostream>

namespace Dictionary
{
  
    Instance Create(const char* name, int size)
    {
        if (strlen(name) > DICTNAMEMAXSIZE) {
            throw THROW01;
        }
        if (size > DICTMAXSIZE) {
            throw THROW02;
        }
        Instance NewDict;
        strcpy_s(NewDict.name, name);
        NewDict.maxsize = size;
        NewDict.size = 0;
        NewDict.dictionary = new Entry[size]; //память из кучи
        return NewDict;
    }

    void AddEntry(Instance& inst, Entry ed)
    {
        if (inst.size >= inst.maxsize) {
            throw THROW03;
        }
        for (int i = 0; i < inst.size; i++) {
            if (inst.dictionary[i].id == ed.id) {
                throw THROW04;
            }
        }
        inst.dictionary[inst.size] = ed;
        inst.size++;
    }

    void DelEntry(Instance& inst, int id)
    {
        bool found = false;
        for (int i = 0; i < inst.size; i++) {
            if (inst.dictionary[i].id == id) {
                found = true;
                for (int j = i; j < inst.size - 1; j++) {
                    inst.dictionary[j] = inst.dictionary[j + 1];
                }
                inst.size--;
                break;
            }
        }
        if (!found) {
            throw THROW06;
        }
    }

    void UpdEntry(Instance& inst, int id, Entry new_ed)
    {
        bool found = false;
        for (int i = 0; i < inst.size; i++) {
            if (inst.dictionary[i].id == id) {
                for (int j = 0; j < inst.size; j++) {
                    if (j != i && inst.dictionary[j].id == new_ed.id) {
                        throw THROW08;
                    }
                }
                found = true;
                inst.dictionary[i] = new_ed;
                break;
            }
        }
        if (!found) {
            throw THROW07;
        }
    }

    Entry GetEntry(Instance& inst, int id)
    {
        for (int i = 0; i < inst.size; i++) {
            if (inst.dictionary[i].id == id) {
                return inst.dictionary[i];
            }
        }
        throw THROW05;
    }

    void Print(Instance& d)
    {
        for (int i = 0; i < d.size; i++) {
            std::cout << d.dictionary[i].id << " " << d.dictionary[i].name << std::endl;
        }
    }

    void Delete(Instance& d)
    {
        delete[] d.dictionary;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    try
    {
        Dictionary::Instance d1 = Dictionary::Create("Преподаватели", 100);
        Dictionary::Entry e1 = { 1, "Гладкий" }, e2 = { 2, "Веялкин" }, e3 = { 3, "Смелов" },
            e4 = { 4, "Урбанович" }, e5 = { 5, "Пацей" };
        Dictionary::AddEntry(d1, e1);
        Dictionary::AddEntry(d1, e2);
        Dictionary::AddEntry(d1, e3);
        Dictionary::AddEntry(d1, e4);
        Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 4);
        Dictionary::DelEntry(d1, 2);
        Dictionary::Entry newentry1 = { 6, "Гурин" };
        Dictionary::UpdEntry(d1, 3, newentry1);
        std::cout << "----" << d1.name << "----" << std::endl;
        Dictionary::Print(d1);

        Dictionary::Instance d2 = Dictionary::Create("Студенты", 5);
        Dictionary::Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" }, s3 = { 3, "Сидоров" };
        Dictionary::AddEntry(d2, s1);
        Dictionary::AddEntry(d2, s2);
        Dictionary::AddEntry(d2, s3);
        Dictionary::Entry newentry3 = { 3, "Николаев" };
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
