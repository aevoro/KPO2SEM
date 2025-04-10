#include "stdafx.h"
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
        NewDict.dictionary = new Entry[size];
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
#if (defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_DELENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) + defined(TEST_DICTIONARY) > 1 )
#error Превышенно количество макросов
#endif
    try {
#if defined(TEST_CREATE_01)
        Dictionary::Instance d1 = Dictionary::Create("ПреподавателиПреподавателиПреподавателиПреподаватели", 5);
#elif defined(TEST_CREATE_02) 
        Dictionary::Instance d1 = Dictionary::Create("Преподaватели", 10000);
#else 
        Dictionary::Instance d1 = Dictionary::Create("Преподaватели", 5);
#endif
        Dictionary::Entry e1 = { 1, "Гладкий" },
            e2 = { 2, "Веялкин" },
            e3 = { 3, "Смелов" },
            e4 = { 4, "Урбанович" },
#if defined(TEST_ADDENTRY_04) 
            e5 = { 2, "Пацей" };
#else 
            e5 = { 5, "Пацей" };
#endif
        AddEntry(d1, e1);
        AddEntry(d1, e2);
        AddEntry(d1, e3);
        AddEntry(d1, e4);
        AddEntry(d1, e5);
#if defined(TEST_ADDENTRY_03) 
        AddEntry(d1, e5);
#endif

#if defined(TEST_GETENTRY_05) 
        Dictionary::Entry ex2 = GetEntry(d1, 40);
#else
        Dictionary::Entry ex2 = GetEntry(d1, 4);
#endif
#if defined(TEST_DELENTRY_06)
        DelEntry(d1, 200);
#else
        DelEntry(d1, 2);
#endif
#if defined(TEST_UPDENTRY_08)
        Dictionary::Entry newentry1 = { 1, "Гурин" };
#else 
        Dictionary::Entry newentry1 = { 6, "Гурин" };
#endif
#if defined(TEST_UPDENTRY_07)
        UpdEntry(d1, 300, newentry1);
#else
        UpdEntry(d1, 3, newentry1);
#endif
        std::cout << "------Преподаватели------" << std::endl;
        Print(d1);

        Dictionary::Instance d2 = Dictionary::Create("Студенты", 5);
        Dictionary::Entry s1 = { 1, "Иванов" },
            s2 = { 2, "Петров" },
            s3 = { 3, "Сидоров" };
        AddEntry(d2, s1);
        AddEntry(d2, s2);
        AddEntry(d2, s3);

        Dictionary::Entry newentry3 = { 3, "Николаев" };
        UpdEntry(d2, 3, newentry3);
        std::cout << "------Студенты------" << std::endl;
        Print(d2);
        Delete(d1);
        Delete(d2);
    }
    catch (const char* e)
    {
        std::cout << e << std::endl;
    }
    system("pause");
}