#ifndef FRAME_RECTANGLE_H
#define FRAME_RECTANGLE_H

#include "Point.h"

class FrameRectangle 
{
public:

	FrameRectangle(const double width, const double height, const Point pos) : width_(width), height_(height), pos_(pos) {};
	FrameRectangle(const FrameRectangle& exampleFrameRect) : width_(exampleFrameRect.width_), \
		height_(exampleFrameRect.height_), pos_(exampleFrameRect.pos_) {};
	~FrameRectangle() {};

	Point getPos() const;
	double getWidth() const;
	double getHeight() const;
	bool areWidthsEqual(const FrameRectangle& exampleFrameRect) const;
	bool areHeightsEqual(const FrameRectangle& exampleFrameRect) const;
	Point getLeftLowest() const;
	Point getRightHighest() const;
	double getArea() const;

private:
	double width_;
	double height_;
	Point pos_;
};

#endif