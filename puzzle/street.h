#ifndef STREET_H
#define STREET_H
#include "house.h"

class street_
{
    void IfThen(ATYPE IfN,eATT Ifv,ATYPE ThenN,eATT Thenv);
    int houseWithSingleAtt(ATYPE n,eATT v);
    void houseWithSingleNotAttDel(ATYPE n,eATT v,eATT d); // find single att that is not v
    void SetAtt(int h,ATYPE n,eATT v);
public:
    street_();public:
    house_ house[5];
    int houseWithSingleAtt(eATT v);
    void RemAtt(int h,eATT v);
    void SetAtt(int h,eATT v);
    void IfThen(eATT Ifv,eATT Thenv);
    void ThisNextToThat(eATT This,eATT That);
    void print();
};

#endif // STREET_H
