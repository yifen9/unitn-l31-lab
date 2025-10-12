/*
Player struct

Create a `struct player` that contains

• The name of the player
• The surname of the player
• The height of the player
• The weight of the player
• The number of wins of the player
• The number of matches played by the player

Which types should you use for each field?

Write a function `playerScore` that, given a player, returns the score of that
player, calculated as the percentage of matches that the given player won.
*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned short int usi;

struct player {
  char *name;
  char *surname;
  usi height;
  usi weight;
  usi wins;
  usi matches;
};

float usi2f(usi a) { return ((float)a); }

float playerScore(struct player P) {
  return (usi2f(P.wins) / usi2f(P.matches));
}

int main() {
  struct player P;
  scanf("%d", &(P.wins));
  scanf("%d", &(P.matches));
  printf("%.2f\n", playerScore(P));
  return 0;
}