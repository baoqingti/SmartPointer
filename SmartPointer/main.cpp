#include "SmartPointer_v1.h"
#include "SmartPointer_v2.h"
#include "SmartPointer_v3.h"
#include "SmartPointer_v4.h"
//���Դ���

//����v1,v2������Ӧ�õ���
class SomeClass
{
public:
    SomeClass() {cout << "SomeClass default constructor" << endl;}
    ~SomeClass() {cout << "SomeClass destructor" << endl;}
};

//����v3������Ӧ�õ���
class SomeClass3: public RefBase
{
public:
    SomeClass3() {cout << "SomeClass3 default constructor" << endl;}

    ~SomeClass3() {cout << "SomeClass3 destructor" << endl;}
};

//����v4������Ӧ�õ���
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
    //����һ����֪��ָ��ָ�룬ʹ������ָ���Ĭ�Ϲ��캯��
    SmartPointer_v1<char> spunknown;
    //����һ���յ�����ָ��
    SmartPointer_v1<char> spnull = nullptr;
    //����һ��ָ���������ָ��
    SmartPointer_v1<SomeClass> spclass = new SomeClass;
    //�����ַ�������ָ��
    SmartPointer_v1<const char> spstr = "Hello World";
}

void testcase2()
{
    //
    SmartPointer_v2<SomeClass> spclass1 = new SomeClass;
    cout << endl;

    spclass1 = spclass1;    //�����Ը�ֵ����
    cout << endl;

    //
    SmartPointer_v2<SomeClass> spclassother(spclass1);

    cout << endl;

    SmartPointer_v2<SomeClass> spclass2 = new SomeClass;
    cout << endl;
    cout << "������ֵ�����" << endl;
    spclass2 = spclass1;    //���Կ�����ֵ�����
    cout << endl;
}

void testcase3()
{
    cout << "�۲���testcase2�Ľ���Ա�,���ü���ʹ��pSomeClass3��������һ�Σ�" << endl;

    SomeClass3 *pSomeClass3 = new SomeClass3();
    cout << pSomeClass3->getRefCount() << endl; //��ʱ���0

    SmartPointer_v3<SomeClass3> spOuter = pSomeClass3;

    cout << "SomeClass3 Ref Count (" << pSomeClass3->getRefCount() << ") outer 1" << endl;

    {//���飬�������Ϊһ��������������ִ�еĶ����βΡ�
        SmartPointer_v3<SomeClass3> spInner = spOuter;
        cout << "SomeClass Ref Count (" << pSomeClass3->getRefCount() << ") inner" << endl;
    }

    cout << "SomeClass Ref Count (" << pSomeClass3->getRefCount() << ") outer 2" << endl;

    cout << "new another SomeClass3 class for spOuter" << endl;
    SmartPointer_v3<SomeClass3> spOuter2 = new SomeClass3();
    spOuter = spOuter2;     //spOuter���ᱻ�ͷ�

    //
}


//���Խ��������������
void testcase4_1()
{
    SmartPointer_v4<SomeClass4> spcomeclass4 = new SomeClass4();
    //���Խ����������
    (*spcomeclass4).func();
    spcomeclass4->func();
    cout << endl;
}

//������Ч�����п�
void testcase4_2()
{
    SomeClass4 *psomeclass4 = new SomeClass4();
    SmartPointer_v4<SomeClass4> spsomeclass4 = psomeclass4;     //

    SmartPointer_v4<OtherClass4> spotherclass4_1 = new OtherClass4();
    SmartPointer_v4<OtherClass4> spotherclass4_2 = spotherclass4_1;

    if (spsomeclass4 == nullptr) cout << "spsomeclass4 is nullpter" << endl;
    if (spotherclass4_1 != nullptr) cout << "spotherclass4_1 is not nullptr" << endl;

    if (spsomeclass4 == psomeclass4)    //��ָͨ��������ָ��
        cout << "spsomeclass4 and psomeclass4 are same pointer" << endl;
    if (spsomeclass4 != psomeclass4)
        cout << "spsomeclass4 and psomeclass are not same pointer" << endl;

    if (spotherclass4_1 == spotherclass4_2)     //����ָ��������ָ��
        cout << "spotherclass4_1 and spotherclass4_2 are same pointer" << endl;
    if (spotherclass4_1 != spotherclass4_2)
        cout << "spotherclass4_1 and spotherclass4_2 are not same pointer" << endl;

}

int main()
{
    cout << "***************testcase1��*****************" << endl;
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
