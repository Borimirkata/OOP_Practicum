#pragma once

namespace Constants {
	constexpr int STRING_SIZE = 25;
	constexpr int EFFECT_SIZE = 100;
}

enum class Type {
	trap=0,
	buff,
	spell
};

class MagicCard {
	char name[Constants::STRING_SIZE]="";
	char effect[Constants::EFFECT_SIZE] = "";
	Type type=Type::trap;

public:
	MagicCard() = default;
	const char* getName() const;
	const char* getEffect() const;
	const Type& getType() const;
	void setName(const char* newName);
	void setEffect(const char* newEffect);
	void setType(const Type& newType);
	~MagicCard();
};
