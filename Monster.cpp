#include <iostream>
#include "Monster.h"

void MonsterCard::copyFrom(const MonsterCard& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	attackPoints = other.attackPoints;
	defendPoints = other.defendPoints;
}

void MonsterCard::free() {
	delete[] name;
	name = nullptr;
	attackPoints = 0;
	defendPoints = 0;
}

MonsterCard::MonsterCard(const MonsterCard& other) {
	copyFrom(other);
}

MonsterCard& MonsterCard::operator=(const MonsterCard& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MonsterCard::~MonsterCard() {
	free();
}

const char* MonsterCard::getName() const {
	return name;
}

unsigned MonsterCard::getAttackPoints() const {
	return attackPoints;
}

unsigned MonsterCard::getDefendPoints() const {
	return defendPoints;
}

void MonsterCard::setName(const char* newName) {
	if (!newName || newName == name) {
		return;
	}
	delete[] name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void MonsterCard::setAttackPoints(unsigned newAttackPoints) {
	attackPoints = newAttackPoints;
}

void MonsterCard::setDefendPoints(unsigned newDefendPoints) {
	defendPoints = newDefendPoints;
}