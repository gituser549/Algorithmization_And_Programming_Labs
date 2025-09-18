
#include "Triangle.h"


void Triangle::setA(const Point& a)
{
	a_ = a;
}

void Triangle::setB(const Point& b)
{
	b_ = b;
}

void Triangle::setC(const Point& c)
{
	c_ = c;
}

Point Triangle::getA() const
{
	return a_;
}

Point Triangle::getB() const
{
	return b_;
}

Point Triangle::getC() const
{
	return c_;
}

bool Triangle::isTriangle() const
{

	double firstLine = max(3, a_.getDistance(b_), b_.getDistance(c_), c_.getDistance(a_));
	double thirdLine = min(3, a_.getDistance(b_), b_.getDistance(c_), c_.getDistance(a_));
	double secondLine = a_.getDistance(b_) + b_.getDistance(c_) + c_.getDistance(a_) - firstLine - thirdLine;

	bool haveThreeLines = !a_.isEqual(b_) && !b_.isEqual(c_) && !c_.isEqual(a_);
	bool notDegTriangle = !(a_.getX() == b_.getX() && b_.getX() == c_.getX()) && \
		!(a_.getY() == b_.getY() && b_.getY() == c_.getY());


	return (firstLine < (secondLine + thirdLine) && haveThreeLines && notDegTriangle);

}

void Triangle::move(const double numK)
{
	a_.move(numK);
	b_.move(numK);
	c_.move(numK);
}

double Triangle::getPerimeter() const
{
	return a_.getDistance(b_) + b_.getDistance(c_) + c_.getDistance(a_);
}

bool Triangle::isEqual(const Triangle& secondTriangle) const
{
	return a_.isEqual(secondTriangle.a_) && b_.isEqual(secondTriangle.b_) && c_.isEqual(secondTriangle.c_);
}

bool Triangle::operator==(const Triangle& rightTriangle) const
{
	return (this->a_ == rightTriangle.a_ && this->b_ == rightTriangle.b_ && this->c_ == rightTriangle.c_);
}

bool Triangle::operator<(const Triangle& rightTriangle) const
{
	return getSquare(*this) < getSquare(rightTriangle);
}

Triangle& Triangle::operator+=(const double givenNum)
{
	this->a_ = this->a_ + givenNum;
	this->b_ = this->b_ + givenNum;
	this->c_ = this->c_ + givenNum;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Triangle& showPoint)
{
	return (out << showPoint.a_ << "," << showPoint.b_ << "," << showPoint.c_);
}

std::istream& operator>>(std::istream& in, Triangle& setTriangle)
{
	return (in >> setTriangle.a_ >> setTriangle.b_ >> setTriangle.c_);
}

bool isEqualSquare(const Triangle& firstTriangle, const Triangle& secondTriangle)
{
	return getSquare(firstTriangle) == getSquare(secondTriangle);
}

void output(const Triangle& chTriangle)
{

	output(chTriangle.getA());
	std::cout << " ";
	output(chTriangle.getB());
	std::cout << " ";
	output(chTriangle.getC());

}

double getSquare(const Triangle& givenTriangle)
{

	double halfPerimeter = 0, firstLine = 0, secondLine = 0, thirdLine = 0;

	halfPerimeter = givenTriangle.getPerimeter() / 2;
	firstLine = givenTriangle.getA().getDistance(givenTriangle.getB());
	secondLine = givenTriangle.getB().getDistance(givenTriangle.getC());
	thirdLine = givenTriangle.getC().getDistance(givenTriangle.getA());

	double resSquare = halfPerimeter * sqrt((halfPerimeter - firstLine) * (halfPerimeter - secondLine) * (halfPerimeter - thirdLine));

	return resSquare;

}
