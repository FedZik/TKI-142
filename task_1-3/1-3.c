#include <stdio.h>

/**
* @brief Поиск значения energy
* @param  "m" масса для функции energy
* @param  "v" скорость для функции energy
* @return Возвращает результат функции getEnergy
*/
double getEnergy(double m, double v);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает корректно, иначе 1
*/
int main()
{
    double m, v;
    scanf("%lf", &m);
    scanf("%lf", &v);
    if (m > 0 && v > 0 && m != 1 && v != 1)
    {
        double energy = getEnergy(m, v);
        printf("\n energy=%lf", energy);
    }
    else
    {
        printf("\n %s", "Неправильный ввод");
    }
    return 0;
}

double getEnergy(double m, double v)
{
    return m * (double) (pow (v, 2) / 2);
}