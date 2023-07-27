/*
 * author derrick shibero 
 * this is a beginner c++ project
 * it contains topics like implementaion of header files, implentation of some of the c\c++ libraries, classes, structs etc;
 */

#ifndef _GAME_
#define _GAME_

#include "iostream"
#include "string"
#include "stdlib.h"
#include "iomanip"

using namespace std;

void printline(void);

// class player contains some of the basic attributes of an object player
class Player{
  private:
    int id;
    string name;
    int score;
  public:
    Player(); // default constructor
    Player(const int, const string, int);
    Player(const int, const string);
    ~Player();
    void setId(int uid){id = uid;}
    void setScore(int uscore){score = uscore;}
    void setName(string uname){name = uname;}
    int getId() const {return id;}
    int getScore() const {return score;}
    string getName() const {return name;}
    void print();
};

// class card contains some of the basic attributes of an object card
class Card{
  private:
    string name;
    int value;
  public:
    Card();
    Card(const string, const int);    
    void setName(string cname) {name = cname;}
    void setValue(int cvalue) {value = cvalue;}
    string getName() const { return name; }
    int getValue() const {return value; }
    void print();
};

// this struct is going to be used when designing how the users will play the game
struct CardPlayer{
  Player player;
  int value = 0;
  bool isstand = false;
};

// some of the functions used in the app
void printplayer(int, Player[10]);
void play(int, Player[10], Card[54]);
void decision(CardPlayer&, Card[54], Card[54], int&);
bool ispresent(Card, Card[54], int&);
void gamesort(CardPlayer[10], int, Player[10]);

#endif
