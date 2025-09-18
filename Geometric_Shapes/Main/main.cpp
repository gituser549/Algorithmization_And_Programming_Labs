
#include <iostream>
#include <string>
#include "Shape.h"
#include "Rectangle.h";
#include "Diamond.h"
#include "CompositeShape.h"
#include "Support.h"

const std::string ERR_INCORRECT_TASK_NAME = "ERROR: you should enter only A1, A2, A3 or END";
const std::string ERR_INCORRECT_TYPE_NAME = "ERROR: you should enter only Rect or Diam";
const std::string ERR_INCORRECT_COORDINATES = "ERROR: only numbers can be coordinates";
const std::string ERR_INCORRECT_SCALE_FACTOR = "ERROR: scale factor must be a number that don't equal to 0";
const std::string ERR_CANT_ALLOC_SO_MUCH_MEMORY = "ERROR: can't allocate so much memory for vector";
const std::string ERR_CANT_ALLOC_MEMORY_FIGURE = "ERROR: can't allocate memory to clone figure";
const std::string ERR_INCORRECT_NUMBER = "ERROR: only numbers can be max number of elements";

const std::string A1_SIGNAL = "A1";
const std::string A2_SIGNAL = "A2";
const std::string A3_SIGNAL = "A3";

const std::string RECT_SIGNAL = "Rect";
const std::string DIAM_SIGNAL = "Diam";
const std::string END_SIGNAL = "END";

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	clearConsole();

	std::string taskName = "";

	while (taskName != END_SIGNAL)
	{
		try
		{
			std::cout << "Enter A1, A2, A3, or END to start testing branch of the program or to end testing: ";
			std::cin >> taskName;

			if (taskName != A1_SIGNAL && taskName != A2_SIGNAL && taskName != A3_SIGNAL && taskName != END_SIGNAL)
			{
				throw std::logic_error(ERR_INCORRECT_TASK_NAME);
			}

			clearConsole();

		}
		catch (std::logic_error& gottenError)
		{
			clearConsoleErr();
			std::cerr << gottenError.what() << "\n";
			return EXIT_FAILURE;
		}

		if (taskName == A1_SIGNAL)
		{
			try
			{

				Rectangle givenRect(Point(0.0, 0.0), Point(1.0, 1.0));
				givenRect.getRectangle();

				std::cout << "Info about given rectangle:" << "\n";
				givenRect.getInfo();

				Point newPoint(0.0, 0.0);

				std::cout << "Enter point to move the center of rectangle: ";
				std::cin >> newPoint;

				if (!std::cin)
				{
					throw std::invalid_argument(ERR_INCORRECT_COORDINATES);
				}

				givenRect.move(newPoint);
				std::cout << "\n";
				std::cout << "Info about moved rectangle:" << "\n";
				givenRect.getInfo();
				

				Rectangle* rectPtr = dynamic_cast<Rectangle*>(givenRect.clone());
				std::cout << "Info about cloned moved rectangle:" << "\n";
				rectPtr->getInfo();
				delete rectPtr;

				pressAnyKeyToContinue();
				clearConsole();

				Diamond givenDiam(Point(0.0, 0.0), 1.0, 1.0);
				givenDiam.getDiamond();

				std::cout << "Info about given diamond:" << "\n";
				givenDiam.getInfo();

				std::cout << "Enter point to move the center of diamond: ";
				std::cin >> newPoint;

				if (!std::cin)
				{
					throw std::invalid_argument(ERR_INCORRECT_COORDINATES);
				}

				givenDiam.move(newPoint);
				std::cout << "\n";
				std::cout << "Info about moved diamond:" << "\n";
				givenDiam.getInfo();

				Diamond* diamPtr = dynamic_cast<Diamond*>(givenDiam.clone());
				std::cout << "Info about cloned moved diamond:" << "\n";
				diamPtr->getInfo();
				delete diamPtr;

			}
			catch (std::invalid_argument& gottenError)
			{
				clearConsoleErr();
				std::cerr << gottenError.what() << "\n";
				return EXIT_FAILURE;
			}
			catch (std::logic_error& gottenError)
			{
				clearConsoleErr();
				std::cerr << gottenError.what() << "\n";
				return EXIT_FAILURE;
			}
			catch (std::bad_alloc&)
			{
				clearConsoleErr();
				std::cerr << ERR_CANT_ALLOC_MEMORY_FIGURE << "\n";
				return EXIT_FAILURE;
			}

		}
		else if (taskName == A2_SIGNAL)
		{
			try {

				Rectangle givenRect(Point(0.0, 0.0), Point(1.0, 1.0));
				givenRect.getRectangle();

				std::cout << "Info about given rectangle:" << "\n";
				givenRect.getInfo();

				Point newPoint(0.0, 0.0);

				std::cout << "Enter point to move the center of rectangle: ";
				std::cin >> newPoint;
				std::cout << "\n";

				if (!std::cin)
				{
					throw std::invalid_argument(ERR_INCORRECT_COORDINATES);
				}


				Rectangle forTestRect(givenRect);

				givenRect.move(newPoint);
				std::cout << "Info about moved rectangle:" << "\n";
				givenRect.getInfo();

				FrameRectangle rectFrRect = forTestRect.getFrameRectangle();
				FrameRectangle movedRectFrRect = givenRect.getFrameRectangle();

				std::cout << "Is width before moving (" << rectFrRect.getWidth() << ") equals to width after moving (" << \
					movedRectFrRect.getWidth() << ") ? - " << std::boolalpha << \
					rectFrRect.areWidthsEqual(movedRectFrRect) << \
					"\n";

				std::cout << "Is height before moving (" << rectFrRect.getHeight() << ") equals to height after moving (" << \
					movedRectFrRect.getHeight() << ") ? - " << std::boolalpha << \
					rectFrRect.areHeightsEqual(movedRectFrRect) << \
					"\n";

				std::cout << "Is area before moving (" << forTestRect.getArea() << ") equals to area after moving (" << \
					givenRect.getArea() << ") ? - " << std::boolalpha << \
					areDoublesEqual(forTestRect.getArea(), givenRect.getArea()) << \
					"\n\n";


				double scaleFactor = 0;

				std::cout << "Enter scale factor: ";
				std::cin >> scaleFactor;
				std::cout << "\n";

				if (!std::cin)
				{
					throw std::logic_error(ERR_INCORRECT_SCALE_FACTOR);
				}


				forTestRect = givenRect;
				givenRect.scale(scaleFactor);
				std::cout << "Info about moved and scaled rectangle:" << "\n";
				givenRect.getInfo();

				std::cout << "Is (" << forTestRect.getArea() << " * (" << scaleFactor << ")^2) equals to " << \
					givenRect.getArea() << "? - " << std::boolalpha << \
					areDoublesEqual(forTestRect.getArea() * scaleFactor * scaleFactor, givenRect.getArea()) << "\n\n";

				pressAnyKeyToContinue();
				clearConsole();

				Diamond givenDiam(Point(0.0, 0.0), 1.0, 1.0);
				givenDiam.getDiamond();

				std::cout << "Info about given diamond:" << "\n";
				givenDiam.getInfo();

				newPoint = Point(0.0, 0.0);

				std::cout << "Enter point to move the center of diamond: ";
				std::cin >> newPoint;
				std::cout << "\n";

				if (!std::cin)
				{
					throw std::invalid_argument(ERR_INCORRECT_COORDINATES);
				}

				Diamond forTestDiam(givenDiam);

				givenDiam.move(newPoint);
				std::cout << "Info about moved diamond:" << "\n";
				givenDiam.getInfo();

				FrameRectangle DiamFrDiam = forTestDiam.getFrameRectangle();
				FrameRectangle movedDiamFrDiam = givenDiam.getFrameRectangle();

				std::cout << "Is width before moving (" << DiamFrDiam.getWidth() << ") equals to width after moving (" << \
					movedDiamFrDiam.getWidth() << ") ? - " << std::boolalpha << areDoublesEqual(DiamFrDiam.getWidth(), movedDiamFrDiam.getWidth()) << \
					"\n";

				std::cout << "Is height before moving (" << DiamFrDiam.getHeight() << ") equals to height after moving (" << \
					movedDiamFrDiam.getHeight() << ") ? - " << std::boolalpha << areDoublesEqual(DiamFrDiam.getHeight(), movedDiamFrDiam.getHeight()) << \
					"\n";

				std::cout << "Is area before moving (" << forTestDiam.getArea() << ") equals to area after moving (" << \
					givenDiam.getArea() << ") ? - " << std::boolalpha << areDoublesEqual(forTestDiam.getArea(), givenDiam.getArea()) << \
					"\n\n";


				scaleFactor = 0;

				std::cout << "Enter scale factor: ";
				std::cin >> scaleFactor;
				std::cout << "\n";

				if (!std::cin)
				{
					throw std::logic_error(ERR_INCORRECT_SCALE_FACTOR);
				}

				forTestDiam = givenDiam;
				givenDiam.scale(scaleFactor);
				std::cout << "Info about moved and scaled diamond:" << "\n";
				givenDiam.getInfo();

				std::cout << "Is (" << forTestDiam.getArea() << " * (" << scaleFactor << ")^2) equals to " << \
					givenDiam.getArea() << "? - " << std::boolalpha << \
					forTestDiam.isCorrectlyScaledAreas(givenDiam, scaleFactor) << "\n\n";

			}
			catch (std::invalid_argument& gottenError)
			{
				clearConsoleErr();
				std::cerr << gottenError.what() << "\n";
				return EXIT_FAILURE;
			}
			catch (std::logic_error& gottenError)
			{
				clearConsoleErr();
				std::cerr << gottenError.what() << "\n";
				return EXIT_FAILURE;
			}

		}
		else if (taskName == A3_SIGNAL)
		{

			int numFigures = 0;
			
			try
			{
				std::cout << "Enter number of figures (it's not recommended to enter more than 10000): ";
				std::cin >> numFigures;

				if (!std::cin)
				{
					throw std::length_error(ERR_INCORRECT_NUMBER);
				}

				CompositeShape compShape(numFigures);

				std::string figType = "";

				Rectangle toInputRect(Point(0.0, 0.0), Point(1.0, 1.0));
				Diamond toInputDiam(Point(0.0, 0.0), 1, 1);

				clearConsole();

				bool isEnd = false;

				for (int curFig = 0; !isEnd && numFigures > 0; curFig++)
				{
					std::cout << "Enter type of figure (Rect, Diam, or END to stop input): ";
					std::cin >> figType;

					if (figType == RECT_SIGNAL)
					{
						toInputRect.getRectangle();
						compShape += toInputRect;

					}
					else if (figType == DIAM_SIGNAL)
					{
						toInputDiam.getDiamond();
						compShape += toInputDiam;

					}
					else if (figType == END_SIGNAL)
					{
						clearConsole();
						isEnd = true;
					}
					else
					{
						throw std::logic_error(ERR_INCORRECT_TYPE_NAME);
					}

					pressAnyKeyToContinue();
					clearConsole();

				}

				std::cout << "Info about composite shape: " << "\n\n";
				compShape.getInfo();

				Point newPoint(0.0, 0.0);

				std::cout << "Enter point to move the center of composite shape: ";
				std::cin >> newPoint;
				std::cout << "\n";

				if (!std::cin)
				{
					throw std::invalid_argument(ERR_INCORRECT_COORDINATES);
				}

				CompositeShape forTestCompShape(compShape);

				compShape.move(newPoint);
				
				std::cout << "Info about moved composite shape: " << "\n\n";
				compShape.getInfo();
				
				std::cout << "Is width and height after moving are the same? - " << \
					std::boolalpha << forTestCompShape.areCorrectlyMoved(compShape, newPoint) << "\n\n";

				forTestCompShape.move(newPoint);

				double scaleFactor = 0;

				std::cout << "Enter scale factor: ";
				std::cin >> scaleFactor;
				std::cout << "\n";

				if (!std::cin)
				{
					throw std::logic_error(ERR_INCORRECT_SCALE_FACTOR);
				}

				compShape.scale(scaleFactor);
				std::cout << "Info about moved and scaled composite shape: " << "\n\n";
				compShape.getInfo();

				std::cout << "Is composite shape correctly scaled (areas): " << std::boolalpha << \
					forTestCompShape.areCorrScaledAreas(compShape, scaleFactor) << "\n";

				std::cout << "Is composite shape correctly scaled (dists from figures centers to composite shape centers: " << \
					std::boolalpha << forTestCompShape.areCorrScaledDists(compShape, scaleFactor) << "\n";

				std::cout << "Is composite shape correctly scaled (the coordinates of center): " << std::boolalpha << \
					forTestCompShape.areCorrScaledCenter(compShape) << "\n\n";


			}
			catch (std::underflow_error& gottenError)
			{
				clearConsoleErr();
				std::cerr << gottenError.what() << "\n";
				return EXIT_FAILURE;
			}
			catch (std::length_error& gottenError)
			{
				clearConsoleErr();
				std::cerr << gottenError.what() << "\n";
				return EXIT_FAILURE;
			}
			catch (std::out_of_range& gottenError)
			{
				clearConsoleErr();
				std::cerr << gottenError.what() << "\n";
				return EXIT_FAILURE;
			}
			catch (std::invalid_argument& gottenError)
			{
				clearConsoleErr();
				std::cerr << gottenError.what() << "\n";
				return EXIT_FAILURE;
			}
			catch (std::logic_error& gottenError)
			{
				clearConsoleErr();
				std::cerr << gottenError.what() << "\n";
				return EXIT_FAILURE;
			}
			catch (std::bad_alloc&)
			{
				clearConsoleErr();
				std::cerr << ERR_CANT_ALLOC_SO_MUCH_MEMORY << "\n";
				return EXIT_FAILURE;
			}
		}
		
		if (taskName != END_SIGNAL)
		{
			pressAnyKeyToContinue();
			clearConsole();
		}
		
	}
	return EXIT_SUCCESS;
}