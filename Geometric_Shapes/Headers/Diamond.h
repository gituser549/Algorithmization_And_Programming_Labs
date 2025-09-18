#ifndef DIAMOND_H

#define DIAMOND_H

#include "Shape.h"

class Diamond : public Shape
{
public:

	Diamond(const Point centerPoint, const double horizDiag, const double vertDiag);
	Diamond(const Diamond& exampleDiam);
	~Diamond();

	virtual double getArea() const;
	virtual FrameRectangle getFrameRectangle() const;
	virtual void move(const Point toPoint);
	virtual void scale(double scaleFactor);
	virtual Diamond* clone() const;
	virtual std::string getName() const;
	bool isCorrectlyScaledAreas(const Diamond& exampleDiam, const double scaleFactor) const;
	virtual void getInfo() const;
	virtual void getInfo(const int number) const;
	void getDiamond();

private:
	Point centerPoint_;
	double horizDiag_;
	double vertDiag_;
};

#endif