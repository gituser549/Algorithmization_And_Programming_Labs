
#ifndef DOG_H

#define DOG_H

#include "Pet.h"
#include <string>

class Dog : public Pet
{
public:
	Dog(std::string name, std::string voice, int weight) : name_(name), voice_(voice), \
		weight_(weight), character_("") {};
	Dog(std::string name, std::string voice, int weight, std::string character) : name_(name), \
		voice_(voice), weight_(weight), character_(character) {};
	Dog(const Dog& exampleDog) : name_(exampleDog.name_), voice_(exampleDog.voice_), \
		weight_(exampleDog.weight_), character_(exampleDog.character_) {};
	~Dog() {};
	virtual std::string getName() const;
	virtual std::string getVoice() const;
	virtual int getWeight() const;
	virtual std::string getCharacter() const;
private:
	std::string name_;
	std::string voice_;
	int weight_;
	std::string character_;
};

#endif