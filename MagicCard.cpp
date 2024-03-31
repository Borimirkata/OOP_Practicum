#include <iostream>
#include "MagicCard.h"

const char* MagicCard::getName() const {
	return name;
}

const char* MagicCard::getEffect() const {
	return effect;
}

const Type& MagicCard::getType() const {
	return type;
}

void MagicCard::setName(const char* newName) {
	int len = strlen(newName);
	if (!newName || newName == name || len > Constants::STRING_SIZE) {
		return;
	}
	strcpy(name, newName);
}

void MagicCard::setEffect(const char* newEffect) {
	int len = strlen(newEffect);
	if (!newEffect || newEffect == effect || len > Constants::EFFECT_SIZE) {
		return;
	}
	strcpy(effect,newEffect);
}

void MagicCard::setType(const Type& newType) {
	type = newType;
}
MagicCard::~MagicCard() {
	strcpy(name, "");
	type = Type::trap;
}