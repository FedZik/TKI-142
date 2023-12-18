#include <stdio.h> 
#include <errno.h> 
#include <stdlib.h> 
 
/** 
* @brief Функция ввода целочисленного неотрицательного значения.
* @return Целочисленное неотрицательное число.
*/ 
int getCount(); 
 
/** 
* @brief Функция расчитывающая сумму членов последовательности. 
* @param startPoint - Начальный член последовательности.
* @param endPoint - Конечный член последовательности.
* @return Сумма последовательности. 
*/ 
double getSum(int startPoint, int endPoint); 
 
/** 
* @brief Функция расчитывающая рекурентный член последовательности. 
* @param k - Номер члена последовательности. 
* @return Значение рекурентного члена последовательности. 
*/ 
double getRecurrent(int k); 

/** 
* @brief Функция ищет первое значение реккурентной формулы.
* @return Значение первого члена реккурентной формулы.
*/ 
double findFirst(int startPoint);


/** 
* @brief Точка входа в программу. 
* @return Возвращает 0 в случае успеха. 
*/ 
int main() 
{ 
    printf("%s", "Insert the start of the segment "); 
    int startPoint = getCount(); 
    printf("%s", "Insert the end of the segment "); 
    int endPoint = getCount(); 
    printf("Second task: %.15lf \n", getSum(startPoint, endPoint));
    return 0; 
} 

int getCount() 
{ 
        int count; 
        int result = scanf("%d", &count); 
        if (result != 1 || count < 0) 
        { 
                errno = EIO; 
                perror("Error:"); 
                abort(); 
        } 
        return count; 
} 
 
double getSum(int startPoint, int endPoint) 
{ 
    double current = findFirst(startPoint);
    double sum = current; 
    for (int k = startPoint; k < endPoint; k++) 
    { 
            current *= getRecurrent(k); 
            sum += current; 
    } 
    return sum; 
} 
 
double getRecurrent(int k) 
{ 
        return 1.0 / ((k + 3) * (k + 4)); 
}

double findFirst(int startPoint)
{
        double k = startPoint;
        return 1.0 / ((k + 3) * (k + 4)); 
}