#include "Header.h"
#include "Time.h"
#include "Employee.h"
#include "Matrix.h"


int main()
{
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    system("chcp 1251");
    srand(time(NULL));
        
    exer25();

    std::cout << "test88";
}

/*Результаты соревнований по прыжкам в длину представлены в виде матрицы 5х3
(5 спортсменов по 3 попытки у каждого). Указать, какой спортсмен и в какой попытке показал наилучший результат.*/

void exer21()
{
    Matrix<double> results{ 5,3 };
    results.fillMatrixManual("Спортсмен #", "Попытка #");
    results.showMatrix();
    results.ShowPosOfMax();
}

/* тестовый код класса Time
Time m1(12, 35, 30);
    Time m2(7, 15, 15);

    std::cout << m1;
    std::cout << m2;
    std::cout << (m1+m2);
    std::cout << (m1-m2);
    std::cout << (m2-m1);
    std::cout << m2-515;*/

/*Дана матрица. Найти сумму элементов в тех столбцах, которые не содержат отрицательные элементы. 
* 
Количество столбцов и строк матрицы должен вводить пользователь. По введенным данным, динамически,
должна выделиться память под матрицу. Матрицу заполнять случайными значениями, как отрицательными
так и положительными. */
void exer25()
{
    int rows = input<int>("Enter rows:");
    int cols = input<int>("Enter columns:");
    Matrix<int> m{ rows,cols };
    m.fillMatrixRandInt(-1, 5);
    m.showMatrix();
    m.exerSum();//Этот метод и делает: @суммы элементов в тех столбцах, которые не содержат отрицательные элементы. 
}

/*В массиве 7х7 целого типа в каждом столбце упорядочить элементы, расположенные между максимальным и минимальным.*/
void exer27()
{
    Matrix<int> MyMatrix(7, 7);
    MyMatrix.fillMatrixRandInt(9);
    MyMatrix.showMatrix();

    for (size_t i = 0; i < 7; i++)
    {
        MyMatrix.sortBetweenMaxMin(i);
    }
    cout << "Changed matrix:\n";
    MyMatrix.showMatrix();
}

//тестовый код класса Employee
//static void exer14()
//{
//    std::list<Employee> workers;
//    Employee alex("AlexW", 5, 400, 160);
//    std::cout << alex << std::endl;
//        
//    workers.push_back(alex);
//    workers.push_back(Employee("Ben", 4, 300, 190));
//
//    //Читаем из списка работников и считаем им зарплаты выдаются файлы
//    std::ifstream in;
//    std::string tempString;
//    in.open("C:\\\\Users\\\\Oleg Vasilev\\\\Desktop\\\\testCodeDirectory\\\\list.txt");
//    while (std::getline(in,tempString))
//    {
//        std::string surName="";
//        std::string temp="";
//        double workExperience=-1;
//        int hourlyRate=-1;
//        int doneHours=-1;
//
//        for (size_t i = 0; i < tempString.length(); i++)
//        {
//            if (tempString[i] == ':')
//            {
//                i++;
//                int count=0;
//                if (surName.empty())
//                {
//                    while (tempString[i] != ',')
//                    {
//                        surName+= tempString[i];
//                        i++;
//                    }
//                }
//                else if (workExperience == -1)
//                {
//                    while (tempString[i] <= '9')
//                    {
//                        temp+= tempString[i];
//                        i++;
//                    }
//                    workExperience = stod(temp);
//                    temp.clear();
//                }
//                else if (hourlyRate == -1)
//                {
//                    while (tempString[i] <='9')
//                    {
//                        temp+= tempString[i];
//                        i++;
//                    }
//                    hourlyRate = stoi(temp);
//                    temp.clear();
//                }
//                else //СЧИТАЕМ ОТРАБОТАННЫЕ ЧАСЫ
//                {
//                    while (tempString[i] <= '9')
//                    {
//                        temp+= tempString[i];
//                        i++;
//                        if (i == tempString.length()) break;
//                    }
//                    doneHours= stoi(temp);
//                    temp.clear();
//                }
//            }
//        }
//        workers.push_back(Employee(surName.c_str(), workExperience, hourlyRate, doneHours));
//    }
//    in.close();
//
//    std::cout << "\n\n";
//    for (Employee elem : workers)
//    {
//        std::cout << elem << endl;
//        elem.writeInfoToFile();
//    }
//}

//