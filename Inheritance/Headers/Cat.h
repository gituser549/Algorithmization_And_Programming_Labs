
#ifndef CAT_H

#define CAT_H

#include "Pet.h"

class Cat : public Pet
{
public:
	Cat(std::string name, std::string voice, int weight) : name_(name), voice_(voice), weight_(weight) {};
	Cat(const Cat& exampleCat) : name_(exampleCat.name_), voice_(exampleCat.voice_), weight_(exampleCat.weight_) {};
	~Cat() {};
	virtual std::string getName() const;
	virtual std::string getVoice() const;
	virtual int getWeight() const;
private:
	std::string name_;
	std::string voice_;
	int weight_;
};

#endif