#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/**
* @brief расчет второй стороны
* @param  firstSide - первая сторона
* @param  n - коэффициент, на который надо умножить 1 сторону для получения второй
* @return возвращает численное значение второй стороны
*/
float getSecondSide(float firstSide, float n);

/**
* @brief расчет площади
* @param firstSide первая сторона
* @param secondSide вторая сторона
* @return возвращает численное значение площади
*/
float getSquare(float firstSide, float secondSide);

/**
* @brief расчет периметра
* @param firstSide первая сторона
* @param secondSide вторая сторона
* @return возвращает численное значение периметра
*/
float getPerimeter(float firstSide, float secondSide);

/**
* @brief проверка введеного значения
* @return возвращает значение если ввод правильный, иначе выводит сообщение об ошибке
*/
float getNumber();

/**
* @brief точка входа в программу
* @return возвращает 0, если программа работает корректно, иначе 1
*/
int main()
{
    float firstSide = getNumber();
    float n = getNumber();

    float secondSide = getSecondSide(firstSide, n);
    float square = getSquare(firstSide, secondSide);
    float perimeter = getPerimeter(firstSide, secondSide);

    printf("\n square=%f", square);
    printf("\n preimeter=%f", perimeter);
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

float getNumber() 
{ 
    float number; 
    if (scanf("%f", &number) != 1 || (number <= DBL_EPSILON)) 
    { 
         printf("%s" "Wrong value"); 
         abort();  
    } 
    return number;
}