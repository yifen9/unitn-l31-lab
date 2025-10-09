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
#define plf(s, f) printf("%s%f\n", s, f)
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
  rep(i, m) {
    if (PA[i].name) {
      plu("[INDEX] ", i);
      printPlayer(PA[i]);
    }
  }
}

bool removePlayerGivenIndex(usi m, struct player *PA, usi i) {
  if (i >= m)
    return false;
  PA[i].name = NULL;
  PA[i].surname = NULL;
  return true;
}

float usi2f(usi a) { return ((float)a); }

float playerScore(struct player P) {
  return (usi2f(P.wins) / usi2f(P.matches));
}

usi playerHighestScore(usi m, struct player *PA) {
  usi i, maxIndex = 0;
  float pai, max = 0;
  rep(i, m) {
    if (PA[i].name) {
      pai = playerScore(PA[i]);
      if (pai > max) {
        max = pai;
        maxIndex = i;
      }
    }
  }
  return maxIndex;
}

int main() {
  struct player *PA = createPlayerArray(MAX_SIZE);

  addPlayerInArray(MAX_SIZE, PA, "Yifeng", "Li", 175, 50, 4, 5);
  addPlayerInArray(MAX_SIZE, PA, "Yifeng", "Li", 176, 51, 5, 5);
  addPlayerInArray(MAX_SIZE, PA, "Yifeng", "Li", 177, 52, 3, 5);

  pls("[INFO] Before Removal", "");
  printPlayerArray(MAX_SIZE, PA);

  removePlayerGivenIndex(MAX_SIZE, PA, 1);

  pls("[INFO] After Removal", "");
  printPlayerArray(MAX_SIZE, PA);

  plu("[INFO] Index of the Player with the Highest Score: ",
      playerHighestScore(MAX_SIZE, PA));

  return 0;
}