#include <stdio.h> 
#include <stdlib.h>

using namespace std;
#pragma warning(disable : 4996)

int custom_strlen(char* str);
void input_in_str(char* str, char* substr, unsigned i);
void strinsi(char* str, char* substr, unsigned* i, unsigned i_len);

int main()
{
	const int msl = 1000;
	
	//основная строка
	char str[msl];  
	printf("%s", "str = ");  // ABCDEFGHLMNKOPQ
	gets_s(str);
	
	char substr[msl];
	printf("%s", "substr = ");
	gets_s(substr);
	

	const int arr_len = 5; //длинна массив позиций

	unsigned i[arr_len]; // массив позиций вставки (должен быть длинны подстроки)
	//ввод массива позиций
	printf("%s", "array of indexes = ");
	for (int j = 0; j < arr_len; j++)
	{
		char str_ind[3]; // максимум трехзначное число
		scanf("%s", &str_ind);
		int ind = atoi(str_ind);
		i[j] = ind;
	}
	
	strinsi(str, substr, i, arr_len);
	
	printf("%s", str);

	return 0;
}

void strinsi(char* str, char* substr, unsigned* i, unsigned i_len)
{
	int substr_len = custom_strlen(substr);

	for (int j = 0; j < i_len; j++)
	{
		input_in_str(str, substr, *(i+j) + (substr_len - 1)*j);
	}
}

void input_in_str(char* str, char* substr, unsigned ind)
{
	int str_len = custom_strlen(str);
	int substr_len = custom_strlen(substr);

	for (char* j = str + str_len; j > str + ind - 1; j--)
	{
		*(j + substr_len-1) = *j;
	}

	for (int j = 0; j < substr_len; j++)
	{
		*(str + ind + j) = *(substr + j);
	}
}

int custom_strlen(char* str)
{
	int str_len = 0;
	char* next_char = str;
	while (*next_char != '\0')
	{
		str_len++;
		next_char++;
	}

	return str_len;
}


//int main()
//{
//	const int msl = 1000;
//
//	//основная строка
//	char str[msl];
//	printf("%s", "str = ");
//	gets_s(str);
//
//	const int substr_len = 5; //длинна подстроки
//
//	char substr[substr_len + 1];
//	printf("%s", "substr = ");
//	gets_s(substr);
//
//	unsigned i[substr_len]; // массив позиций вставки (должен быть длинны подстроки)
//	//ввод массива позиций
//	printf("%s", "array of indexes = ");
//	for (int j = 0; j < substr_len; j++)
//	{
//		char str_ind[3]; // максимум трехзначное число
//		scanf("%s", &str_ind);
//		int ind = atoi(str_ind);
//		i[j] = ind;
//	}
//
//	strinsi(str, substr, i, substr_len);
//
//	printf("%s", str);
//
//	return 0;
//}