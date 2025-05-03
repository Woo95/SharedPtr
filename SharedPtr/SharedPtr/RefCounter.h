#pragma once

class CRefCounter abstract
{
    template <typename T>
    friend class CSharedPtr;

protected:
    CRefCounter() = default;
    virtual ~CRefCounter() = default;

private:
    int mRefCount = 0;

public:
    int GetRefCount() const { return mRefCount; }

private:
    void IncrementRef()
    {
        mRefCount++;
    }
    void DecrementRef()
    {
        mRefCount--;

        if (mRefCount == 0)
            delete this;
    }
};