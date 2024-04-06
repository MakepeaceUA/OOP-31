#include <iostream>
#include <fstream>
using namespace std;

//Задание #1
class Fraction 
{
	int Num, Denom;

public:
    Fraction() 
	{
		Num = 1;
		Denom = 1;
	}

	Fraction(int X,int Y) 
	{
		Num = X;
		Denom = Y;
	}
	
	void SetNum(int value)
	{
		Num = value;
	}

	void SetDenom(int value)
	{
		Denom = value;
		
    }
	int GetNum()
	{
		return Num;
	}

	int GetDenom() 
	{
		return Denom;
	}

	void Sum(Fraction Fr) 
	{
		Num = Num * Fr.Denom + Fr.Num * Denom;
		Denom = Denom * Fr.Denom;
		cout << "Sum:" << Num << "/" << Denom << "\n\n";
    }
	void Dif(Fraction Fr) 
	{
		Num = Num * Fr.Denom - Fr.Num * Denom;
		Denom = Denom * Fr.Denom;
		cout << "Difference:" << Num << "/" << Denom << "\n\n";
	}

	void Mult(Fraction Fr) 
	{
		Num *= Fr.Num;
		Denom *= Fr.Denom;
		cout << "Multiply:" << Num << "/" << Denom << "\n\n";
	}

	void Div(Fraction Fr) 
	{
		if (Fr.Num != 0) 
		{
			Num *= Fr.Denom;
			Denom *= Fr.Num;
			cout << "Dived:" << Num << "/" << Denom << "\n\n";
		}
		else 
		{
		  cout << "Error." << "\n";
		}
	}

	void Output() 
	{
		cout << Num << "/" << Denom << "\n\n";
	}

	Fraction operator+(const Fraction& Fr) 
	{
		int Sum_Num = Num * Fr.Denom + Fr.Num * Denom;
		int Sum_Demom = Denom * Fr.Denom;
		return Fraction(Sum_Num, Sum_Demom);
	}

	Fraction operator-(const Fraction& Fr)
	{
		int Dif_Num = Num * Fr.Denom - Fr.Num * Denom;
		int Dif_Denom = Denom * Fr.Denom;
		return Fraction(Dif_Num, Dif_Denom);
	}

	Fraction operator*(const Fraction& Fr) 
	{
		int Mult_Num = Num * Fr.Num;
		int Mult_Denom = Denom * Fr.Denom;
		return Fraction(Mult_Num, Mult_Denom);
	}

    Fraction operator*(int num)
	{
		int Mult_Num = Num * num;
		return Fraction(Mult_Num, Denom);
	}


	Fraction operator/(const Fraction& Fr)  
	{
		if (Fr.Num != 0)
		{
			int Div_Num = Num * Fr.Num;
			int Div_Denom = Denom * Fr.Denom;
			return Fraction(Div_Num, Div_Denom);
		}
		else
		{
			cout << "Error." << "\n";
		}
	}
};

Fraction operator*(int num, Fraction& Fr)
{
	int Mult_Num = num * Fr.GetNum();
	return Fraction(Mult_Num, Fr.GetDenom());
}


int main() 
{
	Fraction frac1[4]
	{
		Fraction(1,2),
		Fraction(3,4),
		Fraction(5,6),
		Fraction(7,8)
	};
	Fraction frac2[4];
	Fraction obj;

	ofstream file("Fraction_File.DAT", ios::binary);

	if (!file)
	{
		cerr << "Error";
		exit(1);
	}

	file.write((char*)&frac1, sizeof(frac1));
	file.close();
	
	
	ifstream file1("Fraction_File.DAT", ios::binary);
	file1.read((char*)&frac2, sizeof(frac2));
	
	file1.seekg(sizeof(Fraction) * 2, ios::beg);
	file1.read((char*)&obj, sizeof(obj));
	for(int i = 0;i < 4;i++) 
	{
		cout << frac2[i].GetNum() << "/" << frac2[i].GetDenom() << "\n";

	}
	cout << "\n";
	
	cout << obj.GetNum() << "/" << obj.GetDenom() << "\n";
}
