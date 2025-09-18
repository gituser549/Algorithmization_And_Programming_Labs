#include <iostream>
#include <fstream>
#include <io.h> //access

bool isExpression(const char* str, const int firstCheck, const int rightBorder);
int isTerm(const char* str, const int firstCheckEl);
int isMultiplier(const char* str, const int firstCheckEl);
int isUnsignedInt(const char* str, const int firstCheckEl);
int isIdentifier(const char* str, const int checkEl);
int isLetter(const char* str, const int checkEl);
int isDigit(const char* str, const int checkEl);

int findClosedBracket(const char* str, const int checkEl, int numOpenedBracket);
int recStrLen(const char* str, const int limitSymb, const int checkEl = 0);
bool isEven(const int number);

void initCharArray(char* gottenArray, const int lenArray, const int curSymb = 0);
void freadLine(std::ifstream& in, const char* fileName, char* toStr, const int limitSymb);

const int MAX_LEN = 3;
const int FUNCTION_FAILED_CODE = -1;
const int MIN_LEN_EXPR = 1;

const char* ERR_OPEN_FILE = "ERROR: can't open the file: ";
const char* ERR_UNDEF_STR_END = "ERROR: end of the string isn't defined";
const char* ERR_BAD_NUM_OF_SYMB = "ERROR: number of symbols must be an int number > 0 and < 1000. Line number: ";
const char* ERR_BAD_ALLOC_EXPR = "ERROR: can't allocate so much memory for expression. Line number: ";
const char* ERR_ODD_NUM_OF_LINES = "ERROR: number of lines in file must be even. Line number: ";
const char* ERR_MUST_BE_EXPRESSION = "ERROR: there must be an expression. Line number: ";

const char* START_INFORMATION = "ATTENTION! program works only with strings, which length is lower than 1000";
const char* GOTTEN_EXPRESSION_MESSAGE = "String: ";
const char* RESPONSE_IS_EXPRESSION_MESSAGE = " | isExpression: ";

const char* IN_FILE = "in.txt";
const char* OUT_FILE = "out.txt";

template<typename T>
void checkOpenFile(const T& fileResponse);
void isExists(const char* fileName);

int main()
{
	std::cout << START_INFORMATION << "\n\n";

	std::ifstream in;
	std::ofstream out;

	char strForLimit[MAX_LEN + 1];
	int limitSymb = MAX_LEN;

	char* expression = nullptr;
	int checkedLineNum = 1;
	int numCheckedFile = 1;

	try {

		isExists(IN_FILE);
		in.open(IN_FILE);
		checkOpenFile(in);

		numCheckedFile++;
		isExists(OUT_FILE);
		out.open(OUT_FILE);
		checkOpenFile(out);

		while (!in.eof())
		{
			initCharArray(strForLimit, MAX_LEN);
			freadLine(in, IN_FILE, strForLimit, limitSymb);
			int gottenLimit = atoi(strForLimit);

			if (!gottenLimit || gottenLimit < 0)
			{
				throw std::length_error(ERR_BAD_NUM_OF_SYMB);
			}

			if (in.eof())
			{
				throw std::logic_error(ERR_ODD_NUM_OF_LINES);
			}

			expression = new char[gottenLimit + 1] {'0'};
			initCharArray(expression, gottenLimit);
			checkedLineNum++;

			//test_data for ERR_UNDEF_STR_END
			//char test[5] = { '1', '2', '3', '4', '5' };
			//int factLenExpr = recStrLen(test, 5);

			freadLine(in, IN_FILE, expression, gottenLimit);
			int factLenExpr = recStrLen(expression, gottenLimit);

			if (factLenExpr == FUNCTION_FAILED_CODE)
			{
				throw std::range_error(ERR_UNDEF_STR_END);
			}
			else if (factLenExpr < MIN_LEN_EXPR)
			{
				throw std::invalid_argument(ERR_MUST_BE_EXPRESSION);
			}

			std::cout << GOTTEN_EXPRESSION_MESSAGE << expression\
				<< RESPONSE_IS_EXPRESSION_MESSAGE << std::boolalpha << isExpression(expression, 0, factLenExpr - 1) << "\n";

			out << GOTTEN_EXPRESSION_MESSAGE << expression\
				<< RESPONSE_IS_EXPRESSION_MESSAGE << std::boolalpha << isExpression(expression, 0, factLenExpr - 1) << "\n";

			delete[] expression;
			expression = nullptr;
			checkedLineNum++;

		}
	}
	catch (std::domain_error& errorMessage)
	{
		if (isEven(numCheckedFile))
		{
			delete[] expression;
			std::cerr << errorMessage.what() << OUT_FILE << "\n";
			out << errorMessage.what() << OUT_FILE << "\n";
		}
		else
		{
			std::cerr << errorMessage.what() << IN_FILE << "\n";
			out << errorMessage.what() << IN_FILE << "\n";
		}
		in.close();
		out.close();
		return EXIT_FAILURE;
	}
	catch (std::length_error& errorMessage)
	{
		std::cerr << errorMessage.what() << checkedLineNum << "\n";
		out << errorMessage.what() << checkedLineNum << "\n";
		in.close();
		out.close();
		return EXIT_FAILURE;
	}
	catch (std::logic_error& errorMessage)
	{
		std::cerr << errorMessage.what() << checkedLineNum << "\n";
		out << errorMessage.what() << checkedLineNum << "\n";
		in.close();
		out.close();
		return EXIT_FAILURE;
	}
	catch (std::range_error& errorMessage)
	{
		delete[] expression;
		std::cerr << errorMessage.what() << "\n";
		out << errorMessage.what() << "\n";
		in.close();
		out.close();
		return EXIT_FAILURE;
	}
	catch (std::invalid_argument& errorMessage)
	{
		delete[] expression;
		std::cerr << errorMessage.what() << checkedLineNum << "\n";
		out << errorMessage.what() << checkedLineNum << "\n";
		in.close();
		out.close();
		return EXIT_FAILURE;
	}
	catch (std::bad_alloc&)
	{
		delete[] expression;
		std::cerr << ERR_BAD_ALLOC_EXPR << checkedLineNum << "\n";
		out << ERR_BAD_ALLOC_EXPR << checkedLineNum << "\n";
		in.close();
		out.close();
		return EXIT_FAILURE;
	}

	in.close();
	out.close();
	return EXIT_SUCCESS;
}

bool isExpression(const char* str, const int firstCheck, const int rightBorder)
{
	int checkCurRes = isTerm(str, firstCheck);
	if (checkCurRes > FUNCTION_FAILED_CODE)
	{
		if (checkCurRes == rightBorder)
		{
			return true;
		}
		else if (str[checkCurRes + 1] == '+' || str[checkCurRes + 1] == '-')
		{
			return isExpression(str, checkCurRes + 2, rightBorder);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}


int isTerm(const char* str, const int firstCheckEl)
{
	int checkCurRes = isMultiplier(str, firstCheckEl);
	if (checkCurRes > FUNCTION_FAILED_CODE)
	{
		if (str[checkCurRes + 1] == '*')
		{
			return isTerm(str, checkCurRes + 2);
		}
		else
		{
			return checkCurRes;
		}
	}
	/*
	else if (str[firstCheckEl] == '')
	{
		()
	}
	*/
	else
	{
		return FUNCTION_FAILED_CODE;
	}
}

int isMultiplier(const char* str, const int firstCheckEl)
{
	if (isUnsignedInt(str, firstCheckEl) > FUNCTION_FAILED_CODE)
	{
		return isUnsignedInt(str, firstCheckEl);
	}
	else if (isIdentifier(str, firstCheckEl) > FUNCTION_FAILED_CODE)
	{
		return isIdentifier(str, firstCheckEl);
	}
	else if (str[firstCheckEl] == '(')
	{
		int rightBorder = findClosedBracket(str, firstCheckEl, 0);
		if (rightBorder > FUNCTION_FAILED_CODE)
		{
			if (isExpression(str, firstCheckEl + 1, rightBorder - 1))
			{
				return rightBorder;
			}
			else
			{
				return FUNCTION_FAILED_CODE;
			}
		}
		else
		{
			return FUNCTION_FAILED_CODE;
		}

	}
	else
	{
		return FUNCTION_FAILED_CODE;
	}
}

int isUnsignedInt(const char* str, const int firstCheckEl)
{
	//std::cout << "hello";
	if (isDigit(str, firstCheckEl) == FUNCTION_FAILED_CODE)
	{
		if (firstCheckEl >= 1 && isDigit(str, firstCheckEl - 1) > FUNCTION_FAILED_CODE)
		{
			return firstCheckEl - 1;
		}
		else
		{
			return FUNCTION_FAILED_CODE;
		}
	}
	return isUnsignedInt(str, firstCheckEl + 1);
}

int isIdentifier(const char* str, const int checkEl)
{
	return (isLetter(str, checkEl) > FUNCTION_FAILED_CODE) ? checkEl : FUNCTION_FAILED_CODE;
}

int isLetter(const char* str, const int checkEl)
{
	return (str[checkEl] == 'x' || str[checkEl] == 'y' || str[checkEl] == 'z') ? checkEl : FUNCTION_FAILED_CODE;
}

int isDigit(const char* str, const int checkEl)
{
	return (str[checkEl] == '0' || str[checkEl] == '1') ? checkEl : FUNCTION_FAILED_CODE;
}

int findClosedBracket(const char* str, const int checkEl, int numOpenedBracket)
{
	if (str[checkEl] == '\0')
	{
		return FUNCTION_FAILED_CODE;
	}
	else if (str[checkEl] == '(')
	{
		numOpenedBracket++;
	}
	else if (str[checkEl] == ')')
	{
		numOpenedBracket--;
		if (!numOpenedBracket)
		{
			return checkEl;
		}
	}
	return findClosedBracket(str, checkEl + 1, numOpenedBracket);
}

int recStrLen(const char* str, const int limitSymb, const int checkEl)
{
	if (str[checkEl] == '\0')
	{
		return checkEl;
	}
	else if (checkEl == limitSymb)
	{
		return FUNCTION_FAILED_CODE;
	}
	else
	{
		return recStrLen(str, limitSymb, checkEl + 1);
	}
}

bool isEven(const int number)
{
	return (number % 2 == 0);
}

void initCharArray(char* gottenArray, const int lenArray, const int curSymb)
{
	if (curSymb == lenArray)
	{
		gottenArray[curSymb] = '\0';
		return;
	}
	else
	{
		gottenArray[curSymb] = '1';
		return initCharArray(gottenArray, lenArray, curSymb + 1);
	}
}

void freadLine(std::ifstream& in, const char* fileName, char* toStr, const int limitSymb)
{
	char curSymb = in.get();
	int writeInd = 0;
	while (curSymb != '\n' && curSymb != EOF)
	{
		while (curSymb == ' ')
		{
			curSymb = in.get();
		}
		if (writeInd < limitSymb && curSymb != '\n')
		{
			*(toStr + writeInd) = curSymb;
			writeInd++;
		}
		if (curSymb != '\n')
		{
			curSymb = in.get();
		}
	}
	*(toStr + writeInd) = '\0';
	return;
}

template<typename T>
void checkOpenFile(const T& fileResponse) {
	if (!fileResponse) {
		throw std::domain_error(ERR_OPEN_FILE);
	}
}

void isExists(const char* fileName)
{
	if (_access(fileName, 0) == FUNCTION_FAILED_CODE)
	{
		throw std::domain_error(ERR_OPEN_FILE);
	}
}