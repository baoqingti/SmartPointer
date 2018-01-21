#include "SmartPointer_v1.h"

//测试代码

class SomeClass
{
public:
    SomeClass() {cout << "SomeClass default constructor" << endl;}
};

void testcase1()
{
    //创建一个不知所指的指针，使用智能指针的默认构造函数
    SmartPointer_v1<char> spunknown;
    //创建一个空的智能指针
    SmartPointer_v1<char> spnull = nullptr;
    //创建一个指向类的智能指针
    SmartPointer_v1<SomeClass> spclass = new SomeClass;
    //创建字符串智能指针
    //SmartPointer_v1<const char> spstr = "Hello World";
}

int main()
{
    cout << "***************testcase1：*****************" << endl;
    testcase1();

    return 0;
}
