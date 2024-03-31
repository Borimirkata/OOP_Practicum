#pragma once

class MonsterCard {
	char* name=nullptr;
	unsigned attackPoints = 0;
	unsigned defendPoints = 0;
public:
	MonsterCard() = default;
	MonsterCard(const MonsterCard& other);
	MonsterCard& operator=(const MonsterCard& other);
	const char* getName() const;
	unsigned getAttackPoints() const;
	unsigned getDefendPoints() const;
	void setName(const char* newName);
	void setAttackPoints(unsigned newAttackPoints);
	void setDefendPoints(unsigned newDefendPoints);
	~MonsterCard();

private:
	void copyFrom(const MonsterCard& other);
	void free();

};
