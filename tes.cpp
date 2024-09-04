#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h> 
#include <string.h>
#include <iostream>



using namespace std;

bool real_check(char *a, char *b, int c) {
	for (int i = 0; i < c; i++)
	{
		if ('g' == a[0] && 'r' == a[1] && 'e' == a[2] && 'p' == a[3]) {		//проверка на наличие слова grep
			if (b[i] == 'g' && b[i + 1] == ' ') {							//проверка на проблел после grep
				if (sizeof(a) / sizeof(a[0]) >= 4) {						//проверка на содержание массива
					return true;
				}
			}
		}
	}
}




int main() {
	setlocale(LC_ALL, "ru");
	const int co = 80 + 1;
	char first_s[co];											//введенная строка с сохранением знаков 
	int len_arr = 0;
	const int len_id = 12;
	char identific[len_id] = { '-e', '-i', '-v', '-c', '-l', '-n', '-h', '-s', '-o', '-f', '-iv', '-in' };	//массив ключей   потом прибавить -f file

	fgets(first_s, sizeof(first_s), stdin);						//ввод команды с идентификатором

	int co_spaces = 0;

	for (int j = 0; first_s[j] != NULL; j++)					//делаем массив без проблелов
	{
		if (first_s[j] != ' ') {
			len_arr++;
		}
	}

	char* second_s = new char[len_arr+1];
	int count = 0;

	for (int i = 0; i <= len_arr+100; i++)					//делаем строку слитной
	{

		if ( (first_s[i] != ' ')) {
			second_s[count] = first_s[i];
			count++;
		}
	}

	if (real_check(second_s, first_s, len_arr)) {
		cout << "TR";
	}
}
