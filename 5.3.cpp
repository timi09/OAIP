#include <iostream>

using namespace std;

enum PrintedEditions
{
	books,
    newspapers,
    magazines,
    almanacs,
    collections,
    bulletins
};

string toString(PrintedEditions Edition);

int main()
{
    cout << "i = ";
    int i;
    cin >> i;

    PrintedEditions some = static_cast<PrintedEditions>(i);

    cout << toString(some) << endl;

    PrintedEditions some2 = magazines;

    cout << toString(some2) << endl;
	
	system("pause");
	return 0;
}

string toString(PrintedEditions Edition)
{
    string Names[6] = {

        "book",
        "newspaper",
        "magazine",
        "almanac",
        "collection",
        "bulletin" 
    };

    return Names[Edition];
}