#include <iostream> 
#include <string> 

using namespace std;

string ReplaceAll(string Str, string OldSubstr, string NewSubstr);

int main()
{
	string Text;
    cout << "Text = "; // This   item  is a      commodity, where all   the individual items   are effectively identical.   Individual listings aren't accessible; you can instead issue   orders to buy  at  a       specific  price,    with the    cheapest listing getting automatically  matched      to the  highest   buy     order.

    std::getline(std::cin, Text);

    cin >> Text;
    cout << endl;

    Text = ReplaceAll(Text, "  ", " ");

    cout << "New Text = ";
    cout << Text;
    cout << endl;

	return 0;
}

string ReplaceAll(string Str, string OldSubstr, string NewSubstr) 
{
    int index = 0;
    while (true) 
    {
        index = Str.find(OldSubstr, index);
        if (index == std::string::npos) 
        {
            break;
        } 

        Str.replace(index, OldSubstr.length(), NewSubstr);

    }

    return Str;
}