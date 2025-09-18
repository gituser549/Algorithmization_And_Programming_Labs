
#include "Rectangle.h"
#include "Support.h"
#include <iomanip>

const std::string ERR_CONSTR_X = "ERROR: leftLowest point coordinate x must be < rightHighest point coordinate x";
const std::string ERR_CONSTR_Y = "ERROR: leftLowest point coordinate y must be < rightHighest point coordinate y";

const std::string ERR_ZERO_SCALE_FACTOR = "ERROR: scale factor can't be equal to 0";
const std::string ERR_NUM_OF_FIGURE = "ERROR: number of figure must be >= 0";
const std::string ERR_INCORRECT_COORDINATES = "ERROR: only numbers can be coordinates";

const std::string RECTANGLE_NAME = "RECTANGLE";

Rectangle::Rectangle(const Point leftLowest, const Point rightHighest)
{
	if (leftLowest.getX() > rightHighest.getX() || areDoublesEqual(leftLowest.getX(), rightHighest.getX()))
	{
		throw std::logic_error(ERR_CONSTR_X);
	}
	else if (leftLowest.getY() >= rightHighest.getY() || areDoublesEqual(leftLowest.getY(), rightHighest.getY()))
	{
		throw std::logic_error(ERR_CONSTR_Y);
	}

	leftLowest_ = leftLowest;
	rightHighest_ = rightHighest;
	centerPoint_ = Point((rightHighest.getX() + leftLowest.getX()) / 2, (rightHighest.getY() + leftLowest.getY()) / 2);

}

Rectangle::Rectangle(const Rectangle& exampleRect)
{
	leftLowest_ = exampleRect.leftLowest_;
	rightHighest_ = exampleRect.rightHighest_; 
	centerPoint_ = exampleRect.centerPoint_;
}

Rectangle::~Rectangle() {};

double Rectangle::getArea() const
{
	Point rightLowest(rightHighest_.getX(), leftLowest_.getY());
	return leftLowest_.getDistance(rightLowest) * rightHighest_.getDistance(rightLowest);
}

FrameRectangle Rectangle::getFrameRectangle() const 
{
	Point rightLowest(rightHighest_.getX(), leftLowest_.getY());
	return FrameRectangle(leftLowest_.getDistance(rightLowest), rightHighest_.getDistance(rightLowest), \
		Point(centerPoint_));
}


void Rectangle::move(const Point toPoint) 
{
	double deltaX = toPoint.getX() - centerPoint_.getX();
	double deltaY = toPoint.getY() - centerPoint_.getY();
	leftLowest_ = Point(leftLowest_.getX() + deltaX, leftLowest_.getY() + deltaY);
	rightHighest_ = Point(rightHighest_.getX() + deltaX, rightHighest_.getY() + deltaY);
	centerPoint_ = toPoint;
}

void Rectangle::scale(const double scaleFactor)
{
	if (!areDoublesEqual(scaleFactor, 0.0))
	{
		
		leftLowest_ = centerPoint_ + (leftLowest_ - centerPoint_) * scaleFactor;
		rightHighest_ = centerPoint_ + (rightHighest_ - centerPoint_) * scaleFactor;

		if (scaleFactor < 0)
		{
			Point temp(0.0, 0.0);
			temp = leftLowest_;
			leftLowest_ = rightHighest_;
			rightHighest_ = temp;
		}

	}
	else
	{
		throw std::invalid_argument(ERR_ZERO_SCALE_FACTOR);
	}

}


Rectangle* Rectangle::clone() const 
{
	return new Rectangle(*this);
}


std::string Rectangle::getName() const 
{
	return RECTANGLE_NAME;
}

bool Rectangle::isCorrectlyScaledAreas(const Rectangle& exampleRect, const double scaleFactor) const
{
	return areDoublesEqual(getArea() * scaleFactor * scaleFactor, exampleRect.getArea());
}

void Rectangle::getInfo() const
{
	//std::cout << getName() << " " << std::fixed << std::setprecision(1) << getArea() << " " << \ 
	//std::fixed << std::setprecision(1) << getFrameRectangle().getLeftLowest() << " " << \
	//std::fixed << std::setprecision(1) << getFrameRectangle().getRightHighest() << "\n\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Name: " << getName() << "\n";
	std::cout << "Area: " << getArea() << "\n";
	std::cout << "Center point of figure: " << getFrameRectangle().getPos() << "\n";
	std::cout << "Left lowest point of figure: " <<  leftLowest_ << "\n";
	std::cout << "Right highest point of figure: " <<  rightHighest_ << "\n";
	std::cout << "Left lowest point of frameRectangle: " << getFrameRectangle().getLeftLowest() << "\n";
	std::cout << "Right highest point of frameRectangle: " << getFrameRectangle().getRightHighest() << "\n";
	std::cout << "Area of frameRectangle: " << getFrameRectangle().getArea() << "\n";
	std::cout << "\n";
}

void Rectangle::getInfo(const int number) const
{

	if (number < 0)
	{
		throw std::invalid_argument(ERR_NUM_OF_FIGURE);
	}

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Figure number: " << number << "\n";
	std::cout << "Name: " << getName() << "\n";
	std::cout << "Area: " << getArea() << "\n";
	std::cout << "Center point of figure: " << getFrameRectangle().getPos() << "\n";
	std::cout << "Left lowest point of figure: " << leftLowest_ << "\n";
	std::cout << "Right highest point of figure: " << rightHighest_ << "\n";
	std::cout << "Left lowest point of frameRectangle: " << \
		getFrameRectangle().getLeftLowest() << "\n";
	std::cout << "Right highest point of frameRectangle: " << \
		getFrameRectangle().getRightHighest() << "\n";
	std::cout << "Area of frameRectangle: " << \
		getFrameRectangle().getArea() << "\n";
	std::cout << "\n";

}

void Rectangle::getRectangle()
{

	Point leftLowestPt(0.0, 0.0);
	Point rightHighestPt(0.0, 0.0);

	std::cout << "Enter left lowest point of rectangle: ";
	std::cin >> leftLowestPt;

	if (!std::cin)
	{
		throw std::invalid_argument(ERR_INCORRECT_COORDINATES);
	}

	std::cout << "Enter right highest point of rectangle: ";
	std::cin >> rightHighestPt;

	if (!std::cin)
	{
		throw std::invalid_argument(ERR_INCORRECT_COORDINATES);
	}

	std::cout << "\n";

	*this = Rectangle(leftLowestPt, rightHighestPt);

}
