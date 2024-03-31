#pragma once
#include "Monster.h";
#include "MagicCard.h"

namespace Const {
	constexpr int MAX_CARDS = 20;
}

class Deck {
	MonsterCard monsterArr[Const::MAX_CARDS] = {};
	unsigned monsterCardsSize = 0;
	MagicCard magicArr[Const::MAX_CARDS] = {};
	unsigned magicCardsSize = 0;

	bool isFull(unsigned currentSize) const{
		return currentSize >= Const::MAX_CARDS;
	}

public:
	Deck() = default;
	~Deck();
	Deck(const MonsterCard* monsterCards, unsigned monsterSize, const MagicCard* magicCards, unsigned magicSize);
	unsigned getMonsterCardCount() const;
	unsigned getMagicCardCount() const;
	void addMonsterCard(MonsterCard& card);
	void addMagicCard(MagicCard& card);
	MonsterCard& changeMonsterCard(unsigned index, const MonsterCard& newCard);
	MagicCard& changeMagicCard(unsigned index, const MagicCard& newCard);
	void removeMonsterCard(unsigned index);
	void removeMagicCard(unsigned index);
};
