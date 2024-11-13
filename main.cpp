#include <iostream>
#include "exam.cpp"

int main() {
    Polynom p1({3,3,4,9});
    Polynom p2({1,2,3,4});
    Polynom p3({4,12,24});
    
    cout << "p1: " <<p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;

    cout << "Сложение p1+p2: " << p1 + p2 <<endl;
    cout << "Вычитание p1-p2: " << p1 - p2 <<endl;
    cout << "Умножение p1*p2: " << p1 * p2 <<endl;
    cout << "Деление p1/p2: " << p1 / p2 <<endl;
    cout << "Производная p1: " << p1.derivative() << endl;
    cout << "Интеграл p3: " << p3.integrate() << endl;
}
