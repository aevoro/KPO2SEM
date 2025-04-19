#include "dictionary.h"

#include <iostream>

namespace Dictionary
{
    // declarations and structures into Dictionary.h
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