#ifndef SMARTPOINTER_V1_H_INCLUDED
#define SMARTPOINTER_V1_H_INCLUDED

//ͷ�ļ� SmartPointer_v1

#include<iostream>
using namespace std;

//��������ָ����
template <typename T>   //������ָ���ඨ��Ϊģ����
class SmartPointer_v1
{
public:
    //���캯��
    //Ĭ�Ϲ��캯��
    SmartPointer_v1() : mPointer(nullptr) {cout << "create unknown smart pointer" << endl;}
    //����ָ���κ����͵Ĺ��캯��
    SmartPointer_v1(T *p) : mPointer(p)
    {
        cout << "create smart pointer at " << static_cast<const void*>(p) << endl;
    }

    //��������
    ~SmartPointer_v1() {
        cout << "release smart pointer at " << static_cast<const void*>(mPointer) << endl;
        //ʵ���ڴ���Դ�Զ����ٻ���
        if (mPointer) delete mPointer;
    }
private:
    void *mPointer;     //ָ������ָ��ʵ�ʶ������Դ����
};

#endif // SMARTPOINTER_V1_H_INCLUDED
