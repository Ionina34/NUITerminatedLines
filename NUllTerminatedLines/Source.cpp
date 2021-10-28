#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

#define tab "\t"
#define Escape 27

int StringLenght(char str[]);//Принимаепт строку и  возвращает размер строки(кол-во символов в строке);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);

//void main()
//{
//	char key;
//	do
//	{
//		key = _getch();
//		cout << (int)key << tab << key << endl;
//	} while (key != Escape);
//}

void main()
{
	setlocale(LC_ALL, "Ru");
	char key;
	SetConsoleCP(1251);	//Выставляет кодировку на ввод
	SetConsoleOutputCP(1251);//Выставляет кодировку на вывод	
	//char str[] = { 'H','e','l','l','o',0};
	/*char str[] = "Hello";
	cout << str << endl;
	cout << str[1] << endl;
	cout << sizeof(str) << endl;*/
	const int n = 20;
	char str[n] = {};
	cout << "Введите строку: ";
	//cin >> str;
	cin.getline(str, n);
	//SetConsoleCP(866);
	cout << str << endl;
	cout << StringLenght(str) << endl;
	/*to_upper(str);
	cout << str << endl;
	to_lower(str);
	cout << str << endl;*/
	shrink(str);
	cout << str << endl;
	/*cin >> key;
	cout << (char)(key - 32);*/
}

int StringLenght(char str[])
{
	/*cout << typeid(str).name() << endl;
	return sizeof(str);*/
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))str[i] = str[i] - 32;
		if ((str[i] >= 'а') && (str[i] <= 'я'))str[i] = str[i] - 32;
	}
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))str[i] = str[i] + 32;
		if ((str[i] >= 'А') && (str[i] <= 'Я'))str[i] = str[i] + 32;
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] == ' ') && (str[i + 1] == ' '))
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
		}
	}
}
bool is_palindrome(char str[])
{
	
}