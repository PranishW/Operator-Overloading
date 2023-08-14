#include <iostream>

using namespace std;

class Fraction
{
	int numer, denom;
	
	public:
		Fraction(int n=0,int d=1);
		Fraction operator + (Fraction);
		Fraction operator + (int);
		void display();
};
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
Fraction::Fraction(int n,int d)
{
	numer = n;
	denom = d;
}

Fraction Fraction::operator + (Fraction f2)
{
	Fraction f3;
	f3.numer = (numer * f2.denom + f2.numer * denom)/gcd(denom,f2.denom);
	f3.denom = (denom * f2.denom)/gcd(denom,f2.denom);
	int temp = f3.numer;
	f3.numer/=gcd(f3.numer,f3.denom);
	f3.denom/=gcd(temp,f3.denom);
	return f3;	
}

Fraction Fraction::operator + (int no)
{
	Fraction f2;
	f2.numer = numer * 1 + no * denom; 
	f2.denom = denom * 1;
	int temp = f2.numer;
	f2.numer/=gcd(f2.numer,f2.denom);
	f2.denom/=gcd(temp,f2.denom);
	return f2;
}

void Fraction::display()
{
	if(denom>1)
		cout << numer << "/" << denom << endl;
	else
		cout<< numer<<endl;
}

int main()
{
	int n1,d1,n2,d2;
	cout<<"Enter numerator and denominator for fraction f1 :- ";
	cin>>n1>>d1;
	cout<<"Enter numerator and denominator for fraction f2 :- ";
	cin>>n2>>d2;
	Fraction f1(n1,d1), f2(n2,d2), f3, f4;
	f3 = f2 + f1; 
	cout << "f1 contains ";
	f1.display();
	cout << "f2 contains ";
	f2.display();
	cout << "Added fraction is ";
	f3.display();
	int no;
	cout << "Enter a no to be added to fraction f1 :- ";
	cin >> no;
	f4 = f1 + no;
	cout << "Fraction + int is " << endl;
	f4.display();
	return 0;
}
