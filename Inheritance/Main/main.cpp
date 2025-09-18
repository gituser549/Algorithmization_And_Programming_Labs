
#include "FamilyPets.h"
#include <iostream>
#include <string>

const std::string ERR_MAX_NUM = "ERROR: Incorrect number of pets specified";
const std::string ERR_REAL_NUM = "ERROR: The number of pets exceeds the maximum";
const std::string ERR_INCORRECT_TYPE = "ERROR: The type of pet must be Cat or Dog";
const std::string ERR_INCORRECT_NAME = "ERROR: The name of pet must be a word only with letters";
const std::string ERR_INCORRECT_VOICE = "ERROR: The voice of pet must be a word only with letters and underline symbol";
const std::string ERR_INCORRECT_WEIGHT = "ERROR: The weight of pet must be an integer number > 0";
const std::string ERR_INCORRECT_CHECK_NAME = "ERROR: name for check must be a word only with letters";

const std::string ERR_CANT_ALLOC_MEMORY = "ERROR: can't allocate so much memory";

const int NUM_PET_ATTRS = 4;

bool isCorrectName(const std::string gottenName);
bool isCorrectVoice(const std::string gottenVoice);
bool isCorrectWeight(const std::string gottenWeight);


/*TESTS FOR PROGRAM*/

/* TEST 1 (all is ok)
Enter number of pets: 3
Write type, name, voice and weight of pet (end of the input must be string END):
Cat George meow_meow 20
Dog Fred gav_gav 10
Dog George gav_gav_gav 20
END
Names of pets:
George Fred George
Voices of pets:
meow_meow gav_gav gav_gav_gav
Enter the name of pet to check:
George
The number of pets with given name: 2
Lightest in weight pet: Fred
The info about all pets (type, name, voice, weight):
Cat George meow_meow 20
Dog Fred gav_gav 10
Dog George gav_gav_gav 20
*/

/* TEST 2 (ERROR: Incorrect number of pets specified)
Enter number of pets: 8
ERROR: Incorrect number of pets specified
*/

/* TEST 3 (ERROR: Incorrect number of pets specified)
Enter number of pets: -1
ERROR: Incorrect number of pets specified
*/

/* TEST 4 (ERROR: The number of pets exceeds the maximum)
Enter number of pets: 2
Write type, name, voice and weight of pet (end of the input must be string END):
Cat George meow_meow 20
Dog Fred gav_gav 10
Dog George gav_gav_gav 20
END
ERROR: The number of pets exceeds the maximum
*/

/* SOME EXTRA TESTS */

/* TEST 5 (ERROR: The type of pet must be Cat or Dog)
Enter number of pets: 1
Write type, name, voice and weight of pet (end of the input must be string END):
Horse George fr_fr_fr 20
END
ERROR: The type of pet must be Cat or Dog
*/

/* TEST 6 (ERROR: The name of pet must be a word only with letters)
Enter number of pets: 1
Write type, name, voice and weight of pet (end of the input must be string END):
Cat name1 meow_meow 20
END
ERROR: The name of pet must be a word only with letters
*/

/* TEST 7 (ERROR: The voice of pet must be a word only with letters and underline symbol)
Enter number of pets: 1
Write type, name, voice and weight of pet (end of the input must be string END):
Cat George meow_1 20
END
ERROR: The voice of pet must be a word only with letters and underline symbol
*/

/* TEST 8 (ERROR: The weight of pet must be an integer number)
Enter number of pets: 1
Write type, name, voice and weight of pet (end of the input must be string END):
Cat George meow_meow weight
END
ERROR: The weight of pet must be an integer number > 0
*/

/* TEST 9 (ERROR: name for check must be a word only with letters)
Enter number of pets: 1
Write type, name, voice and weight of pet (end of the input must be string END):
Cat George meow_meow 20
END
Names of pets:
George
Voices of pets:
meow_meow
Enter the name of pet to check:
name1
ERROR: name for check must be a word only with letters
*/

/* TEST 10 (ERROR: there are no pets in array at all)
Enter number of pets: 0
Write type, name, voice and weight of pet (end of the input must be string END):
END
ERROR: there are no pets in array at all
*/


int main()
{

	
	int maxNPets = 0;
	std::cout << "Enter number of pets: ";
	std::cin >> maxNPets;

	try {

		if (!std::cin || maxNPets < 0 || maxNPets > 7)
		{
			throw std::domain_error(ERR_MAX_NUM);
		}

	}
	catch (std::domain_error& gottenError)
	{
		std::cerr << gottenError.what() << "\n";
		return EXIT_FAILURE;
	}

	std::vector<std::string> gottenStrings;
	gottenStrings.clear();
	std::string gottenString = "";

	std::cout << "Write type, name, voice and weight of pet (end of the input must be string END):" << "\n";

	while (gottenString != "END")
	{
		std::cin >> gottenString;
		gottenStrings.push_back(gottenString);
	}

	try {

		if (gottenStrings.size() > (maxNPets * 4 + 1))
		{
			throw std::length_error(ERR_REAL_NUM);
		}

	}
	catch (std::length_error& gottenError)
	{
		std::cerr << gottenError.what() << "\n";
		return EXIT_FAILURE;
	}

	FamilyPets famPets(maxNPets);

	std::vector<std::string> curPetAttrs;
	curPetAttrs.clear();

	enum attrNames { TYPE_OF_PET, NAME_OF_PET, VOICE_OF_PET, WEIGHT_OF_PET, NUM_ATTRS };

	for (int curPetAttr = 0; curPetAttr < (maxNPets * 4) && gottenStrings[curPetAttr] != "END"; curPetAttr++)
	{
		try 
		{

			curPetAttrs.push_back(gottenStrings[curPetAttr]);

			if (curPetAttrs.size() == NUM_ATTRS)
			{
				
				if (curPetAttrs[TYPE_OF_PET] == "Cat" || curPetAttrs[TYPE_OF_PET] == "Dog")
				{
					if (!isCorrectName(curPetAttrs[NAME_OF_PET]))
					{
						throw std::invalid_argument(ERR_INCORRECT_NAME);
					}
					else if (!isCorrectVoice(curPetAttrs[VOICE_OF_PET]))
					{
						throw std::invalid_argument(ERR_INCORRECT_VOICE);
					}
					else if (!isCorrectWeight(curPetAttrs[WEIGHT_OF_PET]))
					{
						throw std::invalid_argument(ERR_INCORRECT_WEIGHT);
					}

					if (curPetAttrs[TYPE_OF_PET] == "Cat")
					{
						Cat curCat(curPetAttrs[NAME_OF_PET], curPetAttrs[VOICE_OF_PET], stoi(curPetAttrs[WEIGHT_OF_PET]));
						famPets = famPets + curCat;
					}
					else if (curPetAttrs[TYPE_OF_PET] == "Dog")
					{
						Dog curDog(curPetAttrs[NAME_OF_PET], curPetAttrs[VOICE_OF_PET], stoi(curPetAttrs[WEIGHT_OF_PET]));
						famPets = famPets + curDog;
					}

				}
			else
			{
				throw std::invalid_argument(ERR_INCORRECT_TYPE);
			}
			curPetAttrs.clear();
			}
		}
		catch (std::invalid_argument& gottenError)
		{
			std::cerr << gottenError.what() << "\n";
			return EXIT_FAILURE;
		}
		catch (std::bad_alloc&)
		{
			std::cerr << ERR_CANT_ALLOC_MEMORY << "\n";
			return EXIT_FAILURE;
		}
	}

	try 
	{
		famPets.getNames();
	}
	catch (std::length_error& gottenError)
	{
		std::cerr << gottenError.what() << "\n";
		return EXIT_FAILURE;
	}

	
	famPets.getVoices();


	try 
	{
		std::cout << "Enter the name of pet to check:" << "\n";
		std::string checkName = "";
		std::cin >> checkName;

		if (!isCorrectName(checkName))
		{
			throw std::invalid_argument(ERR_INCORRECT_CHECK_NAME);
		}

		std::cout << "The number of pets with given name: " << famPets.getNumberRepetitionsName(checkName) << "\n";

		std::cout << "Lightest in weight pet: " << famPets.findTheEasiest() << "\n";

		std::cout << "The info about all pets (type, name, voice, weight): " << "\n";
		std::cout << famPets;
	}
	
	catch (std::invalid_argument& gottenError)
	{
		std::cerr << gottenError.what() << "\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;

}

bool isCorrectName(const std::string gottenName)
{
	for (int curSymb = 0; curSymb < gottenName.length(); curSymb++)
	{
		if (!isalpha(gottenName[curSymb]))
		{
			return false;
		}
	}
	return true;
}


bool isCorrectVoice(const std::string gottenVoice)
{
	for (int curSymb = 0; curSymb < gottenVoice.length(); curSymb++)
	{
		if (!isalpha(gottenVoice[curSymb]) && !(gottenVoice[curSymb] == '_'))
		{
			return false;
		}
	}
	return true;
}

bool isCorrectWeight(const std::string gottenWeight)
{
	for (int curSymb = 0; curSymb < gottenWeight.length(); curSymb++)
	{
		if (!isdigit(gottenWeight[curSymb]) || (gottenWeight[0] == '0'))
		{
			return false;
		}
	}
	return true;
}