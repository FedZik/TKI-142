#include <stdio.h>


/**
* @brief Поиск значения secondSide
* @param  "firstSide" для функции secondSide
* @param  "n" для функции secondSide
* @return Возвращает результат функции getSecondSide
*/
float getSecondSide(float firstSide, float n);

/**
* @brief Поиск значения square
* @param "firstSide" для функции getSquare
* @param "secondSide" для функции getSquare
* @return Возвращает результат функции getSquare
*/
float getSquare(float firstSide, float secondSide);

/**
* @brief Поиск значения perimeter
* @param "firstSide" для функции getPerimeter
* @param "secondSide" для функции getPerimeter
* @return Возвращает результат функции getPerimeter
*/
float getPerimeter(float firstSide, float secondSide);


/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает корректно, иначе 1
* @if Проверка правильности ввода
*/
int main()
{
    float firstSide, n;
    scanf("%f", &firstSide);
    scanf("%f", &n);
    if (firstSide > 0 && n > 0 && firstSide != 1 && n != 1)
    {
        float secondSide = getSecondSide(firstSide, n);
        float square = getSquare(firstSide, secondSide);
        float perimeter = getPerimeter(firstSide, secondSide);

        printf("\n square=", square);
        printf("\n preimeter=", perimeter);
    }
    else
    {
        printf("\n %s", "Неправильный ввод");
    }
    return 0;
}

float getSecondSide(float firstSide, float n)
{
    return firstSide * n / 100;
}


float getSquare(float firstSide, float secondSide)
{
    return firstSide * secondSide;
}


float getPerimeter(float firstSide, float secondSide)
{
    return firstSide * 2 + secondSide * 2;
}