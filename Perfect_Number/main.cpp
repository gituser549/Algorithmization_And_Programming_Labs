#include <iostream>
#define MIN_NATURAL_NUM 1

bool isPerfect(unsigned int Num);

int main() {
    long int Num=0;
    if (!(std::cin >> Num) || Num < MIN_NATURAL_NUM) {
        std::cerr << "ERROR:not a natural number" << "\n";
        exit(EXIT_FAILURE);
    }
    (isPerfect(Num)) ? std::cout << "TRUE\n" : std::cout << "FALSE\n";
    exit(EXIT_SUCCESS);
}

bool isPerfect(unsigned int Num) {
    int sumDivs=0;
    for (int curDiv=1; curDiv<Num; curDiv++) {
        sumDivs += (Num % curDiv == 0) ? curDiv : 0;
    }
    return Num!=MIN_NATURAL_NUM && Num==sumDivs;
}