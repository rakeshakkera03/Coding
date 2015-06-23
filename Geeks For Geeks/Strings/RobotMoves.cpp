/* Solution copied from Geeks for Geeks */

#include<iostream>
using namespace std;
 
// Macros for East, North, South and West
#define N 0
#define E 1
#define S 2
#define W 3
 
// This function returns true if the given path is circular, else false
bool isCircular(char path[])
{
  // Initialize starting point for robot as (0, 0) and starting
  // direction as N North
  int x = 0, y = 0;
  int dir = N;
 
  // Travers the path given for robot
  for (int i=0; path[i]; i++)
  {
      // Find current move
      char move = path[i];
 
      // If move is left or right, then change direction
      if (move == 'R')
        dir = (dir + 1)%4;
      else if (move == 'L')
        dir = (4 + dir - 1)%4;
 
      // If move is Go, then change  x or y according to
      // current direction
      else // if (move == 'G')
      {
         if (dir == N)
            y++;
         else if (dir == E)
            x++;
         else if (dir == S)
            y--;
         else // dir == W
            x--;
      }
  }
 
   // If robot comes back to (0, 0), then path is cyclic
  return (x == 0 && y == 0);
}
 
// Driver program
int main()
{
    char path[] = "GLGLGLG";
    if (isCircular(path))
      cout << "Given sequence of moves is circular";
    else
      cout << "Given sequence of moves is NOT circular";
}

