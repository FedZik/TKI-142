#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

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
    printf("введите %d чтобы получить объем, или %d чтобы получить площадь поверхности: ", VOLUME, SURFACEAREA);
    int solve = selectSolve();
    switch ("%d", solve)
    {
    case VOLUME:
        printf("volume = %f", getVolume(r));
        break;
    case SURFACEAREA:
        printf("surface area = %f", getSurfaceArea(r));
        break;
    default:
        printf("\n " "Неправильный ввод" "\n");
        break;
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
    if (scanf("%f", &number) != 1 || (number < DBL_EPSILON)) 
    { 
         printf("%s" "Неправильный ввод"); 
         abort();  
    } 
    return number;
}

int selectSolve()
{
    int number;
    if (scanf("%d", &number) != VOLUME && number != SURFACEAREA)
    {
        printf("\n" "Неправильный ввод" "\n");
        abort();
    }
    return number;
}