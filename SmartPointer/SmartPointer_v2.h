#ifndef SMARTPOINTER_V2_H_INCLUDED
#define SMARTPOINTER_V2_H_INCLUDED

//���ӿ������캯���뿽����ֵ�����
//ͷ�ļ���Smartpointer_v2.h
#include<iostream>

using namespace std;

template<typename T>    //���ඨ��Ϊ��ģ��
class SmartPointer_v2
{
public:
    //Ĭ�Ϲ��캯��
    SmartPointer_v2() : mPointer(nullptr) {cout << "Create null smart pointer" << endl;}
    SmartPointer_v2(T *p) : mPointer(p)
    {
        cout << "Create smart pointer at" << static_cast<const void*>(p) << endl;
    }

    //�������캯��
    SmartPointer_v2(const SmartPointer_v2& other) : mPointer(other.mPointer)
    {
        cout << "Copy smart pointer at " << static_cast<const void*>(other.mPointer) << endl;

    }

    //������ֵ�����
    SmartPointer_v2& operator=(const SmartPointer_v2& other)
    {
        //�����Ը�ֵ����
        if (this == &other) return *this;
        if (mPointer) delete mPointer;      //�����delete
        mPointer = other.mPointer;
        cout << "Assign smart pointer at" << static_cast<const void*>(other.mPointer) << endl;

        return *this;
    }


    ~SmartPointer_v2() {
        cout << "Release smart pointer at " << static_cast<const void*>(mPointer) << endl;
        if (mPointer) delete mPointer;

    }

private:
    T* mPointer;
};

#endif // SMARTPOINTER_V2_H_INCLUDED
