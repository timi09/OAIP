#include <stdio.h> 
#include <string.h> 

using namespace std;
#pragma warning(disable : 4996)
int main()
{
	// this might be a good time to learn a new football expression

	const int msl = 1000;

	char text[msl];
	printf("%s", "text = ");
	gets_s(text);

	char symbol;
	printf("%s", "symbol = ");
	scanf("%c", &symbol);
	
	while (true)
	{
		char* last_word = strrchr(text, ' ') + 1;

		if (last_word - 1 == nullptr)
		{
			last_word = text;
		}

		if (strchr(last_word, symbol) != nullptr)
		{
			printf("%s", last_word);
			printf("%s", "\r\n");
		}

		if (last_word == text)
		{
			break;
		}
		else
		{
			char cut_text[msl] = "";
			strncpy(cut_text, text, strlen(text) - strlen(last_word) - 1);

			strcpy(text, cut_text);
		}

	}

	return 0;
}