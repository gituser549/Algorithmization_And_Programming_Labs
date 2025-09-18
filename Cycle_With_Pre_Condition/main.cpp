#include <iostream>

int main()
{
    const int STOP_PROGRAM=0, FIRST_NUM=1;
    int curNum=0, nNums=0, nPosNums=0, sumNums=0, sumPosNums=0, maxNums=0, minPosNum=0;
    if (!(std::cin >> curNum)) {
        std::cerr << "ERROR: Program works only with integer numbers" << "\n";
        exit(EXIT_FAILURE);
    }
    while (curNum != 0) {
        nNums++;
        sumNums += curNum;
        if (nNums == FIRST_NUM || curNum>maxNums) {
            maxNums = curNum;
        }
        if (curNum > 0) {
            nPosNums++;
            sumPosNums += curNum;
            if (nPosNums == FIRST_NUM || curNum<minPosNum) {
                minPosNum = curNum;
            }
        }
        if (!(std::cin >> curNum)) {
            std::cerr << "ERROR: Program works only with integer numbers" << "\n";
            exit(EXIT_FAILURE);
        }
    }
    if (!nNums) {
        std::cerr << "ERROR: Empty sequence" << "\n";
        exit(EXIT_FAILURE);
    }
    else {
        std::cout << "Arithmetic mean of all numbers = " << static_cast<float>(sumNums)/nNums << "\n";
        std::cout << "Maximum value = " << maxNums << "\n";
    }
    if (!nPosNums) {
        std::cerr << "ERROR: Not positive numbers in the sequence" << "\n";
        exit(EXIT_FAILURE);
    }
    else {
        std::cout << "Arithmetic mean of positive numbers = " << static_cast<float>(sumPosNums)/nPosNums << "\n";
        std::cout << "Minimum positive number = " << minPosNum << "\n";
    }
    exit(EXIT_SUCCESS);
}