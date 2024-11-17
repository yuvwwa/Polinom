#include <vector>
#include <iostream>
using namespace std;

class Polynom {
private:
    int power;
    vector<double> coefficients;
    void update_coef();

public:
    Polynom();
    Polynom(const vector<double>& coef);
    
    double evaluate(double x) const;

    Polynom operator +(const Polynom& other);
    Polynom operator -(const Polynom& other);
    Polynom operator *(const Polynom& other);
    Polynom operator /(const int& num);
    Polynom operator /(const double& num);
    Polynom operator /(const Polynom& divisor);

    friend ostream& operator<<(std::ostream& os, const Polynom& poly);
    Polynom derivative();
    Polynom integrate();
};
