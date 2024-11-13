#include <vector>
using namespace std;

class Polynom {
private:
    int power;
    vector<double> coefficients;
    void update_coef();

public:
    // Конструктор
    Polynom();
    Polynom(const vector<double>& coef);
    

    // Функция для нахождения значения многочлена при заданном x
    double evaluate(double x) const;

    // Математические операции для многочлена
    Polynom& operator =(const Polynom& r);
    Polynom& operator +=(const Polynom& r);
    Polynom& operator -=(const Polynom& r);
    Polynom& operator *=(const Polynom& r);
    Polynom& operator /=(const int& r);
    Polynom& operator /=(const double& r);
    Polynom& operator /=(const Polynom& divisor);

    Polynom operator +(const Polynom& r) const;
    Polynom operator -(const Polynom& r) const;
    Polynom operator *(const Polynom& r) const;
    Polynom operator /(const int& r) const;
    Polynom operator /(const double& r) const;
    Polynom operator /(const Polynom& divisor) const;

    // Вывод многочлена
    friend std::ostream& operator<<(std::ostream& os, const Polynom& poly);
    // Производная
    Polynom derivative(int order = 1);
    // Интегрирование
    Polynom integrate();
};
