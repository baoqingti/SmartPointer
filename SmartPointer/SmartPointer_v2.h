#ifndef SMARTPOINTER_V2_H_INCLUDED
#define SMARTPOINTER_V2_H_INCLUDED

//增加拷贝构造函数与拷贝赋值运算符
//头文件：Smartpointer_v2.h
#include<iostream>

using namespace std;

template<typename T>    //将类定义为类模板
class SmartPointer_v2
{
public:
    //默认构造函数
    SmartPointer_v2() : mPointer(nullptr) {cout << "Create null smart pointer" << endl;}
    SmartPointer_v2(T *p) : mPointer(p)
    {
        cout << "Create smart pointer at" << static_cast<const void*>(p) << endl;
    }

    //拷贝构造函数
    SmartPointer_v2(const SmartPointer_v2& other) : mPointer(other.mPointer)
    {
        cout << "Copy smart pointer at " << static_cast<const void*>(other.mPointer) << endl;

    }

    //拷贝赋值运算符
    SmartPointer_v2& operator=(const SmartPointer_v2& other)
    {
        //处理自赋值问题
        if (this == &other) return *this;
        if (mPointer) delete mPointer;      //将左侧delete
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
