#ifndef SMARTPOINTER_V3_H_INCLUDED
#define SMARTPOINTER_V3_H_INCLUDED
//增加引用计数
//定义头文件SmartPointer_v3.h

//引用计数基类
class RefBase
{
public:
    RefBase() = default;

    void incRefCount()
    {
        mCount++;
    }

    int decRefCount()
    {
        return --mCount;
    }

    int getRefCount()
    {
        return mCount;
    }

    virtual ~RefBase() {}

private:
    int mCount = 0;
} ;

template<typename T>
class SmartPointer_v3
{
public:
    SmartPointer_v3() :mPointer(nullptr) {cout << "Create null smart pointer" << endl;}
    SmartPointer_v3(T *p) :mPointer(p)
    {
        cout << "Create smart pointer at" << static_cast<const void*>(p) << endl;

        //智能指针指向类T，引用计数加1
        if (mPointer) mPointer->incRefCount();

    }

    //
    SmartPointer_v3(const SmartPointer_v3& other) :mPointer(other.mPointer)
    {
        cout << "copy construction at" << static_cast<const void*>(other.mPointer) << endl;
        //引用计数器加1
        if (mPointer) mPointer->incRefCount();
    }

    //
    SmartPointer_v3& operator=(const SmartPointer_v3& other)
    {
        T* temp(other.mPointer);
        //新指向对象，引用计数加1
        if (temp) temp->incRefCount();

        //判断原对象计数器
        if (mPointer && mPointer->decRefCount() == 0) delete mPointer;

        mPointer = temp;

        return *this;
    }

    ~SmartPointer_v3()
    {
        cout << "release smart pointer at" << static_cast<const void*>(mPointer) << endl;
        //只有当计数器为0时才delete
        if (mPointer && mPointer->decRefCount() == 0) delete mPointer;
    }
private:
    T* mPointer;
};


#endif // SMARTPOINTER_V3_H_INCLUDED
