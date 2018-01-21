#include "SmartPointer_v1.h"
#include "SmartPointer_v2.h"
//测试代码

//测试代码中应用的类
class SomeClass
{
public:
    SomeClass() {cout << "SomeClass default constructor" << endl;}
    ~SomeClass() {cout << "SomeClass destructor" << endl;}
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
    SmartPointer_v1<const char> spstr = "Hello World";
}

void testcase2()
{
    //
    SmartPointer_v2<SomeClass> spclass1 = new SomeClass;
    cout << endl;

    spclass1 = spclass1;    //测试自赋值问题
    cout << endl;

    //
    SmartPointer_v2<SomeClass> spclassother(spclass1);

    cout << endl;

    SmartPointer_v2<SomeClass> spclass2 = new SomeClass;
    cout << endl;
    cout << "拷贝赋值运算符" << endl;
    spclass2 = spclass1;    //测试拷贝赋值运算符
    cout << endl;
}

int main()
{
    cout << "***************testcase1：*****************" << endl;
    testcase1();
    cout << "***************testcase2:******************" << endl;
    testcase2();

    return 0;
}
