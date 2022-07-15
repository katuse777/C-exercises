/* combinatorics.h
   ---------------
   this interface exports the permutations function
*/

#ifndef _combinatorics_h
#define _combinatorics_h

/*int permutations(int n,int k)
  -----------------------------
 *Takes in an integer n and integer k and returns the number possible ways you can choose k items
  from the set of elements in n. e.g) You want to know how many possible ways are there to pick 
  2 cards from a deck of 52 cards, permutations(52, 2) = 2652 
*/
int permutations(int n,int k);


#endif