#pragma once
#include <iostream>
#include "Input.h"

template <class T>
class Matrix
{
	int rows;
	int cols;

	T** matr;//указтель на саму матрицу 
	int iIndexOfMaxInColumn(int column) const;
	int iIndexOfMinInColumn(int column) const;

public:
	inline Matrix();
	Matrix(const Matrix& M);
	Matrix(int rows, int cols);
	void fillMatrixRandInt(int max=9);
	void fillMatrixRandInt(int min, int max);
	void fillMatrixManual();
	void fillMatrixManual(const char* comment1, const char* comment2);
	void showMatrix() const;
	void ShowPosOfMax() const;
	
	//сортировать элементы внутри столбца между минимумом и максимумом
	void sortBetweenMaxMin(int column);

	//Найти сумму элементов в тех столбцах, которые не содержат отрицательные элементы.
	void exerSum();

	Matrix operator+(Matrix<T> M) const;
	Matrix operator*(Matrix<T> M) const;
	friend std::ostream& operator<<(std::ostream& o, const Matrix<T> M);
	~Matrix();
};

template <typename T>
std::ostream& operator<<(std::ostream& o, const Matrix<T> M)
{
	for (int i = 0; i < M.rows; i++)
	{
		for (int j = 0; j < M.cols; j++)
		{
			o << M.matr[i][j] << "\t";
		}
		o << std::endl;
	}
	return o;
}

template <typename T>
Matrix<T>::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;

	matr = new T* [rows];

	for (int i = 0; i < rows; i++)
	{
		matr[i] = new T[cols];
	}
}

template <typename T>
inline Matrix<T>::Matrix()
{
	rows = cols = 0;
	matr = nullptr;
};

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& M)
{
	cols = M.cols;
	rows = M.rows;

	matr = new T * [rows];

	for (size_t i = 0; i < rows; i++)
	{
		matr[i] = new T[cols];
		for (size_t j = 0; j < cols; j++)
		{
			matr[i][j] = M.matr[i][j];
		}
	}
}

template <typename T>
void Matrix<T>::fillMatrixRandInt(int max)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matr[i][j] = rand() % (max + 1);
		}
	}
}
template <typename T>
void Matrix<T>::fillMatrixRandInt(int min, int max)
{
	int range = max - min+1;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matr[i][j] = rand()%range + min;
		}
	}
}

template <typename T>
void Matrix<T>::fillMatrixManual()
{
	for (int i = 0; i < rows; i++)
	{
		std::cout << "\tEnter elems string " << i << std::endl;
		for (int j = 0; j < cols; j++)
		{
			std::cout << "Enter elem[" << i << "][" << j << "] = ";
			std::cin >> matr[i][j];
		}
	}
}

template <typename T>
void Matrix<T>::fillMatrixManual(const char* comment1, const char* comment2)
{
	for (int i = 0; i < rows; i++)
	{
		std::cout << comment1 << " " << i + 1 << std::endl;
		for (int j = 0; j < cols; j++)
		{
			std::cout << comment2 << " " << j + 1 << ":";
			matr[i][j] = input<T>("");
		}
	}
}

template <typename T>
void Matrix<T>::showMatrix() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << matr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

template <typename T>
void Matrix<T>::ShowPosOfMax() const
{
	T max = matr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matr[i][j] > max)
			{
				max = matr[i][j];
			}
		}
	}
	//Сколько человек набрало такой результат?  Если несколько выведем их всех
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matr[i][j] == max)
			{
				std::cout << "\nBest result: " << max;
				std::cout << " Sportsman #: " << i + 1;
				std::cout << " in try#: " << j + 1;
			}
		}
	}
}

template <typename T>
int Matrix<T>::iIndexOfMaxInColumn(int column) const
{
	T max = matr[0][column];
	int index = 0;
	for (int i = 0; i < rows; i++)
	{
		if (matr[i][column] > max)
		{
			max = matr[i][column];
			index = i;
		}
	}
	return index;
}
template <typename T>
int Matrix<T>::iIndexOfMinInColumn(int column) const
{
	T min = matr[0][column];
	int index = 0;
	for (int i = 0; i < rows; i++)
	{
		if (matr[i][column] < min)
		{
			min = matr[i][column];
			index = i;
		}
	}
	return index;
}



template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> M) const
{
	if (rows == M.rows && cols == M.rows)
	{
		Matrix<T> NM(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				NM.matr[i][j] = matr[i][j] + M.matr[i][j];
			}
		}
		return NM;
	}
	else
	{
		std::cout << "ERROR 1! Summ is impossiible // Matrix has different sizes\n";
		return Matrix();
	}
}
template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> M) const
{
	if (cols == M.rows)
	{
		Matrix<T> NM(rows, M.cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < M.cols; j++)
			{
				int elem = 0;
				for (size_t k = 0; k < cols; k++)
				{
					elem += matr[i][k] * M.matr[k][j];
				}

				NM.matr[i][j] = elem;
			}
		}
		return NM;
	}
	else
	{
		std::cout << "ERROR 2! Can not multyplicate // Matrix has uncorrect size\n";
		return Matrix<int>();
	}
}

template <typename T>
//Найти сумму элементов в тех столбцах, которые не содержат отрицательные элементы.
void Matrix<T>::exerSum()
{
	for (size_t j = 0; j < cols; j++) //идем по столбцам
	{
		int sumInCol = 0;
		bool HaveNegatives = false;
		for (size_t i = 0; i < rows; i++)
		{
			sumInCol += matr[i][j];
			if (matr[i][j] < 0)
			{
				HaveNegatives = true;
				break;
			}
		}
		if (!HaveNegatives) std::cout << "Column " << j + 1 << " sum = " << sumInCol << std::endl;
	}
}

template <typename T>
void Matrix<T>::sortBetweenMaxMin(int column)
{
	int maxIndex = iIndexOfMaxInColumn(column);//индекс первого наиБольшего элемента в столбце
	int minIndex = iIndexOfMinInColumn(column);//индекс первого наиМеньшего элемента в столбце

	if (maxIndex > minIndex) // 0 -- 1456445 --- 9
	{
		for (int k = minIndex + 1; k < maxIndex - 1; k++)
		{
			for (size_t i = minIndex + 1; i < maxIndex - 1; i++)
			{
				if (matr[i][column] > matr[i + 1][column])
				{
					std::swap(matr[i][column], matr[i + 1][column]);
				}
			}
		}
	}
	else // 9 ---5456654---1
	{
		for (int k = maxIndex + 1; k < minIndex - 1; k++)
		{
			for (size_t i = maxIndex + 1; i < minIndex - 1; i++)
			{
				if (matr[i][column] < matr[i + 1][column])
				{
					std::swap(matr[i][column], matr[i + 1][column]);
				}
			}
		}
	}

}

template <typename T>
Matrix<T>::~Matrix()
{
	//удаление исходной матрицы
	for (int i = 0; i < rows; i++)
	{
		delete[] matr[i];
	}
	delete[] matr;
}
