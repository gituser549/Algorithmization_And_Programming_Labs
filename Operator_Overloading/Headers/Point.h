
#include <cmath>
#include <iostream>
#include <cstdarg>

class Point
{
private:

	double x_;
	double y_;

public:

	Point() : x_(0), y_(0) {};
	Point(double x, double y) : x_(x), y_(y) {};
	Point(const Point& copyFromPoint) : x_(copyFromPoint.getX()), y_(copyFromPoint.getY()) {};
	~Point() {};

	void setX(const double x);
	void setY(const double y);
	double getX() const;
	double getY() const;
	bool isEqual(const Point& secondPoint) const;
	double getDistance(const Point& secondPoint) const;
	void move(const double k);

	bool operator==(const Point& rightPoint) const;
	bool operator<(const Point& rightPoint) const;
	Point operator+(const double givenNum) const;

	friend std::ostream& operator<<(std::ostream& out, const Point& showPoint);
	friend std::istream& operator>>(std::istream& in, Point& setPoint);

};

bool isPointInCircle(const Point& checkPoint, const double radius);
void output(const Point& checkPoint);
void input(Point& inputPoint);

//double max(double num1, double num2);
double max(int count, ...);
//double min(double num1, double num2);
double min(int count, ...);