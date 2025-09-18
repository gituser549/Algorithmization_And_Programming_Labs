#include <iostream> // cout, cin, cerr, fixed
#include <iomanip> // setprecision, setw
#include <cmath> // fabs, cos

using l_dbl = long double;
using fl = float;

l_dbl calculateCosTR(l_dbl X, l_dbl nomError, int numberMax);

int main() {
	l_dbl nomError = 0, lBorder = 0, rBorder = 0, step = 0;
	int numberMax = 0;
	std::cout << "Enter nominal error (float number > 0):\n";
	if (!(std::cin >> nomError) || nomError <= 0) {
		std::cerr << "\nERROR: nominal error must be a float number > 0\n";
		return EXIT_FAILURE;
	}
	std::cout << "Enter max number of terms (int number >= 1):\n";
	if (!(std::cin >> numberMax) || numberMax <= 1) {
		std::cerr << "\nERROR: max number of terms must be an integer number >= 1\n";
		return EXIT_FAILURE;
	}
	std::cout << "Enter left border and right border of the interval (both must be float numbers between -1 and 1):\n";
	if (!(std::cin >> lBorder) || !(std::cin >> rBorder) || lBorder <= -1 || rBorder <= -1 || lBorder >= 1 || rBorder >= 1) {
		std::cerr << "\nERROR: both borders must be float numbers between -1 and 1\n";
		return EXIT_FAILURE;
	}
	if (lBorder > rBorder) {
		std::cerr << "\nERROR: left border must be <= right border\n";
		return EXIT_FAILURE;
	}
	std::cout << "Enter step of the interval (float number):\n";
	if (!(std::cin >> step) || step <= 0) {
		std::cerr << "\nERROR: step must be a float number > 0\n";
		return EXIT_FAILURE;
	}
	l_dbl X = lBorder;
	std::cout << "\n" << std::setw(11) << "THE VALUE OF X" << std::setw(25) << "THE VALUE OF COS(X)";
	std::cout << std::setw(31) << "THE VALUE OF STD COS(X)\n\n";
	for (X; X <= rBorder; X += step) {
		l_dbl rescalculateCosTR = calculateCosTR(X, nomError, numberMax);
		std::cout << std::setw(12) << std::fixed << std::setprecision(7) << X;
		std::cout << std::setw(22) << std::fixed << std::setprecision(7) << rescalculateCosTR;
		std::cout << std::setw(27) << std::fixed << std::setprecision(7) << std::cos(X) << "\n\n";
	}
	if (static_cast<fl>(X - step) < (rBorder)) {
		std::cerr << "WARNING: haven't checked the right border of the interval (last checked X = " \
			<< std::fixed << std::setprecision(7) << X - step << ");\n";
	}
	return EXIT_SUCCESS;
}

l_dbl calculateCosTR(l_dbl X, l_dbl nomError, int numberMax) {
	const l_dbl POWER_AND_FACT_STEP = 2.0;
	l_dbl numTerm = 1, denTerm = 1, fullTerm = 0, numFact = 0;
	for (int cTerm = 0; cTerm < numberMax; cTerm++) {
		fullTerm += (cTerm % 2 == 0) ? numTerm / denTerm : -numTerm / denTerm;
		numTerm *= X * X;
		numFact += POWER_AND_FACT_STEP;
		denTerm *= (numFact - 1) * numFact;
	}
	l_dbl absError = std::fabs(numTerm / denTerm);
	if (static_cast<fl>(absError) > nomError) {
		std::cerr << std::setw(52) << "WARNING: haven't reached the nominal error (X = " << std::fixed \
			<< std::setprecision(7) << X << ");\n\n";
	}
	return fullTerm;
}