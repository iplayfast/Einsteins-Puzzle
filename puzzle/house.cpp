#include <stdio.h>

#include "house.h"

house_::house_()
{
    for(int i=0;i<25;i++)
        Attributes.All[i] = static_cast<eATT>(i);
}

eATT * house_::SelectIntoFive(ATYPE n)
{
    eATT *p = Attributes.Five.NAT;
    switch(n) {
    case N: p = Attributes.Five.NAT; break;
    case D: p= Attributes.Five.DRINK; break;
    case C: p= Attributes.Five.COLOUR; break;
    case P: p = Attributes.Five.PET; break;
    case S: p = Attributes.Five.SMOKE; break;
    }
    return p;
}

void house_::print()
{

    for(int i=0;i<25;i++) {
            if (i % 5==0) printf("\n    ");
            printf("%s",FindAttText(Attributes.All[i]));
    }
}

void house_::SetAttribute(ATYPE n, eATT v)
{
    eATT *p =  SelectIntoFive(n);
    *p++ = v;
    *p++ = NOTHING;
    *p++ = NOTHING;
    *p++ = NOTHING;
    *p++ = NOTHING;
}

void house_::SetAttribute(eATT v)
{
   SetAttribute(FindAType(v),v);
}

bool house_::HasSingleAttribute(ATYPE n, eATT v)
{
    eATT *p =  SelectIntoFive(n);
    int cmatch=0;
    int nmatch=0;
    for(int i=0;i<5;i++) {
        if (*p==v) cmatch++;
        if (*p==NOTHING) nmatch++;
        p++;
    }
    return (cmatch==1 && nmatch==4);
}

eATT house_::HasSingleTYPE(ATYPE n)
{
    eATT *p =  SelectIntoFive(n);
    eATT Return = NOTHING;
    int cmatch=0;
    int nmatch=0;
    for(int i=0;i<5;i++) {
        if (*p !=NOTHING) { Return = *p; cmatch++;}
        if (*p==NOTHING) nmatch++;
        p++;
    }
    if (cmatch==1 && nmatch==4)
        return Return;
    else return NOTHING;
}

bool house_::HasAttribute(eATT v)
{
    for(int i=0;i<25;i++) {
        if (Attributes.All[i]==v) return true;
    }
    return false;
}

bool house_::RemoveAttribute(eATT v)
{
  for(int i=0;i<25;i++)
      if (Attributes.All[i]==v)
          Attributes.All[i]=NOTHING;
}
