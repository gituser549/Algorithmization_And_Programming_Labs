
#include "FrameRectangle.h"
#include "Support.h"

Point FrameRectangle::getPos() const
{
	return pos_;
};

double FrameRectangle::getWidth() const
{
	return width_;
};

double FrameRectangle::getHeight() const
{
	return height_;
};

bool FrameRectangle::areWidthsEqual(const FrameRectangle& exampleFrameRect) const
{
	return areDoublesEqual(width_, exampleFrameRect.width_);
}

bool FrameRectangle::areHeightsEqual(const FrameRectangle& exampleFrameRect) const
{
	return areDoublesEqual(height_, exampleFrameRect.height_);
}

Point FrameRectangle::getLeftLowest() const
{
	return Point(pos_.getX() - width_ / 2.0, pos_.getY() - height_ / 2.0);
}

Point FrameRectangle::getRightHighest() const
{
	return Point(pos_.getX() + width_ / 2.0, pos_.getY() + height_ / 2.0);
}

double FrameRectangle::getArea() const
{
	return width_ * height_;
}