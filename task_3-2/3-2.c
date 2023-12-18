#include <stdio.h> 
#include <math.h> 
#include <float.h> 
#include <errno.h> 
#include <stdlib.h> 
 
/** 
* @brief Функция считывающая количество членов последовательности. 
* @return Количество членов последовательности. 
*/ 
int getCount(); 
 
/** 
* @brief Функция расчитывающая сумму членов последовательности. 
* @param count - количество членов последовательности. 
* @return Сумма последовательности. 
*/ 
double getSum(int count); 
 
/** 
* @brief Функция расчитывающая рекурентный член последовательности. 
* @param k - номер члена последовательности. 
* @return Значение рекурентного члена последовательности. 
*/ 
double getRecurrent(int k); 

double findFirst();


/** 
* @brief Точка входа в программу. 
* @return Возвращает 0 в случае успеха. 
*/ 
int main() 
{ 
        printf("%s", "Insert the end of the segment "); 
        int count = getCount(); 
        printf("First task: %.15lf \n", getSum(count));
        printf("%s", "Insert e ");
        int e = getCount();
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
 
double getSum(int count) 
{ 
        double current = findFirst();
        double sum = current; 
        for (int k = 1; k < count; k++) 
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

double findFirst()
{
        double k = 0;
        return 1.0 / ((k + 3) * (k + 4)); 
}

