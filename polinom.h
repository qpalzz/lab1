#ifndef POLINOM_H_INCLUDED
#define POLINOM_H_INCLUDED

#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

class Polinom
{
    public:
        Polinom(int n = 0);
        Polinom(int n, double *a);
        Polinom(const Polinom &);
        ~Polinom();

        double calculate(double x) const;
        void output() const;
        void output(double x) const;

        Polinom &operator =(const Polinom &);
        Polinom operator +(Polinom &);
        Polinom operator -(Polinom &);
        Polinom operator *(Polinom &);

    private:
        int n; // степень многочлена
        double *a; // массив коэффициентов, первый элеемнт при старшей степени
};

#endif // POLINOM_H_INCLUDED
