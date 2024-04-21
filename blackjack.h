#pragma once
#include "cards.h"


class BlackjackHand : public Hand {
  public:
  int score() const;
};


int play (Deck&deck, int wager);
