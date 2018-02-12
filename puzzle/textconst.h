#ifndef TEXTCONST_H
#define TEXTCONST_H

extern const char *tHouse[5];
enum eATT {BRIT,SWEDE,DANE,NORWEGIAN,GERMAN,
         TEA,COFFEE,WATER,BEER,MILK,
            RED,GREEN,WHITE,YELLOW,BLUE,
            DOG,BIRD,HORSE,FISH,CAT,
     PALL,DUNHILL,BLEND,BMASTER,PRINCE,NOTHING };

enum eATTtYPE { HOUSE,NATION,DRINK,COLOUR,PET,SMOKE,TYPEERROR} ;
enum eHOUSE {HOUSE1,HOUSE2,HOUSE3,HOUSE4,HOUSE5};
struct ALLPossibles {
        eATT P[25];
};
struct Five_ {
    eATT NAT[5];
    eATT DRINK[5];
    eATT COLOUR[5];
    eATT PET[5];
    eATT SMOKE[5];
};
enum ATYPE {N=0,D,C,P,S};
ATYPE FindAType(eATT v);
const char *FindAttText(eATT v);
    union U {
        eATT All[25];
        struct Five_ Five;
    };
extern const char *tNation[5];
extern const char *tDrink[5];
extern const char *tColour[5];
extern const char *tSmoke[5];
extern const char *tPet[5];
extern const char *tCat[5];
#endif // TEXTCONST_H
