#include "Triangle.h"

const char* ERR_IMPOSSIBLE_TO_CONSTR_TRIANGLE = "ERROR: it is impossible to construct a triangle from given points";
const char* EQUAL_TRIANGLES = "The triangles are equal";
const char* NOT_EQUAL_TRIANGLES = "The triangles are not equal";
const char* FIRST_AREA_LESSER = "The area of the first triangle is less than the second";
const char* FIRST_AREA_NOT_LESSER = "The area of the first triangle is NOT less than the second";
const char* TRIANGLE_MOVED = "Triangle1 moved, new vertices=";


int main()
{


	Triangle triangle1(Point(0, 0), Point(0, 0), Point(0, 0));

	std::cin >> triangle1;

	//std::cout.precision(3);

	try
	{
		if (!triangle1.isTriangle())
		{
			throw std::invalid_argument(ERR_IMPOSSIBLE_TO_CONSTR_TRIANGLE);
		}


		Triangle triangle2(Point(0, 0), Point(0, 0), Point(0, 0));

		std::cin >> triangle2;

		if (!triangle2.isTriangle())
		{
			throw std::invalid_argument(ERR_IMPOSSIBLE_TO_CONSTR_TRIANGLE);
		}

		if (triangle1 == triangle2)
		{

			std::cout << EQUAL_TRIANGLES << "\n";
		}
		else
		{
			std::cout << NOT_EQUAL_TRIANGLES << "\n";
		}

		if (triangle1 < triangle2)
		{
			std::cout << FIRST_AREA_LESSER << "\n";
		}
		else
		{
			std::cout << FIRST_AREA_NOT_LESSER << "\n";
		}

		double numK = 0;
		std::cin >> numK;

		triangle1 += numK;

		std::cout << TRIANGLE_MOVED << triangle1 << "\n";

	}

	catch (const std::invalid_argument& gottenError)
	{

		std::cerr << gottenError.what() << "\n";
		return EXIT_FAILURE;

	}


	return EXIT_SUCCESS;


}