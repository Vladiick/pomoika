﻿#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <windows.h>
#include "MyString.h"
#include "coordinate.h"
#include "MyStringIdentifier.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

void TestIdString() {
	bool exit = false;
	char menu;
	int num;
	string st;
	MyStringIdentifier IdStr;
	MyStringIdentifier OtherIdStr;
	cin.get();
	do
	{
		system("CLS");
		cout << "Тестирование класса Стрка Идентифекатор" << endl
			<< "1 - показать содержимое строки" << endl
			<< "2 - ввести строку" << endl
			<< "3 - поиск последнего вхождениясимвола в строку" << endl
			<< "4 - проверка на равенство ==" << endl
			<< "5 - проверка операции индексации []" << endl
			<< "q - выход" << endl
			<< endl << ">>";

		cin >> menu;
		switch (menu)
		{
		case '1':
			cout << "Строка:" << endl;
			cout << IdStr;
			cin.get();
			cin.get();
			break;
		case '2':
			cout << "Введите строку" << endl;
			cin >> IdStr;
			cin.get();
			break;
		case '3':
			char symbol;
			int result;
			cout << "Введите символ для поиска:" << endl;
			cin >> symbol;
			result = IdStr.FindSymbol(symbol);
			if (result != -1) {
				cout << "Символ находиться в строке на позиции" << result << endl;
			}
			else
			{
				cout << "Символ не найден" << endl;
			}
			cin.get();
			cin.get();
			break;
		case '4':
			cout << "Введите вторую строку для проверки" << endl;
			cin >> OtherIdStr;
			cin.get();
			if (IdStr == OtherIdStr) {
				cout << "равны" << endl;
			}
			else
			{
				cout << "не равны" << endl;
			}
			cin.get();
			cin.get();
			break;
		case '5':
			cout << "какой элемент вы хотитет получить ?" << endl;
			cin >> num;
			cout << IdStr[num];
			cin.get();
			cin.get();
			break;
		case 'q':
			exit = true;
			cin.get();
			cin.get();
			break;
		case 'Q':
			exit = true;
			cin.get();
			cin.get();
			break;
		default:
			break;
		}
	} while (!exit);
}
int main()
{
	setlocale(LC_ALL, "");
	char menu;
	bool exit = false;
	do
	{
		system("CLS");
		cout << "ЯВУ 2. Казанцев О.А. О714Б" << endl << endl;
		cout << "1 - проверка класса Строка идентификатор" << endl;
		cout << "2 - проверка класса Шестнадцетиричная Строка" << endl;
		cout << "q - выход" << endl;
		cout << endl << ">>";
		cin >> menu;
		switch (menu)
		{
		case '1':
			TestIdString();
			cin.get();
			break;
		/*case '2':
			TestHexString();
			cin.get();
			break;*/
		case 'q':
			exit = true;
			break;
		case 'Q':
			exit = true;
			break;
		default:
			break;
		}
	} while (!exit);
}
