#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <errno.h>

/**
 * @brief присваивает целочисленное значение переменной
 * @return целочисленная цифра
*/
int getInt();

/**
 * @brief присваивает переменной целочисленное значение и проверяет его на положителность
 * @return number положительное число
*/
size_t getSizeT();

/**
 * @brief хранит константы, указывающие выбор пользователя для заполнения массива
 * @brief userChoice хранит значение, вызывающее ввод массива вручную
 * @brief randomChoice хранит значение, вызывающее ввод массива случайными числами
*/
enum Choices
{
    userChoice = 1,
    randomChoice = 2,
};

/**
 * @brief выделяет память под массив
 * @param length длина массива
 * @return array указатель на пустой массив
*/
int* getMemoryArray(const int length);

/**
 * @brief заполняет массив, элементы вводит пользователь
 * @param array указатель на заполняемый массив
 * @param length длина массива
 * @param min минимальное значение массива
 * @param max максимальное значение массива
*/
void userArray(int* array, const size_t length, int min, int max);

/**
 * @brief заполняет массив случайными числами в диапазоне [-10:10]
 * @param array указатель на заполняемый массив
 * @param length длина массива
 * @param min минимальное значение массива
 * @param max максимальное значение массива
*/
void randomArray(int* array, const size_t length, int min, int max);

/**
 * @brief освобождение массива
 * @param array указатель на массив
*/
void freeArray(int* array);

/**
 * @brief находит сумму элементов, имеющих нечетное значение
 * @param array указатель на заполняемый массив
 * @param length длина массива
*/
int firstTask(int* array, size_t length);

/**
 * @brief выводит индексы элементов, значения которых больше заданного числа
 * @param array указатель на заполняемый массив
 * @param length длина массива
*/
void secondTask(int* array, size_t length);

/**
 * @brief заменяет второй элемент массива на максимальный среди отрицательных и выводит его
 * @param array указатель на заполняемый массив
 * @param length длина массива
*/
void thirdTask(int* array, const int length);

/**
 * @brief находит наибольшее отрицательное значение в массиве
 * @param length длина массива
 * @param array указатель на заполняемый массив
 * @return array указатель на пустой массив
*/
int maxNegative (int* array, const int length);

/**
 * @brief находит первый отрицательный элемент массива
 * @param array указатель на заполняемый массив
 * @param length длина массива
 * @return возвращает первое отрицательное значение массива если оно есть
 * @return возвращает 0 если в массиве нет отрицательных чисел
*/
int firstNegative(int* array, const int length);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0 если программа работет исправно, иначе 1
*/
int main()
{
    printf("insert a length of array \n");
    size_t length = getSizeT();
    printf("insert mimnimum value \n");
    int min = getInt();
    printf("insert maximum value \n");
    int max = getInt();
    if (min >= max)
    {
        errno = EIO; 
        perror("Error: ");  
        abort();
    }
    printf("enter %d if you want to fill array by youself or %d to fill array by random numbers \n", userChoice, randomChoice);
    int choice = getInt();
    int mas = getMemoryArray(length);
    switch ("%d", choice)
    {
        case randomChoice:
            randomArray(mas, length, min, max);
            break;
        case userChoice:
            userArray(mas, length, min, max);
            break;
        default:
            puts("Entered invalid number!\n");
            return 1;
    }
    printf("First task: %d\n", firstTask(mas, length));
    secondTask(mas, length);
    thirdTask(mas, length);
    freeArray(mas);
    return 0;
}

int getInt()
{
    int number;
    if (scanf("%d", &number) != 1)
    {
        errno = EIO; 
        perror("Error: ");  
        abort();
    }
    return number;
}

size_t getSizeT()
{
    int number = getInt();
    if (number <= 0)
    {
        errno = ERANGE;
        perror("Error: \n");
        abort();
    }
    return (size_t)number;
}

int* getMemoryArray(const int length)
{
    int* array = malloc(length * sizeof(int));
    if (NULL == array)
    {
        errno = ENOMEM;
        perror("Error: ");
        abort();
    }
    return array;
}

void userArray(int* array, const size_t length, int min, int max)
{
    printf("Insert array elements:");

    for (size_t i = 0; i < length; i++)
    {
        int number = getInt();
        if (number > min && number < max)
        {
            array[i] = number;
        }
        else
        {
            errno = EIO;
            perror("Error: \n");
            return 1;
        }
    }
}

void randomArray(int* array, const size_t length, int min, int max)
{
    for (size_t i = 0; i < length; i++)
    {
        array[i] = rand() % max + min;
    }
}

void freeArray(int* array)
{
    if (NULL != array)
    {
        free(array);
    }
}

int firstTask(int* array, size_t length)
{
    int sum = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (abs(array[i]) % 2 != 0)
        {
            sum += array[i];
        }
    }
    return sum;
}

void secondTask(int* array, size_t length)
{
    size_t count = 0;
    printf("enter an integer number \n");
    int number = getInt();
    printf("Second task: ");
    for (size_t i = 0; i <= length; i++)
    {
        if (array[i] > number)
        {
            printf("%u ", i);
        }
        else
        {
            count += 1;
        }
    }
    if (count == length + 1)
    {
        printf("Not found");
    }
}

void thirdTask(int* array, const int length)
{
    array[1] = maxNegative(array, length);
    if (array[1] == 0)
    {
        printf("\nThird task: Not found\n");
    }
    else
    {
        printf("\nThird task: %d", array[1]);
    }
}

int maxNegative (int* array, const int length)
{
    int number = firstNegative(array, length);
    for (size_t i = 0; i < length; i++)
    {
        if (array[i] < 0 && array[i] > number)
        {
            number = array[i];
        }
    }   
    return number;
    
}

int firstNegative(int* array, const int length)
{
    for (size_t i = 0; i < length; i++)
    {
        if (array[i] < 0)
        {
            return array[i];
        }
        
    }
    return 0;
}