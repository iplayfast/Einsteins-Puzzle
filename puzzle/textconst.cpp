#include "textconst.h"
const char *tNation[5] = {"Brit,","Swede,","Dane,","Norwegian,","German"};
const char *tDrink[5] = {"Tea,","Coffee,","Water,","Beer,","Milk"};
const char *tColour[5]= {"Red,","Green,","White,","Yellow,","Blue"};
const char *tSmoke[5] = {"Pall,","Dunhill,","Blend,","Blue Master,","Prince"};
const char *tPet[5] = {"Dog,","Bird,","Horse,","Fish,","Cat"};
const char *tCat[5] = {"House,","Nation,","Drink,","Colour,","Smoke"};

ATYPE FindAType(eATT v)
{
    switch(v) {
    case BRIT:
    case SWEDE:
    case DANE:
    case NORWEGIAN:
    case GERMAN: return N;
    case TEA:
    case COFFEE:
    case WATER:
    case BEER:
    case MILK: return D;
    case RED:
    case GREEN:
    case WHITE:
    case YELLOW:
    case BLUE: return C;
    case DOG:
    case BIRD:
    case HORSE:
    case FISH:
    case CAT: return P;
    case PALL:
    case DUNHILL:
    case BLEND:
    case BMASTER:
    case PRINCE: return S;
    case NOTHING: break; // should never get here
    }
    return S;
}

const char *FindAttText(eATT v)
{
    switch (v) {
    case BRIT: 	return tNation[0];
    case SWEDE: return tNation[1];
    case DANE: 	return tNation[2];
    case NORWEGIAN:	return tNation[3];
    case GERMAN: 	return tNation[4];
    case TEA: 	return tDrink[0];
    case COFFEE: return tDrink[1];
    case WATER: return tDrink[2];
    case BEER: return tDrink[3];
    case MILK:  return tDrink[4];
    case RED:	return tColour[0];
    case GREEN:	return tColour[1];
    case WHITE:	return tColour[2];
    case YELLOW:	return tColour[3];
    case BLUE: 	return tColour[4];
    case DOG:	return tPet[0];
    case BIRD:	return tPet[1];
    case HORSE:	return tPet[2];
    case FISH:	return tPet[3];
    case CAT: 	return tPet[4];
    case PALL: 	return tSmoke[0];
    case DUNHILL: 	return tSmoke[1];
    case BLEND: 	return tSmoke[2];
    case BMASTER: 	return tSmoke[3];
    case PRINCE:  	return tSmoke[4];
    case NOTHING: return "";
    }
    return "";
}
