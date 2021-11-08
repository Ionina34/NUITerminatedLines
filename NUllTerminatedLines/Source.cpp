#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

#define tab "\t"
#define Escape 27
//#define KEY
//#define NULLTERMINATEDLINES

int StringLenght(char str[]);//Принимаепт строку и  возвращает размер строки(кол-во символов в строке);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);
bool is_int_number(char str[]);
bool is_bin_number(char str[]);
bool is_hex_number(char str[]);
int string_to_int(char str[]);
int bin_to_int(char str[]);
int hex_to_int(char str[]);

#ifdef KEY
void main()
{
	char key;
	do
	{
		key = _getch();
		cout << int(key) << tab << key << endl;
	} while (key != Escape);
}
#endif // KEY


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

#ifdef NULLTERMINATEDLINES
	cout << "1-да        0-нет" << endl;
	cout << "Строка вверхнем регистре: " << endl;
	to_upper(str);
	cout << str << endl;
	cout << "Строка в нижнем регистре: " << endl;
	to_lower(str);
	cout << str << endl;
	cout << "Удаляем лишние пробелы: " << endl;
	shrink(str);
	cout << str << endl;
	cout << "Является ли строка палиндромом: " << is_palindrome(str) << endl;
	cout << "Является ли строка целым 10-тичным чилом: " << is_int_number(str) << endl;
	cout << "Является ли строка 2-ичным числом: " << is_bin_number(str) << endl;
	cout << "Является ли строка 16-ричным числом: " << is_hex_number(str) << endl;
#endif // NULLTERMINATEDLINES

	cout << string_to_int(str) << endl;
	cout << bin_to_int(str) << endl;
	cout << hex_to_int(str) << endl;

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
		//str[i] = toupper(str[i]); //Функция toupper() возвращает принятую букву в верхнем регистре.
		//Функции toupper() и tolower() находятся в библиотеке ctype.h (ссtype) 	
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
	/*int n=1;
	for (int i = 0; str[i]; i++)
	{
		n++;
	}*/
	bool palindrome = 0;
	int n = StringLenght(str);
	for (int i = 0; i <= n; i++)
	{
		if (str[i] == str[n - 1])
		{
			palindrome = 1;
		}
		else if (str[i] != str[n - 1])
		{
			break;
		}
		n--;
	}
	return palindrome;
}
bool is_int_number(char str[])
{
	bool number = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[0] == '0')
		{
			number = 0; break;
		}
		if ((str[i] <= '0') ||(str[i] >= '9'))
		{
			number = 0; break;
		}
		else if ((str[i] >= '0') && (str[i] <= '9'))
		{
			number = 1;
		}
	}
	return number;
}
bool is_bin_number(char str[])
{
	bool number = 0;
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] == '1') || (str[i] == '0'))
		{
			number = 1;
		}
		if ((str[i] != '1') && (str[i] != '0'))
		{
			number = 0; break;
		}
	}
	return number;
}
bool is_hex_number(char str[])
{
	bool number = 0;
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			number = 1;
		}
		else if ((str[i] >= 'A') && (str[i] <= 'F'))
		{
			number = 1;
		}
		else if ((str[i] >= 'a') && (str[i] <= 'f'))
		{
			number = 1;
		}
		else if ((str[i] < '0') || (str[i] > '9'))
		{
			number = 0; break;
		}
		else if ((str[i] < 'A') || (str[i] > 'F'))
		{
			number = 0; break;
		}
		else if ((str[i] < 'a') || (str[i] > 'f'))
		{
			number = 0; break;
		}
		/*else if (str[i] == 'g')
		{
			number = 0; break;
		}*/
	}
	return number;
}
int string_to_int(char str[])
{
	int znachenie = 0;
	if (is_int_number(str) == 1)
	{
		for (int i = 0; str[i]; i++)
		{
			znachenie = znachenie * 10 + (str[i]-'0');
		}
	}
	else
	{
		cout << "Число не является десятичным!" << endl;
		//znachenie = 0;
	}
	return znachenie;
}
int bin_to_int(char str[])
{
	int znachenie = 0;
	if (is_bin_number(str) == 1)
	{
		for (int i = 0; str[i]; i++)
		{
			znachenie = znachenie * 2 + (str[i]-'0');
		}
	}
	else
	{
		cout << "Число не является двоичным!" << endl;
	}
	return znachenie;
}
int hex_to_int(char str[])
{
	int znachenie = 0;
	if (is_hex_number(str))
	{
		for (int i = 0; str[i]; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				znachenie = znachenie * 16 + (str[i] - '0');
			}
			if (str[i] >= 'a' && str[i] <= 'f')
			{
				znachenie = znachenie * 16 + (str[i] - 87);
			}
			if (str[i] >= 'A' && str[i] <= 'F')
			{
				znachenie = znachenie * 16 + (str[i] - 55);
			}
		}
	}
	else
	{
		cout << "Число не является шестнадцатеричным!" << endl;
	}
	return znachenie;
}
