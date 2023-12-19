#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**
* @brief Выбор заполнения массива.
*/
enum Choices
{
	/**
	* @brief Ручной способ.
	*/
	MANUAL = 1,
	/**
	* @brief Заполнение массива случайными числами.
	*/
	RANDOM = 2
};

/**
* @brief Функция для считывания элементов массива с клавиатуры.
* @param size - длина массива.
* @param myArray - массив.
*/
void manualInput(int* myArray, size_t size, const int minimumLimit, const int maximumLimit);

/**
* @brief Функция для заполнения массива случайными числами.
* @param size - длина массива.
* @param myArray - массив.
*/
void randomInput(int* myArray, size_t size, const int minimumLimit, const int maximumLimit);

/**
* @brief Функция для печати массива.
* @param array - массив.
* @param size - длина массива.
*/
void printArray(int* array, size_t size);

/**
* @brief Функция для считывания значения с клавиатуры.
* @param message - сообщение пользователю.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
* @return Значение с клавиатуры.
*/
int getValue(const char* message);

/**
* @brief Функция для проверки длинны массива.
* @param intSize - длина массива.
* @remarks Экстренное завершение программы, в случае неправильной длинны массива.
*/
void checkSize(int intSize);

/**
* @brief Функция для проверки массива.
* @param myArray - первый массив.
* @remarks Экстренное завершение программы, в случае несуществования массива.
*/
void checkArray(int* myArray);

/**
* @brief Функция проверки интервала массива на правильность.
* @param minimumLimit - минимальный возможный элемент массива.checkArray-
* @param maximumLimit - максимальный возможный элемент массива.
*/
void checkSegment(const int minimumLimit, const int maximumLimit);

/**
* @brief Функция для нахождения индекса минимального положительного элемента массива.
* @param myArray - первый массив.
* @param size - длина массива.
* @return Индекс минимального положительного элемента массива.
*/
size_t indexMinimumPositive(int* myArray, size_t size);

/**
* @brief Функция для нахождения первого положительного элемента массива.
* @param myArray - первый массив.
* @param size - длина массива.
* @return Максимальный элемент массива.
*/
size_t indexFirstPositive(int* myArray, size_t size);

/**
* @brief Функция для нахождения длины второго массива.
* @param myArray - первый массив.
* @param size - длина первого массива.
* @return Длина второго массива.
*/
int secondArrayLength(int* myArray, size_t size);

/**
* @brief Функция для заполнения третьего массива.
* @param myArray - первый массив.
* @param size - старая длина массива.
* @return Третий массив.
*/
int* getThirdArray(int* myArray, size_t size);

/**
* @brief Функция для получения второго массива.
* @param myArray - первый массив.
* @param size - старая длина массива.
* @param secondArraySize - длина второго массива.
* @return Второй массив.
*/
int* getSecondArray(int* myArray, size_t size, size_t secondArraySize);

/**
* @brief Функция считывания размера массива.
* @return Размер массива
*/
size_t getSize();

/**
* @brief Функция проверки наличия положительных элементов в массиве.
* @param myArray - массив.
* @param size - размер массива.
* @return Возвращает истину в случае успеха.
*/
bool checkPositive(int* myArray, size_t size);

/**
* @brief Функция для заполнения первого массива.
* @param myArray - массив.
* @param size - размер массива.
* @return Первый массив.
*/
int* getFirstArray(int* myArray, size_t size);


int maxNegative(int* myArray, size_t size);


int firstNegative(int* myArray, size_t size);


/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	setlocale(LC_ALL, "RU");

	size_t size = getSize();

	const int minimumLimit = getValue("Введите минимум массива: ");
	const int maximumLimit = getValue("Введите максимум массива: ");
	checkSegment(minimumLimit, maximumLimit);

	int* myArray = (int*)malloc(size * sizeof(int));
	checkArray(myArray);

	printf("Введите номер соответствующий способу, которым вы хотите ввести массив:\n");
	printf("%d - для заполнения массива с клавиатуры\n", MANUAL);
	printf("%d - для заполнения массива случайными числами\n", RANDOM);

	int choice = getValue("");

	enum Choices userInput = choice;

	switch (userInput)
	{
	case MANUAL:
	{
		manualInput(myArray, size, minimumLimit, maximumLimit);
		break;
	}
	case RANDOM:
	{
		randomInput(myArray, size, minimumLimit, maximumLimit);
		break;
	}
	default:
	{
		errno = EIO;
		perror("Ошибка:");
		return 1;
	}
	}

	if (checkPositive(myArray, size))
	{
		
		printf("Ответ на первое задание: \n");
		printArray(getFirstArray(myArray, size), size);
	}
	else 
	{
		printf("В массиве нет отрицатиельных чисел.");
	}

	printf("Ответ на второе задание: \n");
	printArray(getSecondArray(myArray, size, secondArrayLength(myArray, size)), secondArrayLength(myArray, size));

	printf("Ответ на третье задание: \n");
	printArray(getThirdArray(myArray, size), size);
	
	checkArray(myArray);
	free(myArray);
	return 0;
}

int getValue(const char* message)
{
	int value;
	printf("%s", message);
	int result = scanf("%d", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}
	return value;
}

void checkSize(int intSize)
{
	if (intSize <= 0)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}
}

void checkArray(int* myArray)
{
	if (myArray == NULL)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}
}

void manualInput(int* myArray, size_t size, const int minimumLimit, const int maximumLimit)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("Введите число от %d до %d: ", minimumLimit, maximumLimit);
		int c = getValue("");
		if (c < minimumLimit || c > maximumLimit)
		{
			errno = EIO;
			perror("Ошибка ввода");
			abort();
		}
		myArray[i] = c;
	}
}

void randomInput(int* myArray, size_t size, const int minimumLimit, const int maximumLimit)
{
	unsigned int ttime = time(NULL);
	srand(ttime);
	for (size_t i = 0; i < size; i++)
	{
		myArray[i] = minimumLimit + rand() % (maximumLimit - minimumLimit + 1);
	}
}

void checkSegment(const int minimumLimit, const int maximumLimit)
{
	if (minimumLimit > maximumLimit)
	{
		printf("Неверно введен интервал.");
		abort();
	}
}

void printArray(int* array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%lu %d\n", i, array[i]);
	}
}

size_t indexMinimumPositive(int* myArray, size_t size)
{
	{
		int minimumPositiveElement = myArray[indexFirstPositive(myArray, size)];
		int number = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (minimumPositiveElement > myArray[i] && myArray[i] > 0)
			{
				minimumPositiveElement = myArray[i];
				number = i;
			}
		}
		return number;
	}
}

size_t indexFirstPositive(int* myArray, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (myArray[i] > 0)
		{
			return i;
			break;
		}
	}
}

int* getThirdArray(int* myArray, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (abs(i % 2) == 0)
		{
			myArray[i] = pow(myArray[i], 2);
		}
		else
		{
			myArray[i] = (float)myArray[i] / (float)i;
		}
	}
	return myArray;
}

int secondArrayLength(int* myArray, size_t size)
{
	int countRemoved = 0;
	for (int i = 0; i < size; i++)
	{
		if (myArray[i] % 10 % 2 != 0 && myArray[i] % 3 == 0)
		{
			countRemoved += 1;
		}
	}
	return (size - countRemoved);
}

int* getSecondArray(int* myArray, size_t size, size_t secondArraySize)
{
	int* secondArray= (int*)malloc(secondArraySize * sizeof(int));
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (myArray[i] % 10 % 2 == 0 || myArray[i] % 3 != 0)
		{
			secondArray[j] = myArray[i];
			j++;
		}
	}
	return secondArray;
}

size_t getSize()
{
	int intSize = getValue("Введите размер массива: ");
	checkSize(intSize);
	size_t size = (size_t)(intSize);
	return size;
}

bool checkPositive(int* myArray, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (myArray[i] < 0)
		{
			return true;
			break;
		}
	}
	return false;
}

int* getFirstArray(int* myArray, size_t size)
{   
    myArray[1] = maxNegative(myArray, size);
    return myArray;
}




int maxNegative(int* myArray, size_t size)
{
    int number = firstNegative(myArray, size);
    for (size_t i = 0; i < size; i++)
    {
        if (myArray[i] < 0 && myArray[i] > number)
        {
            number = myArray[i];
        }
    }   
    return number;
    
}

int firstNegative(int* myArray, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (myArray[i] < 0)
        {
            return myArray[i];
        }
        
    }
    return 0;
}