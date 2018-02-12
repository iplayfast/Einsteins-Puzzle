#include <stdio.h>
#include <stdarg.h>
#include <textconst.h>
#include "house.h"
#include "street.h"

/***

Einstein's Puzzle
Variations of this riddle appear on the net from time to time.
It is sometimes attributed to Albert Einstein and it is claimed that 98%
of the people are incapable of solving it. Some commentators suggest that
Einstein created such puzzles not to test out intelligence but to get rid
of all the students who wanted him as an advisor. It is not likely that
there is any truth to these stories. Whereever this comes from, it is a nice riddle.

Let us assume that there are five houses of different colors next to each other on
the same road. In each house lives a man of a different nationality. Every man has
his favorite drink, his favorite brand of cigarettes, and keeps pets of a particular kind.

The Brit lives in the red house
The Swede keeps dogs as pets
The Dane drinks tea
The green house is on the left of the white house
The green homeowner drinks coffee
The person who smokes Pall Mall rears birds
The owner of the yellow house smokes Dunhill
The man living in the center house drinks milk
The Norwegian lives in the first house
The man who smokes Blend lives next to the one who keeps cats
The man who keeps the horse lives next to the man who smokes Dunhill
The owner who smokes Blue Master drinks beer
The German smokes Prince
The Norwegian lives next to the blue house
The man who smokes Blend has a neighbor who drinks water
The Question:
Who has a fish for a pet?
*/
void SetAttributes(street_ &street)
{
//The Brit lives in the red house
    street.IfThen(BRIT,RED);
//The Swede keeps dogs as pets
    street.IfThen(DOG,SWEDE);
//The Dane drinks tea
        street.IfThen(DANE,TEA);
//   The green house is on the left of the white house
        street.house[0].RemoveAttribute(WHITE);
        street.house[4].RemoveAttribute(GREEN);
        int whiteHouse = street.houseWithSingleAtt(WHITE);
        int greenHouse = street.houseWithSingleAtt(GREEN);
        if (whiteHouse!=-1) street.SetAtt(whiteHouse-1,GREEN);
        if (greenHouse!=-1) street.SetAtt(greenHouse+1,WHITE);
        whiteHouse = street.houseWithSingleAtt(WHITE);
        greenHouse = street.houseWithSingleAtt(GREEN);
        if (whiteHouse==-1 && greenHouse==-1) {
            for(int i=0;i<4;i++)
             if (street.house[i].HasSingleTYPE(C)!=NOTHING) { 	// house has single colour that is not green or white
                    street.RemAtt(i+1,WHITE);		// next one cannot be WHITE
                 eATT r = street.house[i+1].HasSingleTYPE(C); // if next is now a single colour
                 if (r!=NOTHING)
                     street.SetAtt(i+1,r); // clear out any others with that colour

             }
            for(int i=1;i<5;i++)
             if (street.house[i].HasSingleTYPE(C)!=NOTHING)	{// house has single colour that is not green or white
                 street.RemAtt(i-1,GREEN);		// previous one cannot be GREEN
                 eATT r = street.house[i-1].HasSingleTYPE(C); // if prev is now a single colour
                 if (r!=NOTHING)
                     street.SetAtt(i-1,r); // clear out any others with that colour
             }
        }

       //The green homeowner drinks coffee
        street.IfThen(GREEN,COFFEE);
//The person who smokes Pall Mall rears birds
        street.IfThen(PALL,BIRD);
//The owner of the yellow house smokes Dunhill
        street.IfThen(YELLOW,DUNHILL);
//The man living in the center house drinks milk
        street.SetAtt(2,MILK);
//The Norwegian lives in the first house
        street.SetAtt(0,NORWEGIAN);
//The man who smokes Blend lives next to the one who keeps cats
        street.ThisNextToThat(BLEND,CAT);
//The man who keeps the horse lives next to the man who smokes Dunhill
        street.ThisNextToThat(HORSE,DUNHILL);
//The owner who smokes Blue Master drinks beer
        street.IfThen(BMASTER,BEER);
//The German smokes Prince
        street.IfThen(GERMAN,PRINCE);
//The Norwegian lives next to the blue house
        street.ThisNextToThat(NORWEGIAN,BLUE);
//The man who smokes Blend has a neighbor who drinks water
        street.ThisNextToThat(BLEND,WATER);
//The Question:
//Who has a fish for a pet?
}

int main()
{
    street_ street;
    while(true)	{
        SetAttributes(street);

        int fishHouse = street.houseWithSingleAtt(FISH);
        if (fishHouse>-1)	{
            street.print();
            printf("\n\nfish is in house %d (numbered from 0)\n",fishHouse);
            return 0;
        }
    }

}

