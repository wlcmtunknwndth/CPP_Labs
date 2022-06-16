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
		//Constructor
        vect(int d)
        {
            cout << "\nVectConstructor(int d)\n";
            this->dim=d;
            this->V=new double[this->dim];
            for (int i = 0; i < this->dim; i++)
            {
                this->V[i]=0;
            }
            return;
        }

		vect(int d, double *v)
        {
            cout << "\nVectConstructor(int d, double *X)\n";
            this->dim=d;
            this->V=new double[this->dim];
            for (int i = 0; i < this->dim; i++)
            {
                this->V[i]=v[i];
            }
            return;
        }

        //Copying
		vect(vect const &b) 
        {
            cout << "\nCopying vect\n";
            this->dim=b.dim;
            this->V=new double[this->dim];
            for (int i = 0; i < b.dim; i++)
            {
                this->V[i]=b.V[i];
            }
            return;
        }

		//Destructor
		~vect()
        {
            cout << "\nVectDestructor\n";
            this->dim=0;
            delete[] this->V;
        }

		//Setting vect made by default constructor 
		void set(int d, double *x)
		{
			dim=d;
			this->V=x;
		}

		//Printing vect
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
		
        //==============
		vect& operator=(const vect &r)
        {
            cout << "\nAssignment vect\n";
            this->dim=r.dim;
            this->V=new double[this->dim];
            for (int i = 0; i < this->dim; i++)
            {
                this->V[i]=r.V[i];
            }
            return *this;
        }

        //++++++++++++++
		vect operator+(const vect& r)
        {
            cout << "\nAddition of vectors\n";
            vect res(r.dim);
            for (int i = 0; i < r.dim; i++)
            {
                res.V[i]=this->V[i]+r.V[i];
            }
            return res;
        }
        //Binary----------------
		vect operator-(const vect &r)
        {
            cout << "\nSubstracting vectors\n";
            vect res(r.dim);
            for (int i = 0; i < r.dim; i++)
            {
                res.V[i]=this->V[i]-r.V[i];
            }
            return res;
        }
        //Unary-----------------
		vect operator-()
        {
            cout << "\nNegativating vectors\n";
            vect res(this->dim);
            for (int i = 0; i < this->dim; i++)
            {
                res.V[i]=-(this->V[i]);
            }
            return res;
        }
        //SCALAR product
		double operator*(const vect &r)
        {
            cout << "\nScalar product of vectors\n";
            double res=0;
            for (int i = 0; i < this->dim; i++)
            {
                res+=this->V[i]*r.V[i];
            }
            return res;
        }
        //Multyplying by a num
		vect operator*(double k)
        {
            cout << "\nMultyplying vectors by a num\n";
            vect res(this->dim);
            for (int i = 0; i < this->dim; i++)
            {
                res.V[i]=this->V[i]*k;
            }
            return res;
        }
		friend class matr;

        bool operator==(vect &r)
        {
            int counter=0;
            for (int i = 0; i < r.dim; i++)
            {
                if (this->V[i] != r.V[i])
                {
                    counter++;
                }
            }
            if (counter > 0)
            {
                return false;
            }
            return true;
        }
};	

class matr
{
	double *X;
	int dim;
public:
    //Constructors
	matr(int d, double *x)
    {
        cout << "\nMatrConstructor(int d, double *x)\n";
        this->dim=d;
        this->X=new double[this->dim*this->dim];
        for (int i = 0; i < this->dim*this->dim; i++)
        {
            this->X[i]=x[i];
        }
    }	
	matr(int d)
    {
        this->dim=d;
        this->X=new double[this->dim*this->dim];
        for (int i = 0; i < this->dim*this->dim; i++)
        {
            this->X[i]=0;
        }
        
    }

    //Destructor
    ~matr()
    {
        cout << "MatrDestructor";
        this->dim=0;
        delete[] this->X;
    }
    
    //Copying constructor
	matr(const matr &b)
	{
		cout<< "\ncopying\n";
		X=new double[b.dim*b.dim];
		for (int i = 0; i < b.dim*b.dim; i++)
		{
			X[i]=b.X[i];
		}
		this->dim=b.dim;
	}

    //Printing
	void print() //hope there is no need to tell whats this
	{
        int counter=0;
		cout << "\nPrintin matrix\n";
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

	//=================
	matr& operator=(const matr &r)
    {
        cout << "\nAssignment Matrix\n";
        this->dim=r.dim;
        this->X=new double[this->dim*this->dim];
        for (int i = 0; i < this->dim*this->dim; i++)
        {
            this->X[i]=r.X[i];
        }
        return *this;
    }
    //+++++++++++++++++++++++ 
	matr operator+(const matr& r)
    {
        cout << "\nSum of matrixes\n";
        matr res(this->dim);
        for (int i = 0; i < this->dim*this->dim; i++)
        {
            res.X[i]=this->X[i]+r.X[i];
        }
        return res;
    }
    //Binary----------------
	// matr operator-(matr &r)
    // {
    //     cout << "\nSubstracting matrixes\n";
    //     matr res(this->dim);
    //     for (int i = 0; i < this->dim*this->dim; i++)
    //     {
    //         res.X[i]=this->X[i]-r.X[i];
    //     }
    //     return res;
    // } 
    friend matr operator-(matr l, matr r)
    {
        cout << "\nSubstracting matrixes\n";
        matr res(l.dim);
        for (int i = 0; i < l.dim*l.dim; i++)
        {
            res.X[i]=l.X[i]-r.X[i];
        }
        return res;
    }
    //Unary-----------------
	// matr operator-()
    // {
    //     cout << "\nNegativating matrix\n";
    //     matr res(this->dim);
    //     for (int i = 0; i < this->dim*this->dim; i++)
    //     {
    //         res.X[i]=-(this->X[i]);
    //     }
    //     return res;
    // }
    //k*M
    friend matr operator*(double k, const matr& r);
    //M*V
	vect operator*(vect& r)
    {
        cout << "\nMxV\n";
        vect res(this->dim);
        for (int i = 0; i < this->dim; i++)
            for (int j = 0; j < this->dim; j++)
    		    res.V[i] = res.V[i] + this->X[j+this->dim*i] * r.V[j];
        return res;
    }
    //M*M
	matr operator*(const matr &r)
    {
        cout << "\nM*M\n";
        matr res(this->dim);
        for (int i = 0; i<res.dim; i++)
            for (int j = 0; j<res.dim; j++)
    		    for (int h = 0; h<res.dim; h++)
    		        res.X[j+res.dim*i] = res.X[j+res.dim*i] + this->X[h+res.dim*i] * r.X[h*res.dim+j];
        return res; 
    }

    vect JacobiMethod(vect& b);
    friend class vect;
};

// matr operator-(matr &l, matr &r)
// {
//         cout << "\nSubstracting matrixes\n";
//         matr res(l.dim);
//         for (int i = 0; i < l.dim*l.dim; i++)
//         {
//             res.X[i]=l.X[i]-r.X[i];
//         }
//         return res;
// }

matr operator*(double k, const matr& r)
{
    cout << "\nMultyplying matr by a num\n";
    matr res(r.dim);
    for (int i = 0; i < res.dim*res.dim; i++)
    {
        res.X[i]=k*(r.X[i]);
    }
    return res;
}



int main()
{	
    
    srand(time(NULL));
    cout << "Enter dim of matr(n*n) and vect(n)\n";
    int n;
    cin >> n;
    //Matr A rand nums
    double *x=new double[n*n];
    for (int i = 0; i < n*n; i++)
    {
        x[i]=(rand()%100)-50;
        if (x[i] == 0)
        {
            x[i]+=1;
        }
    }
    matr A(n, x);
    A.print();
    //Vect b rand nums
    double *v=new double[n];
    for (int i = 0; i < n; i++)
    {
        v[i]=(rand()%100)-50.0;
        if (v[i] == 0)
        {
            v[i]+=1;
        }
    }
    vect b(n, v);
    b.print();

    A.JacobiMethod(b);
    return 0;
}

vect matr::JacobiMethod(vect &b)
{
    cout<< setprecision(6)<< fixed;
    getch();
    matr I(this->dim);
    matr D(this->dim);
	for (int i = 0; i < D.dim; i++)
	{
		D.X[i+D.dim*i]=1/this->X[i+this->dim*i];
        I.X[i+this->dim*i]=1;
	}
    I.print();
    D.print();   
    //Ax=b, x=(I-D^(1)*A)x+D^(-1)*b;
    
    // double *Xarr=new double[this->dim];
    // for (int i = 0; i < this->dim; i++)
    // {
    //     Xarr[i]=b.V[i]*D.X[i+D.dim*i];
    // }
    // vect x(this->dim, Xarr);
    vect x(this->dim);
    vect x_next(this->dim);
    matr A(*this);
    matr B= I-A*D;
    B.print();
    vect g = D*b;
    g.print();
    for(int i=0; i < 10000; i++)
    {    
        if ((A*x) == b) break;
        cout << "Itteration" << i << endl;
        x_next = B * x + g;
        cout << "\nb=\n";
        b.print();
        x = x_next;
        // cout << "\nA*x= \n";
        cout << "\nx=\n";
        x.print();
        
    }
    cout << "\nA*x=" << endl;
    vect res=A*x;
    res.print();
    cout << "\nb=\n";
    b.print();
    return x;
}