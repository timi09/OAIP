#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

enum PrintedEditions
{
	book,
    newspaper,
    magazine,
    almanac,
    collection,
    bulletin,

	underfind //��� ������
};

string toString(PrintedEditions Edition);
PrintedEditions toEnum(string Name);

int main()
{
	//� ����
	PrintedEditions enum1 = magazine;

	cout << toString(enum1) << endl;


	// ���� ����� ����� �����
    cout << "i = ";
    int i;
    cin >> i;

    PrintedEditions enum2 = static_cast<PrintedEditions>(i);

    cout << toString(enum2) << endl;


	// ���� ����� ������
	cout << "str = ";
	string str;
	cin >> str;

	PrintedEditions enum3 = toEnum(str);

	cout << toString(enum3) << endl;

	system("pause");
	return 0;
}

PrintedEditions toEnum(string Name)
{
	if (Name == "book")
	{
		return book;
	}
	else if (Name == "newspaper")
	{
		return newspaper;
	}
	else if (Name == "magazine")
	{
		return magazine;
	}
	else if (Name == "almanac")
	{
		return almanac;
	}
	else if (Name == "collection")
	{
		return collection;
	}
	else if (Name == "bulletin")
	{
		return bulletin;
	}
	else
		return underfind;

}

string toString(PrintedEditions Edition)
{
    string Names[7] = {

        "book",
        "newspaper",
        "magazine",
        "almanac",
        "collection",
        "bulletin",
		"underfind"
    };

    return Names[Edition];
}