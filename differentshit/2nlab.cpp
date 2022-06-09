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
		static int count; //schetchik vektorov
		
		vect(int d, double *x);
		vect(vect &b); // copy
		vect(){}; //constructor
		
		~vect(){}; //destructor
		
		void set(int d, double *x)
		{
			dim=d;
			this->V=x;
		}
		
		void print()
		{
			for (int i = 0; i < dim; i++)
			{
				cout << "(";
				if (i == dim-1) cout<<this->V[i];
				else if(i < dim) cout<<this->V[i] << ",";
				cout << ")\n";
			}
		}
		
		vect& operator=(const vect &r); //+
		vect& operator+(const vect& r); //+
		friend vect& operator-(vect &l, vect &r); //+
		vect& operator-();
		double operator*(vect &r); 
		friend vect& operator*(double k, vect& r);
		double operator[](int i);
		friend class matr;
};	

vect::vect(int d, double *X)
{
	cout << "\nVector constructor\n";
	this->dim=d;
	this->V=X;
}

vect& vect::operator+(const vect& r) //сложение векторов
{
	cout << "Addition of vectors\n";
	for(int i=0; i<r.dim; i++)
	{
		this->V[i]=this->V[i]+r.V[i];
	}
	return *this;	
}

vect& vect::operator=(const vect &r) //присваивание вектору вектора
{
	cout << "assignment\n";
	for(int i=0; i < r.dim; i++)
	{
		this->V[i]=r.V[i];
	}
	return *this; 
} 

vect& operator-(vect& l, vect& r) //вычитание векторов
{
	cout << "substracting vectors\n";
	for (int i = 0; i < l.dim; i++)
	{
		l.V[i]=l.V[i]-r.V[i];
	}
	return l;
}

vect& vect::operator-() // получение противоположного по знаку вектора
{
	cout << "turning negative\n";
	for (int i = 0; i < this->dim; i++)
	{
		this->V[i]*=-1;
	}
	return *this;
}

double vect::operator*(vect &r) //скалярное произведение векторов
{
	cout << "multyplying vect by vect\n";
	double num1=0;
	for (int i = 0; i < this->dim; i++)
	{
		num1+=this->V[i]*r.V[i];
	}
	return num1;
}

vect& operator*(double k, vect& r) //произведение вектора на число
{
	cout << "multyplying vect by a num\n";
	for (int i = 0; i < r.dim; i++)
	{
		r.V[i]=r.V[i]*k;
	}
	return r;
}

double vect::operator[](int i) //получение нужно числа из вектора по индексу
{
	cout << "using class vect as a usual array\n";
	return this->V[i];
}

//--------------------------------------------------------------//
//--------------------------------------------------------------//
class matr
{
	double *X;
	int dim;
public:
	static int countMatr; int num; double idk; //idk protiv UB, ya de bil
	matr(int d, double *x);	
	
	matr()
	{
	}
	matr(const matr &b)
	{
		cout<< "copying";
		X=new double[b.dim*b.dim];
		for (int i = 0; i < b.dim*b.dim; i++)
		{
			X[i]=b.X[i];
		}
		this->dim=b.dim;
	}


	void print() //hope there is no need to tell whats this
	{
		int counter=0;
		cout << "\nPrintin matrix\n";
		if (this->X[dim+1] == idk)
		{
			for (int i = 0; i < dim; i++)
			{
				cout << "\n|" << this->X[i] << "|";		
			}
			return;
		}
		
		for (int i = 0; i < dim; i++)
		{
			cout << "|";
			for (int i=0; i < dim; i++)
			{

				cout << this->X[counter] << " ";
				counter++;	
			}
			cout << "|\n";
		}
		
	}
	//overloading operators for class matrix
	matr& operator=(const matr &r); //+
	matr& operator+(const matr& r); //+
	friend matr& operator-(matr &l,matr &r); 
	matr& operator-();
	matr& operator*(vect& r);
	matr& operator*(matr &r); 
	friend matr& operator*(double k, matr& r);
	double operator[](int i);
	matr& operator=(vect &r);
};

matr::matr(int d, double *x) //++++
{
	cout << "\n matr Constructor\n";
	dim=d;
	this->X=x;
}

matr& matr::operator=(const matr &r) //++++
{
	cout << "\noperator prisvaivaniya\n";
	for (int i = 0; i < r.dim*r.dim; i++)
	{
		this->X[i]=r.X[i];
	}
	return *this;
}

matr& matr::operator+(const matr& r)
{
	cout << "\nsumming matrixes\n";
	for (int i = 0; i < r.dim*r.dim; i++)
	{
		this->X[i]+=r.X[i];
	}
	return *this;
}

matr& operator-(matr &l, matr &r)
{
	cout << "\nsubstracting matrixes\n";
	for (int i = 0; i < r.dim*r.dim; i++)
	{
		l.X[i]-=r.X[i];
	}
	return l;
}

matr& matr::operator-()
{
	cout << "\nneg. matrix\n";
	for (int i = 0; i < this->dim*this->dim; i++)
	{
		this->X[i]*=-1;
	}
	return *this;
}

matr& matr::operator*(vect& r)
{
	cout << "Multyplying left matrix by right vector";
	vect pm;                
    pm.dim=r.dim;
    pm.V = new double[pm.dim]();
	for (int i = 0; i < pm.dim; i++)
        for (int j = 0; j < pm.dim; j++)
    		pm.V[i] = pm.V[i] + this->X[j+pm.dim*i] * r.V[j];
	
	delete this->X;
	this->X=pm.V;
	this->X[dim+1]=this->idk;
	return *this;
}

matr& matr::operator=(vect &r)
{
	cout << "\nassignment vect to matr\n";
	this->dim=r.dim;
	delete this->X;
	this->X=new double[r.dim+1]();
	for (int i = 0; i < this->dim; i++)
	{
		this->X[i]=r.V[i];
	}
	this->X[this->dim+1]=idk;
	return *this;
}

matr& matr::operator*(matr &r)
{
    cout << "Multiplying left matrix by matrix\n";
	matr pm;                
    pm.dim=r.dim;
    pm.X = new double[pm.dim*pm.dim]();
    for (int i = 0; i<pm.dim; i++)
        for (int j = 0; j<pm.dim; j++)
    		for (int h = 0; h<pm.dim; h++)
    		pm.X[j+pm.dim*i] = pm.X[j+pm.dim*i] + this->X[h+pm.dim*i] * r.X[h*pm.dim+j];
    *this=pm;
	return *this;
} 

int main()
{	
	//class vector
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
	
	cout << first*second << "\n";
	first.print();

	3*first;
	first.print();

	cout << first[0] << "\n";

	-first;
	first.print();

	//class matrix
	double third[4]={1, 2, 3, 4};
	double fourth[4]={5, 6, 7, 8};

	matr third1(2, third);
	matr fourth1(2, fourth);
	
	third1.print();
	third1=fourth1;
	
	third1.print();
	third1+fourth1;
	
	third1.print();
	third1-fourth1;
	
	third1.print();
	
	third1*fourth1;
	third1.print();
	
	double r[2]={1, 2};
	vect fifth;
	fifth.set(2, r);
	third1*fifth;
	third1.print();
	
	fourth1=fifth;
	fourth1.print();
	return 0;
}