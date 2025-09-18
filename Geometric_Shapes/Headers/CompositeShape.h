
#ifndef COMPOSITE_SHAPE_H

#define COMPOSITE_SHAPE

#include "Rectangle.h"
#include "Diamond.h"
#include <vector>


class CompositeShape
{
public:

	CompositeShape(const int maxNumEls);
	CompositeShape(const CompositeShape& exampleCompShape);
	~CompositeShape();
	CompositeShape& operator+(Shape& gottenFigure);
	CompositeShape& operator+=(Shape& gottenFigure);

	FrameRectangle getFrameRectangle() const;
	void move(const Point toPoint);
	void scale(double scaleFactor);

	int getNumFigures() const;
	void getInfo() const;
	bool areCorrectlyMoved(const CompositeShape& exampleCompShape, const Point toPoint) const;
	bool areCorrScaledAreas(const CompositeShape& exampleCompShape, const double scaleFactor) const;
	bool areCorrScaledDists(const CompositeShape& exampleCompShape, const double scaleFactor) const;
	bool areCorrScaledCenter(const CompositeShape& exampleCompShape) const;

private:
	int maxNumEls_;
	std::vector<Shape*> shapes_;
};

#endif