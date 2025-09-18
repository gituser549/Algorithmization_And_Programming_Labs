
#include "Diamond.h"
#include "Support.h"
#include <iomanip>

const std::string ERR_HORIZ_DIAG_INCORRECT = "ERROR: the length of horizontal diagonal can't be <= 0";
const std::string ERR_VERT_DIAG_INCORRECT = "ERROR: the length of vertical diagonal can't be <= 0";

const std::string ERR_ZERO_SCALE_FACTOR = "ERROR: scale factor can't be equal to 0";
const std::string ERR_NUM_OF_FIGURE = "ERROR: number of figure must be >= 0";
const std::string ERR_INCORRECT_COORDINATES = "ERROR: only numbers can be coordinates";
const std::string ERR_INCORRECT_DIAGONAL = "ERROR: the length of diagonal must be a number";

const std::string DIAMOND_NAME = "DIAMOND";

Diamond::Diamond(const Point centerPoint, const double horizDiag, const double vertDiag)
{

	if (horizDiag < 0 || areDoublesEqual(vertDiag, 0.0))
	{
		throw std::logic_error(ERR_HORIZ_DIAG_INCORRECT);
	}
	else if (vertDiag < 0.0 || areDoublesEqual(vertDiag, 0.0))
	{
		throw std::logic_error(ERR_VERT_DIAG_INCORRECT);
	}

	centerPoint_ = centerPoint;
	horizDiag_ = horizDiag;
	vertDiag_ = vertDiag;

}

Diamond::Diamond(const Diamond& exampleDiam)
{
	centerPoint_ = exampleDiam.centerPoint_;
	horizDiag_ = exampleDiam.horizDiag_;
	vertDiag_ = exampleDiam.vertDiag_;
}

Diamond::~Diamond() {};

double Diamond::getArea() const
{
	return horizDiag_ * vertDiag_ / 2.0;
}

FrameRectangle Diamond::getFrameRectangle() const
{
	return FrameRectangle(horizDiag_, vertDiag_, centerPoint_);
}

void Diamond::move(const Point toPoint)
{
	centerPoint_ = toPoint;
}

void Diamond::scale(const double scaleFactor)
{
	if (areDoublesEqual(scaleFactor, 0.0))
	{
		throw std::invalid_argument(ERR_ZERO_SCALE_FACTOR);
	}
	horizDiag_ = horizDiag_ * abs(scaleFactor);
	vertDiag_ = vertDiag_ * abs(scaleFactor);
}

Diamond* Diamond::clone() const
{
	return new Diamond(*this);
}

std::string Diamond::getName() const
{
	return DIAMOND_NAME;
}

bool Diamond::isCorrectlyScaledAreas(const Diamond& exampleDiam, const double scaleFactor) const
{
	return areDoublesEqual(getArea() * scaleFactor * scaleFactor, exampleDiam.getArea());
}

void Diamond::getInfo() const
{

	//std::cout << getName() << " " << std::fixed << std::setprecision(1) << getArea() << " " << \ 
	// std::fixed << std::setprecision(1) getFrameRectangle().getLeftLowest() << " " << \
	// std::fixed << std::setprecision(1) << getFrameRectangle().getRightHighest() << "\n\n";

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Name: " << getName() << "\n";
	std::cout << "Area: " << std::fixed << getArea() << "\n";
	std::cout << "Center point of figure: " << centerPoint_ << "\n";
	std::cout << "Horizontal diagonal length: " << horizDiag_ << "\n";
	std::cout << "Vertical diagonal length: " << vertDiag_ << "\n";
	std::cout << "Left lowest point of frameRectangle: " << getFrameRectangle().getLeftLowest() << "\n";
	std::cout << "Right highest point of frameRectangle: " << getFrameRectangle().getRightHighest() << "\n";
	std::cout << "Area of frameRectangle: " << getFrameRectangle().getArea() << "\n";
	std::cout << "\n";

}

void Diamond::getInfo(const int number) const
{

	if (number < 0)
	{
		throw std::invalid_argument(ERR_NUM_OF_FIGURE);
	}

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Figure number: " << number << "\n";
	std::cout << "Name: " << getName() << "\n";
	std::cout << "Area: " << getArea() << "\n";
	std::cout << "Center point of figure: " << centerPoint_ << "\n";
	std::cout << "Horizontal diagonal length: " << horizDiag_ << "\n";
	std::cout << "Vertical diagonal length: " << vertDiag_ << "\n";
	std::cout << "Left lowest point of frameRectangle: " << \
		getFrameRectangle().getLeftLowest() << "\n";
	std::cout << "Right highest point of frameRectangle: " << \
		getFrameRectangle().getRightHighest() << "\n";
	std::cout << "Area of frameRectangle: " << \
		getFrameRectangle().getArea() << "\n";
	std::cout << "\n";

}

void Diamond::getDiamond()
{

	Point centerPt(0.0, 0.0);
	double horizDiag = 0.0, vertDiag = 0.0;

	std::cout << "Enter center point of diamond: ";
	std::cin >> centerPt;

	if (!std::cin)
	{
		throw std::invalid_argument(ERR_INCORRECT_COORDINATES);
	}

	std::cout << "Enter horizontal diagonal of diamond: ";
	std::cin >> horizDiag;

	if (!std::cin)
	{
		throw std::invalid_argument(ERR_INCORRECT_DIAGONAL);
	}

	std::cout << "Enter vertical diagonal of diamond: ";
	std::cin >> vertDiag;

	if (!std::cin)
	{
		throw std::invalid_argument(ERR_INCORRECT_DIAGONAL);
	}

	std::cout << "\n";

	*this = Diamond(centerPt, horizDiag, vertDiag);

}