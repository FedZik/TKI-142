#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <errno.h>

/**
 * @brief Функция присваивает целочисленное значение переменной
 * @return целочисленная цифра
*/
int get_int();

/**
 * @brief Функция присваивает переменной целочисленное значение и проверяет его на положителность
 * @return number положительное число
*/
size_t get_size_t();

/**
 * @brief структура хранит константы, указывающие выбор пользователя заполнить массив
 * @brief user_choice хранит значение, вызывающее ввод массива вручную
 * @brief random_choice хранит значение, вызывающее ввод массива случайными числами
*/
enum Choices
{
    user_choice = 1,
    random_choice = 2,
};

/**
 * @brief Функция выделяет память под массив
 * @param length длина массива
 * @return array указатель на пустой массив
*/
int* get_mem_array(const int length);

/**
 * @brief Функция заполняет массив, элементы вводит пользователь
 * @param array указатель на заполняемый массив
 * @param length длина массива
*/
void user_array(int* array, const size_t length);

/**
 * @brief Функция заполняет массив рандомными числами в диапазоне [-100:200]
 * @param array указатель на заполняемый массив
 * @param length длина массива
*/
void random_array(int* array, const size_t length);

/**
 * @brief Функция, освобождающая массив
 * @param array указатель на массив
*/
void free_array(int* array);

int first_task(int* array, size_t length);

void second_task(int* array, size_t length, int number);

void third_task(int* array, const int length);

int maxNegative (int* array, const int length);

/**
 * @brief Точка входа в программу
 * @return 0 Программа исправна
 * @return 1 Программа досрочно закрылась с ошибкой
*/
int main()
{
    printf("insert a length of array \n");
    size_t length = get_size_t();
    printf("enter %d if you want to fill array by youself or %d to fill array by random numbers \n", user_choice, random_choice);
    int choice = get_int();
    int mas = get_mem_array(length);
    switch ("%d", choice)
    {
        case random_choice:
            random_array(mas, length);
            break;
        case user_choice:
            user_array(mas, length);
            break;
        default:
            puts("Entered invalid number!\n");
            return 1;
    }
    printf("enter an integer number \n");
    int number = get_int();
    printf("First task: %d\n", first_task(mas, length));
    second_task(mas, length, number);
    if (maxNegative(mas, length) == INT_MIN)
    {
        printf("\nThird task: Not found\n");
    }
    else
    {
        third_task(mas, length);
    }
    free_array(mas);
    return 0;
}

int get_int()
{
    int number;
    if (scanf("%d", &number) != 1)
    {
        puts("Inserted a wrong value\n");
        abort();
    }
    return number;
}

size_t get_size_t()
{
    int number = get_int();
    if (number <= 0)
    {
        errno = ERANGE;
        perror("Error: \n");
        abort();
    }
    return (size_t)number;
}

int* get_mem_array(const int length)
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

void user_array(int* array, const size_t length)
{
    puts("Insert array elements:");

    for (size_t i = 0; i < length; i++)
    {
        array[i] = get_int();
    }
}

void random_array(int* array, const size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        array[i] = rand() % 20 - 10;
    }
}

void free_array(int* array)
{
    if (NULL != array)
    {
        free(array);
    }
}

int first_task(int* array, size_t length)
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

void second_task(int* array, size_t length, int number)
{
    printf("Second task: ");
    for (size_t i = 0; i <= length; i++)
    {
        if (array[i] > number)
        {
            printf("%u ", i);
        }
    }
}

void third_task(int* array, const int length)
{
    array[1] = maxNegative(array, length);
    printf("\nThird task: %d", array[1]);
}

int maxNegative (int* array, const int length)
{
    int number = INT_MIN;
    for (size_t i = 0; i < length; i++)
    {
        if (array[i] < 0 && array[i] > number)
        {
            number = array[i];
        }
    }
    return number;
}