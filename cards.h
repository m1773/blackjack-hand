#pragma once
#include <string>

/**
  * A single card from a deck of cards
  *
  * The default constructor for a Card object creates a card placeholder,
  * which does not represent an actual card from the deck. Actual cards are
  * produced only by the Deck object (see Deck::deal()), and those objects
  * may be assigned to a Card object to represent an actual playing card.
  */
class Card {
friend class Deck;
private:
  int card_index;
  Card(int index);
public:
  /**
    * Creates a card placeholder*
    */
  Card() { card_index = 52; }

  /**
    * Gets the suit of the card
    *
    * Returns one of 'H', 'S', 'D', or 'C' to indicate the suit of the card.
    * If a placeholder card, returns '*'.
    *
    * @return Character representing card suit
    */
  char suit() const;

  /**
    * Gets the value of the card
    *
    * Returns one of '2', '3', ..., 'T', 'J', 'K', or 'A'to indicate the value
    * of the card. If a placeholder card, returns '*'.
    *
    * @return Character representing card value
    */
  char value() const;

  /**
    * Gets a string representation of the card
    *
    * Returns two characters as a string, combining the value and suit.
    *
    * @return String representation of the card
    */
  std::string str() const;
};

/**
  * A deck of cards
  *
  * When a Deck object is created, it contains 52 unique Card object, each
  * representing a card from the deck. The deck is initially not shuffled,
  * so programs using this class must explicitly shuffle the deck
  * (see Deck::shuffle()).
  */
class Deck {
private:
  Card cards[52];
  int cards_used;
public:
  /**
    * Constructs a new deck of cards
    */
  Deck();

  /**
    * Deals the next card from the deck
    *
    * Returns the next card from the deck, reducing the number of cards in
    * the deck by one.
    *
    * @return The card that was dealt
    */
  Card deal() { return cards[cards_used++]; }

  /**
    * Shuffles the deck
    *
    * Shuffles the deck by randomizing the order of Card objects in the deck.
    * Upon shuffling, the Deck object returns to the full compliment of 52 cards.
    */
  void shuffle();

  /**
    * Get number of cards in the deck
    *
    * @return Number of cards remaining
    */
  int size() const { return 52 - cards_used; }
};

/**
  * A player's collection of cards
  *
  * When used in a card game, represents a player's "hand". A hand initially
  * includes zero cards. The Hand::insert() function is used to add cards to
  * the hand (by assigning the return value of Deck::deal()). A hand may include
  * as many as 52 cards, the maximum number of cards that can be dealt from a
  * deck.
  */
class Hand {
private:
  Card cards[52];
  int cards_count;
public:
  /**
    * Constructs an empty hand
    */
  Hand() { cards_count = 0; }

  /**
    * Get card in hand by its index
    *
    * Returns a single card from the deck by its index, where the first card
    * in the hand is card number 0. A valid index value must be provided.
    *
    * @param index Index of the card to retrieve
    * @return The card at the given index
    */
  Card card (int index) const { return cards[index]; }

  /**
    * Adds a card to the hand
    *
    * @param card The card to be added to the hand
    */
  void insert (const Card& card) { cards[cards_count++] = card; }

  /**
    * Get number of cards in the hand
    *
    * return Number of cards
    */
  int size() const { return cards_count; }

  /**
    * Get a string representation of the hand
    *
    * A string representation is produced by concatenating the string
    * representations of all the cards in the hand separated by hyphens.
    *
    * @return String of all card string
    */
  std::string str() const;
};
