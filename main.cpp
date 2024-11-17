#include <iostream>
#include "exam.cpp"

int main() {
    Polynom p1({1,2,2});
    Polynom p2({2,3,4});
    Polynom p3({4,12,24});
    Polynom p4({5,3,1});
    Polynom p5({1,2,2});
    Polynom p6({1,2});
    Polynom p7({3,4,9});
    Polynom p8({3,3,4});
    Polynom p9({1,2,3});
    
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;
    cout << "p4: " << p4 << endl;
    cout << "p5: " << p5 << endl;

    cout << "Сложение p1+p2: " << p1 + p2 <<endl;
    cout << "Вычитание p2-p4: " << p2 - p4 <<endl;
    cout << "Умножение p6*p5: " << p6 * p5 <<endl;
    //cout << p8 << ' ' << p9<< " Деление p8/p9: " << p8 / p9 <<endl;
    cout << "Деление p3/2: " << p3 / 2 <<endl;
    cout << "Производная p4: " << p4.derivative() << endl;
    cout <<p7<< " Интеграл p3: " << p7.integrate() << "+C"<< endl;
    cout << "p5(2): " << p5.evaluate(1) << endl;
}
