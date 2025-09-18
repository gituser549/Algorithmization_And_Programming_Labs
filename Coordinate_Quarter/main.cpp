#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    float x = 0.0, y = 0.0;
    bool flag = false;
    std::cout << "Введите координаты точки: ";
    if (!(std::cin >> x)) { 
        std::cerr << "Значение x должно быть числом\n"; 
        return 1; 
    }
    if (!(std::cin >> y)) { 
        std::cerr << "Значение y должно быть числом\n"; 
        return 1; 
    }
    if (x >= 0 && y >= 0) {
        std::cout << "1";
        flag = true;
    }
    if (x <= 0 && y >= 0) {
        (flag) ? std::cout << " 2" : std::cout << "2";
        flag = true;
    }
    if (x <= 0 && y <= 0) {
        (flag) ? std::cout << " 3" : std::cout << "3";
        flag = true;
    }
    if (x >= 0 && y <= 0) {
        (flag) ? std::cout << " 4" : std::cout << "4";
    }
    std::cout << "\n";
    return 0;
}