#include <stdio.h>
#include <math.h>
#include <stdlib.h>

enum solve
{
    VOLUME = 1,
    SURFACEAREA = 2
};

/**
* @brief Получешние введеного значения из консоли
* @return Возвращает число при условии правильного ввода
*/
float getNumber();

/**
* @brief Выбор типа расчёта
* @return Возвращает выбор пользователя
*/
int selectSolve();

/**
* @brief Поиск значения volume
* @param r радиус для функции getVolume
* @return Возвращает результат функции getVolume
*/
float getVolume(float r);

/**
* @brief Поиск значения surfaceArea
* @param r радиус для функции getSurfaceArea
* @return Возвращает площадь поверхности
*/
float getSurfaceArea(float r);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает корректно, иначе 1
*/
int main()
{
    float r = getNumber();
    printf("Enter %d to get volume, %d to get surface area: ", VOLUME, SURFACEAREA);
    int solve = selectSolve();
    if (solve == VOLUME)
    {
        printf("volume = %f", getVolume(r));
    }
    if (solve == SURFACEAREA)
    {
        printf("surface area = %f", getSurfaceArea(r));
    }
    if (solve != VOLUME && solve != SURFACEAREA)
    {
        printf("\n " "Неправильный ввод" "\n");
    }
    return 0;
}


float getVolume(float r)
{
    return 4 * M_PI * pow(r, 3) / 3;
}

float getSurfaceArea(float r)
{
    return 4 * M_PI * pow(r, 2);
}

float getNumber()
{
    float number;
    if (scanf("%f", &number) == 1 && number > 0)
    {
        return number;
    }
    else
    {
        printf("\n " "Неправильный ввод" "\n");
        abort();
    }
}

int selectSolve()
{
    int number;
    if (scanf("%d", &number) == VOLUME || number == SURFACEAREA)
    {
        return number;
    }
    else
    {
        printf("\n" "Неправильный ввод" "\n");
        abort();
    }
}