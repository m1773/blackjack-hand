#include "cards.h"
#include "blackjack.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  srand(time(0));
  Deck d;
  BlackjackHand h;
  d.shuffle();
  h.insert(d.deal());
  h.insert(d.deal());
  cout << h.str() << " " << h.score() << endl;
  for (int i = 0; i < 4; i++) 
    {
      h.insert(d.deal());
      cout << h.str() << " " << h.score() << endl;
    }
  
}
