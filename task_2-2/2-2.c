#include <stdio.h>
#include <math.h>
#include <float.h>

/**
* @brief расчет y
* @param x значение х 
* @return возвращает значение у
**/
double yFunc(double x);

/**
* @brief проверка введеного значения
* @return возвращает значение если ввод правильный, иначе выводит сообщение об ошибке
*/
float getNumber();

/**
 * @brief точка входа в программу 
 * @return возвращает 0, если все верно, возвращает 1 в случае ошибки
 **/
int main()
{
    double x;
    x = getNumber();
    double y = yFunc(x);
    printf("\n y= %lf", y);
    return 0;
}

float getNumber() 
{ 
 float number; 
    if (scanf("%f", &number) != 1 || (number < DBL_EPSILON)) 
    { 
         printf("%s" "Wrong value"); 
         abort();  
    } 
    return number;
}

double yFunc(double x)
{
    const double a = 2.5;
    if (x <= a){return x * sin(a) * x;}
    else {return x * pow(x - a, 1.0 / 3);};
}