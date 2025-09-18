
#ifndef PET_H

#define PET_H

#include <string>

class Pet
{
public:
	virtual ~Pet() {};
	virtual std::string getName() const = 0;
	virtual std::string getVoice() const = 0;
};

#endif