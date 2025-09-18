
#include "CompositeShape.h"
#include "Support.h"

const std::string ERR_CANT_ADD_ANYMORE = "ERROR: the limit of elements in array exceeded";
const std::string ERR_MAX_NUM_OF_ELS = "ERROR: the limit of elements in array can't be less than 1";
const std::string ERR_ZERO_SCALE_FACTOR = "ERROR: scale factor can't be equal to 0";
const std::string ERR_NO_FIGURE_IN_VECTOR = "ERROR: you haven't entered any figures";

const int MIN_NUM_ELS_IN_VECTOR = 1;

CompositeShape::CompositeShape(const int maxNumEls)
{
	
	if (maxNumEls < MIN_NUM_ELS_IN_VECTOR)
	{
		throw std::underflow_error(ERR_MAX_NUM_OF_ELS);
	}
	
	maxNumEls_ = maxNumEls;
	shapes_.clear();
	
}

CompositeShape::CompositeShape(const CompositeShape& exampleCompShape)
{

	maxNumEls_ = exampleCompShape.maxNumEls_;

	for (int shapeInd = 0; shapeInd < exampleCompShape.getNumFigures(); shapeInd++)
	{
		shapes_.push_back(exampleCompShape.shapes_[shapeInd]->clone());	
	}
	
}

CompositeShape::~CompositeShape()
{
	for (int shapeInd = 0; shapeInd < getNumFigures(); shapeInd++)
	{
		delete shapes_[shapeInd];
	}
	shapes_.clear();
}

CompositeShape& CompositeShape::operator+(Shape& gottenFigure)
{
	Rectangle* rectPtr = nullptr;
	Diamond* diamPtr = nullptr;

	if (getNumFigures() < maxNumEls_)
	{
		if (rectPtr = dynamic_cast<Rectangle*>(&gottenFigure))
		{
			rectPtr = new Rectangle(*rectPtr);
			shapes_.push_back(rectPtr);
		}
		else
		{
			diamPtr = dynamic_cast<Diamond*>(&gottenFigure);
			diamPtr = new Diamond(*diamPtr);
			shapes_.push_back(diamPtr);
		}
	}
	else
	{
		throw std::out_of_range(ERR_CANT_ADD_ANYMORE);
	}

	return *this;

}

CompositeShape& CompositeShape::operator+=(Shape& gottenFigure)
{
	Rectangle* rectPtr = nullptr;
	Diamond* diamPtr = nullptr;

	if (getNumFigures() < maxNumEls_)
	{
		if (rectPtr = dynamic_cast<Rectangle*>(&gottenFigure))
		{
			rectPtr = new Rectangle(*rectPtr);
			shapes_.push_back(rectPtr);
		}
		else
		{
			diamPtr = dynamic_cast<Diamond*>(&gottenFigure);
			diamPtr = new Diamond(*diamPtr);
			shapes_.push_back(diamPtr);
		}
	}
	else
	{
		throw std::out_of_range(ERR_CANT_ADD_ANYMORE);
	}

	return *this;

}

FrameRectangle CompositeShape::getFrameRectangle() const
{
	
	if (getNumFigures() < MIN_NUM_ELS_IN_VECTOR)
	{
		throw std::length_error(ERR_NO_FIGURE_IN_VECTOR);
	}

	FrameRectangle curFrameRect = shapes_[0]->getFrameRectangle();
	
	Point leftLowestPt = curFrameRect.getLeftLowest();

	Point rightHighestPt = curFrameRect.getRightHighest();

	double minX = leftLowestPt.getX(), minY = leftLowestPt.getY(), \
		maxX = rightHighestPt.getX(), maxY = rightHighestPt.getY();


	for (int shapeInd = 1; shapeInd < getNumFigures(); shapeInd++)
	{
		curFrameRect = shapes_[shapeInd]->getFrameRectangle();
	

		leftLowestPt = curFrameRect.getLeftLowest();
		rightHighestPt = curFrameRect.getRightHighest();

		minX = min(minX, leftLowestPt.getX());
		minY = min(minY, leftLowestPt.getY());
		
		maxX = max(maxX, rightHighestPt.getX());
		maxY = max(maxY, rightHighestPt.getY());

	}

	return FrameRectangle(maxX-minX, maxY-minY, Point((maxX + minX) / 2, (maxY + minY) / 2));

}


void CompositeShape::move(const Point toPoint)
{

	if (getNumFigures() < MIN_NUM_ELS_IN_VECTOR)
	{
		throw std::length_error(ERR_NO_FIGURE_IN_VECTOR);
	}

	Point compFigCent = getFrameRectangle().getPos();

	double deltaX = toPoint.getX() - compFigCent.getX();
	double deltaY = toPoint.getY() - compFigCent.getY();

	Point curCentPt = Point(0, 0);

	for (int shapeInd = 0; shapeInd < getNumFigures(); shapeInd++)
	{

		curCentPt = shapes_[shapeInd]->getFrameRectangle().getPos();
		shapes_[shapeInd]->move(Point(curCentPt.getX() + deltaX, curCentPt.getY() + deltaY));

	}
}

void CompositeShape::scale(double scaleFactor)
{

	if (getNumFigures() < MIN_NUM_ELS_IN_VECTOR)
	{
		throw std::length_error(ERR_NO_FIGURE_IN_VECTOR);
	}

	Point compFigCent = getFrameRectangle().getPos();
	double newX = 0, newY = 0;

	for (int shapeInd = 0; shapeInd < getNumFigures(); shapeInd++)
	{

		shapes_[shapeInd]->scale(scaleFactor);
		newX = compFigCent.getX() + scaleFactor * \
			(shapes_[shapeInd]->getFrameRectangle().getPos().getX() - compFigCent.getX());
		newY = compFigCent.getY() + scaleFactor * \
			(shapes_[shapeInd]->getFrameRectangle().getPos().getY() - compFigCent.getY());
		shapes_[shapeInd]->move(Point(newX, newY));

	}

}

int CompositeShape::getNumFigures() const
{
	return shapes_.size();
}


void CompositeShape::getInfo() const
{

	if (!getNumFigures())
	{
		throw std::length_error(ERR_NO_FIGURE_IN_VECTOR);
	}

	double sumAreas = 0.0;

	for (int shapeInd = 0; shapeInd < getNumFigures(); shapeInd++)
	{
		shapes_[shapeInd]->getInfo(shapeInd + 1);
		sumAreas += shapes_[shapeInd]->getFrameRectangle().getArea();
	}

	std::cout << "Sum of areas of frameRectangles: " << sumAreas << "\n";
	std::cout << "CompositeShape Center: " << getFrameRectangle().getPos() << "\n";
	std::cout << "CompositeShape width: " << getFrameRectangle().getWidth() << "\n";
	std::cout << "CompositeShape height: " << getFrameRectangle().getHeight() << "\n";
	std::cout << "\n";

}

bool CompositeShape::areCorrectlyMoved(const CompositeShape& exampleCompShape, const Point toPoint) const
{

	if (!getNumFigures())
	{
		throw std::length_error(ERR_NO_FIGURE_IN_VECTOR);
	}

	if (getNumFigures() != exampleCompShape.getNumFigures())
	{
		return false;
	}

	FrameRectangle thisFrameRect = getFrameRectangle();
	FrameRectangle exampleFrameRect = exampleCompShape.getFrameRectangle();

	if (!areDoublesEqual(thisFrameRect.getWidth(), exampleFrameRect.getWidth()) || \
		!areDoublesEqual(thisFrameRect.getHeight(), exampleFrameRect.getHeight()))
	{
		return false;
	}


	for (int shapeInd = 0; shapeInd < getNumFigures(); shapeInd++)
	{
		thisFrameRect = shapes_[shapeInd]->getFrameRectangle();
		exampleFrameRect = shapes_[shapeInd]->getFrameRectangle();
		if (!thisFrameRect.areWidthsEqual(exampleFrameRect) || !thisFrameRect.areHeightsEqual(exampleFrameRect))
		{
			return false;
		}
	}

	return true;

}

bool CompositeShape::areCorrScaledAreas(const CompositeShape& exampleCompShape, const double scaleFactor) const
{

	if (!getNumFigures())
	{
		throw std::length_error(ERR_NO_FIGURE_IN_VECTOR);
	}

	if (areDoublesEqual(scaleFactor, 0.0))
	{
		throw std::invalid_argument(ERR_ZERO_SCALE_FACTOR);
	}
	else if (getNumFigures() != exampleCompShape.getNumFigures())
	{
		return false;
	}


	for (int shapeInd = 0; shapeInd < getNumFigures(); shapeInd++)
	{
		if (!areDoublesEqual(shapes_[shapeInd]->getArea() * scaleFactor * scaleFactor, \
			exampleCompShape.shapes_[shapeInd]->getArea()))
		{
			return false;
		}
	}

	return true;

}

bool CompositeShape::areCorrScaledDists(const CompositeShape& exampleCompShape, const double scaleFactor) const
{

	if (!getNumFigures())
	{
		throw std::length_error(ERR_NO_FIGURE_IN_VECTOR);
	}

	if (!scaleFactor)
	{
		throw std::invalid_argument(ERR_ZERO_SCALE_FACTOR);
	}
	else if (getNumFigures() != exampleCompShape.getNumFigures())
	{
		return false;
	}

	for (int shapeInd = 0; shapeInd < getNumFigures(); shapeInd++)
	{
		double firstDist = shapes_[shapeInd]->getFrameRectangle().getPos().getDistance(getFrameRectangle().getPos());
		double secondDist = exampleCompShape.shapes_[shapeInd]-> \
			getFrameRectangle().getPos().getDistance(getFrameRectangle().getPos());

		if (!areDoublesEqual(firstDist * fabs(scaleFactor), secondDist))
		{
			return false;
		}
	}

	return true;
}

bool CompositeShape::areCorrScaledCenter(const CompositeShape& exampleCompShape) const
{

	if (!getNumFigures())
	{
		throw std::length_error(ERR_NO_FIGURE_IN_VECTOR);
	}

	if (getNumFigures() != exampleCompShape.getNumFigures())
	{
		return false;
	}
	else if (getFrameRectangle().getPos() == exampleCompShape.getFrameRectangle().getPos())
	{
		return true;
	}
	else
	{
		return false;
	}
}