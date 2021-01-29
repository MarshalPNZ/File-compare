#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	string Text_file1, Text_file2;
	vector <string> Vector_file1, Vector_file2;
	ifstream file;
	ofstream out_file;
	int StrCount; // Счетчик строк
	int difstr; // Разница количества строк 
	int Vector1; // Для количества строк в file1


	cout << "Введите название первого файла" << endl;
	cin >> Text_file1;
	cout << '\n';

	cout << "Введите название второго файла" << endl;
	cin >> Text_file2;
	cout << '\n';

	file.open(Text_file1.c_str(), ifstream::in);
	while (getline(file, Text_file1))
	{
		Vector_file1.push_back(Text_file1);
	
	}
	file.close();

	file.open(Text_file2.c_str(), ifstream::in);
	while (getline(file, Text_file2))
	{
		Vector_file2.push_back(Text_file2);
	}
	file.close();


	out_file.open("out_file.txt"); // Открытие файла для записи

	Vector1 = Vector_file1.size(); 


	//Поиск отсутствующих строк во втором файле
	if (Vector_file1.size() > Vector_file2.size()) // Если размер file1  больше file2
	{
	
		difstr = Vector_file1.size() - Vector_file2.size(); //На сколько строк file1 больше file2
		Vector1 = Vector_file1.size() - difstr;

		//Вывод в файл отсутствующих строк во втром файле
		while (difstr != 0) {
			out_file << "Отсутствует строка во втором файле:  ";
			out_file << Vector_file1[Vector_file1.size() - difstr];
			out_file << '\n' << endl;
			difstr--;

		}

	}
	
	//Поиск отсутствующих строк в первом файле
	if (Vector_file1.size() < Vector_file2.size()) // Если размер file1 меньше file2
	{
		difstr = Vector_file2.size() - Vector_file1.size(); //На сколько строк file2 больше file1

		//Вывод в файл отсутствующих строк в первом файле
		while (difstr != 0) {
			out_file << "Отсутствует строка в первом файле:  ";
			out_file << Vector_file2[Vector_file2.size() - difstr];
			out_file << '\n' << endl;
			difstr--;

		}
	}


	out_file << "Отличающиеся строки:  " << '\n' << endl;
	
	//Поиск различающихся строк
	for (StrCount = 0; StrCount < Vector1; StrCount++) //Допустим file1 и file2 имеют одинаковое количество строк
	{
	
		if (Vector_file1[StrCount] != Vector_file2[StrCount]) // Если строки различаются
		{
		
			out_file << "Строка из первого файла:  ";
			out_file << Vector_file1[StrCount],"   "; //запись в out_file строки из первого файла
			out_file << '\n';
			out_file << "Отличающаяся cтрока из второго файла:  ";
			out_file << Vector_file2[StrCount],"   "; //запись в out_file строки из второго файла
			out_file << '\n';
		
		}

	}


	out_file.close();

	cout << "Различия выведены в файле out_file.txt" << '\n';
	_getch();
	return 0;

}