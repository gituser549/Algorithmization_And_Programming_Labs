
#include "Point.h"

class Triangle
{
private:

	Point a_;
	Point b_;
	Point c_;

public:

	Triangle() : a_(Point(0, 0)), b_(Point(0, 1)), c_(Point(1, 0)) {};
	Triangle(const Point& a, const Point& b, const Point& c) : a_(a), b_(b), c_(c) {};
	Triangle(const Triangle& copyFromTriangle) : \
		a_(copyFromTriangle.getA()), b_(copyFromTriangle.getB()), c_(copyFromTriangle.getC()) {};
	~Triangle() {};

	void setA(const Point& a);
	void setB(const Point& b);
	void setC(const Point& c);

	Point getA() const;
	Point getB() const;
	Point getC() const;

	bool isTriangle() const;
	void move(const double numK);
	double getPerimeter() const;
	bool isEqual(const Triangle& secondTriangle) const;

	bool operator==(const Triangle& rightTriangle) const;
	bool operator<(const Triangle& rightTriangle) const;
	Triangle& operator+=(const double givenNum);

	friend std::ostream& operator<<(std::ostream& out, const Triangle& showTriangle);
	friend std::istream& operator>>(std::istream& in, Triangle& setTriangle);

};

bool isEqualSquare(const Triangle& firstTirangle, const Triangle& secondTriangle);
void output(const Triangle& chTriangle);

double getSquare(const Triangle& givenTriangle);