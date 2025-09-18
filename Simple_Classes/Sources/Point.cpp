
#include "Point.h"


void Point::setX(const double x)
{
	x_ = x;
}

void Point::setY(const double y)
{
	y_ = y;
}

double Point::getX() const
{
	return x_;
}

double Point::getY() const
{
	return y_;
}

bool Point::isEqual(const Point& secondPoint) const
{
	return (x_ == secondPoint.x_ && y_ == secondPoint.y_);
}

double Point::getDistance(const Point& secondPoint) const
{
	return sqrt((x_ - secondPoint.x_)*(x_ - secondPoint.x_) + (y_ - secondPoint.y_)*(y_ - secondPoint.y_));
}

void Point::move(const double numK)
{
	x_ += numK;
	y_ += numK;
}

bool Point::operator==(const Point& rightPoint) const
{
	return this->x_ == rightPoint.x_ && this->y_ == rightPoint.y_;
}

bool Point::operator<(const Point& rightPoint) const
{
	return (this->x_ * this->x_ + this->y_ * this->y_ < \
		(rightPoint.x_ * rightPoint.x_ + rightPoint.y_ * rightPoint.y_));
}

Point Point::operator+(const double givenNum) const
{
	return Point(x_ + givenNum, y_ + givenNum);
}

std::ostream& operator<<(std::ostream& out, const Point& showPoint)
{
	return (out << "(" << showPoint.x_ << "," << showPoint.y_ << ")");
}

std::istream& operator>>(std::istream& in, Point& setPoint) 
{
	return (in >> setPoint.x_ >> setPoint.y_);
}


bool isPointInCircle(const Point& checkPoint, const double radius)
{
	Point centerCircle(0, 0);
	return (checkPoint.getDistance(centerCircle) <= radius);
}

void output(const Point& checkPoint)
{
	std::cout << "(" << checkPoint.getX() << "," << checkPoint.getY() << ")";
}

void input(Point& inputPoint)
{

	double x = 0, y = 0;
	std::cin >> x >> y;
	inputPoint.setX(x);
	inputPoint.setY(y);

}

/*double max(double num1, double num2)
{
	return (num1 > num2) ? num1 : num2;
}

double min(double num1, double num2)
{
	return (num1 < num2) ? num1 : num2;
}*/

double max(int count, ...)
{

	va_list args;
	va_start(args, count);

	double firEl = va_arg(args, double);
	double secEl = 0;

	for (int consoleInd = 1; consoleInd < count; consoleInd++)
	{

		secEl = va_arg(args, double);
		firEl = (firEl > secEl) ? firEl : secEl;

	}
	
	va_end(args);

	return firEl; 

}

double min(int count, ...)
{

	va_list args;
	va_start(args, count);

	double firEl = va_arg(args, double);
	double secEl = 0;

	for (int consoleInd = 1; consoleInd < count; consoleInd++)
	{

		secEl = va_arg(args, double);
		firEl = (firEl < secEl) ? firEl : secEl;

	}

	va_end(args);

	return firEl;


}