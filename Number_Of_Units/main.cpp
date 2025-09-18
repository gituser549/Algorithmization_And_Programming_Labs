#include <iostream>
#define MIN_VALID_NUM 0

int cBinOnes(unsigned int Num);

int main() {
    long int Num=0;
    if (!(std::cin >> Num) || Num < MIN_VALID_NUM) {
        std::cerr << "ERROR:not a positive integer number or zero" << "\n";
        exit(EXIT_FAILURE);
    }
    std::cout << cBinOnes(Num) << "\n";
    exit(EXIT_SUCCESS);
}

int cBinOnes(unsigned int Num) {
    return (Num!=0) ? (Num%2==1) + cBinOnes(Num/=2) : 0;
}