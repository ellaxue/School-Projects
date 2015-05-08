/*
 * as20_RatClass.cpp
 *
 *  Created on: 2014/11/30
 *      Author: Ella Xue
 */

// Rat class i.e. a class for rational numbers
#include <iostream>
#include <cmath>
#include <cstdlib>

class Rat{
private:
	 int n;
	 int d;
public:
// constructors

	// default constructor
	Rat()
	{
		 n=0;
		 d=1;
	}

	// 2 parameter constructor
	Rat(int i, int j)
	{
		n=i;
		d=j;
	}

	// conversion constructor
	Rat(int i)
	{
		n=i;
		d=1;
	}

	//accessor functions (usually called get() and set(...) )
	int getN()
	{
		return n;
	}
	int getD()
	{
		return d;
	}
	void setN(int i)
	{
		n=i;
	}
	void setD(int i)
	{
		d=i;
	}

	//arithmetic operators
//	Rat operator+(Rat r)
//	{
//		Rat t;
//		t.n=n*r.d+d*r.n; // n=1 r.d =3 d=2 d.n=2
//		t.d=d*r.d; // d=2 r.d=3
//		return t;
//	}

	// 2 overloaded i/o operators
	friend std::ostream& operator<<(std::ostream& os, Rat r);
	friend std::istream& operator>>(std::istream& is, Rat& r);
	friend Rat operator+(Rat p, Rat q);
	friend Rat operator-(Rat p, Rat q);
	friend Rat operator*(Rat p, Rat q);
	friend Rat operator/(Rat p, Rat q);
}; //end Rat

//overloading arithmetic operators
Rat operator+(Rat p, Rat q)
{
	Rat t;
	t.n = p.n*q.d + q.n*p.d;
	t.d = p.d*q.d;
	return t;
}
Rat operator-(Rat p, Rat q)
{
	Rat t;
	t.n = p.n*q.d - q.n*p.d;
	t.d = p.d*q.d;
	return t;
}
Rat operator*(Rat p, Rat q)
{
	Rat t;
	t.n = p.n*q.n;
	t.d = p.d*q.d;
	return t;
}
Rat operator/(Rat p, Rat q)
{
	Rat t;
	t.n = p.n*q.d;
	t.d = p.d*q.n;
	return t;
}

// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
std::ostream& operator<<(std::ostream& os, Rat r)
{
	int whole_num = 0;

		// if the rational number can be converted into integer without any remaining, return the integer
		if(r.n % r.d == 0)
		{
			os<<r.n / r.d;
			return os;
		}

		//numerator > denominator, get the whole number out and simply the remaining rational number
		if(abs(r.n) > r.d)
		{
			whole_num = r.n / r.d;
			r.n = abs(r.n - whole_num*r.d);
		}

		//simply the rational number by finding the common divisors
		for (int i = r.n; i >1; i--)
		{
			if(r.n%i==0 && r.d%i==0)
			{
				r.n = r.n / i;
				r.d = r.d / i;
				i = r.n+1; //to update new value of i since the numerator has been reduced
			}
		}

	if (whole_num != 0)
		os<<whole_num<<" "<<r.n<<"/"<<r.d;
	else
		os<<r.n<<"/"<<r.d;

	return os;
}

// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
std::istream& operator>>(std::istream& is, Rat& r)
{
	is>>r.n>>r.d;
	return is;
}

int main()
{
	Rat x(1,2), y(2,3), z;
	z=x+y;// z = x.operator+(y);
	std::cout<<"z=x+y, z = "<<x<<" + "<<y<<" = "<<z<<std::endl;
	z=x-y;
	std::cout<<"z=x-y, z = "<<x<<" - "<<y<<" = "<<z<<std::endl;
	z=x*y;
	std::cout<<"z=x*y, z = "<<x<<" * "<<y<<" = "<<z<<std::endl;
	z=x/y;
	std::cout<<"z=x/y, z = "<<x<<" / "<<y<<" = "<<z<<std::endl<<std::endl;

	x.setN(3);
	y.setD(2);
	std::cout<<"After set method:" <<std::endl;
	z=x+y;
	std::cout<<"z=x+y, z = "<<x<<" + "<<y<<" = "<<z<<std::endl;
	z=x-y;
	std::cout<<"z=x-y, z = "<<x<<" - "<<y<<" = "<<z<<std::endl;
	z=x*y;
	std::cout<<"z=x*y, z = "<<x<<" * "<<y<<" = "<<z<<std::endl;
	z=x/y;
	std::cout<<"z=x/y, z = "<<x<<" / "<<y<<" = "<<z<<std::endl<<std::endl;

	std::cout<< "Please input 2 integer numbers:" <<std::endl;
	std::cin>> x;
	std::cout<<"x = "<< x <<std::endl<<std::endl;

	z= x+5;
	std::cout<<"z = x + 5, z = "<<x<<" + 5"<<" = "<<z<<std::endl;
	z= x-5;
	std::cout<<"z = x - 5, z = "<<x<<" - 5"<<" = "<<z<<std::endl;
	z= x*5;
	std::cout<<"z = x * 5, z = "<<x<<" * 5"<<" = "<<z<<std::endl;
	z= x/5;
	std::cout<<"z = x / 5, z = "<<x<<" / 5"<<" = "<<z<<std::endl<<std::endl;

	z= 5+x;
	std::cout<<"z = 5 + x, z = "<<"5 + "<<x<<" = "<<z<<std::endl;

	return 0;
}


