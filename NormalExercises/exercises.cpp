#pragma once
#include "Header.h"



/*В текстовом файле, содержащем текст программы на языке Си, проверить соответствие открывающихся 
и закрывающихся фигурных скобок { и }. Результат проверки вывести на экран и записать в виде фразы 
в текстовый файл. Результат работы программы (вывод) поместить в отдельный текстовый файл 
(например, "out . txt " ), продублировав на экране.*/

static void exer1()
{
	std::ifstream in;
	std::string textLine;
	std::string path;
	while (!in.is_open())
	{
		cout << "Введи путь к файлу: ";//G:\Мой диск\Programming\OOP C++\Задания\№9\DictinaryFreq\testText.txt
		//C:\\Users\\Oleg Vasilev\\Desktop\\testCodeDirectory\\My1Text.cpp
		getline(std::cin, path);
		in.open(path);// окрываем файл для чтения 
		if (!in.is_open()) cout << "error of path!\n";
	}
	int QofOpenBrackets = 0;
	int QofCloseBrackets = 0;
	char symbol;

	while (in >> symbol)
	{
		//cout << symbol << endl;
		if (symbol == '{')
		{
			QofOpenBrackets++;
			cout << symbol << endl;
		}
		else if (symbol == '}')
		{
			QofCloseBrackets++;
			cout << symbol << endl;
		}
	}
	in.close(); // закрываем файл. 

	//подготовка пути файла для сохранения
	std::string newFile;
	for (size_t i = 0; i <= path.find_last_of('\\'); i++)
	{
		newFile += path[i];
	}
	newFile += "outReport.txt";
	cout << newFile;
	std::ofstream out;
	out.open(newFile);

	//Запись результатов
	cout << "QofOpenBrackets=" << QofOpenBrackets << " QofCloseBrackets=" << QofCloseBrackets << "\n";
	out << "QofOpenBrackets=" << QofOpenBrackets << " QofCloseBrackets=" << QofCloseBrackets << "\n";
	if (QofOpenBrackets == QofCloseBrackets)
	{
		cout << "Brackets are balanced- GOOD\n";
		out << "Brackets are balanced- GOOD\n";
	}
	else
	{
		cout << "Brackets are NOT balanced- BAD\n";
		out << "Brackets are NOT balanced- BAD\n";
	}
	out.close();
}

/*Используя показатели функции вычислить цепную дробь. Количество елементов дроби надо задавать с клавиатуры.
1+1/(1+1/(1+1/(1+1/….)))*/
inline double chainShot(int num){
	if (num == 0) return 1;
	return 1 + 1 / (chainShot(num - 1));
}

static void exer2()
{
	int num = input<int>("Enter quantity of members chain shot thrush: ");
	cout << chainShot(num) << endl;
}

/*Нужно вычислить произведение матрицы на вектор. В полученном векторе найти макисмальный  элемент. необходимо решить данную задачу тремя способами:

с использованием статических массивов
использовать только динамические массивы с явным разыменованием указателя
использовать только динамические массивы, адресацию к элементам массива выполнять с помощью индексов.
То есть, у вас должно получиться три отдельных исходника — три программы.*/
template <typename T>
void showArray(T* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << std::endl;
}
template <typename T>
void fillArray(T* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "arr[" << i << "]=";
		arr[i] = input<T>("");
	}
}

template <typename T>
void fillArrayRandomInt(T* arr, int size, int boundMin, int boundMax)
{
	srand(time(NULL));
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand()%(boundMax-boundMin)+boundMin;
	}
}
template <typename T>
int indexOfMaxElem(T* arr, int size)
{
	T maxElem = arr[0];
	int indexOfMax = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > maxElem)
		{
			indexOfMax = i;
			maxElem = arr[i];
		}
	}
	return indexOfMax;
}

inline void fillMatrix(int** matrix, int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << "Enter matrix[" << i << "][" << j << "] = ";
			matrix[i][j] = input<int>("");
		}
	}
}
inline void fillMatrixRandomInt(int** matrix, int rows, int cols,int max)
{
	srand(time(NULL));
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] = rand() % (max+1);
		}
	}
}
inline void fillMatrixRandomDouble(double** matrix, int rows, int cols, int min, int max)
{
	srand(time(NULL));
	int startX = rand()%90+1;//стартовое значение конргруэнтного метода
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] = congruential(startX, min, max);

		}
	}
}
template <typename T>
inline void showMatrix(T* arr[], int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
inline void matrix1()
{
	int matrix[2][4];
	//заполним матрицу с клавиатуры
	cout << "fill matrix:\n";
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cout << "Enter matrix[" << i << "][" << j << "] = ";
			matrix[i][j] = input<int>("");
		}
	}
	// покажем ее
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	int vector[4];
	cout << "Fill vector:\n";
	for (size_t i = 0; i < 4; i++)
	{
		cout << "Enter vector [" << i << "]=";
		vector[i] = input<int>("");
	}
	cout << "Show vector:\n";
	for (size_t i = 0; i < 4; i++)
	{
		cout << vector[i] << "\n";
	}
	int vectorAnswer[2];

	//вычисление ответа
	for (size_t i = 0; i < 2; i++)
	{
		vectorAnswer[i] = 0;
		for (size_t j = 0; j < 4; j++)
		{
			vectorAnswer[i] += matrix[i][j] * vector[j];
		}
	}
	//показ ответа
	cout << "Show vectorAnswer:\n";
	for (size_t i = 0; i < 2; i++)
	{
		cout << vectorAnswer[i] << "\n";
	}

}
inline void matrixMultVector()
{
	//ввод данных и инициализация
	cout << "Enter size of matrix\n";
	unsigned int rows = input<unsigned int>("Rows=");
	unsigned int cols = input<unsigned int>("Cols=");

	int** matrix = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		*(matrix + i) = new int[cols];
	}

	//заполнение исходных данных и вывод в консоль
	fillMatrix(matrix, rows, cols);
	showMatrix(matrix, rows, cols);
	int* vector = new int[cols];
	int* resultVector = new int[rows];
	fillArray(vector, cols);
	showArray(vector, cols);
	
	//умножаем матрицу на вектор
	for (size_t i = 0; i < rows; i++)
	{
		*(resultVector+i) = 0;
		for (size_t j = 0; j < cols; j++)
		{
			*(resultVector+i) += *(*(matrix+i)+j) * *(vector+j);
			//resultVector[i] += matrix[i][j] * vector[j];
		}
	}
	showArray(resultVector, rows);

	delete[] vector;//удаление исходного вектора
	//удаление исходной матрицы
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] resultVector;//удаление ответа
}
static void exer3()
{
	//matrix1(); //Статические массивы
	matrixMultVector();// динамические массивы 
}

/*Задача на динамическое выделение памяти. Изначально есть указатель на массив с одним элементом.
Пользователь вводит число. Если оно больше 0 записываем его в массив. Далее пользователь вводит второе число,
тут уже,  если оно больше 0, надо пере выделять память для 2-х элементов массива и записать в массив второе 
число. И так далее…  для 3-х элементов, для 4-х…  пока пользователь не введет отрицательное число.*/

static void exer4()
{
	int size = 1;
	int* arr = new int[size];
	int userInput = 0;
	userInput = input<int>("Enter integer number: ");
	if (userInput > 0) arr[0] = userInput;
	while (userInput > 0) 
	{
		userInput = input<int>("Enter integer number: ");
		if (userInput > 0) {
			int* temp = new int[++size];
			for (size_t i = 0; i < size-1; i++)
			{
				temp[i] = arr[i];
			}
			temp[size - 1] = userInput;
			delete[] arr;
			arr = temp;
			temp = nullptr;
			delete temp;
			showArray(arr, size);
		}
	}
	cout << "end of programm. Array is deleted";
	delete[] arr;
}

/*Необходимо создать структуру, которая содержит элемент типа int и строку. 
Объявить указатель типа структуры (объект структуры) и выделить память для хранения 
данных одной структуры. Предложить пользователю внести данные и записать их в элементы 
объекта структуры.
Далее пользователю необходимо сделать выбор:
внести еще данные (создать еще один объект структуры) либо выйти из программы. 
Если пользователь продолжает ввод — необходимо выделить новую память для указателя на объект структуры
и дописать в нее введенные пользователем новые данные.

Цикл выделения новой памяти продолжается, пока пользователь не выберет выход из программы.*/
static void exer5()
{
	struct MyStruct
	{
		int num;
		std::string str;
				
		void toString()
		{
			cout << "num=" << num << ", str=" << str << endl;
		}
	};
	
	int size = 1;
	MyStruct* ptr = new MyStruct[size];
	MyStruct* tempPtr=nullptr;
	cout << "Enter data of first member in struct:\n";
	ptr[0].num = input<int>("int number: ");
	cout << "Comment: ";
	std::getline(std::cin, ptr[0].str);
	
	unsigned short userChoise;
	do {
		userChoise = input<unsigned short>("Menu: 1-add new member; 2-exit;\n:");
		switch (userChoise)
		{
		case 1:
			tempPtr = new MyStruct[++size];
			for (size_t i = 0; i < size-1; i++)
			{
				tempPtr[i] = ptr[i];//проверять
			}
			tempPtr[size-1].num= input<int>("int number: ");
			cout << "Comment: ";
			std::getline(std::cin, tempPtr[size - 1].str);

			delete[] ptr;
			ptr = tempPtr;
			tempPtr = nullptr;

			cout << "now in array ptr:\n";
			for (size_t i = 0; i < size; i++)
			{
				ptr[i].toString();
			}
			cout << endl;
			break;
		case 2:
			delete[] ptr;
			break;
		default:
			cout << "Error! ReEntry is requared\n";
		}
	} while (userChoise != 2);
}

/*Требуется написать программу, которая заполняет массив размерности nxn по заданному правилу:
      1  3  4 10 11
      2  5  9 12 19
      6  8 13 18 20
      7 14 17 21 24
	 15 16 22 23 25  */

inline void fillMatrixSpecial(int** matrix, int rows, int cols)
{
	int Qofelems = rows * cols;
	int i = 0;
	int j = 0;
	bool direction = true; //true +  false -
	
	for (int counter = 1; counter <= Qofelems; counter++)
	{
		matrix[i][j] = counter;
		if (i == 0 && j!=0) // касаемся верхней стороны.
		{
			if (direction)
			{
				i++;
				if (j != 0) j--;//если не верхний левый угол
			}
			else
			{
				if (j != cols - 1) j++; //если еще не верхний правый угол.
				else i++;
			}
			if (!direction) direction = !direction;
		}

		else if (j == 0)// касаемся левой стороны
		{
			if (direction)
			{
				if (i != rows - 1) i++; // не нижний левый угол
				else j++;
			}
			else
			{
				j++;
				i--;
			}
			if (direction) direction = !direction;
		}

		else if (i == rows - 1) // касаемся нижней стороны.
		{
			if (direction == false)
			{
				i--;
			}
			j++;
			if (direction) direction = !direction;
		}
		
		else if (j==cols-1)// касаемся правой стороны
		{
			if (!direction)
			{
				i++;
			}
			else
			{
				i++;
				j--;
			}
			if (!direction) direction = !direction;
		}

		else //идем по направлениям не касаясь граней.
		{
			if (direction)
			{
				i++;
				j--;
			}
			else
			{
				i--;
				j++;
			}
		}
	}
}
static void exer6()
{
	//ввод данных и инициализация
	cout << "Enter size of matrix\n";
	unsigned int rows; 
	unsigned int cols;
	do {
		rows = input<unsigned int>("Rows=");
		cols = input<unsigned int>("Cols=");//квадратная матрица по условиям задачи? но можно любую (миниму 2х2)
	} while (rows < 2 || cols < 2);
	

	int** matrix = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		*(matrix + i) = new int[cols];
	}

	//заполнение исходных данных и вывод в консоль
	fillMatrixSpecial(matrix, rows, cols);
	showMatrix(matrix, rows, cols);
	

	//удаление исходной матрицы
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

/*По заданному вещественному x, вычислить корень кубический из x по следующей итерационной формуле:
yi+1= 0.5 ( yi + 3 x / ( 2 yi^2 + x / yi )). 
Начальное приближение y0 = x
Итерации прекратить при |yi+1-yi|<10^-5
*/
static void exer7()
{
	double x = input<double>("Enter x: ");
	double yi = x;//Начальное значение
	double yi1;//Yi+1
		
	while (true)
	{
		yi1 = 0.5 * (yi + 3 * x/ (2 * yi * yi + x / yi));
		if (abs(yi1 - yi) < pow(10.0, -5.0)) break;
		yi = yi1;
	}

	cout << "Answer:" << yi1<<endl;
}

/*Программа должна выполнять преобразования строки (длина строки 255 символов):

СТРОКА ЗАГЛАВНЫМИ БУКВАМИ
строка в нижнем регистре
С Заглавной Буквы (Первый Символ Каждого Слова В Строке )
пЕРВЫЙ сИМВОЛ в нИЖНЕМ рЕГИСТРЕ
Как в предложении(с заглавной буквы).
Символ 'f' — выход из программы
Организовать в программе меню, через которое можно удобно выбирать любое действие. Программа должна выполняться пока пользователь не введет  символ 'f'.*/

inline void toUpperCase(std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = 'A' + (str[i] - 'a');
		}

		if (str[i] >= 'а' && str[i] <= 'я') // русский язык
		{
			str[i] = 'А' + (str[i] - 'а');
		}
	}
}
inline void toUpperCaseFirstSymb(std::string& str)
{
	str[0] = toupper(str[0]);
	for (size_t i = 1; i < str.length(); i++)
	{
		if (!((str[i-1] >= 'a' && str[i-1] <= 'z')|| (str[i-1] >= 'A' && str[i-1] <= 'Z')||
			(str[i-1] >= 'а' && str[i-1] <= 'я')||(str[i-1] >= 'А' && str[i-1] <= 'Я')||(str[i-1] >= '0' && str[i-1] <= '9')))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = 'A' + (str[i] - 'a');
			}

			if (str[i] >= 'а' && str[i] <= 'я') // русский язык
			{
				str[i] = 'А' + (str[i] - 'а');
			}
		}
	}
}
inline void toUpperCaseFirstSymbPhrase(std::string& str)
{
	bool newPhrase = true;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.'|| str[i] == '!'|| str[i] == '?')
		{
			newPhrase = true;
		}
		if (newPhrase == true && i < str.length())
		{
			while (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') ||
				(str[i] >= 'а' && str[i] <= 'я') || (str[i] >= 'А' && str[i] <= 'Я')) && i < str.length())
			{
				i++;
			}
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = 'A' + (str[i] - 'a');
			}

			if (str[i] >= 'а' && str[i] <= 'я') // русский язык
			{
				str[i] = 'А' + (str[i] - 'а');
			}
			newPhrase = false;
		}
	}
}

inline void toLowerCase(std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = (char)tolower(str[i]);
	}
}

static void exer8()
{
	//Сделать меню и переделать функции на Return.
	system("chcp 1251");
	std::string str;
	cout << "Enter your string: ";
	getline(cin, str);
	cout << str << endl;

	toUpperCase(str);
	cout << str << endl;

	toLowerCase(str);
	cout << str << endl;

	toUpperCaseFirstSymb(str);
	cout << str << endl;

	toLowerCase(str);
	cout << str << endl;

	toUpperCaseFirstSymbPhrase(str);
	cout << str << endl;

}

/*В квадратной матрице найти минималтный элемент ниже побочной диагонали*/
const inline void showMatrixUnderDiag(int** matrix, int& size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (size - j <= i + 1) cout << matrix[i][j];
			else cout << " ";
			cout << "\t";
		}
		cout << endl;
	}
}

const inline int minUnderDiag(int** matrix, int& size)
{
	int min = INT_MAX;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (size - j <= i + 1)
			{
				if (matrix[i][j] < min) min = matrix[i][j];
			}
		}
	}
	return min;
}

static void exer9()
{
	int size = input<int>("Enter size of qoad matrix: ");
	int** matrix = new int* [size];
	for (size_t i = 0; i < size; i++)
	{
		*(matrix + i) = new int[size];
	}

	//заполнение исходных данных и вывод в консоль
	fillMatrixRandomInt(matrix, size, size,100);
	showMatrix(matrix, size, size);


	cout << endl;
	showMatrixUnderDiag(matrix, size);
	cout<<"minimal elem under diagon:"<<minUnderDiag(matrix, size);

	//удаление исходной матрицы
	for (size_t i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

/*Составить пррограмму которая будет генерировать случlайные числа в интервале [a,b] 
и заполнять ими массив 10х10.
Поменять местами первую строку и строку с минимальным элементом.*/
template <typename T>
const inline int indexOfRowWithMinElem(T** matrix, int rows, int cols)
{
	int indexOfrowWithMinElem = 0;
	T minElem = matrix[0][0];
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (matrix[i][j] < minElem)
			{
				minElem = matrix[i][j];
				indexOfrowWithMinElem = i;
			}
		}
	}
	return indexOfrowWithMinElem;
}
template <typename T>
const inline int indexOfRowWithMaxElem(T** matrix, int rows, int cols)
{
	int indexOfrowWithMaxElem = 0;
	T maxElem = matrix[0][0];
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (matrix[i][j] > maxElem)
			{
				maxElem = matrix[i][j];
				indexOfrowWithMaxElem = i;
			}
		}
	}
	return indexOfrowWithMaxElem;
}

template <typename T>
const inline int indexOfColumnWithMaxElem(T** matrix, int rows, int cols)
{
	int indexOfColWithMaxElem = 0;
	T maxElem = matrix[0][0];
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (matrix[i][j] > maxElem)
			{
				maxElem = matrix[i][j];
				indexOfColWithMaxElem = j;
			}
		}
	}
	return indexOfColWithMaxElem;
}
template <typename T>
static void changeRowsInMatrix(T** matrix, int rows, int cols, int index1, int index2)
{
	for (size_t j = 0; j < cols; j++)
	{
		std::swap(matrix[index1][j], matrix[index2][j]);
	}
}
static void exer10()
{
	//ввод данных и инициализация
	cout << "Enter size of matrix\n";
	unsigned int rows;
	unsigned int cols;
	do {
		rows = input<unsigned int>("Rows=");
		cols = input<unsigned int>("Cols=");
	} while (rows < 2 || cols < 2);//минимально  2х2
	double** matrix = new double* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		*(matrix + i) = new double[cols];
	}
	//заполнение исходных данных и вывод в консоль
	int min = 10; 
	int max = 30;
	fillMatrixRandomDouble(matrix, rows, cols, min, max);
	showMatrix(matrix, rows, cols);

	cout << "\nmin elem in a row #" << indexOfRowWithMinElem(matrix, rows, cols) + 1 << endl;

	changeRowsInMatrix(matrix, rows, cols, 0, indexOfRowWithMinElem(matrix, rows, cols));
	cout << "Changin rows matrix:\n";
	showMatrix(matrix, rows, cols);

}
inline double congruential(int& x, int min, int max) // функция генерации псевдослучайных чисел
{
	const int m = 100, // генерация псевдослучайных чисел в диапазоне значений от 0 до 100 (выбирается случайно m > 0)
		a = 8, // множитель (выбирается случайно 0 <= a <= m)
		inc = 65; // инкрементирующее значение (выбирается случайно 0 <= inc <= m)
	x = ((a * x) + inc) % m; // формула линейного конгруэнтного метода генерации псевдослучайных чисел 
	return (x / double(m))+rand()%(max-min)+min;
}

/*Посчитать количество повторений в строке элементов указанной последовательности*/
static void exer11()
{
	std::string str;
	std::string seekStr;
	cout << "Enter any phrase:";
	getline(cin, str);
	cout << "Enter symbols to seek:";
	getline(cin, seekStr);

	cout << str << " /n::searching symbols:: " << seekStr;

	std::map<char, int> Dictinary;
	for (size_t i = 0; i < seekStr.length(); i++)
	{
		Dictinary[seekStr[i]]=0;

	}

	std::map<char, int>::iterator iter;//итератор указатель на элемент словаря

	for (size_t i = 0; i < str.length(); i++) //идем по фразе
	{
		iter = Dictinary.begin();
		for (; iter != Dictinary.end(); iter++)//идем по словарю
		{
			if (str[i] == iter->first) iter->second++; //если такое есть в словаре ++.
		}
	}
	
	iter = Dictinary.begin();//перестановка указателя в начало
	for (; iter != Dictinary.end(); iter++)
	{
		cout << "\nsymbol --> \"" << iter->first<<"\""
			<< "\ttimes: " << iter->second;
	}	
}
/*Дан массив размера n. Найти все нечетные числа массива */
static void exer12()
{
	int size= input<unsigned int>("Enter size:");
	int* mas = new int[size];
	fillArrayRandomInt(mas, size, 10, 50);
	showArray(mas, size);
	std::list<int> listOfOdd;
	for (size_t i = 0; i < size; i++)
	{
		if (mas[i] % 2 != 0) listOfOdd.push_back(mas[i]);
	}
	cout << "List of Odd numbers:";
	for (auto& var : listOfOdd)
	{
		cout << var << " ";
	}
}
/*Посчитать кол-во повторений каждого символа строки*/
static void exer13()
{
	std::string str;
	cout << "Enter any phrase:";
	getline(cin, str);

	std::map <const char, int> charMap;

	for (size_t i = 0; i < str.length(); i++)
	{
		charMap[str[i]]++;
		/*if (charMap.count(str[i]))
			charMap[str[i]] += 1;
		else
			charMap[str[i]] = 1;*/
	}
	for (const auto& [ch, quantity] : charMap)
		std::cout << ch << " : " << quantity << std::endl;
	
}

/*Время задается в формате час, минута, секунда. Реализовать:

1) вычитание из времени указанного пользователем количества секунд;

2) подсчёт числа секунд между двумя моментами времени, лежащими в пределах одних суток.

*/

/*Задана матрица А размерностью nxm. Записать все элементы матрицы в одномерный массив.*/

static void exer15()
{
	//ввод данных и инициализация
	cout << "Enter size of matrix\n";
	unsigned int rows;
	unsigned int cols;
	do {
		rows = input<unsigned int>("Rows=");
		cols = input<unsigned int>("Cols=");// можно любую (минимум 2х2)
	} while (rows < 2 || cols < 2);
	int** matrix = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		*(matrix + i) = new int[cols];
	}
	
	fillMatrixRandomInt(matrix, rows, cols,99); ///заполнение матрицы
	showMatrix(matrix, rows, cols);
	int* arr = new int[rows * cols];
	int* ptr;
	ptr = arr;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			*ptr = matrix[i][j];
			ptr++;
		}
	}

	showArray(arr, rows * cols);

	ptr = nullptr;
	delete[] arr;
	delete ptr;

	//удаление исходной матрицы
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

/*Выполнить преобразование матрицы, а именно — перестановку строк и столбцов. 
Для  квадратной матрицы размером n переставляйте столбцы и строки таким образом,
чтобы элемент матрицы с наибольшим значением, по модулю, располагался в нижнем правом углу матрицы.
Заполнение исходной матрицы организовать с клавиатуры.*/

static void exer16()
{
	//ввод данных и инициализация
	cout << "Enter size of matrix\n";
	unsigned int rows;
	unsigned int cols;
	do {
		rows = input<unsigned int>("Rows=");
		cols = input<unsigned int>("Cols="); // можно любую (минимум 2х2)
	} while (rows < 2 || cols < 2);
	int** matrix = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		*(matrix + i) = new int[cols];
	}
	fillMatrixRandomInt(matrix, rows, cols, 99); ///заполнение матрицы
	showMatrix(matrix, rows, cols);

	int changeRowIndex = indexOfRowWithMaxElem(matrix, rows, cols);
	if (changeRowIndex != rows - 1)
	{
		cout <<"Change rows position:" << endl;
		
		for (size_t i = 0; i < cols; i++)
		{
			std::swap(matrix[changeRowIndex][i], matrix[rows - 1][i]);
		}
		showMatrix(matrix, rows, cols);
	}

	int changeColIndex = indexOfMaxElem(matrix[rows - 1], cols);
	if (changeColIndex != cols - 1)
	{
		cout << "Change cols position:" << endl;
		for (size_t i = 0; i < rows; i++)
		{
			std::swap(matrix[i][changeColIndex], matrix[i][cols-1]);
		}
		showMatrix(matrix, rows, cols);
	}
}

/*Поменять согласные буквы на гласные во введенной пользователем строке, 
а гласные — на соответствующий ASCII код, используя функции.*/

void exer17()
{
	srand(time(NULL));
	std::string userString;
	cout << "Input your string of text:";
	std::getline(cin, userString);
	std::set<int> vowels {'a', 'e', 'i','o','u', 'y', 'а', 'е','ё','и','о','у','ы','э', 'ю', 'я'};
	std::set<int> consonants { 'b', 'c', 'd', 'f','g', 'h', 'j', 'k', 'l', 'm', 'n', 'p','q','r','s', 't',
		'v','w', 'x', 'z',
		'б','в','г','д','ж', 'й', 'з','к','л','м','н','п','р','с','т','ф','х','ц','ч','ъ','ь','ш','щ'};

	std::string changedStr = "";

	for (size_t i = 0; i < userString.length(); i++)
	{
		if (vowels.count((int)userString[i]))
		{
			changedStr += std::to_string((int)userString[i]);
		}
		else if (consonants.count((int)userString[i]))
		{
			std::set<int>::iterator it= vowels.begin();
			for (size_t i = 0; i < rand()%15; i++)
			{
				it++;
			}
			changedStr+=*it;
		}
		else
		{
			changedStr += userString[i];
		}
	}

	cout << "userString: " << userString <<endl;
	cout << "changedStr: " << changedStr <<endl;

	userString = changedStr;
	cout << "userString: " << userString << endl;
}

/*
дан текст, который пользователь должен ввести в программу, найти наибольшее количество идущих подряд букв.

меню пользователя, состоящее как минимум из 4-х пунктов:
ввод данных (текст вводится пользователем );
обработка данных (поиск наибольшего количества, подряд идущих, букв);
вывод результата на стандартное устройство вывода (экран);
выход из программы.
организовать промежуточное хранение результата, это относится к пункту меню — вывод результата;
разбить программу на функции.*/

void showMenu() 
{
	cout << "Menu:\n" <<
		"1)Enter new text line;\n" <<
		"2)Show saved string;\n" <<
		"3)Analise data;\n" <<
		"4)Show results;\n" <<
		"5)Exit;\n" << endl;
}
bool logic(std::string& str, char& ch, int& tempRes)
{
	int userChoice = input<int>("Your choice: ");
	int* maxInArow = new int;
	*maxInArow = 0;
	int* thisRow = new int;
	*thisRow = 0;
	switch (userChoice)
	{
		case 1:
			getline(cin, str);
			cout << "Good, your text saved.\n";
			break;
		case 2:
			cout << "Saved string:" << str << endl;
			break;
		case 3:
			cout << "Analis...";
			for (size_t i = 0; i < str.length()-1; i++)
			{
				if (str[i] == str[i + 1])
				{
					*thisRow= *thisRow+1;
					if ((i + 1) == str.length() - 1 && *thisRow > *maxInArow)
					{
						ch = str[i];
						*maxInArow = *thisRow;
						*thisRow = 0;
					}
				}
				else if (*thisRow > *maxInArow)
				{
					ch = str[i];
					*maxInArow = *thisRow;
					cout << "\"" << ch  << "\" "<< *maxInArow<<"..";
					*thisRow = 0;
				}
				else
				{
					*thisRow = 0;
				}
			}
			tempRes = *maxInArow;
			cout << "..Compleet!\n";
			break;
		case 4:
			if (tempRes > 0)
				cout << "Max symbols in a row:" << tempRes + 1 << ", symbol: \"" << ch <<"\"" << endl;
			else
			{
				cout << "There is no more than 1 symbols in a row.\n";
			}
			break;
		case 5:
			cout << "Bye!";
			return false;
		default:
			break;
	}
	delete maxInArow;
	delete thisRow;

	return true;
}

void exer18()
{
	string str;
	char tempCh='0';
	int times=0;
	do {
		showMenu();
	} while (logic(str, tempCh, times));
}

class AnilizeString
{
	std::string str;
	char repeaterChar;
	int times;

	int userChoice;
	int maxInArow;
	int thisRow;
	
	void analise(bool flag)
	{
		for (size_t i = 0; i < str.length() - 1; i++)
		{
			if (str[i] == str[i + 1])
			{
				thisRow = thisRow + 1;
				if ((i + 1) == str.length() - 1 && thisRow > maxInArow)
				{
					repeaterChar = str[i];
					maxInArow = thisRow;
					if (flag==true) {
						cout << "\"" << repeaterChar << "\" " << maxInArow << "..";
					}
					thisRow = 0;
				}
			}
			else if (thisRow > maxInArow)
			{
				repeaterChar = str[i];
				maxInArow = thisRow;
				if (flag == true) {
					cout << "\"" << repeaterChar << "\" " << maxInArow << "..";
				}
				thisRow = 0;
			}
			else
			{
				thisRow = 0;
			}
		}
		times = maxInArow;
	}

public:
	AnilizeString()
	{
		str = "";
		repeaterChar='\0';
		times=0;

		userChoice = 0;
		maxInArow = 0;
		thisRow = 0;
	}

	void showMenu()
	{
		cout << "Menu:\n" <<
			"1)Enter new text line;\n" <<
			"2)Show saved string;\n" <<
			"3)Analise data;\n" <<
			"4)Show results;\n" <<
			"5)Exit;\n" << endl;
	}
	bool logic()
	{
		userChoice = input<int>("Your choice: ");
				
		switch (userChoice)
		{
		case 1:
			getline(cin, str);
			cout << "Good, your text saved.\n";
			analise(false);
			break;
		case 2:
			cout << "Saved string:" << str << endl;
			break;
		case 3:
			cout << "Analise...";
			if (!str.empty()) {
				analise(true);
				cout << "..Compleet!\n";
			}
			else
			{
				cout << "..Error! str is empty\n";
			}
			break;
		case 4:
			if (!str.empty())
			{
				if (times > 0)
					cout << "Max symbols in a row:" << times + 1 << ", symbol: \"" << repeaterChar << "\"" << endl;
				else
				{
					cout << "There is no more than 1 symbols in a row.\n";
				}
			}
			else
			{
				cout << "..Error! str is empty\n";
			}
			break;
		case 5:
			cout << "Bye!";
			return false;
		default:
			break;
		}
		return true;
	}

	void setNewString(const char* str)
	{
		this->str = str;
		repeaterChar = '\0';
		analise(false);
	}
};

void exer18_1()
{
	AnilizeString str;
	do {
		str.showMenu();
	} while (str.logic());
}

/*Описать функцию аddRightDigit(d, k), 
которая должна добавлять к целому положительному числу К справа цифру D (D — целочисленное значение в диапазоне 0-9,
К — целочисленное значение, которое является одновременно входным параметром и модифицируемым значением).
С помощью этой функции добавить к данному числу К цифры D1 и D2, выводя результат каждого добавления.*/



void аddRightDigit(int d, int& k)
{
	if (0 <= d && d <= 9)
	{
		if (k > 0)
		{
			k = k * 10 + d;
		}
		else
		{
			k = k * 10 - d;
		}
		cout << "k=" << k << endl;;
	}
	else
	{
		cout << "Error. d is not from 0 to 9\n";
	}
}

void exer19()
{
	
	int k = input<int>("Enter k:");
	int d = input<int>("Enter D1:");
	аddRightDigit(d, k);

	d = input<int>("Enter D2:");
	аddRightDigit(d, k);
	return;
}

/*Необходимо разработать программу, которая предоставляет удобный функционал для работы с разреженной матрицей.
Разреженная матрица — матрица с большим количеством нулевых элементов. Требуется написать следующие функции:

Ввода матрицы;
Печати матрицы;
Суммирования двух матриц;
Умножения двух матриц.
Представлять матрицы можно в виде списка или в виде динамического массива.*/



void exer20()
{
	/*Matrix my1(3, 3); Запускать в Main.  Или полключить "Matrix.h"
	my1.fillMatrixManual();
	cout << my1 << endl;

	Matrix my2(3, 1);
	my2.fillMatrixManual();
	cout << my2 << "\n\n";

	cout << my1 * my2 << "\n\n";
	cout << my2 * my1 << "\n\n";*/
	
	return;
}


/*Дана строка символов. Признак конца строки — символ 'n' (переход на новую строку). 
Строка состоит из слов, которые отделены друг от друга пробелами. Вывести самое длинное слово 
и его порядковый номер.*/ /*тоже для самого короткого слова*/
void exer22()
{
	int QuantityOfwords = 0;
	std::vector<std::string> wordsArray;
	std::string str;
	cout << "Enter your string: ";
	getline(cin, str);
	std::set <char> stopSymbols{' ', ',' , '.', '/', ':', '!', '@', '#', '(', ')', '"'};
	

	for (size_t i = 0; i < str.length(); i++)
	{
		std::string tempStr = "";
		while ( (!stopSymbols.count(str[i])) && i < str.length())
		{
			tempStr += str[i];
			i++;
		}
		if(!tempStr.empty()) wordsArray.push_back(tempStr);
		QuantityOfwords++;
	}
	

	cout << QuantityOfwords << " words in text\n";
	int maxLenght = wordsArray[0].length();
	int minLenght = wordsArray[0].length();
	for (size_t i = 0; i < wordsArray.size(); i++)
	{
		if (maxLenght < wordsArray[i].length())
		{
			maxLenght = wordsArray[i].length();
		}

		else if (minLenght > wordsArray[i].length())
		{
			minLenght = wordsArray[i].length();
		}
	}

	/*for (size_t i = 0; i < wordsArray.size(); i++)
	{
		cout << "word --> \"" << wordsArray[i] << "\"" << "\tsymbols: " << wordsArray[i].length() << endl;
	}*/
	cout << "\n\n";

	//проверка кол-ва длинных слов (вдруг их несколько)
	for (size_t i = 0; i < wordsArray.size(); i++)
	{
		if (maxLenght == wordsArray[i].length())
		{
			cout << "The longest word --> \"" << wordsArray[i] << "\""
				<< "\tsymbols: " << maxLenght << " at position #" << i + 1 << endl;
		}

		if (minLenght == wordsArray[i].length())
		{
			cout << "The shortest word --> \"" << wordsArray[i] << "\""
				<< "\tsymbols: " << minLenght << " at position #" << i + 1 << endl;
		}
	}
}

/*Напишите программу которая сортирует записи в файле в порядке возрастания номера телефона.
В текстовом файле находятся записи о номерах телефонов. 
В каждой строке записана информация: номер телефона, ФИО, адрес. Пример работы программы:*/

void exer23()
{
	std::set<std::string> stringsOfFile;

	std::ifstream in;
	std::string textLine;
	std::string path;
	while (!in.is_open())
	{
		cout << "Введи путь к файлу: ";//G:\Мой диск\Programming\OOP C++\Задания\№9\DictinaryFreq\testText.txt
		//C:\\Users\\Oleg Vasilev\\Desktop\\testCodeDirectory\\Dictinary.txt
		getline(std::cin, path);
		in.open(path);// окрываем файл для чтения 
		if (!in.is_open()) cout << "error of path!\n";
	}
	while (getline(in, textLine))
	{
		stringsOfFile.insert(textLine);
	}
	in.close(); // закрываем файл. 

	std::ofstream out;
	out.open(path);
	
	for (std::string str: stringsOfFile)
	{
		cout << str << endl;
		out << str << endl;
	}
	cout << "your file sorted.";
	out.close();
}

/*Определить, является ли введённое число составным. 4, 6, 8, 9  (Не простое число)*/
void exer24()
{
	int userNum = input<int>("Enter your integer number: ");
	cout << userNum;
	if (userNum < 0) userNum *= -1;

	bool flagSimple = true;
	for (size_t i = 2; i < userNum/2+1; i++)
	{
		if (userNum % i == 0)
		{
			flagSimple = false;
			break;
		}
	}

	if (userNum == 0)
	{
		cout << " - нулевое";
	}
	else if (flagSimple)
	{
		cout << " - простое";
	}
	else
	{
		cout << " - составное";
	}
}

/*Дана строка символов, которая обязательно заканчивается символом точки. 
Удалить из строки первые буквы каждого слова.*/

void exer26()
{
	std::string str;
	cout << "Enter your string of text: ";
	getline(cin, str);
	std::vector<std::string> words;

	std::string word = "";
	std::string newString = "";

	for (size_t i = 0; i < str.length(); i++)
	{
		while (str[i] != ' ' && i < str.length())
		{
			word += str[i];
			i++;
		}
		//words.push_back(tempString);
		word = word.substr(1);
		newString += ' ' + word;
		word = "";
	}
	newString = newString.substr(1);//удалим пробел в начале;

	cout << "Your string:" << str<<endl;
	cout << "Changed string:" << newString;
}

