/*
Arrays, basics

Define a constant `MAX_SIZE = 10`, create a player array of that size, then
create functions to:

• Add a player in the array
    • What happens if the array is full?
• Print the array
    • What happens if the array is NOT full?
• Remove a player, given the index inside the array
    • What happens if the indexed player does not exist?
• Return the player with the highest score
    • How do you return it? Just the index, a pointer, a copy, ... you decide.

Briefly discuss the computational complexity of each of the procedures.
*/

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define rep(i, n) for (usi i = 0; i < n; ++i)
#define pl printf("\n")
#define plu(s, u) printf("%s%u\n", s, u)
#define pls(s1, s2) printf("%s%s\n", s1, s2)

#define MAX_SIZE 10

typedef unsigned short int usi;

struct player {
  char *name;
  char *surname;
  usi height;
  usi weight;
  usi wins;
  usi matches;
};

struct player *createPlayerArray(usi m) {
  struct player *PA = NULL;
  PA = (struct player *)malloc(m * sizeof(struct player));
  return PA;
}

void addPlayer(struct player *P, char *name, char *surname, usi height,
               usi weight, usi wins, usi matches) {
  P->name = name;
  P->surname = surname;
  P->height = height;
  P->weight = weight;
  P->wins = wins;
  P->matches = matches;
}

bool addPlayerInArray(usi m, struct player *PA, char *name, char *surname,
                      usi height, usi weight, usi wins, usi matches) {
  usi i = 0;
  while ((i < m) && PA[i].name)
    ++i;
  if (i == m)
    return false;
  addPlayer(&PA[i], name, surname, height, weight, wins, matches);
  return true;
}

void printPlayer(struct player P) {
  pls("name:    ", P.name);
  pls("surname: ", P.surname);
  plu("height:  ", P.height);
  plu("weight:  ", P.weight);
  plu("wins:    ", P.wins);
  plu("matches: ", P.matches);
}

void printPlayerArray(usi m, struct player *PA) {
  usi i = 0;
  while ((i < m) && PA[i].name) {
    plu("INDEX: ", i);
    printPlayer(PA[i]);
    ++i;
  }
}

bool removePlayer(usi m, struct player *PA, usi i) {
  if (i >= m)
    return false;
  free(PA[i]);
  PA[i] = (struct player *)malloc(sizeof(struct player));
  return true;
}

int main() {
  struct player *PA = createPlayerArray(MAX_SIZE);

  addPlayerInArray(MAX_SIZE, PA, "Yifeng", "Li", 175, 50, 4, 5);
  addPlayerInArray(MAX_SIZE, PA, "Yifeng", "Li", 175, 50, 4, 5);
  addPlayerInArray(MAX_SIZE, PA, "Yifeng", "Li", 175, 50, 4, 5);

  printPlayerArray(MAX_SIZE, PA);

  return 0;
}