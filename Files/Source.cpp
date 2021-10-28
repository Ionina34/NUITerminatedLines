#include<iostream>
#include<fstream>//File stream (�������� ������)
using namespace std;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef WRITE_TO_WILE
	//cout << "HelloWorld!" << endl;
	ofstream fout("file.txt", ios::app);//������� � ��������� �����
	fout << "HelloWorld!";
	fout.close();//������ ����������� ����� ����������
	system("more file.txt");
	//"notepad file.txt"  
#endif // WRITE_TO_WILE

#ifdef READ_FROM_FILE
	ifstream fin;//������� ����
	fin.open("file.txt");
	const unsigned int SIZE = 2048;
	char sz_buffer[SIZE]{};//� ��� ������ ����� ������ �� �����
	//sz_ - Sring Zero (������, ��������������� ����)
	if (fin.is_open())//���������, ������ �� ����
	{
		//TODO:���� ������, ����� ������
		while (!fin.eof())//���� �� ����� ����� -
		{
			// - ����� ������������� ������
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

	ofstream fout("201 ready.txt");
	ifstream fin("201 RAW.txt");
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
	system("notepad 201 ready.txt");
} 