#include "SmartPointer_v1.h"

//���Դ���

class SomeClass
{
public:
    SomeClass() {cout << "SomeClass default constructor" << endl;}
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
    //SmartPointer_v1<const char> spstr = "Hello World";
}

int main()
{
    cout << "***************testcase1��*****************" << endl;
    testcase1();

    return 0;
}
