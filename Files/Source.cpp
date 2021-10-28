#include<iostream>
#include<fstream>//File stream (Файловые потоки)
using namespace std;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef WRITE_TO_WILE
	//cout << "HelloWorld!" << endl;
	ofstream fout("file.txt", ios::app);//Создаем и открываем поток
	fout << "HelloWorld!";
	fout.close();//Потоки обязательно нужно закртывать
	system("more file.txt");
	//"notepad file.txt"  
#endif // WRITE_TO_WILE

#ifdef READ_FROM_FILE
	ifstream fin;//Создаем пток
	fin.open("file.txt");
	const unsigned int SIZE = 2048;
	char sz_buffer[SIZE]{};//В эту строку будем читать из файла
	//sz_ - Sring Zero (Строка, заканчивающаяся нулём)
	if (fin.is_open())//Проверяем, открыт ли файл
	{
		//TODO:если открыт, будем читать
		while (!fin.eof())//Пока НЕ конец файла -
		{
			// - будет производиться чтение
			//eof()- End Of file
			//fin >> sz_buffer;
			fin.ignore();
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
	}
	else
	{
		cerr << "Error: file not found" << endl;
	}
	fin.close();
#endif // READ_FROM_FILE

	const unsigned int SIZE = 256;
	char sz_source_filename[SIZE] = {};       //Source - исходник, источник
	char sz_destination_filename[SIZE] = {};  //Destination - пункт назначения 
	cout << "Введите имя исходного файла: "; cin.getline(sz_source_filename,SIZE);
	//1)Находим последнюю точку в строку:
	char* extension = strrchr(sz_source_filename, '.');
	//2)Теперь нужно проверить, являются ли символы после последней точки правильным расширением файла:
	if (extension == nullptr || strcmp(extension, ".txt") != 0)
	{
		strcat(sz_source_filename,".txt");
	}

	//cout <<(extension ? extension: "У файла нет расширения" )<< endl;

	//char* strchr(char* str, char symbol);
	//Функция strchr находит указанный символ (symbol) в указанной строке (str) 
	//и возвращает указатель на найденный символ.
	//Если указанный символ (symbol) в указанной строке (str) не найден, 
	//то функция strchr возвращает указатель на 0 (nullptr - указатель в никуда).
    //Функция  strrchr делает тоже самое, но с конца строки
	cout << "Введите имя конечного файла: "; cin.getline(sz_destination_filename,SIZE);
	extension = strrchr(sz_destination_filename, '.');
	if (extension == nullptr || strcmp(extension, ".txt") != 0)
	{
		strcat(sz_destination_filename, ".txt");
	}

	//cout <<( extension?extension : "У файла нет расширения") << endl;

	//ofstream fout("201 ready.txt");
	//ifstream fin("201 RAW.txt");
	ifstream fin(sz_source_filename);
	ofstream fout(sz_destination_filename);
	const unsigned int IP_SIZE = 16;
	const unsigned int MAC_SIZE = 18;
	char sz_ip_buffer[IP_SIZE] = {};
	char sz_mac_buffer[MAC_SIZE] = {};
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> sz_ip_buffer;
			fin >> sz_mac_buffer;

			/*cout << sz_mac_buffer << "\t";
			cout<< sz_ip_buffer << "\n";*/

			fout << sz_mac_buffer << "\t";
			fout << sz_ip_buffer << "\n";
		}
	}
	else
	{
		cerr << "Error: file not found" << endl;
	}
	fin.close();
	fout.close();

	//system("notepad 201 ready.txt");
	char sz_cmd[SIZE] = "notepad ";
	strcat(sz_cmd, sz_destination_filename);
	//strcat(sz_dst,sz_src);//strcat выполняет конкатернацию(слияние) строк,
	//например, "Hello" + "World" = "HelloWorld";
	//sz_dst - строка получатель, в которую будет сохранен результат  конкатенации
	//sz_src - строка источник, которая будет добавлена к получателю.
	system(sz_cmd);
} 