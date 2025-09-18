#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:

	Rectangle(const Point leftLowest, const Point rightHighest);
	Rectangle(const Rectangle& exampleRect);
	~Rectangle();

	virtual double getArea() const;
	virtual FrameRectangle getFrameRectangle() const;
	virtual void move(const Point toPoint);
	virtual void scale(const double scaleFactor);
	virtual Rectangle* clone() const;
	virtual std::string getName() const;
	bool isCorrectlyScaledAreas(const Rectangle& exampleRect, const double scaleFactor) const;
	virtual void getInfo() const;
	virtual void getInfo(const int number) const;
	void getRectangle();

private:
	Point leftLowest_;
	Point rightHighest_;
	Point centerPoint_;
};

#endif