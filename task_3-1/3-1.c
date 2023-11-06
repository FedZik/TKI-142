#include <stdio.h>
#include <math.h>
/**
* @brief расситывает значение у
* @param x значение х получаемое из цикла функции forFunc
* @return возвращает значение у
*/
double yFunc();

/**
* @brief табулирует значения х
*/
void forFunc();

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает корректно, иначе 1
*/
int main()
{
    forFunc();
    return 0;
}

double yFunc(double x)
{
    return 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
}

void forFunc()
{
    for(double x = 2; x <= 3; x += 0.1)
    {
        printf ("\n  %9lf", yFunc(x));
    }
}