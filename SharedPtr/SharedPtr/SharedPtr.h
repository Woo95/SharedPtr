#pragma once

template <typename T>
class CSharedPtr
{
public:
    CSharedPtr() :
        mPtr(nullptr)
    {
    }
    CSharedPtr(T* ptr) :
        mPtr(ptr)
    {
        mPtr->IncrementRef();
    }
    CSharedPtr(const CSharedPtr<T>& other) :
        mPtr(other.mPtr)
    {
        mPtr->IncrementRef();
    }

    ~CSharedPtr()
    {
        if (mPtr)
            mPtr->DecrementRef();
    }

private:
    T* mPtr;

public:
    void operator = (T* ptr)
    {
        if (mPtr)
            mPtr->DecrementRef();

        mPtr = ptr;

        if (mPtr)
            mPtr->IncrementRef();
    }
    void operator = (const CSharedPtr<T>& other)
    {
        if (mPtr)
            mPtr->DecrementRef();

        mPtr = other.mPtr;

        if (mPtr)
            mPtr->IncrementRef();
    }

    bool operator == (T* ptr) const
    {
        return mPtr == ptr;
    }
    bool operator == (const CSharedPtr<T>& other) const
    {
        return mPtr == other.mPtr;
    }

    bool operator != (T* ptr) const
    {
        return mPtr != ptr;
    }
    bool operator != (const CSharedPtr<T>& other) const
    {
        return mPtr != other.mPtr;
    }

    T* operator -> () const
    {
        return mPtr;
    }

    // conversion operator: Converts CSharedPtr<T> to T*
    operator T* () const
    {
        return mPtr;
    }
};