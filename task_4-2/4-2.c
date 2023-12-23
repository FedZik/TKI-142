#include <memory.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

/**
* @brief Функция выводит вариант выбора: Клавиатура или Рандом
*/
void userChoise();

/**
* @brief Пользовательский ввод
*/
enum randomOrKeyboard
{
	Keyboard = 1,
	Random = 2
};

/**
* @brief Функция принимающая и проверяющая значение размера на ввод
* @param message - текст сообщения для пользователя
* @return Значение размера
*/
size_t getSize(char const* message);

/**
* @brief Функция выделяющая память под массив
* @param size - размер массива
* @return Массив
*/
int* initArray(const size_t size);

/**
* @brief Функция запалняет массив случайными числами или числами с клавиатуры в зависимости от выбора пользователя
* @param size - размер массива
* @param array - массив
*/
void fillArray(const size_t size, int* array);

/**
* @brief Функция считывающая ввод с клавиатуры
* @param size - размер массива
* @param array - массив
*/
void fillKeyboard(const size_t size, int* array);

/**
* @brief Функция заполняющая массив рандомными числами
* @param size - размер массива
* @param array - массив
* @return 1 если все хорошо
*/
int fillRandom(const size_t size, int* array);

/**
* @brief Функция выводящая заполненный массив
* @param size - размер массива
* @param array - массив
*/
int printArray(const size_t size, const int* array);

/**
* @brief Функция принимающая и проверяющая значение на ввод
* @param message - текст сообщения для пользователя
* @return Значение
*/
int getValue(const char* message);

/**
* @brief Функция заменяющая второй элемент на максимальный отрицательный
* @param array - целочисленный массив
* @param size - размер
* @return Возвращает изменёный массив
*/
int* replaceSecondElement(const int* const array, size_t size);

/**
* @brief Функция вставляющающая k после всех элементов кратную своему номеру
* @param array - целочисленный массив
* @param size - размер
* @param k - элемент
* @return Возвращает изменёный массив
*/
int* insertK(const int* const array, size_t size, int k);

/**
* @brief Функция формирует массив из исходного по условию 3 задания
* @param array - целочисленный массив
* @param size - размер
* @return Возвращает новый массив A
*/
int* getArrayA(const int* const array, size_t size);

/**
* @brief Поиск максимального отрицательного элемента
* @param array - целочисленный массив
* @param size - размер
* @return Возвращает максимальный отрицательный элемент
*/
int maxNegative(const int* const array, size_t size);

/**
* @brief Поиск первого отрицательного элемента
* @param array - целочисленный массив
* @param size - размер
* @return Возвращает первый отрицательный элемент
*/
int firstNegative(const int* const array, size_t size);

/**
* @brief получение размера нового массива
* @param array - целочисленный массив
* @param size - размер
* @return Возвращает размер нового массива
*/
size_t getNewSize(const int* array, size_t size);

/**
* @brief проверка числа на наличие 1
* @param array - целочисленный массив
* @param size - размер
* @return Возвращает истину в случае успешной проверки
*/
bool elementHasK(const int* const array, int i);

/**
* @brief Точка входа в программу
* @return Возврящает 0, если программа работает верно, иначе 1
*/
int main()
{
	setlocale(LC_ALL, "RU");

	size_t size = getSize("Введите размер массива: ");

	int* array = initArray(size);
	fillArray(size, array);

	puts("Исходный массив:\n");
	printArray(size, array);
	int* replacedArraySecondElement = replaceSecondElement(array, size);

	puts("Массив с заменённым вторым элементом на максимальный отрицательный:\n");
	printArray(size, replacedArraySecondElement);

	int k = getValue("Введите k: ");
	int* arrayInsertedK = insertK(array, size, k);

	puts("Массив со вставленным числом К перед всеми элементами, которые содержат 1:\n");
	printArray(getNewSize(array, size), arrayInsertedK);
	int* arrayA = getArrayA(array, size);

	puts("Массив A, сформированный из исходного массива D по 3-му условию:\n");
	printArray(size, arrayA);
	

	return 0;
}

void userChoise()
{
	printf("Заполнение с клавиатуры - %d\n", (int)Keyboard);
	printf("Случайное заполнение - %d\n", (int)Random);
}

size_t getSize(char const* message)
{
	int size = getValue(message);
	if (size < 0) {
		perror("Неверный массив!\n");
		abort();
	}
	return (size_t)size;
}

int* initArray(const size_t size)
{
	int* arr = malloc(size * sizeof(int));
	if (arr == NULL)
	{
		perror("Невозможно выделить память под массив!\n");
	}
	return arr;
}

void fillArray(const size_t size, int* array)
{
	puts("Как Вы хотите заполнить массив:\n");
	userChoise();

	enum randomOrKeyboard choice = getValue("Выберите нужный вариант: ");
	switch (choice)
	{
	case Keyboard:
		fillKeyboard(size, array);
		break;
	case Random:
		fillRandom(size, array);
		break;
	default:
		perror("Неверный выбор!!\n");
	}
}

void fillKeyboard(const size_t size, int* array)
{
	const int minimumLimit = getValue("Введите нижнюю границу массива: ");
	const int maximumLimit = getValue("Введите верхнюю границу массива: ");
	if (minimumLimit >= maximumLimit)
	{
		errno = EIO;
		perror("Неверные границы!\n");
		abort();
	}
	puts("Введите массив: ");
	for (size_t i = 0; i < size; i++)
	{
		int c = getValue("");
		if (c < minimumLimit || c > maximumLimit)
		{
			errno = EIO;
			perror("Ошибка ввода!\n");
			abort();
		}
		array[i] = c;
	}
}

int fillRandom(const size_t size, int* array)
{
	const int minimumLimit = getValue("Введите нижнюю границу массива: ");
	const int maximumLimit = getValue("Введите верхнюю границу массива: ");
	unsigned int ttime = time(NULL);
	srand(ttime);
	for (size_t i = 0; i < size; i++)
	{
		array[i] = minimumLimit + rand() % (maximumLimit - minimumLimit + 1);
	}
	return 1;
}

int printArray(const size_t size, const int* array)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%lu\t%d\n", i, array[i]);
	}
	return 1;
}

int getValue(const char* message)
{
	int a;
	printf("%s", message);
	int res = scanf_s("%d", &a);
	if (res != 1)
	{
		errno = EIO;
		perror("Неверное значение\n");
		abort();
	}
	return a;
}

int* replaceSecondElement(const int* const array, size_t size)
{
	int* newArray = initArray(size);
	for (size_t i=0; i < size; ++i)
	{
		newArray[i] = array[i];
	}
    newArray[1] = maxNegative(newArray, size);
	return newArray;
}

int* insertK(const int* const array, size_t size, int k)
{
	const size_t newSize = getNewSize(array, size);
	int* newArray = initArray(newSize);
    size_t j = getNewSize(array, size) - 1;
    for (int i = size - 1; i >= 0; i--)
    {
       
        newArray[j] = array[i];
        if (elementHasK(array, i))
        {
            newArray[j - 1] = k;
            j -= 2;
        }
        else
        {
            j--;
        }
    }
    return newArray;
}

int* getArrayA(const int* const array, size_t size)
{
	int* newArray = initArray(size);
	for (int i = 0; i < size; ++i)
	{
		if (abs(i % 2) == 0)
		{
			newArray[i] = pow(array[i], 2);
		}
		else
		{
			newArray[i] = array[i] / i;
		}
	}
	return newArray;
}


int maxNegative(const int* const array, size_t size)
{
    int number = firstNegative(array, size);
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] < 0 && array[i] > number)
        {
            number = array[i];
        }
    }   
    return number;
    
}

int firstNegative(const int* array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] < 0)
        {
            return array[i];
        }
        
    }
    return 0;
}

bool elementHasK(const int* const array, int i)
{
    int number = abs(array[i]);
    while(number > 0)
    {
        if (number % 10 == 1)
        {
            return true;
        }
        number /= 10;
    }
    return false;
}

size_t getNewSize(const int* array, size_t size)
{
    size_t quantityOfAddedElement = 0;
    for (size_t i = 0;i < size; i++)
    {
        if (elementHasK(array,  i))
        {
            quantityOfAddedElement += 1;
        }
    }
    return size + quantityOfAddedElement;
}