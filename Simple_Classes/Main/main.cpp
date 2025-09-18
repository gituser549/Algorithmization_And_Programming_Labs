#include "Triangle.h"

const char* ERR_IMPOSSIBLE_TO_CONSTR_TRIANGLE = "ERROR: it is impossible to construct a triangle from given points";
const char* SHOW_PERIMETER_R = "perimeterR: ";
const char* SHOW_PERIMETER_P = "perimeterP: ";
const char* EQUAL_TRIANGLES = "The triangles are equal";
const char* NOT_EQUAL_TRIANGLES = "The triangles are not equal";
const char* EQUAL_AREAS = "The areas are equal";
const char* NOT_EQUAL_AREAS = "The areas are not equal";
const char* TRIANGLE_MOVED = "TriangleP moved, new vertices=";


int main()
{

	Point firPt(0, 0), secPt(0, 0), thPt(0, 0);


	input(firPt);
	//std::cin >> firPt;
	input(secPt);
	//std::cin >> secPt;
	input(thPt);
	//std::cin >> thPt;

	Triangle triangleR(firPt, secPt, thPt);

	std::cout.precision(3);

	try
	{
		if (!triangleR.isTriangle())
		{
			throw std::invalid_argument(ERR_IMPOSSIBLE_TO_CONSTR_TRIANGLE);
		}
		else
		{
			std::cout << SHOW_PERIMETER_R << triangleR.getPerimeter() << "\n";
		}

		input(firPt);
		//std::cin >> firPt;
		input(secPt);
		//std::cin >> secPt;
		input(thPt);
		//std::cin >> thPt;

		Triangle triangleP(firPt, secPt, thPt);

		if (!triangleP.isTriangle())
		{
			throw std::invalid_argument(ERR_IMPOSSIBLE_TO_CONSTR_TRIANGLE);
		}
		else
		{
			std::cout << SHOW_PERIMETER_P << triangleP.getPerimeter() << "\n";
		}

		if (triangleR.isTriangle() && triangleP.isTriangle())
		{

			if (triangleR.isEqual(triangleP))
			{
				std::cout << EQUAL_TRIANGLES << "\n";
			}
			else
			{
				std::cout << NOT_EQUAL_TRIANGLES << "\n";
			}

			if (isEqualSquare(triangleR, triangleP))
			{
				std::cout << EQUAL_AREAS << "\n";
			}
			else
			{
				std::cout << NOT_EQUAL_AREAS << "\n";
			}

		}

		if (triangleP.isTriangle())
		{

			double forMove = 0;
			std::cin >> forMove;
			triangleP.move(forMove);
			std::cout << TRIANGLE_MOVED;
			output(triangleP);
			std::cout << "\n";

		}

	}

	catch (const std::invalid_argument& gottenError)
	{

		std::cerr << gottenError.what() << "\n";
		return EXIT_FAILURE;

	}


	return EXIT_SUCCESS;


}

