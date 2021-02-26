#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

using namespace std;
#pragma warning(disable : 4996)
int main()
{
	const int msl = 100;

	//ввод необходимых значений
	char str1[msl];
	printf("%s", "str1 = ");
	scanf("%s", str1);

	getchar();

	char str2[msl];
	printf("%s", "str2 = ");
	scanf("%s", str2);

	getchar();

	char symbol;
	printf("%s", "symbol = ");
	scanf("%c", &symbol);

	getchar();

	char sym_n[5];
	printf("%s", "n = ");
	scanf("%s", &sym_n);
	int n = atoi(sym_n);


	//сам алгоритм

	char* last_symb = strrchr(str1, symbol); // указатель последнего symbol в str1

	char* sub_str2 = strchr(str2, symbol); //подстрока str2

	
	strncpy(last_symb, sub_str2, n);

	printf("%s", "str1 = ");
	printf("%s", str1);

	return 0;
}
/*
str1 = plmamkonjiabhuvgy
str2 = NJIaBFEXGF
symbol = a
n = 4

*/

