#include "SmartPointer_v1.h"
#include "SmartPointer_v2.h"
#include "SmartPointer_v3.h"
//测试代码

//测试v1,v2代码中应用的类
class SomeClass
{
public:
    SomeClass() {cout << "SomeClass default constructor" << endl;}
    ~SomeClass() {cout << "SomeClass destructor" << endl;}
};

//测试v3代码中应用的类
class SomeClass3: public RefBase
{
public:
    SomeClass3() {cout << "SomeClass3 default constructor" << endl;}

    ~SomeClass3() {cout << "SomeClass3 destructor" << endl;}
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

void testcase3()
{
    cout << "观察与testcase2的结果对比,引用计数使得pSomeClass3仅被销毁一次！"

    SomeClass3 *pSomeClass3 = new SomeClass3();
    cout << pSomeClass3->getRefCount() << endl; //此时输出0

    SmartPointer_v3<SomeClass3> spOuter = pSomeClass3;

    cout << "SomeClass3 Ref Count (" << pSomeClass3->getRefCount() << ") outer 1" << endl;

    {//语句块，可以理解为一个函数，里面所执行的都是形参。
        SmartPointer_v3<SomeClass3> spInner = spOuter;
        cout << "SomeClass Ref Count (" << pSomeClass3->getRefCount() << ") inner" << endl;
    }

    cout << "SomeClass Ref Count (" << pSomeClass3->getRefCount() << ") outer 2" << endl;

    cout << "new another SomeClass3 class for spOuter" << endl;
    SmartPointer_v3<SomeClass3> spOuter2 = new SomeClass3();
    spOuter = spOuter2;     //spOuter将会被释放

    //
}

int main()
{
    cout << "***************testcase1：*****************" << endl;
    testcase1();
    cout << "***************testcase2:******************" << endl;
    testcase2();
    cout << "***************testcase3:******************" << endl;
    testcase3();

    return 0;
}
