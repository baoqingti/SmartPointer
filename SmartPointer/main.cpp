#include "SmartPointer_v1.h"
#include "SmartPointer_v2.h"
//���Դ���

//���Դ�����Ӧ�õ���
class SomeClass
{
public:
    SomeClass() {cout << "SomeClass default constructor" << endl;}
    ~SomeClass() {cout << "SomeClass destructor" << endl;}
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

int main()
{
    cout << "***************testcase1��*****************" << endl;
    testcase1();
    cout << "***************testcase2:******************" << endl;
    testcase2();

    return 0;
}
