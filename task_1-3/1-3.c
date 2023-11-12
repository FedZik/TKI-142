#include <stdio.h>
#include <float.h>

/**
* @brief расчет кинетической энергии
* @param mass - масса
* @param speed - скорость
* @return возвращает численное значение кинетической энергии
*/
double getEnergy(double mass, double speed);

/**
* @brief проверка введеного значения
* @param convertToGramm значение для перевода массы в систему СИ
* @return возвращает значение если ввод правильный, иначе выводит сообщение об ошибке
*/
float getNumber();

/**
* @brief точка входа в программу
* @return возвращает 0, если программа работает корректно, иначе 1
*/
int main()
{
    double mass, speed;
    mass = getNumber();
    speed = getNumber();
    double energy = getEnergy(mass, speed);
    printf("\n energy=%lf", energy);
    return 0;
}

double getEnergy(double mass, double speed)
{
    const double convertToGramm = 1000;
    return mass / convertToGramm * (double) (pow (speed, 2) / 2);
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