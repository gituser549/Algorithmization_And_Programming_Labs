#ifndef SHAPE_H
#define SHAPE_H

#include "FrameRectangle.h"
#include <string>

class Shape
{
public:
	virtual ~Shape() {};
	virtual double getArea() const = 0;
	virtual FrameRectangle getFrameRectangle() const = 0;
	virtual void move(const Point toPoint) = 0;
	virtual void scale(const double scalingFactor) = 0;
	virtual Shape* clone() const = 0;
	virtual std::string getName() const = 0;
	virtual void getInfo() const = 0;
	virtual void getInfo(const int number) const = 0;
};

#endif