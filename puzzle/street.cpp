#include <stdio.h>
#include "street.h"
#include "textconst.h"

street_::street_()
{

}

int street_::houseWithSingleAtt(eATT v)
{
    return houseWithSingleAtt(FindAType(v),v);
}

void street_::RemAtt(int h, eATT v)
{
   house[h].RemoveAttribute(v);
   int found=-1;
   for(int i=0;i<5;i++)	{
       if (house[i].HasAttribute(v))	{
           if (found!=-1)  return;  // at least two have this attribute
            else found = i;
       }
   }
   this->SetAtt(found,v);

}


void street_::SetAtt(int h, eATT v)
{
   ATYPE t = FindAType(v);
   SetAtt(h,t,v);
}
int street_::houseWithSingleAtt(ATYPE n,eATT v)
{
    for(int i=0;i<5;i++)
        if (house[i].HasSingleAttribute(n,v)) return i;
    return -1;
}

void street_::houseWithSingleNotAttDel(ATYPE n,eATT v,eATT d) // find single att that is not v
{
    for(int i=0;i<5;i++){
        eATT test = house[i].HasSingleTYPE(n);
        if (test!=v && test!=NOTHING){
            house[i].RemoveAttribute(d);
            ATYPE t = FindAType(d);
            eATT a =house[i].HasSingleTYPE(t);
            if (a!=NOTHING)
                this->SetAtt(i,a); // clear out any others
        }
    }

}

void street_::SetAtt(int h, ATYPE n, eATT v) {
    if (h>-1){
        for(int i=0;i<5;i++)	{
            if (i!=h)
                house[i].RemoveAttribute(v);
        }
        house[h].SetAttribute(n,v);
    }
}

void street_::IfThen(ATYPE IfN, eATT Ifv, ATYPE ThenN,eATT Thenv) {
    SetAtt(houseWithSingleAtt(IfN,Ifv),ThenN,Thenv);
    houseWithSingleNotAttDel(IfN,Ifv,Thenv);
}

void street_::IfThen(eATT Ifv, eATT Thenv)
{
   ATYPE IfN = FindAType(Ifv);
   ATYPE ThenN = FindAType(Thenv);
   IfThen(IfN,Ifv,ThenN,Thenv);
   IfThen(ThenN,Thenv,IfN,Ifv);
}

void street_::ThisNextToThat(eATT This, eATT That)
{
   int iThis = houseWithSingleAtt(This);
   int iThat = houseWithSingleAtt(That);
   if (iThis>-1) {
            for(int i=0;i<5;i++)
                if (i+1==iThis || i-1==iThis) continue;
                else house[i].RemoveAttribute(That);
            if (iThis==0)
                this->SetAtt(1,That);
            if (iThis==4)
                SetAtt(3,That);
        }

   if (iThat>-1) {
            for(int i=0;i<5;i++)
                if (i+1==iThat || i-1==iThat) continue;
                else house[i].RemoveAttribute(This);
            if (iThat==0)
                this->SetAtt(1,This);
            if (iThat==4)
                SetAtt(3,This);
        }
}

void street_::print()
{
   for(int i=0;i<5;i++){
        printf("\nHouse #%d",i);
       house[i].print();
   }
}
