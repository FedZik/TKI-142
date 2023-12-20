#include <stdio.h>
#include <float.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief Функция считывающая количество членов последовательности.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
* @return Количество членов последовательности.
*/
int getCount();

/**
* @brief Функция расчитывающая сумму членов последовательности.
* @param count - количество членов последовательности.
* @return Сумма последовательности.
*/
double getFirstSum(int count);

/**
* @brief Функция расчитывающая рекурентный член последовательности.
* @param k номер члена последовательности.
* @return Значение рекурентного члена последовательности.
*/
double getReccurent(int k);

/**
* @brief Функция ввода и проверки на правильность точности вычислений.
* @return Точность вычислений.
*/
double getEpsilon();

/**
* @brief Функция вычисления суммы членов последовательности, не меньших e.
* @param e - точность вычислений.
* @return Сумма.
*/
double getSecondSum(const double e);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
    printf("%s", "Enter the end of the sequence: ");
    int count = getCount();
    printf("Sum of %d terms of the sequence: %.15lf \n", count, getFirstSum(count));
    printf("Enter 'e': ");
    const double e = getEpsilon();
    printf("The sum of the terms of the sequence which is not less than the accuracy: %.15lf\n", getSecondSum(e));
    return 0;
}

int getCount()
{
	int count;
	int result = scanf("%d", &count);
	if (result != 1 || count < 0)
	{
		errno = EIO;
		perror("Error");
		abort();
	}
	return count;
}

double getFirstSum(int count)
{
	double current = getReccurent(0);
	double sum = current;
	for (int k = 1; k <= count; k++)
	{
		current *= getReccurent(k);
		sum += current;
	}
	return sum;
}

double getReccurent(int k)
{
  return 1.0 / ((k + 3) * (k + 4));
	
}

double getEpsilon()
{
	double e;
	double result = scanf("%lf", &e);
	if (result != 1 || e < DBL_EPSILON)
	{
		errno = EIO;
		perror("Error");
		abort();
	}
	return e;
}

double getSecondSum(const double e)
{
	double current = getReccurent(0);
	double sum = current;
	int k = 1;
	while (current >= e)
	{
		current *= getReccurent(k);
		sum += current;
		k++;
	}
	return sum;
}