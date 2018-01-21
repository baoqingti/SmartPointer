#include "SmartPointer_v1.h"
#include "SmartPointer_v2.h"
#include "SmartPointer_v3.h"
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
    cout << "�۲���testcase2�Ľ���Ա�,���ü���ʹ��pSomeClass3��������һ�Σ�"

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

int main()
{
    cout << "***************testcase1��*****************" << endl;
    testcase1();
    cout << "***************testcase2:******************" << endl;
    testcase2();
    cout << "***************testcase3:******************" << endl;
    testcase3();

    return 0;
}
