#include <iostream>
#include "Deck.h";

Deck::Deck(const MonsterCard* monsterCards, unsigned monsterSize, const MagicCard* magicCards, unsigned magicSize) {
	monsterCardsSize = monsterSize;
	magicCardsSize = magicSize;

	for (int i = 0; i < monsterCardsSize; i++) {
		monsterArr[i].setName(monsterCards[i].getName());
		monsterArr[i].setAttackPoints(monsterCards[i].getAttackPoints());
		monsterArr[i].setDefendPoints(monsterCards[i].getDefendPoints());
	}

	for (int i = 0; i < magicCardsSize; i++) {
		magicArr[i].setName(magicCards[i].getName());
		magicArr[i].setEffect(magicCards[i].getEffect());
		magicArr[i].setType(magicCards[i].getType());
	}
}

Deck::~Deck() {
	monsterCardsSize = 0;
	magicCardsSize = 0;
}

unsigned Deck::getMonsterCardCount() const {
	return monsterCardsSize;
}

unsigned Deck::getMagicCardCount() const {
	return magicCardsSize;
}

void Deck::addMonsterCard(MonsterCard& newCard) {
	if (isFull(monsterCardsSize)) {
		return;
	}
	monsterArr[monsterCardsSize].setName(newCard.getName());
	monsterArr[monsterCardsSize].setAttackPoints(newCard.getAttackPoints());
	monsterArr[monsterCardsSize].setDefendPoints(newCard.getDefendPoints());
	monsterCardsSize++;
}

void Deck::addMagicCard(MagicCard& newCard) {
	if (isFull(magicCardsSize)) {
		return;
	}
	magicArr[magicCardsSize].setName(newCard.getName());
	magicArr[magicCardsSize].setEffect(newCard.getEffect());
	magicArr[magicCardsSize].setType(newCard.getType());
	magicCardsSize++;
}

MonsterCard& Deck::changeMonsterCard(unsigned index, const MonsterCard& newCard) {
	int cardsSize = getMonsterCardCount();
	if (index > cardsSize) {
		return;
	}
	monsterArr[index] = newCard;
	return monsterArr[index];
}

MagicCard& Deck::changeMagicCard(unsigned index, const MagicCard& newCard) {
	int cardsSize = getMonsterCardCount();
	if (index > cardsSize) {
		return;
	}
	magicArr[index] = newCard;
	return magicArr[index];
}

void Deck::removeMonsterCard(unsigned index){
	int size = getMonsterCardCount();
	if (index >= size) {
		return;
	}

	for (int i = index; i < size - 1; i++) {
		monsterArr[i].setName(monsterArr[i + 1].getName());
		monsterArr[i].setAttackPoints(monsterArr[i + 1].getAttackPoints());
		monsterArr[i].setDefendPoints(monsterArr[i + 1].getDefendPoints());
	}
	monsterCardsSize--;
}

void Deck::removeMagicCard(unsigned index) {
	int size = getMagicCardCount();
	if (index >= size) {
		return;
	}

	for (int i = index; i < size - 1; i++) {
		magicArr[i].setName(magicArr[i + 1].getName());
		magicArr[i].setEffect(magicArr[i + 1].getEffect());
		magicArr[i].setType(magicArr[i + 1].getType());
	}
	magicCardsSize--;
}