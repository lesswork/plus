#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Employee
{
	int id;
	int Salary;
public:
	Employee()
	{
		cout << "Employee() cttor" << endl;
	}

	// Will not work for non virtual funtion
	// dynmic_cast work runtime. It need vtable
	// void DoSomeThing()
	virtual void DoSomeThing()
	{
		cout << "Employee() done something" << endl;
	}
};

class Manager : public Employee
{
	int permission;
public:
	void DoSomeThing()
	{
		cout << "Manager() done something" << endl;
	}
	void Approveleave()
	{
		cout << "Approveleave()" << endl;
	}
};

void processData(Employee* obj)
{
	Manager *ptr = dynamic_cast<Manager *> (obj);
	if(ptr == NULL)
	{
		cout << "Object is of Employee class" << endl;
	}
	else
	{
		cout << "Object is of Manager" << endl << "Downcast succesfull" << endl;
	}
}

int main()
{
	Employee Ajay;
	Manager Satish;

	processData(&Ajay);
	processData(&Satish);
}
