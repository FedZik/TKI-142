#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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
* @brief проверка введеного значения
* @return возвращает значение если ввод правильный, иначе выводит сообщение об ошибке
*/
double getNumber();

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
    double startPoint = getNumber();
    double endPoint = getNumber();
    double step = getNumber();
    if (endPoint < startPoint)
    {
        printf("%s" "Wrong value"); 
        abort();
    }
    else
    {
        for(double x = startPoint; x <= endPoint; x += step)  
        {
        printf ("\n  %9lf", yFunc(x));
        }
    }
}

double getNumber() 
{ 
    double number; 
    if (scanf("%lf", &number) != 1) 
    { 
         printf("%s" "Wrong value"); 
         abort();  
    } 
    return number;
}