#include <stdio.h>
#include <math.h>

/**
* @brief Возвращает результат функции a
* @param Параметр "x" для функуии a
* @param Параметр "y" для функуии a
* @param Параметр "z" для функуии a
**/
double afunc(double x, double y, double z);

/*
* @brief Возвращает результат функции a
* @param Параметр "x" для функуии a
* @param Параметр "y" для функуии a
* @param Параметр "z" для функуии a
**/
double bfunc(double x, double y, double z);

/*
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает корректно, иначе не 0
**/
int main()
{
    const double x = 0.78;
    const double y = 1.24;
    const double z = 0.5;
    double a = afunc(x, y, z);
    double b = bfunc(x, y, z);

    printf("a = %lf\n", a);
    printf("b = %lf\n", b);

    return 0;
}

double afunc(double x, double y, double z)
{
    return (2 * pow(z,x)) / (sqrt((pow(y, x) * pow(cos(x + y), 2))) - 3 * z);
}

double bfunc(double x, double y, double z)
{
    return x * exp(sqrt(z)) * cos((pow(x, 2)) / (y * z));
}