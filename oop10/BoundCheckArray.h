#ifndef __BOUNDCHECKARRAY_H__
#define __BOUNDCHECKARRAY_H__

#include "Account.h"
#include "BankingCommonDecl.h"

template <class T>
class BoundCheckArray{
    private:
        T *arr;
        int arrlen;
        BoundCheckArray(const BoundCheckArray &arr);
        BoundCheckArray& operator=(const BoundCheckArray &arr);
    public:
        BoundCheckArray(int len=100);
        T &operator[](int idx);
        T operator[](int idx) const;
        int GetArrLen() const;
        ~BoundCheckArray();
};
#endif