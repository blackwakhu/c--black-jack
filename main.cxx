#include "game.h"

void filldeck();
void menu();
void showplayers();

Card deck[54];
Player player[10];

int num;

int main(){
  cout<<"\033[2J\n";
  filldeck();
  cout<<"enter the number of players(>1 && <10)\n>>";
  cin>>num;
  
  if(num >= 2 && num <= 10){
    for(int i =0; i < num; i++){
      string name;
      cout<<"\nenter the name of the player "<<i+1<<"\n>>";
      cin>>name;
      player[i].setName(name);
      player[i].setId(i +1);
    }
    menu();
  }
  else{
    cout<<"incorrect entry exiting the program\n";
    return 1;
  }
  return 0;
}

void filldeck(){
  string type[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
  string symbols[] = {"spades", "heart", "diamond", "club"};
  int i = 1, p = 0;
  for(string a: type){
    for(string symbol: symbols){
      deck[p].setName(a+" "+symbol);
      deck[p].setValue(i);
      p += 1;
    }
    i += 1;
  }
}

void menu(){
  bool exit = false;
  cout<<"\033[2J\n";

  while(!exit){
    char a;
    cout<<" M A I N  M E N U ";
    printline();
    cout<<"1. new game\n2. show players\n3. help\n0. exit\n>>";
    cin>>a;
    switch(a){
      case '1':
        play(num, player, deck);
        break;
      case '2':
        showplayers();
        break;
      case '3':
        break;
      case 'x':
      case '0':
        exit = true;
        break;
      default:
        menu();
    }
  }
}

void showplayers(){
  cout<<"\033[2J\n";
  cout<<"Player details\n";
  printplayer(num, player);
  cout<<"press any character to exit\n>> ";
  char a; cin>>a;
  cout<<"\033[2J\n";
}

