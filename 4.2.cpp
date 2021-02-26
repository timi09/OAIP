#include <iostream> 
#include <string> 
#include <vector> 

using namespace std;

vector<string> Sort(vector<string> WordList);
vector<string> RemoveAllWithLen(vector<string> WordList, int WordLen);
vector<string> Split(string Str, string Delim);
string toLower(string Str);

int main()
{
    string Text;
    cout << "Text = "; // This item is a commodity where all the individual items are effectively identical
    std::getline(std::cin, Text);

    cin >> Text;
    cin.clear();
    cout << endl;

    vector<string> WordList = Split(Text, " ");

    int BanWordLen;
    cout << "BanWordLen = ";
    cin >> BanWordLen;
    cout << endl;

    WordList = RemoveAllWithLen(WordList, BanWordLen);

    WordList = Sort(WordList);

    for (auto word = WordList.begin(); word != WordList.end(); word++)
    {
        cout << *word;
        cout << endl;
    }

    cout << endl;

    return 0;
}

vector<string> Sort(vector<string> WordList)
{
    for (int i = 0; i < WordList.size() - 1; i++) 
    {
        for (int j = 0; j < WordList.size() - i - 1; j++) 
        {
            if (toLower(WordList[j]) > toLower(WordList[j + 1]))
            {
                string temp = WordList[j];
                WordList[j] = WordList[j + 1];
                WordList[j + 1] = temp;
            }
        }
    }

    return WordList;
}

string toLower(string Str)
{
    string NewStr;
    for (int i = 0; i < Str.length(); i++)
    {
        char Ch = Str[i];
        if (Ch >= 'A' && Ch <= 'Z')
        {
            Ch = Ch - ('Z' - 'z');
        }
        
        NewStr += Ch;
    }
    
    return NewStr;
}

vector<string> RemoveAllWithLen(vector<string> WordList, int WordLen)
{
    for (auto word = WordList.begin(); word != WordList.end();)
    {
        if ((*word).length() == WordLen)
        {
            word = WordList.erase(word);
        }
        else
        {
            word++;
        }
    }

    return WordList;
}

vector<string> Split(string Str, string Delim)
{
    vector<string> WordList;
    int start = 0;
    int end = 0;
    while (end != Str.length())
    {
        end = Str.find(Delim, start);
        if (end == std::string::npos)
        {
            end = Str.length();
        }

        string Word = string(Str, start, end - start);
        WordList.push_back(Word);

        start = end + 1;

    }

    return WordList;
}