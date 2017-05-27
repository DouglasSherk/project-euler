#include <iostream>
#include <set>
#include <unordered_map>
#include <stdexcept>
#include <fstream>
#include <algorithm>

#include "headers/euler.hpp"

const int NUM_PLAYERS = 2;
const int HAND_SIZE = 5;

class Card {
public:
  enum CardSuit {
    CardSuitSpades = 0,
    CardSuitClubs,
    CardSuitHearts,
    CardSuitDiamonds,
    CardSuitMax
  };

  enum CardFace {
    CardFaceDontUseMeLol = 0,
    CardFaceDontUseMeLoll,
    CardFaceTwo,
    CardFaceThree,
    CardFaceFour,
    CardFaceFive,
    CardFaceSix,
    CardFaceSeven,
    CardFaceEight,
    CardFaceNine,
    CardFaceTen,
    CardFaceJack,
    CardFaceQueen,
    CardFaceKing,
    CardFaceAce,
    CardFaceMax
  };

  Card(std::string card)
    : face(faceMappings.at(card[0])),
      suit(suitMappings.at(card[1])) {

  }

  Card() {

  }

  CardSuit getSuit() const {
    return suit;
  }

  CardFace getFace() const {
    return face;
  }

  char getSuitName() const {
    for (auto suitMapping : suitMappings) {
      if (suitMapping.second == suit) {
        return suitMapping.first;
      }
    }

    return '\0';
  }

  char getFaceName() const {
    for (auto faceMapping : faceMappings) {
      if (faceMapping.second == face) {
        return faceMapping.first;
      }
    }

    return '\0';
  }

  bool isAdjacent(const Card& other) const {
    return abs(getFace() - other.getFace()) == 1;
  }

  bool operator <(const Card& other) const {
    return getFace() < other.getFace();
  }

  friend std::ostream& operator<<(std::ostream& stream, const Card& card) {
    stream << card.getFaceName() << card.getSuitName();
    return stream;
  }

private:
  CardFace face;
  CardSuit suit;

  static const std::unordered_map<char, CardFace> faceMappings;
  static const std::unordered_map<char, CardSuit> suitMappings;
};

const std::unordered_map<char, Card::CardFace> Card::faceMappings = {
  std::pair<char, Card::CardFace>('2', Card::CardFaceTwo),
  std::pair<char, Card::CardFace>('3', Card::CardFaceThree),
  std::pair<char, Card::CardFace>('4', Card::CardFaceFour),
  std::pair<char, Card::CardFace>('5', Card::CardFaceFive),
  std::pair<char, Card::CardFace>('6', Card::CardFaceSix),
  std::pair<char, Card::CardFace>('7', Card::CardFaceSeven),
  std::pair<char, Card::CardFace>('8', Card::CardFaceEight),
  std::pair<char, Card::CardFace>('9', Card::CardFaceNine),
  std::pair<char, Card::CardFace>('T', Card::CardFaceTen),
  std::pair<char, Card::CardFace>('J', Card::CardFaceJack),
  std::pair<char, Card::CardFace>('Q', Card::CardFaceQueen),
  std::pair<char, Card::CardFace>('K', Card::CardFaceKing),
  std::pair<char, Card::CardFace>('A', Card::CardFaceAce)
};

const std::unordered_map<char, Card::CardSuit> Card::suitMappings = {
  std::pair<char, Card::CardSuit>('S', Card::CardSuitSpades),
  std::pair<char, Card::CardSuit>('C', Card::CardSuitClubs),
  std::pair<char, Card::CardSuit>('H', Card::CardSuitHearts),
  std::pair<char, Card::CardSuit>('D', Card::CardSuitDiamonds)
};

class Hand {
public:
  Hand(const std::vector<Card>& handCards)
    : cards(handCards) {
    if (cards.size() != HAND_SIZE) {
      throw new std::invalid_argument("hand size must be " + HAND_SIZE);
    }
    std::sort(cards.begin(), cards.end());
    rank = getRank();
  }

  bool operator <(const Hand& other) const {
    if (rank < other.rank) {
      return true;
    } else if (other.rank < rank) {
      return false;
    }

    return rankCardsBetter(other);
  }

  friend std::ostream& operator<<(std::ostream& stream, const Hand& hand) {
    for (auto card : hand.cards) {
      stream << card << " ";
    }
    stream << hand.rank;
    return stream;
  }

  int rankrank() {
    return rank;
  }

private:
  enum HandRank {
    HandRankHighCard = 0,
    HandRankOnePair,
    HandRankTwoPair,
    HandRankThreeOfAKind,
    HandRankStraight,
    HandRankFlush,
    HandRankFullHouse,
    HandRankFourOfAKind,
    HandRankStraightFlush
  };

  HandRank getRank() const {
    int cardFaces[Card::CardFaceMax] = {0};
    int cardSuits[Card::CardSuitMax] = {0};

    bool hasFlush = false;
    bool hasStraight = false;

    int numStraight = 1;
    for (auto card = cards.begin(); card != cards.end(); card++) {
      cardFaces[card->getFace()]++;

      auto nextCard = card + 1;

      if (nextCard != cards.end() && card->isAdjacent(*nextCard)) {
        if (++numStraight >= HAND_SIZE) {
          hasStraight = true;
        }
      }

      if (++cardSuits[card->getSuit()] >= HAND_SIZE) {
        hasFlush = true;
      }
    }

    if (hasStraight && hasFlush) {
      return HandRankStraightFlush;
    }

    int numRanksWithThree = 0, numRanksWithTwo = 0;
    for (int i = 0; i < Card::CardFaceMax; i++) {
      switch (cardFaces[i]) {
      case 4:
        return HandRankFourOfAKind;
        break;
      case 3:
        numRanksWithThree++;
        break;
      case 2:
        numRanksWithTwo++;
        break;
      }
    }

    if (numRanksWithThree >= 1 && numRanksWithTwo >= 1) {
      return HandRankFullHouse;
    }

    if (hasFlush) {
      return HandRankFlush;
    } else if (hasStraight) {
      return HandRankStraight;
    } else if (numRanksWithThree >= 1) {
      return HandRankThreeOfAKind;
    } else if (numRanksWithTwo >= 2) {
      return HandRankTwoPair;
    } else if (numRanksWithTwo >= 1) {
      return HandRankOnePair;
    }

    return HandRankHighCard;
  }

  bool rankCardsBetter(const Hand& other) const {
    switch (rank) {

    case HandRankStraightFlush:
    case HandRankStraight:
    case HandRankFlush:
    case HandRankFullHouse:
    case HandRankHighCard:
      for (int i = cards.size() - 1; i >= 0; i--) {
        if (cards[i] < other.cards[i]) {
          return true;
        } else if (other.cards[i] < cards[i]) {
          return false;
        }
      }
      break;

    case HandRankFourOfAKind:
    case HandRankThreeOfAKind:
    case HandRankTwoPair:
    case HandRankOnePair:
      int cardFaces[Card::CardFaceMax] = {0};
      int otherCardFaces[Card::CardFaceMax] = {0};

      for (auto card = cards.begin(); card != cards.end(); card++) {
        cardFaces[card->getFace()]++;
      }
      for (auto card = other.cards.begin(); card != other.cards.end(); card++) {
        otherCardFaces[card->getFace()]++;
      }

      int targetRank;
      switch (rank) {
      case HandRankFourOfAKind:
        targetRank = 4;
        break;
      case HandRankThreeOfAKind:
        targetRank = 3;
        break;
      case HandRankTwoPair:
      case HandRankOnePair:
        targetRank = 2;
        break;
      default:
        return false;
      }

      Card topCard;
      for (int i = cards.size() - 1; i >= 0; i--) {
        if (cardFaces[cards[i].getFace()] == targetRank) {
          topCard = cards[i];
          break;
        }
      }

      Card otherTopCard;
      for (int i = other.cards.size() - 1; i >= 0; i--) {
        if (otherCardFaces[other.cards[i].getFace()] == targetRank) {
          otherTopCard = other.cards[i];
          break;
        }
      }

      if (topCard < otherTopCard) {
        return true;
      } else if (otherTopCard < topCard) {
        return false;
      }

      if (rank == HandRankTwoPair) {
        for (int i = cards.size() - 1; i >= 0; i--) {
          if (cards[i] < topCard && cardFaces[cards[i].getFace()] == targetRank) {
            topCard = cards[i];
            break;
          }
        }

        for (int i = other.cards.size() - 1; i >= 0; i--) {
          if (other.cards[i] < otherTopCard && otherCardFaces[other.cards[i].getFace()] == targetRank) {
            otherTopCard = other.cards[i];
            break;
          }
        }

        if (topCard < otherTopCard) {
          return true;
        } else if (otherTopCard < topCard) {
          return false;
        }
      }

      for (int i = cards.size() - 1; i >= 0; i--) {
        if (cards[i] < other.cards[i]) {
          return true;
        } else if (other.cards[i] < cards[i]) {
          return false;
        }
      }

      break;
    }

    return false;
  }

  std::vector<Card> cards;
  HandRank rank;
};

std::vector<Hand> getHands(std::string fileName) {
  std::ifstream handsStream(fileName);

  std::vector<Hand> hands;
  std::vector<Card> cards;

  std::string line;

  while (handsStream) {
    for (int p = 0; p < NUM_PLAYERS; p++) {
      for (int c = 0; c < HAND_SIZE; c++) {
        handsStream >> line;
        cards.push_back(line);
      }

      if (!handsStream) {
        break;
      }

      hands.push_back(cards);
      cards.clear();
    }
  }

  return hands;
}

int main(int argc, char** argv) {
  auto hands(getHands("54_hands.txt"));

  int numHandsPlayerOneWins = 0;
  for (int i = 0; i + 1 < hands.size(); i += 2) {
    std::cout << "P1: " << hands[i] << " vs. P2: " << hands[i + 1];
    if (hands[i + 1] < hands[i]) {
      numHandsPlayerOneWins++;
      std::cout << " -- P1 wins" << std::endl;
    } else {
      std::cout << " -- P2 wins" << std::endl;
    }
  }

  std::cout << "Player 1 wins " << numHandsPlayerOneWins << " hands." << std::endl;

  return 0;
}
