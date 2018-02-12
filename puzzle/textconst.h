#ifndef TEXTCONST_H
#define TEXTCONST_H
enum eATT {BRIT,SWEDE,DANE,NORWEGIAN,GERMAN,
         TEA,COFFEE,WATER,BEER,MILK,
            RED,GREEN,WHITE,YELLOW,BLUE,
            DOG,BIRD,HORSE,FISH,CAT,
     PALL,DUNHILL,BLEND,BMASTER,PRINCE,NOTHING };
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
