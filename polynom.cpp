#include "polynom.h"
#include <vector>
using namespace std;

Polynom::Polynom() {
    power = 0;
}
// Конструктор
Polynom::Polynom(const vector<double>& coef) {
    coefficients = coef;
    update_coef();
}

void Polynom::update_coef() {
    power = coefficients.size() - 1;
}

//Функция для нахождения значения многочлена для заданного аргумента
double Polynom::evaluate(double x) const {
    double result = 0.0;
    for (int i = power; i >= 0; --i) {
        result = result * x + coefficients[i];
    }
    return result;
}

// Сложение
Polynom Polynom::operator +(const Polynom& other) {
    int maxPower = max(power, other.power);
    std::vector<double> resultCoeffs(maxPower + 1, 0);

    for (int i = 0; i <= power; ++i) {
        resultCoeffs[i] += coefficients[i];
    }
    for (int i = 0; i <= other.power; ++i) {
        resultCoeffs[i] += other.coefficients[i];
    }
    coefficients = resultCoeffs;
    update_coef();
    return *this;
}

// Вычитание
Polynom Polynom::operator -(const Polynom& other) {
        int maxPower = max(power, other.power);
        vector<double> resultCoeffs(maxPower + 1, 0);

        for (int i = 0; i <= power; ++i) {
            resultCoeffs[i] += coefficients[i];
        }
        for (int i = 0; i <= other.power; ++i) {
            resultCoeffs[i] -= other.coefficients[i];
        }
        coefficients = resultCoeffs;
        update_coef();
        return *this;
}

// Умножение
Polynom Polynom::operator *(const Polynom& other) {
    int resultSize = power + other.power;
    vector<double> result(resultSize + 1, 0);

    for (int i = 0; i <= power; ++i) {
        for (int j = 0; j <= other.power; ++j) {
            result[i + j] += coefficients[i] * other.coefficients[j];
        }
    }
    coefficients = result;
    update_coef();

    return *this;
}

//Деление
Polynom Polynom::operator /(const int& num){
    for (int i = 0; i < coefficients.size(); i++) {
        coefficients[i] /= num;
    }
    return *this;
}

Polynom Polynom::operator /(const double& num){
    for (int i = 0; i < coefficients.size(); i++) {
        coefficients[i] /= num;
    }
    return *this;
}

// // Деление
// Polynom Polynom::operator /(const Polynom& divisor) {
//     if (divisor.power == 0 && divisor.coefficients[0] == 0) {
//         throw runtime_error("Division by zero Polynom");
//     }
    
//     if (power < divisor.power) {
//         coefficients = vector<double>(1, 0);
//         power = 0;
//         return *this;
//     }

//     vector<double> quotient_coeffs(power - divisor.power + 1, 0);
//     vector<double> remainder = coefficients;

//     while (remainder.size() >= divisor.coefficients.size()) {
//         // Вычисляем текущий член частного
//         int degree_diff = remainder.size() - divisor.coefficients.size();
//         double coeff = remainder.back() / divisor.coefficients.back();
//         quotient_coeffs[degree_diff] = coeff;

//         // Вычитаем произведение текущего члена частного на делитель
//         for (int i = 0; i < divisor.coefficients.size(); ++i) {
//             remainder[i + degree_diff] -= coeff * divisor.coefficients[i];
//         }

//         // Удаляем ведущие нули из остатка
//         while (!remainder.empty() && abs(remainder.back()) < 1e-10) {
//             remainder.pop_back();
//         }
//     }

//     coefficients = quotient_coeffs;
//     update_coef();
//     return *this;
// }

// Производная
Polynom Polynom::derivative(){
    vector<double> result = coefficients;
    
    for (int i = 0; i < 1; ++i) {
        if (result.size() <= 1) {
            if (result.size() == 1) break;
        }
        
        vector<double> der_coeffs(result.size() - 1);
        for (int j = 1; j < result.size(); ++j) {
            der_coeffs[j-1] = result[j] * j;
        }
        result = der_coeffs;
    }
    coefficients = result;
    update_coef();
    return *this;
}

// Интеграл
Polynom Polynom::integrate(){
    vector<double> result(coefficients.size() + 1, 0);
    for (int i = 0; i < coefficients.size(); ++i) {
        result[i + 1] = coefficients[i] / (i + 1);
    }
    
    coefficients = result;
    update_coef();
    return *this;
}

// Вывод
ostream& operator<<(ostream& os, const Polynom& poly) {
    bool first = true;
    for (int i = poly.power; i >= 0; --i) {
        if (poly.coefficients[i] != 0) {
            if (!first && poly.coefficients[i] > 0) {
                os << "+";
            }
            if (poly.coefficients[i] != 1 || i == 0) {
                os << poly.coefficients[i];
            }
            if (i > 0) {
                os << "x";
                if (i > 1) {
                    os << "^" << i;
                }
            }
            first = false;
        }
    }
    if (first) {
        os << "0";
    }
    return os;
}
