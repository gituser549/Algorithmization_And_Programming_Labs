
#ifndef FAMILY_PETS_H

#define FAMILY_PETS_H

#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include <string>
#include <vector>

const int ZERO_PETS = 0;

class FamilyPets
{
public:
	FamilyPets(int maxNumPets) : maxNumPets_(maxNumPets), realNumPets_(ZERO_PETS), arrayPets_() {};
	~FamilyPets() { clearPets(); };
	FamilyPets& operator+(Pet& gottenPet);
	void getVoices() const;
	void getNames() const;
	int getNumberRepetitionsName(const std::string gottenName) const;
	std::string findTheEasiest() const;
	friend std::ostream& operator<<(std::ostream& out, const FamilyPets& famPets);
	void clearPets();
private:
	int maxNumPets_;
	int realNumPets_;
	std::vector<Pet*> arrayPets_;
};

#endif