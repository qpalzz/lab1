#include "polinom.h"

Polinom::Polinom(int n)
{
    a = NULL;
    this->n = n;
    if (n > 0) {
        a = new double[n+1];
        for (int i = 0; i <= n; i++) {
            a[i] = rand()%5+1;
        }
    }
}

Polinom::Polinom(int n, double *a)
{
    this->n = n;
    this->a = a;
}

Polinom::Polinom(const Polinom &obj)
{
    this->n = obj.n;
    for (int i = 0; i <= this->n; i++) {
        this->a[i] = obj.a[i];
    }
}

Polinom::~Polinom()
{
    delete []a;
}

double Polinom::calculate(double x) const
{
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        sum += a[i]*pow(x,n-i+0.0);
    }
    return sum;
}

void Polinom::output() const
{
    cout << "P = ";
    cout << a[0] << "x^" << n;
    for (int i = 1; i <= n; i++) {
        char sign = (a[i] > 0)?'+':'\0';
        cout << sign << a[i] << "x^" << n-i;
    }
    cout << endl;
}

void Polinom::output(double x) const
{
    cout << "P(" << x << ") = " << calculate(x);
}

Polinom& Polinom::operator =(const Polinom &p)
{
    if (&p == this)
        return *this;
    delete []a;
    n = p.n;
    a = new double[n+1];
    for (int i = 0; i <= n; i++) {
        a[i] = p.a[i];
    }
    return *this;
}

Polinom Polinom::operator +(Polinom &p)
{
    int N = max(this->n,p.n);
    double *A = new double[N+1];
    int i,j,r;
    for (i = this->n, j = p.n, r = N; i >= 0, j >= 0; i--, j--, r--) {
        A[r] = this->a[i] + p.a[j];
        if (i < 0 || j < 0) break;
    }
    if (i >= 0) {
        for (int r = i; r >= 0; r--) {
            A[r] = this->a[r];
        }
    }
    else if (j >= 0) {
        for (int r = j; r >= 0; r--) {
            A[r] = p.a[r];
        }
    }
    return Polinom(N,A);
}

Polinom Polinom::operator -(Polinom &p)
{
    int N = max(this->n,p.n);
    double *A = new double[N+1];
    int i,j,r;
    for (i = this->n, j = p.n, r = N; i >= 0, j >= 0; i--, j--, r--) {
        A[r] = this->a[i] - p.a[j];
        if (i < 0 || j < 0) break;
    }
    if (i >= 0) {
        for (int r = i; r >= 0; r--) {
            A[r] = this->a[r];
        }
    }
    else if (j >= 0) {
        for (int r = j; r >= 0; r--) {
            A[r] = p.a[r];
        }
    }
    return Polinom(N,A);
}

Polinom Polinom::operator *(Polinom &p)
{
    int N = this->n + p.n;
    double *A = new double[N+1];
    for (int i = 0; i <= this->n; i++) {
        for (int j = 0; j <= p.n; j++) {
            A[i+j] += this->a[i] * p.a[j];
        }
    }
    return Polinom(N,A);
}
