#pragma once
#include <iostream>
using namespace std;

class MyString
{
protected:
	static long unsigned int copy; //��� ��������, ������� ��� �������� �����������	
public:
	char* Str;
	long unsigned int length;

	unsigned long int GetLength()
	{
		cout << "�������� ����� ��������� ����� ������" << endl;
		return this->length;
	}

	MyString() {
		cout << "�������� ����������� �� ���������" << endl;
		Str = new char[1];
		Str[0] = '\0';
		length = 1;
	}
	MyString(char* UserString) {
		cout << "�������� ����������� � ���������� ��-������" << endl;
		Str = new char[strlen(UserString) + 1];
		length = (strlen(UserString) + 1);
		for (long unsigned int i = 0; i < length; i++) {
			Str[i] = UserString[i];
		}
		Str[length - 1] = '\0';
	}
	MyString(const MyString& CopyString) {
		copy++;
		cout << "�������� ����������� ����������� (" << copy << "-� ���)" << endl;
		length = (strlen(CopyString.Str) + 1);
		Str = new char[length + 1];
		for (long unsigned int i = 0; i < length; i++) {
			Str[i] = CopyString.Str[i];
		}
		Str[length] = '\0';
	}
	MyString(char symbol)
	{
		cout << "�������� ����������� � ���������� ������ char" << endl;
		Str = new char[2];
		Str[0] = symbol;
		Str[1] = '\0';
		length = 0;
	}
	virtual MyString& operator = (const MyString& other)
	{
		cout << "�������� ����� ���������� �������� =" << endl;
		if (Str != nullptr)
			delete[] Str;
		int length = strlen(other.Str);
		Str = new char[length + 1];
		for (unsigned int i = 0; i < length; i++)
			Str[i] = other.Str[i];
		Str[length] = '\0';
		return *this;
	}
	void SetEmptyString()
	{
		length = 1;
		Str[length - 1] = '\0';
	}
	void Print()
	{
		cout << Str << endl;
	}
	void set(const char* UserString) {
		Str = new char[strlen(UserString) + 1];
		length = (strlen(UserString) + 1);
		for (long unsigned int i = 0; i < length; i++) {
			Str[i] = UserString[i];
		}
		Str[length - 1] = '\0';
	}

	friend ostream& operator << (ostream& out, MyString& other)
	{
		out << other.Str << endl;
		return out;
	}
	friend istream& operator >> (istream& in, MyString& other) {
		string st;
		in >> st;
		other.set(st.c_str());
		return in;
	}
	virtual ~MyString()
	{
		cout << "�������� ����������" << endl;
		delete[] this->Str;
	}
	virtual void SetLowerCase() {}
	virtual void Angle() {};
};
long unsigned int MyString::copy = 0;