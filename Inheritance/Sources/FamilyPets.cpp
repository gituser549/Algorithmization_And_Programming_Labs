
#include "FamilyPets.h"
#include <iostream>

const std::string ERROR_EMPTY_ARR_OF_PETS = "ERROR: there are no pets in array at all";

const int FIRST_PET_IND = 0;

FamilyPets& FamilyPets::operator+(Pet& gottenPet)
{

	Cat* catPtr = nullptr;
	Dog* dogPtr = nullptr;
	if (catPtr = dynamic_cast<Cat*>(&gottenPet))
	{
		Cat* newCat = new Cat(*catPtr);
		arrayPets_.push_back(newCat);
	}
	else if (dogPtr = dynamic_cast<Dog*>(&gottenPet))
	{
		Dog* newDog = new Dog(*dogPtr);
		arrayPets_.push_back(newDog);
	}

	realNumPets_++;
	return *this;
}

void FamilyPets::getNames() const
{
	if (realNumPets_ == ZERO_PETS)
	{
		throw std::length_error(ERROR_EMPTY_ARR_OF_PETS);
	}
	std::cout << "Names of pets:" << "\n";
	for (int curPet = FIRST_PET_IND; curPet < realNumPets_; curPet++)
	{
		std::cout << arrayPets_[curPet]->getName();
		std::cout << " ";
	}
	std::cout << "\n";
}

void FamilyPets::getVoices() const
{
	if (realNumPets_ == ZERO_PETS)
	{
		throw std::length_error(ERROR_EMPTY_ARR_OF_PETS);
	}
	std::cout << "Voices of pets:" << "\n";
	for (int curPet = FIRST_PET_IND; curPet < realNumPets_; curPet++)
	{
		std::cout << arrayPets_[curPet]->getVoice();
		std::cout << " ";
	}
	std::cout << "\n";
}

int FamilyPets::getNumberRepetitionsName(const std::string gottenName) const
{
	if (realNumPets_ == ZERO_PETS)
	{
		throw std::length_error(ERROR_EMPTY_ARR_OF_PETS);
	}
	int counterSameName = 0;
	for (int curPet = FIRST_PET_IND; curPet < realNumPets_; curPet++)
	{
		if (arrayPets_[curPet]->getName() == gottenName)
		{
			counterSameName++;
		}
	}
	return counterSameName;
}

std::string FamilyPets::findTheEasiest() const
{
	if (realNumPets_ == ZERO_PETS)
	{
		throw std::length_error(ERROR_EMPTY_ARR_OF_PETS);
	}
	else
	{
		int minWeight = -1;
		std::string minWeightName = "";
		Cat* catPtr = nullptr;
		Dog* dogPtr = nullptr;
		for (int numPet = FIRST_PET_IND; numPet < realNumPets_; numPet++)
		{
			catPtr = dynamic_cast<Cat*>(arrayPets_[numPet]);
			if (catPtr = dynamic_cast<Cat*>(arrayPets_[numPet]))
			{
				if (catPtr->getWeight() < minWeight || numPet == FIRST_PET_IND)
				{
					minWeight = catPtr->getWeight();
					minWeightName = catPtr->getName();
				}
			}
			else
			{
				dogPtr = dynamic_cast<Dog*>(arrayPets_[numPet]);
				if (dogPtr->getWeight() < minWeight || numPet == FIRST_PET_IND)
				{
					minWeight = dogPtr->getWeight();
					minWeightName = dogPtr->getName();
				}
			}
		}
		return minWeightName;
	}
}

std::ostream& operator<<(std::ostream& out, const FamilyPets& famPets)
{
	Cat* catPtr = nullptr;
	Dog* dogPtr = nullptr;
	for (int numPet = 0; numPet < famPets.realNumPets_; numPet++)
	{
		if (catPtr = dynamic_cast<Cat*>(famPets.arrayPets_[numPet]))
		{
			out << "Cat" << " " << catPtr->getName() << " " << catPtr->getVoice() << " " << catPtr->getWeight() << "\n";
		}
		else
		{
			dogPtr = dynamic_cast<Dog*>(famPets.arrayPets_[numPet]);
			out << "Dog" << " " << dogPtr->getName() << " " << dogPtr->getVoice() << " " << dogPtr->getWeight() << "\n";
		}
	}
	return out;

}

void FamilyPets::clearPets()
{
	for (int curPet = FIRST_PET_IND; curPet < realNumPets_; curPet++)
	{
		delete arrayPets_[curPet];
	}
	realNumPets_ = 0;
	arrayPets_.clear();
}