#include <iostream> //cin, cout, cerr
#include <iomanip> // setw
#include <cstring> // strlen
#define LEN_EMPTY_STR 0
#define MAX_LEN 51

int makeUniqString(const char (&sourceStr)[MAX_LEN], char (&outputStr)[MAX_LEN]);
bool isOnlyOne(const char (&sourceStr)[MAX_LEN], char symb);
void sortBubble(char (&sourceStr)[MAX_LEN]);

int main() {
	char sourceStr[MAX_LEN]{ 'a' };
	char outputStr[MAX_LEN]{ 'a' };
	std::cin >> std::setw(MAX_LEN) >> sourceStr;
	if (makeUniqString(sourceStr, outputStr)) {
		for (char symb : outputStr) {
			std::cout << symb;
		}
		std::cout << "\n";
		return EXIT_SUCCESS;
	}
	else {
		return EXIT_FAILURE;
	}
}

int makeUniqString(const char (&sourceStr)[MAX_LEN], char (&outputStr)[MAX_LEN]) {
	try {
		int i = 0;
		for (char symb : sourceStr) {
			if (isOnlyOne(sourceStr, symb)) {
				outputStr[i] = symb;
				i++;
			}
		}
		outputStr[i] = '\0';
		if (strlen(outputStr) == 0) {
			int error_code = 1;
			throw 1;
		}
		sortBubble(outputStr);
		return strlen(outputStr);
	}
	catch (std::invalid_argument) {
		std::cerr << "ERROR: makeUniqString arguments must be two char arrays\n";
		exit(EXIT_FAILURE);
	}
	catch (int error_code) {
		if (error_code == 1) {
			std::cerr << "No unique symbols\n";
			return LEN_EMPTY_STR;
		}
	}
}

bool isOnlyOne(const char (&sourceStr)[MAX_LEN], char symb) {
	try {
		int symbCounter = 0;
		for (char strSymb : sourceStr) {
			if (strSymb == symb) {
				symbCounter++;
			}
		}
		return symbCounter == 1;
	}
	catch (std::invalid_argument) {
		std::cerr << "ERROR: isOnlyOne arguments must be char array and char symbol\n";
		exit(EXIT_FAILURE);
	}
}

void sortBubble(char (&sourceStr)[MAX_LEN]) {
	try {
		bool isSorted = strlen(sourceStr) <= 1;
		while (!isSorted) {
			isSorted = true;
			for (int i = 1; i < strlen(sourceStr); i++) {
				if (sourceStr[i] < sourceStr[i - 1]) {
					char tempForChange = sourceStr[i];
					sourceStr[i] = sourceStr[i - 1];
					sourceStr[i - 1] = tempForChange;
					isSorted = false;
				}
			}
		}
	}
	catch (std::invalid_argument) {
		std::cerr << "ERROR: sortBubble argument must be an array\n";
		exit(EXIT_FAILURE);
	}
}