#include <iostream> // cout, cerr
#include <fstream> // ifstream, ofstream

const int MAX_LEN = 10;

const char* ERR_OPEN_FILE = "ERROR: can't open the file";
const char* ERR_UNDEF_STR_END = "ERROR: end of the string isn't defined";

const char* IN_FILE = "in.txt";
const char* OUT_FILE = "out.txt";

bool isNotAllSymbUniq(const char* sourceStr);

template<typename T>
void checkOpenFile(T& inResponse);

int main() {
	std::ifstream in;
	std::ofstream out;
	char* sourceStr = nullptr;
	sourceStr = new char[MAX_LEN] {'0'};
	try {
		in.open(IN_FILE);
		checkOpenFile(in);
		out.open(OUT_FILE);
		checkOpenFile(out);
		while (!in.eof()) {	
			char curSymb = in.get();
			int writeInd = 0;
			while (curSymb != '\n' && curSymb != EOF) {
				if ((writeInd + 1) < MAX_LEN) {
					*(sourceStr + writeInd) = curSymb;
					writeInd++;
				}
				curSymb = in.get();		
			}
			*(sourceStr + writeInd) = '\0';
			std::cout << std::boolalpha << isNotAllSymbUniq(sourceStr) << "\n";
			out << std::boolalpha << isNotAllSymbUniq(sourceStr) << "\n";
		}
		delete[] sourceStr;
		in.close();
		out.close();
		return EXIT_SUCCESS;
	}
	catch (const char* errorMessage) {
		delete[] sourceStr;
		in.close();
		out.close();
		std::cerr << errorMessage << "\n";
		return EXIT_FAILURE;
	}
	catch (std::exception gottenException) {
		delete[] sourceStr;
		in.close();
		out.close();
		std::cerr << gottenException.what() << "\n";
		return EXIT_FAILURE;
	}
}

bool isNotAllSymbUniq(const char* sourceStrPtr) {
	bool haveRepeatSymb = false;
	int checkElemInd = 0;
	while (*(sourceStrPtr + checkElemInd) != '\0' && !haveRepeatSymb) {
		int pairElemInd = 0;
		const char* beginStrPtr = sourceStrPtr;
		while (*(beginStrPtr + pairElemInd) != '\0' && !haveRepeatSymb) {
			if ((pairElemInd + 1) >= MAX_LEN) {
				throw ERR_UNDEF_STR_END;
			}
			else if (checkElemInd != pairElemInd && *(beginStrPtr + pairElemInd) == *(sourceStrPtr + checkElemInd)) {
				haveRepeatSymb = true;
			}
			else {
				pairElemInd++;
			}
		}
		checkElemInd++;
	}
	return haveRepeatSymb;
}

template<typename T>
void checkOpenFile(T& inResponse) {
	if (!inResponse) {
		throw ERR_OPEN_FILE;
	}
}