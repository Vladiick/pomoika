#define _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
using namespace std;
class coordinate
{
private:
	double Ox;
	double Oy;
	double CountSqrtMod;

public:
	void SetOx(double startOx)
	{
		Ox = startOx;
	}//������ �������� ����� 
	void SetOy(double startOy)
	{
		Oy = startOy;
	}//������ ������ ����� 
	double GetX()
	{
		return Ox;
	}//������ ������� �����
	double GetY()
	{
		return Oy;
	}//������ ������ �����
	coordinate()
	{
		Ox = 1;
		Oy = 1;
	}//����������� �����������
	void sqrtnum()
	{
		double alfa;
		double real;
		double image;
		double argz;
		int k;
		argz = Ox + Oy;
		CountSqrtMod = sqrt(pow(Ox, 2) + pow(Oy, 2));
		alfa = atan(Oy / Ox);
		CountSqrtMod = sqrt(CountSqrtMod);
		for (k = 0; k < 2; k++)
		{
			const double PI = 3.141592653589793;
			real = (cos((alfa + 2 * PI * k) / 2));
			image = (sin((alfa + 2 * PI * k) / 2));
			cout << CountSqrtMod * real << endl;
			cout << CountSqrtMod * image << endl;
			cout << "________\n";
		}
	}
	coordinate(const coordinate& other) : Ox(other.Ox), Oy(other.Oy) {}
	coordinate(double X, double Y) :Ox(X), Oy(Y) {} //������ 2 �������� ����
	void createnum()
	{

		cout << "print Ox " << endl;
		cin >> Ox;
		cout << "print Oy " << endl;
		cin >> Oy;
		cout << Ox << "+" << Oy << "i" << endl;
	}

	double korni()
	{
		CountSqrtMod = sqrt(pow(Ox, 2) + pow(Oy, 2));
		CountSqrtMod = sqrt(CountSqrtMod);
		if (Ox < 0)
			CountSqrtMod = CountSqrtMod * (-1);//������� ������
		return CountSqrtMod;
	}
	~coordinate() {}
	bool operator>(coordinate srav1)
	{
		double h, g;
		system("CLS");
		sqrtnum();
		g = korni();
		cout << "\n"
			<< g << "\n"
			<< endl;
		srav1.sqrtnum();
		h = srav1.korni();
		cout << "\n"
			<< h << "\n"
			<< endl;
		if (g > h)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(coordinate srav1)//���������� ==
	{
		double h, g;
		system("CLS");
		sqrtnum();
		g = korni();
		cout << "\n"
			<< g << "\n"
			<< endl;
		srav1.sqrtnum();
		h = srav1.korni();
		cout << "\n"
			<< h << "\n"
			<< endl;
		if (g == h)
		{
			return true;
		}
		else
			return false;
	}
};
istream& operator>>(istream& in, coordinate& tr)
{
	double val2, val3;
	val2 = 0;
	val3 = 0;
	system("cls");
	cout << "������� �������� ����� ����� " << endl;
	in >> val2;
	tr.SetOx(val2);
	cout << "������� ������ ����� " << endl;
	in >> val3;
	tr.SetOy(val3);
	return in;
}
ostream& operator<<(ostream& os, coordinate& tr) //���������� ��������� >> ������ �� ������� �������� � ��� �����
{
	return os
		<< "����� ������" << endl
		<< "������� A : " << tr.GetX() << endl
		<< "������� B : " << tr.GetY() << endl
		<< endl;
}
/*StringIdentificator operator + (const StringIdentificator& other)
{
	cout << "��������� ���������� ��������� + ��� ������������ �����"
		<< endl;
	StringIdentificator result;
	delete result.str;
	result.length = length + other.length;
	result.str = new char[result.length + 1];
	strcpy(result.str, str);
	strcpy(result.str + length, other.str);
	return result;
}*/
