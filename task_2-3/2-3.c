#include <stdio.h>
/**
* @brief проверка чисел на четность
* @param  firstNumber первое число
* @param  secondNumber второе число
* @return возвращает 1 если среднее значение - целое число, иначе 2
*/
int parityFunc(int firstNumber, int secondNumber);

/**
* @brief проверка введеного значения
* @return возвращает значение если ввод правильный, иначе выводит сообщение об ошибке
*/
float getNumber();

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает корректно, иначе 1
*/
int main()
{
    int firstNumber, secondNumber;
    firstNumber = getNumber();
    secondNumber = getNumber();
    int solve = parityFunc(firstNumber, secondNumber);
    if (solve == 1)
    {
        printf("\n %s", "NO");
    }
    else
    {
        printf("\n %s", "YES");
    }
    return 0;
}

int parityFunc(int firstNumber, int secondNumber)
{
    if ((firstNumber % 2 == 0 && secondNumber % 2 == 1) || (firstNumber % 2 == 1 && secondNumber % 2 == 0))
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

float getNumber() 
{ 
    float number; 
    if (scanf("%f", &number) == 1 && (number > 0)) 
    { 
    return number; 
    } 
    printf("\n" "Неправильный ввод"); 
    abort(); 
} 