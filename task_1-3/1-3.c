#include <stdio.h>

/**
* @brief Поиск кинетической энергии
* @param "m" масса
* @param "v" скорость
* @param "si" значение для перевода массы в систему СИ
* @return Возвращает численное значение кинетической энергии
*/
double getEnergy(double m, double v, const si);

/**
* @brief проверка введеного значения
* @return Возвращает значение если ввод правильный, иначе выводит сообщение об ошибке
*/
double getNumber();

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает корректно, иначе 1
*/
int main()
{
    double m, v;
    const si = 1000;
    m = getNumber();
    v = getNumber();
    double energy = getEnergy(m, v, si);
    printf("\n energy=%lf", energy);
    return 0;
}

double getEnergy(double m, double v, const si)
{
    return m / si * (double) (pow (v, 2) / 2);
}

double getNumber() 
{ 
 double number; 
 if (scanf("%lf", &number) == 1 && (number > 0)) 
 { 
  return number; 
 } 
 printf("%s" "Wrong value"); 
 abort(); 
} 