/*
 * author derrick shibero
 * in this we are going to define some of the functions and methods that we saw in the game.h header file
 * */

#include "game.h"

void printline(){
  cout<<"\n********************************************************\n";
}

/*
 * Player constructors
 * */
Player::Player(){ // defaultconstructor to player definitions
  setId(1);
  setName("Jane Doe");
  setScore(0);
}

Player::Player(const int id, const string name){ 
  setId(id);
  setName(name);
  setScore(0);
}

Player::Player(const int id, const string name, int score){
  setId(id);
  setName(name);
  setScore(score);
}

Player::~Player(){ // destructor
} 

void Player::print(){ // prints the details of a single player
  cout<<"\nPlayer details";
  printline();
  cout<<setw(9)<<left<<"id"<<setw(15)<<right<<getId()<<endl
    <<setw(9)<<left<<"name"<<setw(15)<<right<<getName()<<endl
    <<setw(9)<<left<<"score"<<setw(15)<<right<<getScore()<<endl;
  cout<<"enter any character to exit: ";
  cin.get();
}

/*
 * Card constructors
 * */
Card::Card(){ // default constructor to Card
  setName("AS");
  setValue(1);
}

Card::Card(const string name, const int value){
  setName(name);
  setValue(value);
}

void Card::print(){
  cout<<"\nCard details";
  printline();
  cout<<setw(9)<<left<<"name"<<setw(15)<<right<<getName()<<endl
    <<setw(9)<<left<<"value"<<setw(15)<<right<<getValue()<<endl;
  cout<<"enter any character to exit: ";
  cin.get();
}
  
void printplayer(int n, Player player[]){
  cout<<setw(25)<<left<<"name"<<setw(15)<<right<<"score"<<endl;
  for(int i= 0; i< n; i++)
    cout<<setw(25)<<left<<player[i].getName()<<setw(15)<<right<<player[i].getScore()<<endl; 
}

void play(int num, Player player[], Card card[]){
  CardPlayer progress[10];
  Card input[54];
  int count = 0;

  for(int i =0; i < num; i++)
    progress[i].player = player[i];

  for(int y = 0; y < 5;  y++){
    for(int i = 0; i < num; i++){
      cout<<"\033[2J\n"; //clears screen
    
      if(!progress[i].isstand){
        cout<<"player name: "<<player[i].getName()<<endl;
        decision(progress[i], card, input, count); // this functions is where the actual playing takes place
        cout<<"press any character to exit: ";
        char a; cin>>a; cout<<"\033[2J\n";
      }
    }

    gamesort(progress, num, player);

    // this code returns the scores after each game
    for(int i = 0; i< num; i++){
      player[i].setScore(i + 1);
    }

    cout<<player[num-1].getName()<<" won this round\n\n\npress any character to exit";
    char a; cin>>a;
    cout<<"\033[2J\n";
  }
}

// sorting to dertemine winner and also to give out scores
void gamesort(CardPlayer cp[], int num, Player player[]){
  for(int i = 0; i < num; i++){
    for(int j = 1; j< num; j++){
      if(cp[j-1].value > cp[j].value){
        Player temp = player[j-1];
        player[j-1] = player[j];
        player[j] = temp;
      }
    }
  }
}

// where the actual playing takes place
void decision(CardPlayer &cp, Card cards[], Card inp[], int &num){
  cout<<"1. hit\n2. surrender\n3. stand\n>>";
  int ans, x;
  bool repeat = true;
  cin>>ans;

  switch(ans){
    case 1:
      cout<<"hit\n";
      while(repeat){
        x = (int)(rand() % 52);
        repeat = ispresent(cards[x], inp, num);
      }
      cout<<"the card you have selected is "<<cards[x].getName()<<endl;
      cp.value += cards[x].getValue();
      break;
    case 2:
      cout<<"surrender\n";
      break;
    case 3:
      cout<<"stand\n";
      cp.isstand = true;
      break;
    default:
      decision(cp, cards, inp, num);
  }
}

// used to check if any card has been repeated
bool ispresent(Card card, Card in[54], int &c){
  for(int i = 0; i < c; i++){
    if(card.getName() == in[i].getName())
      return true;
  }
  return false;
}
