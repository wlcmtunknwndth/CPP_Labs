#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class vect
{
	int dim; // razmernost'
	double *V; // massiv 
	
	public:
		int num;
		static int count;
		
		vect(int d, double *x);
		vect(int d);
		vect(vect &b); // copy
		vect(){} //constructor
		
		~vect(){} //destructor
		
		void set(int d, double *x)
		{
			dim=d;
			this->V=x;
		}
		
		void print()
		{
			cout << "(";
			for (int i = 0; i < dim; i++)
			{
				if (i == dim-1) cout<<this->V[i];
				else if(i < dim) cout<<this->V[i] << ";";
			}
			cout << ")";
		}
		
		vect& operator=(const vect &r); //+
		vect& operator+(const vect& r); //+
		friend vect operator-(vect &l, vect &r); //+
		vect& operator-();
		double operator*(vect &r); 
		friend vect& operator*(double k, vect& r);
		double operator[](int i);
		
};	

vect& vect::operator+(const vect& r) //сложение векторов
{
	for(int i=0; i<r.dim; i++)
	{
		this->V[i]=this->V[i]+r.V[i];
	}
	return *this;	
}

vect& vect::operator=(const vect &r) //присваивание вектору вектора
{
	for(int i=0; i < r.dim; i++)
	{
		this->V[i]=r.V[i];
	}
	return *this; 
} 

vect operator-(vect& l, vect& r) //вычитание векторов
{
	vect tmp;
	for (int i = 0; i < l.dim; i++)
	{
		tmp.V[i]=l.V[i]-r.V[i];
	}
	return tmp;
}

vect& vect::operator-() // получение противоположного по знаку вектора
{
	for (int i = 0; i < this->dim; i++)
	{
		this->V[i]*=-1;
	}
	return *this;
}

double vect::operator*(vect &r) //скалярное произведение векторов
{
	double num1=0;
	for (int i = 0; i < this->dim; i++)
	{
		num1+=this->V[i]*r.V[i];
	}
	return num1;
}

vect& operator*(double k, vect& r) //произведение вектора на число
{
	for (int i = 0; i < r.dim; i++)
	{
		r.V[i]=r.V[i]*k;
	}
	return r;
}

double vect::operator[](int i) //получение нужно числа из вектора по индексу
{
	return this->V[i];
}



int main()
{	
	double f[3]={1, 4, 3};
	vect first;
	first.set(3, f);
	
	vect second;
	double s[3]={1, 2, 3};
	second.set(3, s);
	
	first+second;
	first.print();
	second.print();
	
	first=first-second; 
	first.print();
	
	cout << first*second;
	first.print();

	3*first;
	first.print();

	cout << first[0];

	-first;
	first.print();

	return 0;
}