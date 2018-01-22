#include "SmartPointer_v1.h"
#include "SmartPointer_v2.h"
#include "SmartPointer_v3.h"
#include "SmartPointer_v4.h"
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

//测试v4代码中应用的类
class SomeClass4: public RefBase
{
public:
    SomeClass4() {cout << "SomeClass4 default constructor" << endl;}
    ~SomeClass4() {cout << "SomeClass4 destructor" << endl;}

    void func() {cout << "func() function" << endl;}
};

class OtherClass4:public RefBase
{
public:
    OtherClass4() {cout << "OtherClass4 default constructor" << endl;}
    ~OtherClass4() {cout << "OtherClass4 destructor" << endl;}

    void foo() {cout << "foo() function" << endl;}
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
    cout << "观察与testcase2的结果对比,引用计数使得pSomeClass3仅被销毁一次！" << endl;

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


//测试解引用运算符函数
void testcase4_1()
{
    SmartPointer_v4<SomeClass4> spcomeclass4 = new SomeClass4();
    //测试解引用运算符
    (*spcomeclass4).func();
    spcomeclass4->func();
    cout << endl;
}

//测试有效性与判空
void testcase4_2()
{
    SomeClass4 *psomeclass4 = new SomeClass4();
    SmartPointer_v4<SomeClass4> spsomeclass4 = psomeclass4;     //

    SmartPointer_v4<OtherClass4> spotherclass4_1 = new OtherClass4();
    SmartPointer_v4<OtherClass4> spotherclass4_2 = spotherclass4_1;

    if (spsomeclass4 == nullptr) cout << "spsomeclass4 is nullpter" << endl;
    if (spotherclass4_1 != nullptr) cout << "spotherclass4_1 is not nullptr" << endl;

    if (spsomeclass4 == psomeclass4)    //普通指针与智能指针
        cout << "spsomeclass4 and psomeclass4 are same pointer" << endl;
    if (spsomeclass4 != psomeclass4)
        cout << "spsomeclass4 and psomeclass are not same pointer" << endl;

    if (spotherclass4_1 == spotherclass4_2)     //智能指针与智能指针
        cout << "spotherclass4_1 and spotherclass4_2 are same pointer" << endl;
    if (spotherclass4_1 != spotherclass4_2)
        cout << "spotherclass4_1 and spotherclass4_2 are not same pointer" << endl;

}

int main()
{
    cout << "***************testcase1：*****************" << endl;
    testcase1();
    cout << "***************testcase2:******************" << endl;
    testcase2();
    cout << "***************testcase3:******************" << endl;
    testcase3();

    cout << endl;
    cout << "***************testcase4_1:*****************" << endl;
    testcase4_1();

    cout << "***************testcase4_2:******************" << endl;
    testcase4_2();

    return 0;
}
