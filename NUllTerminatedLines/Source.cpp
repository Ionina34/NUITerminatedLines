#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

#define tab "\t"
#define Escape 27

int StringLenght(char str[]);//Принимаепт строку и  возвращает размер строки(кол-во символов в строке);

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
