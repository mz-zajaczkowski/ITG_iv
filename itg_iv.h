#ifndef ITG_IV_H
#define ITG_IV_H

#include <iostream>
using namespace std;
#include <vector>
#include <memory>

struct MySharedStruct {

    shared_ptr<unsigned short*> tab[2];

    MySharedStruct(size_t size) {
        cout << "ctor\n";
        tab[0] = make_shared<unsigned short*>(new unsigned short[size]);
        tab[1] = make_shared<unsigned short*>(new unsigned short[size]);
        for (size_t i = 0; i < size; ++i)
        {
            *(*tab[1] + i) = 0u;
            *(*tab[0] + i) = 0u;
        }
    }

    ~MySharedStruct() {
        cout << "DTor\n";
        cout << "tab[0].use_count: " << (*tab).use_count() << endl;
        cout << "tab[1].use_count: " << (*(tab+1)).use_count() << endl;
    }
};
typedef std::vector<MySharedStruct> MyStructList;

struct RegularPtrStruct
{
    uint16_t * ptr;
    string name;

    RegularPtrStruct(string name)
        : ptr(new uint16_t(0))
        , name(name)
    {cout << "Regular CTor: " << name << "\n";}

    ~RegularPtrStruct()
    {
        cout << "Regular DTor: " << name << "\n";
        delete ptr;
    }
};

typedef std::vector<RegularPtrStruct> RegularPtrList;

#endif // ITG_IV_H
