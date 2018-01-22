#ifndef SMARTPOINTER_V4_H_INCLUDED
#define SMARTPOINTER_V4_H_INCLUDED

//计数基类
class RefBase
{
public:
    RefBase() = default;

    void incRefCount(){
        ++count;
    }

    int decRefCount() {
        return --count;
    }

    int getRefCount() {
        return count;
    }

    virtual ~RefBase() {}
private:
    int count = 0;
};

//增加解引用运算符,以及有效与判空即if(sp), if(!sp), if(sp==nullptr)
//头文件SmartPointer_v4.h
template<typename T>
class SmartPointer_v4
{
public:
    SmartPointer_v4() :mPointer(nullptr) {cout << "Create null smart pointer" << endl;}
    SmartPointer_v4(T* p) :mPointer(p)
    {
        cout << "Create smart pointer at" << static_cast<const void*>(p) << endl;
        if (mPointer) mPointer->incRefCount();
    }

    SmartPointer_v4(const SmartPointer_v4& other) :mPointer(other.mPointer)
    {
        cout << "Copy smart pointer at" << static_cast<const void*>(other.mPointer) << endl;
        if (mPointer) mPointer->incRefCount();
    }

    SmartPointer_v4& operator=(const SmartPointer_v4& other)
    {
        T* temp(other.mPointer);
        if (temp) temp->incRefCount();
        if (mPointer && mPointer->decRefCount() == 0) delete mPointer;

        mPointer = temp;

        return *this;
    }

    //重载运算符*
    T& operator*() const {return *mPointer;};

    //重载运算符->
    T* operator->() const {return mPointer;};


    //增加有效判断与判空判断,通过重载运算符==与!=实现
    //重载==
    //与普通指针的版本
    bool operator==(const T* other) const {
        return mPointer == o;
    }
    //与智能指针的版本
    bool operator==(const SmartPointer_v4& other) const {
        return mPointer == other.mPointer;
    }

    //重载!=
    //与普通指针的版本
    bool operator!=(const T* other) const {
        return mPointer != other;
    }
    //与智能指针的版本
    bool operator!=(const SmartPointer_v4& other) const {
        return mPointer != other.mPointer;
    }


    ~SmartPointer_v4()
    {
        cout << "Release smart pointer at" << static_cast<const void*>(mPointer) << endl;
        if (mPointer && mPointer->decRefCount() == 0) delete mPointer;
    }

private:
    T* mPointer;
};
#endif // SMARTPOINTER_V4_H_INCLUDED
