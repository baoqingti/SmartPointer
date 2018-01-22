#ifndef SMARTPOINTER_V4_H_INCLUDED
#define SMARTPOINTER_V4_H_INCLUDED

//��������
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

//���ӽ����������,�Լ���Ч���пռ�if(sp), if(!sp), if(sp==nullptr)
//ͷ�ļ�SmartPointer_v4.h
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

    //���������*
    T& operator*() const {return *mPointer;};

    //���������->
    T* operator->() const {return mPointer;};


    //������Ч�ж����п��ж�,ͨ�����������==��!=ʵ��
    //����==
    //����ָͨ��İ汾
    bool operator==(const T* other) const {
        return mPointer == o;
    }
    //������ָ��İ汾
    bool operator==(const SmartPointer_v4& other) const {
        return mPointer == other.mPointer;
    }

    //����!=
    //����ָͨ��İ汾
    bool operator!=(const T* other) const {
        return mPointer != other;
    }
    //������ָ��İ汾
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
