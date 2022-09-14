#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class MyString
{
protected:
	static long unsigned int copy; //��� ��������, ������� ��� �������� �����������	
public:
	char* str;
	long unsigned int length;

	unsigned long int GetLength()
	{
		cout << "�������� ����� ��������� ����� ������" << endl;
		return this->length;
	}

	MyString() {
		cout << "�������� ����������� �� ���������" << endl;
		str = new char[1];
		str[0] = '\0';
		length = 1;
	}

	MyString(char* UserString) {
		cout << "�������� ����������� � ���������� ��-������" << endl;
		str = new char[strlen(UserString) + 1];
		length = (strlen(UserString) + 1);
		for (long unsigned int i = 0; i < length; i++) {
			str[i] = UserString[i];
		}
		str[length - 1] = '\0';
	}

	MyString(const MyString& CopyString) {
		copy++;
		cout << "�������� ����������� ����������� (" << copy << "-� ���)" << endl;
		length = (strlen(CopyString.str) + 1);
		str = new char[length + 1];
		for (long unsigned int i = 0; i < length; i++) {
			str[i] = CopyString.str[i];
		}
		str[length] = '\0';
	}

	MyString(char symbol)
	{
		cout << "�������� ����������� � ���������� ������ charr" << endl;
		str = new char[2];
		str[0] = symbol;
		str[1] = '\0';
		length = 0;
	}

	virtual MyString& operator = (const MyString& other)
	{
		cout << "�������� ����� ���������� �������� =" << endl;
		if (str != nullptr)
			delete[] str;
		int length = strlen(other.str);
		str = new char[length + 1];
		for (unsigned int i = 0; i < length; i++)
			str[i] = other.str[i];
		str[length] = '\0';
		return *this;
	}

	void SetEmptyString()
	{
		length = 1;
		str[length - 1] = '\0';
	}

	void Print()
	{
		cout << str << endl;
	}

	void set(const char* UserString) {
		str = new char[strlen(UserString) + 1];
		length = (strlen(UserString) + 1);
		for (long unsigned int i = 0; i < length; i++) {
			str[i] = UserString[i];
		}
		str[length - 1] = '\0';
	}
	friend ostream& operator << (ostream& out, MyString& other)
	{
		out << other.str << endl;
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
		delete[] this->str;
	}
	virtual void SetLowerCase() {}
	virtual void Angle() {};
};
long unsigned int MyString::copy = 0;
long unsigned int MyString::copy = 0;

