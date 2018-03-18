#include "itg_iv.h"




int main()
{
    MySharedStruct str1(3);
    MySharedStruct str2(3);
    *(*(*str2.tab)) = (uint16_t)100;
    cout << *(*(*str1.tab)) << endl;
    cout << "vector ctor" << endl;
    MyStructList list;
    list.push_back(str1);
    list.push_back(str2);
    MySharedStruct str3 = list[0];
    MySharedStruct str4 = list[1];
    *(*(*str4.tab)) = (uint16_t)456;
    cout << "str3,tab: " << *(*(*str3.tab)) << endl;
    cout << "Regular ptr struct list\n";
    RegularPtrStruct reg1(string("reg1"));
    RegularPtrStruct reg2(string("reg2"));
    cout << "reg1.ptr: " << *reg1.ptr << endl;
    {
        RegularPtrList rpList;
        rpList.push_back(reg1);
        rpList.push_back(reg2);
        rpList[1].ptr = new uint16_t(100);
        cout << "reg1 value from vector: " << *rpList[0].ptr << endl;
    }
    cout << "reg1 value after vector destroyed: " << *reg1.ptr << endl;
    cout << "THE END\n";
    return 0;
}
