#include<iostream>
#include<string.h>
using namespace std;

//#define COPY_AND_LENGTH
//#define COPY_MEMORY
//#define CONCATENATION
//#define COMPARISON

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef COPY_AND_LENGTH
	const unsigned int SIZE = 256;
	char str[SIZE] = {};
	cout << "¬ведите строку: ";
	cin.getline(str, SIZE);
	cout << str << endl;
	cout << "ƒлина введенной строки: " << strlen(str) << endl;

	// опирование строк:
	char dst[SIZE] = {};
	strcpy(dst, str);//string copy
	//strcpy(dst,src);
	//dst (destination) - строка-получатель, в которую скопируетс€ друга€ строка.
	//src (source)      - строка-источник, содержимое которой будем копировать.
	cout << " опи€ строки: " << dst << endl;
#endif // COPY_AND_LENGTH

#ifdef COPY_MEMORY
	const int SIZE = 5;
	int arr[SIZE] = { 3,5,8,13,21 };
	int brr[SIZE] = {};
	memcpy(brr, arr, SIZE * sizeof(int));// опирует содержимое области пам€ти в другую
	for (int i = 0; i < SIZE; i++)
	{
		cout << brr[i] << "\t";
	}
	cout << endl;
#endif // COPY_MEMORY

#ifdef CONCATENATION
	// онкатенаци€ (объ€денение/сли€ние) строк:
	const size_t SIZE = 256;
	char str1[SIZE] = {};
	char str2[SIZE] = {};
	cout << "¬ведите первую строку: "; cin >> str1;
	cout << "¬ведите вторую строку: "; cin >> str2;
	strcat(str1, str2);//+=
	strncat(str1, str2, 2); //2-число символов второй строки, которые нужно скопировать
	cout << "str1:\t" << str1 << endl;
	cout << "str2:\t" << str2 << endl;
#endif // CONCATENATION

#ifdef COMPARISON
	/*char str1[] = "Hello";
char str2[] = "Hello";
cout << strcmp(str1, str2) << endl;*/
//strcmp - может вернуть 0, значение больше 0 или значение меньше 0
//если strcmp вернуло 0 - строки индетичны 
//если значение меньше 0 - первый несовпадающий символ в первой строке меньше того же символа во второй строке
//если strcmp вернуло значение больше 0 - то первый несовпадающий символ первой строки больше того же символа второй строки

	const char* movie[] =
	{
		"Hello",
		"World",
		"Avatar",
		"Terminator",
		"Captain America",
		"Tor",
		"Loki"
	};
	for (int i = 0; i < sizeof(movie) / sizeof(const char*); i++)
	{
		cout << movie[i] << endl;
	}

	for (int i = 0; i < sizeof(movie) / sizeof(const char*); i++)
	{
		for (int j = i + 1; j < sizeof(movie) / sizeof(const char*); j++)
		{
			if (strcmp(movie[i], movie[j]) > 0)
			{
				const char* buffer = movie[i];
				movie[i] = movie[j];
				movie[j] = buffer;
			}
		}
	}

	cout << "\n-----------------------------------------------\n";
	for (int i = 0; i < sizeof(movie) / sizeof(const char*); i++)
	{
		cout << movie[i] << endl;
	}
#endif // COMPARISON

	const size_t n = 5;
	int arr[n];
	memset(arr,0x00FF,n*sizeof(int));//memset-заполн€ет мусор значени€ми
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}