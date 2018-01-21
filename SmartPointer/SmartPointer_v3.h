#ifndef SMARTPOINTER_V3_H_INCLUDED
#define SMARTPOINTER_V3_H_INCLUDED
//�������ü���
//����ͷ�ļ�SmartPointer_v3.h

//���ü�������
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

        //����ָ��ָ����T�����ü�����1
        if (mPointer) mPointer->incRefCount();

    }

    //
    SmartPointer_v3(const SmartPointer_v3& other) :mPointer(other.mPointer)
    {
        cout << "copy construction at" << static_cast<const void*>(other.mPointer) << endl;
        //���ü�������1
        if (mPointer) mPointer->incRefCount();
    }

    //
    SmartPointer_v3& operator=(const SmartPointer_v3& other)
    {
        T* temp(other.mPointer);
        //��ָ��������ü�����1
        if (temp) temp->incRefCount();

        //�ж�ԭ���������
        if (mPointer && mPointer->decRefCount() == 0) delete mPointer;

        mPointer = temp;

        return *this;
    }

    ~SmartPointer_v3()
    {
        cout << "release smart pointer at" << static_cast<const void*>(mPointer) << endl;
        //ֻ�е�������Ϊ0ʱ��delete
        if (mPointer && mPointer->decRefCount() == 0) delete mPointer;
    }
private:
    T* mPointer;
};


#endif // SMARTPOINTER_V3_H_INCLUDED
