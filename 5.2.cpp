#include "pch.h"
#include <iostream>
#include <string> 
#include <vector> 

using namespace std;

struct Worker
{
	string Surname;
	string Post;
	unsigned int DaysWorked;
	unsigned int CountOfLate;

	string SalaryChange;
};

vector<Worker> WorkersInput(int count);
void WorkersOutput(vector<Worker> workers);
void Control(vector<Worker>& workers);
void Check(Worker& worker);

int main()
{
	system("chcp 1251");


	/*
	
	A дир. 100 15
	B зам.дир. 100 3
	C глав.бух. 100 25
	D зам.глав.бух. 100 5
	E бух. 100 2
	F юр. 100 20

	*/

	int n;
	cout << "n = ";
	cin >> n;

	vector<Worker> Workers = WorkersInput(n);
	
	Control(Workers);

	WorkersOutput(Workers);

	system("pause");
	return 0;
}

vector<Worker> WorkersInput(int count)
{
	vector<Worker> Workers;
	for (size_t i = 0; i < count; i++)
	{
		Worker worker = Worker();

		cout << "Input worker: ";
		cin >> worker.Surname 
			>> worker.Post
			>> worker.DaysWorked
			>> worker.CountOfLate;

		cout << endl;

		Workers.push_back(worker);
	}
	return Workers;
}

void Control(vector<Worker>& workers)
{
	for (vector<Worker>::iterator i = workers.begin(); i != workers.end(); ++i)
	{
		Check(*i);
	}
}

void Check(Worker& worker) 
{
	if ((double)worker.CountOfLate / worker.DaysWorked < 0.05)
	{
		worker.SalaryChange = "премия";
	}
	else if((double)worker.CountOfLate / worker.DaysWorked > 0.2)
	{
		worker.SalaryChange = "штраф";
	}
	else
	{
		worker.SalaryChange = "без изменений";
	}
}

void WorkersOutput(vector<Worker> workers)
{
	for (Worker worker : workers)
	{
		cout << "Output worker: ";
		cout << worker.Surname << " " 
			 << worker.Post << " "
			 << worker.DaysWorked << " "
			 << worker.CountOfLate << " "
			 << worker.SalaryChange;
		cout << endl;
	}
}