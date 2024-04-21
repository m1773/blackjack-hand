#include "blackjack.h"
#include <iostream>
using namespace std;
int BlackjackHand::score()const{
  int total_score=0;
  for (int i=0; i<size(); i++){
  Card c= card(i);
    switch (c.value()){
      case 'T':
      case 'K':
      case 'Q':
      case 'J':
      total_score+=10;
      break;
      case 'A':
      total_score+=11;
      break;
      case '*':
        break;
      default:
        total_score+= c.value()- '0';      
    }
  }
  for (int i=0; i<size(); i++)
    if(card(i).value()=='A' && total_score>21)
      total_score-=10;
  return total_score;
  }
int play(Deck& deck, int wager){
  Hand dealer;
  Hand player;


  
  player.insert(deck.deal());
  dealer.insert(deck.deal());
  player.insert(deck.deal());
  dealer.insert(deck.deal());

 
}
