#include <stdio.h>
#include <math.h>

/**
* @brief Поиск значения volume
* @param r радиус для функции getVolume
* @return Возвращает результат функции getVolume
*/
float getVolume(float r);

/**
* @brief Поиск значения surfaceSqueare
* @param r радиус для функции getSurfaceSquare
* @return Возвращает результат функции getSurfaceSquare
*/
float getSurfaceSquare(float r);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает корректно, иначе 1
*/
int main()
{
    float r;
    scanf("%f", &r);
    if (r > 0 && r != 1)
    {
        float volume=getVolume(r);
        float surfaceSquare=getSurfaceSquare(r);

        printf("\n surfaceSquare=%f",surfaceSquare);
        printf("\n volume=%f",volume);
    }
    else
    {
        printf("\n %s", "Неправильный ввод");
    }
    return 0;
}


float getVolume(float r)
{
    return 4*M_PI*pow(r,3)/3;
}

float getSurfaceSquare(float r)
{
    return 4*M_PI*pow(r,2);
}