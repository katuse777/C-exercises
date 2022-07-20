/*Write a program that reads in words
  and prints out their score in Scrabble, not counting any of the other bonuses
  that occur in the game. You should ignore any characters other than uppercase
  letters in computing the score. In particular, lowercase letters are assumed to
  represent blank tiles, which can stand for any letter but have a score of 0.
  In
Scrabble™, the points are allocated as follows:
Points Letters
1   A, E, I, L, N, O, R, S, T, U
2   D, G
3   B, C, M, P
4   F, H, V, W, Y
5   K
8   J, X
10  Q, Z
*/

#include <iostream>
#include <string>

//FUNCTION PROTOTYPES
int scrabble_points(char);
int total_points();

//MAIN FUNCTION
int main()
{
   std::cout << total_points();

    system("pause>0");
    return 0;
}

int scrabble_points(char ch)
{
    int points;
    switch(ch)
    {
        case 'A':
        case 'E':
        case 'I':
        case 'L':
        case 'N':
        case 'O':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
            points = 1;
            break;
        case 'D':
        case 'G':
            points = 2;
            break;
        case 'B':
        case 'C':
        case 'M':
        case 'P':
            points = 3;
            break;
        case 'F':
        case 'H':
        case 'V':
        case 'W':
        case 'Y':
            points = 4;
            break;
        case 'K':
            points = 5;
            break;
        case 'J':
        case 'X':
            points = 8;
            break;
        case 'Q':
        case 'Z':
            points = 10;
            break;    
        default:
            points = 0;
    }
    return points;
}

int total_points()
{
    int total_points = 0;
    std::string str;
    std::cout << "Enter a word and I'll tell you how many points that word is worth in SCRABBLE: ";
    std::cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        total_points +=  scrabble_points(str[i]);
    }
    return total_points;
}