//Nanka iyana yokan ga suru
#include <iostream>
#include <iomanip>
using namespace std;

class complex
{
	double re;
	double im;
	
	public:
	complex()
	{
		re=0;
		im=0;
	}
	
		complex(double re, double im);
		
		complex(complex &x);
		~complex()
		{
			
		}
		
		double getre()
		{
			return this->re;
		}
		
		double getim()
		{
			return this->im;
		}
		
		complex operator+(complex r)
		{
			double rr=this->re+r.re, ii=im+r.im;
			complex z(rr, ii);
			return z;
		}
		friend complex operator-(complex l, complex r);
//		complex operator-(complex r)
//		{
//		double rr=l.re-r.re, ii=l.im-r.im;
//		complex z=complex(rr, ii);
//		return z;
//		}
		void print();
};

complex::complex(complex &x)
{
	re=x.re;
	im=x.im;
}

complex::complex(double rr, double ii)
{
	re=rr;
	im=ii;
}

void complex::print()
{
	cout << "Re=" << this->re << "\n";
	cout << "Im=" << im << "\n";
	return;
}


int main()
{
	complex a, b(1,2), c(1,3);
	a=b+c;
	a.print();
	return 0;
}