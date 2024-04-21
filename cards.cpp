#include "cards.h"
#include <algorithm>
#include <cstdlib>

Card::Card(int index) {
  card_index = index;
}

std::string Card::str() const {
  return std::string() + value() + suit();
}

char Card::suit() const {
  static const char suits[] = { 'H', 'S', 'D', 'C' };
  if (card_index == 52)
    return '*';
  return suits[card_index % 4];
}

char Card::value() const {
  static const char values[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };
  if (card_index == 52)
    return '*';
  return values[card_index / 4];
}

Deck::Deck() {
  for (int i = 0; i < 52; i++)
    cards[i] = Card(i);
  cards_used = 0;
}

void Deck::shuffle() {
  for (int i = 0; i < 52; i++) {
    int index = rand() % 52;
    std::swap(cards[i], cards[index]);
  }
  cards_used = 0;
}

std::string Hand::str() const {
  std::string s;
  for (int i = 0; i < cards_count; i++) {
    if (i)
      s += '-';
    s += cards[i].str();
  }
  return s;
}