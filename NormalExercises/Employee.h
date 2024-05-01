#pragma once
#include<iostream>
#include <sstream>
#include <fstream>
//Создать класс, описывающий понятие работник, со свойствами :
//
//фамилия;
//стаж;
//часовая заработная плата;
//количество отработанных часов.

class Employee
{
	std::string surName;
	double workExperience;
	int hourlyRate;
	int doneHours;

public:
	Employee();
	Employee(const char* name, int workExperience,	int hourlyRate,	int doneHours);
	
	int calculateSalaryMounth(bool endMonth = false);
	void setWorkExp(int workExperience);
	void setHourlyRate(int hourlyRate);
	void setDoneHours(int doneHours);

	void writeInfoToFile();

	friend std::ostream& operator<<(std::ostream& o, const Employee emp);
};




