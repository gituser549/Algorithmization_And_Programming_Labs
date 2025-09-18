
#include "Support.h"

#include <iostream>
#include <cmath>
#include <limits>

bool areDoublesEqual(const double fir, const double sec)
{
	return std::fabs(fir - sec) < std::numeric_limits<double>::epsilon();
}

void pressAnyKeyToContinue()
{
	std::cout << "Press any key to continue" << "\n";
	std::cin.ignore();
	std::cin.get();
}

void clearConsole()
{
	std::cout << "\033[2J\033[H";
}

void clearConsoleErr()
{
	std::cerr << "\033[2J\033[H";
}

double min(const double fir, const double sec)
{
	if (fir < sec)
	{
		return fir;
	}
	else
	{
		return sec;
	}
}

double max(const double fir, const double sec)
{
	if (fir > sec)
	{
		return fir;
	}
	else
	{
		return sec;
	}
}