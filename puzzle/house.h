#ifndef HOUSE_H
#define HOUSE_H
#include "textconst.h"

class house_
{
public:
    union U Attributes;
    house_();
    void SetAttribute(ATYPE n,eATT v);
    void SetAttribute(eATT v);
    bool HasSingleAttribute(ATYPE n,eATT v);
    eATT HasSingleTYPE(ATYPE n);
    bool HasAttribute(eATT v);
    bool RemoveAttribute(eATT v);
    eATT *SelectIntoFive(ATYPE n);
    void print();
};

#endif // HOUSE_H
