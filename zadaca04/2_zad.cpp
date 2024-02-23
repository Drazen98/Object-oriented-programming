#include <iostream>
using namespace std;

class Complex{
protected:
	float re, im;
public:
	Complex(float re = 0, float im = 0);
	
	float real() const { return re; }
	float imag() const { return im; }
	
	void real(float r) { re = r; }
	void imag(float i) { im = i; }
	
	Complex& operator=(const Complex&);
	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);
	
	Complex operator+(const Complex&) const;
	Complex operator-(const Complex&) const;
	Complex operator*(const Complex&) const;
	Complex operator/(const Complex&) const;
	
	bool operator==(const Complex&) const;
	bool operator!=(const Complex&) const;
	
	void print();
};

Complex::Complex(float x,float y){
	re = x;
	im = y;
}

Complex& Complex::operator=(const Complex& c){
	re = c.real();
	im = c.imag();
}

Complex& Complex::operator+=(const Complex& c){
	re += c.real();
	im += c.imag();
}

Complex& Complex::operator-=(const Complex& c){
	re -= c.real();
	im -= c.imag();
}

Complex& Complex::operator*=(const Complex& c){
	float re1 = re;
	float im1 = im;
	re = re1 * c.real() - im1 * c.imag();
	im = re1 * c.imag() + c.real() * im1;
}

Complex& Complex::operator/=(const Complex& c){
	float raz = c.real() * c.real() + c.imag() * c.imag(); 
	Complex cp(c.real(),(-1*c.imag()));
	Complex cp1 = *(this) * cp;
	re = cp1.real() / raz;
	im = cp1.imag() / raz;
}

Complex Complex::operator+(const Complex& c) const{
	Complex c1(re + c.real(),im + c.imag());
	return c1;

}

Complex Complex::operator-(const Complex& c) const{
	Complex c1(re - c.real(),im - c.imag());
	return c1;

}

Complex Complex::operator*(const Complex& c) const{
	Complex c1(re * c.real() - im * c.imag(),re * c.imag() + c.real() * im);
	return c1;

}

Complex Complex::operator/(const Complex& c) const{
	float raz = c.real() * c.real() + c.imag() * c.imag(); 
	Complex cp(c.real(),(-1*c.imag()));
	Complex cp1 = *(this) * cp;
	Complex c1(cp1.real() / raz,cp1.imag() / raz);
	return c1;

}

bool Complex::operator==(const Complex& c) const{
return(re == c.real() && im == c.imag());
}

bool Complex::operator!=(const Complex& c) const{
return(re != c.real() || im != c.imag());
}

void Complex::print(){
	if(imag() > 0)
		cout<<real()<<" + "<<imag()<<"i"<<endl;
	else
		cout<<real()<<" - "<<imag() * (-1) <<"i"<<endl;		
}


int main(){
	return 0;
}
