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

	int ind_last_symb = last_symb - str1; // индекс последнего symbol в str1


	// первая часть строки
	char start_str1[msl] = "";
	strncpy(start_str1, str1, ind_last_symb);

	// центральная часть строки (подстрока str2)
	char* sub_str2 = strchr(str2, symbol); //подстрока str2
	char cut_substr2[msl] = "";
	strncpy(cut_substr2, sub_str2, n); // мы не евреи но строку обрезать придется...


	// последняя часть строки
	strrev(str1);
	char end_str1[msl] = "";
	int end_len = strlen(str1) - ind_last_symb - strlen(cut_substr2);
	strncpy(end_str1, str1, end_len);
	strrev(str1);
	strrev(end_str1);

	
	// соединяем все
	strcat(start_str1, cut_substr2);
	strcat(start_str1, end_str1);

	strcpy(str1, start_str1);

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