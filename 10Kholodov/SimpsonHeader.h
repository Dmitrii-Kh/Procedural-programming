#pragma once
double Simpson(const double a, const double b, const double eps, double(*const f)(double));
double AGM(const double a, const double b);
double Elliptic(double x);
double Dirichlet(double x);
double Poisson(double x);
double Eulers(double x);
double test0(double x);
double test1(double x);
double test2(double x);
void EllipticVerifier(double eps);
void PoissonVerifier(double eps);
void DirichletVerifier(double eps);
void EulersVerifier(double eps);