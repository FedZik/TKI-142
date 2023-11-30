#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>

/**
* @brief расситывает значение у
* @param x значение х получаемое из цикла for
* @return возвращает значение у
*/
double yFunc(double x);

/**
* @brief проверяет, существует ли функция в точке х
* @param x аргумент функции
* @return возвращает true если существует
*/
bool isExists(const double x);

/**
* @brief проверка введеного значения
* @return возвращает значение если ввод правильный, иначе выводит сообщение об ошибке
*/
double getNumber();

/**
* @brief проверяет правильность ввода шага
* @param step введенное значение шага расчета
* @return возвращает true если ввод правильный
*/
bool checkStep(double step);

/**
* @brief проверяет правильность ввода начальной и конечной точек расчета
* @param startPoint введенное значение начальной точки расчета
* @param endPoint введенное значение конечной точки расчета
* @return возвращает true если ввод правильный
*/
bool comparePoints(double startPoint, double endPoint);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает корректно, иначе 1
*/
int main()
{
    double startPoint = getNumber();
    double endPoint = getNumber();
    double step = getNumber();

    checkStep(step);
    comparePoints(startPoint, endPoint);
    for(double x = startPoint; x <= endPoint + DBL_EPSILON ; x += step)  
    {
        if (isExists(x))
        {
            printf("\n %7.4lf %7.4lf", x, yFunc(x));
        }
         else
        {
            printf("\n %7.4lf %s", x, "no solution");
        }
    }
    return 0;
}

double yFunc(double x)
{
    return 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
}



double getNumber() 
{ 
    double number; 
    if (scanf("%lf", &number) != 1) 
    { 
         errno = EIO; 
         perror("Invalid value entered");  
         abort();  
    } 
    return number;
}

bool isExists(const double x)
{
    if (x > -DBL_EPSILON)
    {
        return true;
    }
    return false;
    
}

bool checkStep(double step)
{
    if (step <= DBL_EPSILON)
    {
        errno = EIO; 
        perror("Invalid value entered"); 
        abort();
    }
    return true;
}

bool comparePoints(double startPoint, double endPoint)
{
    if (startPoint - endPoint >= DBL_EPSILON)
    {
        errno = EIO; 
        perror("Invalid value entered"); 
        abort();
    }
    return true;
}