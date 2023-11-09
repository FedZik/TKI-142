#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
* @brief проверяет целое ли среднее значение
* @param  firstNumber первое число
* @param  secondNumber второе число
* @return возвращает 1 если среднее значение - целое число, иначе 0
*/
bool parityFunc(int firstNumber, int secondNumber);

/**
* @brief проверка введеного значения
* @return возвращает значение если ввод правильный, иначе выводит сообщение об ошибке
*/
float getNumber();

/**
* @brief проверяет число на четность
* @param  number проверяемое число
* @return возвращает 1 если число четное, иначе 0
*/
bool isEven(int number);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает корректно, иначе 1
*/
int main()
{
    int firstNumber, secondNumber;
    firstNumber = getNumber();
    secondNumber = getNumber();
    if (parityFunc(firstNumber, secondNumber))
    {
        printf("\n %s", "NO");
    }
    else
    {
        printf("\n %s", "YES");
    }
    return 0;
}

bool parityFunc(int firstNumber, int secondNumber)
{
    return (isEven(firstNumber) && isEven(secondNumber) == false) || (isEven(firstNumber) == false && isEven(secondNumber));
}

bool isEven(int number) 
{
    return ((number % 2) == 0);
}

float getNumber() 
{ 
    float number; 
    if (scanf("%f", &number) != 1 || (number < 0)) 
    { 
         printf("%s" "Wrong value"); 
         abort();  
    } 
    return number;
}