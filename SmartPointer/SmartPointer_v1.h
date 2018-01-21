#ifndef SMARTPOINTER_V1_H_INCLUDED
#define SMARTPOINTER_V1_H_INCLUDED

//头文件 SmartPointer_v1

#include<iostream>
using namespace std;

//定义智能指针类
template <typename T>   //将智能指针类定义为模板类
class SmartPointer_v1
{
public:
    //构造函数
    //默认构造函数
    SmartPointer_v1() : mPointer(nullptr) {cout << "create unknown smart pointer" << endl;}
    //可以指向任何类型的构造函数
    SmartPointer_v1(T *p) : mPointer(p)
    {
        cout << "create smart pointer at " << static_cast<const void*>(p) << endl;
    }

    //析构函数
    ~SmartPointer_v1() {
        cout << "release smart pointer at " << static_cast<const void*>(mPointer) << endl;
        //实现内存资源自动销毁机制
        if (mPointer) delete mPointer;
    }
private:
    void *mPointer;     //指向智能指针实际对象的资源对象
};

#endif // SMARTPOINTER_V1_H_INCLUDED
