#include <iostream>
#include <stdexcept>

const char* ERR_INVALID_NUM_ROWS = "ERROR: Invalid number of rows specified";
const char* ERR_INVALID_NUM_COLS = "ERROR: Invalid number of columns specified";
const char* ERR_BAD_ALLOC_MATR = "ERROR: Memory not allocated for array";
const char* ERR_INVALID_MATR_EL = "ERROR: Invalid matrix element";
const char* ERR_NOT_ENOUGH_MATR_EL = "ERROR: Not enough matrix elements";
const char* ERR_IMPOS_CONSTR_VECT = "ERROR: It is impossible to construct a vector";
const char* ERR_BAD_ALLOC_ARR = "ERROR: Memory not allocated for vector";

const char* OUTPUT_VECTOR_MESSAGE = "Vector of arithmetic means = ";

int** inArray(int** matrPtr, const int numRows, const int numCols);
float* arithmeticMeansOfPositive(int** matrPtr, const int numRows, const int numCols, float* arrPtr);
void outArray(const float* outArray, const int numElems);
void deleteMatrix(int** matrPtr, const int numRows);
void skipCurSymb();

int main() {

    int numRows = 0, numCols = 0;
    
    try {

        std::cin >> numRows;

        if (!std::cin || numRows <= 0) {
            throw std::logic_error(ERR_INVALID_NUM_ROWS);
        }

        std::cin >> numCols;

        if (!std::cin || numCols <= 0) {
            throw std::logic_error(ERR_INVALID_NUM_COLS);
        }

    }
    catch (const std::logic_error& gottenError) {

        std::cerr << gottenError.what() << "\n";
        return EXIT_FAILURE;

    }

    int** sourceMatr = nullptr;

    try {

        sourceMatr = new int* [numRows] {nullptr};

        for (int createRow = 0; createRow < numRows; createRow++) {
            //*(sourceMatr + createRow) = new int[numCols] {0};
            sourceMatr[createRow] = new int[numCols];
        }

        for (int initRow = 0; initRow < numRows; initRow++) {
            for (int initCol = 0; initCol < numCols; initCol++) {
                //*(*(sourceMatr + initRow) + initCol) = 0;
                sourceMatr[initRow][initCol] = 0;
            }
        }

        inArray(sourceMatr, numRows, numCols);

    }
    catch (const std::bad_alloc&) {

        std::cerr << ERR_BAD_ALLOC_MATR << "\n";
        deleteMatrix(sourceMatr, numRows);    
        return EXIT_FAILURE;

    }
    catch (const std::length_error& gottenError) {

        std::cerr << gottenError.what() << "\n";
        deleteMatrix(sourceMatr, numRows);
        return EXIT_FAILURE;

    }
    catch (const std::invalid_argument& gottenError) {

        std::cerr << gottenError.what() << "\n";
        deleteMatrix(sourceMatr, numRows);
        return EXIT_FAILURE;

    }

    float* resultArr = nullptr;

    try {

        resultArr = new float[numRows] {0.0};

        for (int initElem = 0; initElem < numRows; initElem++) {
            //*(resultArr + initElem) = 0.0;
            resultArr[initElem] = 0.0;
        }

        arithmeticMeansOfPositive(sourceMatr, numRows, numCols, resultArr);
    
    }
    catch (const std::bad_alloc&) {

        std::cerr << ERR_BAD_ALLOC_ARR << "\n";
        deleteMatrix(sourceMatr, numRows);
        delete[] resultArr;
        return EXIT_FAILURE;

    }
    catch (const std::invalid_argument& gottenError) {

        std::cerr << gottenError.what() << "\n";
        deleteMatrix(sourceMatr, numRows);
        delete[] resultArr;
        return EXIT_FAILURE;

    }

    outArray(resultArr, numRows);
    deleteMatrix(sourceMatr, numRows);
    delete[] resultArr;
    return EXIT_SUCCESS;

}


int** inArray(int** matrPtr, int numRows, int numCols) {

    skipCurSymb();
    char buffSymb = ' ';

    for (int curRow = 0; curRow < numRows; curRow++) {
        for (int curCol = 0; curCol < numCols; curCol++) {
            std::cin.get(buffSymb);
            while (buffSymb == ' ') {
                std::cin.get(buffSymb);
            }
            std::cin.unget();
            if (buffSymb == '\n') {
                throw std::length_error(ERR_NOT_ENOUGH_MATR_EL);
            }
            else {
                //std::cin >> *(*(matrPtr + curRow) + curCol);
                std::cin >> matrPtr[curRow][curCol];
                if (!std::cin) {
                    throw std::invalid_argument(ERR_INVALID_MATR_EL);
                }
            }
        }
    }
    
    return matrPtr;

}

float* arithmeticMeansOfPositive(int** matrPtr, const int numRows, const int numCols, float* arrPtr) {

    for (int curRow = 0; curRow < numRows; curRow++) {
        int countPosNums = 0;
        int sumPosNums = 0;
        for (int curCol = 0; curCol < numCols; curCol++) {
            /*
            if (*(*(matrPtr + curRow) + curCol) > 0) {
                sumPosNums += *(*(matrPtr + curRow) + curCol);
                countPosNums++;
            }
            */
            if (matrPtr[curRow][curCol] > 0) {
                sumPosNums += matrPtr[curRow][curCol];
                countPosNums++;
            }
        }
        if (!countPosNums) {
            throw std::invalid_argument(ERR_IMPOS_CONSTR_VECT);
        }
        else {
            //*(arrPtr + curRow) = static_cast<float>(sumPosNums) / static_cast<float>(countPosNums);
            arrPtr[curRow] = static_cast<float>(sumPosNums) / static_cast<float>(countPosNums);
        }
    }
    
    return arrPtr;

}

void outArray(const float* outArray, const int numElems) {
    int curElem = 0;
    std::cout << OUTPUT_VECTOR_MESSAGE;
    for (curElem; curElem < (numElems - 1); curElem++) {
        //std::cout << *(outArray + curElem) << ' ';
        std::cout << outArray[curElem] << ' ';
    }
    //std::cout << *(outArray + curElem) << '\n';
    std::cout << outArray[curElem] << '\n';
}

void deleteMatrix(int** matrPtr, const int numRows) {

    for (int curRow = 0; curRow < numRows; curRow++) {
        //delete[] *(matrPtr + curRow);
        delete[] matrPtr[curRow];
    }

    delete[] matrPtr;
}

void skipCurSymb() {

    std::cin.get();

}