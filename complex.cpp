#include <iostream>
using namespace std;

class Complex
{
	double real,imaginary;
	public:
		Complex operator + (Complex);
		Complex operator - (Complex);
		Complex operator * (Complex);
		friend istream& operator >> (istream&,Complex&);
		friend ostream& operator << (ostream&,Complex&);
};
Complex Complex::operator +(Complex c2)
{
	Complex c3;
	c3.real = this->real + c2.real;
	c3.imaginary = this->imaginary + c2.imaginary;
	return c3;
}
Complex Complex::operator -(Complex c2)
{
	Complex c3;
	c3.real = this->real - c2.real;
	c3.imaginary = this->imaginary - c2.imaginary;
	return c3;
}
Complex Complex::operator *(Complex c2)
{
	Complex c3;
	c3.real = this->real*c2.real - this->imaginary*c2.imaginary;
	c3.imaginary = this->real*c2.imaginary + c2.real*this->imaginary;
	return c3;
}
istream& operator >>(istream& in,Complex& c)
{
	cout<<"Enter the real and imaginary value of the complex number :- ";
	in>>c.real>>c.imaginary;
	return in;
}
ostream& operator <<(ostream& out,Complex& c)
{
	if(c.imaginary<0)
		out<<c.real<<" - i"<<-c.imaginary;
	else
		out<<c.real<<" + i"<<c.imaginary;
	return out;
}
int main()
{
	Complex c1,c2,c3;
	cin>>c1;
	cin>>c2;
	cout<<"Complex Number 1 :- "<<c1<<endl;
	cout<<"Complex Number 2 :- "<<c2<<endl;
	c3 = c1 + c2;
	cout<<"Addition of 2 complex nos is :- "<<c3<<endl;
	c3 = c1 - c2;
	cout<<"Subtraction of 2 complex nos is :- "<<c3<<endl;
	c3 = c1*c2;
	cout<<"Multiplication of 2 complex nos is :- "<<c3<<endl;
	return 0;
}
