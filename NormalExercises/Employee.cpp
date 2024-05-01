#include "Employee.h"

std::ostream& operator<<(std::ostream& o, const Employee emp)
{
	o << "Employee:" << emp.surName << ", workExperience:" << emp.workExperience <<
		" years, hourlyRate: " << emp.hourlyRate << " rubbles, hours of work this mounth: " << emp.doneHours;
	return o;
}

Employee::Employee()
{
	std::cout << "Enter worker's name:";
	getline(std::cin, surName);
	std::cout << "Enter worker's experience:";
	std::cin >> workExperience;
	std::cout << "Enter worker's hourly rate:";
	std::cin >> hourlyRate;
	std::cout << "Enter how much hours "<< surName<<" has worked this month: ";
	std::cin >> doneHours;
}

Employee::Employee(const char* name, int workExperience, int hourlyRate, int doneHours) 
{
	this->surName = name;
	this->workExperience = workExperience;
	this->hourlyRate = hourlyRate;
	this->doneHours = doneHours;
};

void Employee::setHourlyRate(int hourlyRate)
{
	this->hourlyRate = hourlyRate;
}
void Employee::setDoneHours(int doneHours)
{
	this->doneHours = doneHours;
}

void Employee::setWorkExp(int workExperience)
{
	this->workExperience = workExperience;
}

int Employee::calculateSalaryMounth(bool endMonth)
{
	int salary;
	salary = doneHours * hourlyRate;
	int award=0;
	// (при стаже до 1 года 0%, до 3 лет 5%, до 5 лет 8%, свыше 5 лет 15%).
	if (workExperience > 5) award = salary * 0.15;
	else if (workExperience > 3) award = salary * 0.08;
	else if (workExperience > 1) award = salary * 0.05;
	std::cout << "Salary: " << salary << " rubles, award: " << award << std::endl;
	/*std::cout << "Is the month finished? Clear done hours? Y/N\n: ";
	char answer;
	std::cin >> answer;*/
	if (/*answer == 'y' || answer == 'Y'*/endMonth)
	{
		doneHours = 0;
		workExperience += 1 / 12;
	}
	return salary + award;
}

void Employee::writeInfoToFile()
{
	std::ofstream out;
	std::string file = "C:\\\\Users\\\\Oleg Vasilev\\\\Desktop\\\\testCodeDirectory\\\\" + surName + ".txt";
	out.open(file);
	
	out<< "Employee:" << surName << ", workExperience:" << workExperience <<
		" years, hourlyRate: " << hourlyRate << " rubbles, hours of work this mounth: " << doneHours<<std::endl;
	out << "Salary this month:" << calculateSalaryMounth() << std::endl;
	
	out.close();
}