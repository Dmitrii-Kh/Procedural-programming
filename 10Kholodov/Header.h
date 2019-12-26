#pragma once
double Simpson(const double a, const double b, const double eps, double(*const f)(double));
double AGM(double a, double b);

double Elliptic(double x);
double Dirihle(double x);
double Puasson(double x);
double Eulers(double x);

double test0(double x);
double test1(double x);
