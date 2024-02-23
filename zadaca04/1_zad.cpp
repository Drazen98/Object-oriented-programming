#include <iostream>
using namespace std;

class mojVektor {
protected:
    int* P;
    int _size;
    int _capacity;
public:
	mojVektor();
    mojVektor(int);
    mojVektor(const mojVektor& v);
    ~mojVektor();
    void print();
    void push_back(int);
    void pop_back();
    int* search(int);
    int capacity() const;
    int size() const;
    bool empty();
    int& at(int pos);
    int& front();
    int& back(); 
	mojVektor& operator=(const mojVektor&);     
	mojVektor& operator+=(const mojVektor&);
	mojVektor operator+(const mojVektor&) const;
	int operator*(const mojVektor&) const;
	bool operator==(const mojVektor&) const;
	int* begin() const;
	int* end() const;
	const int& operator[](int) const;
	int& operator[](int);
};
mojVektor::mojVektor(){
	P = new int [0];
	_size = 0;
	_capacity = 0;
}

mojVektor::mojVektor(int n) {
    P = new int[n];
    _capacity = n;
    _size = 0;
}

mojVektor::mojVektor(const mojVektor &v) {
    P = new int[v.capacity()];
    for (int i=0;i<v.size();i++){
    	P[i] = v.P[i];
	}
	_size = v.size();
	_capacity = v.capacity();

}

mojVektor::~mojVektor(){
	delete [] P;
}

void mojVektor::print(){
	for(int i=0;i<_size; i++)
		cout<< P[i] << " ";
	cout<<endl;
		
}

void mojVektor::push_back(int x){
	if (_size < _capacity)
	{
		P[_size] = x;
		_size++;
	}
	else if(_size == _capacity)
	{
		P[_size] = x;
		_capacity = 2 * _capacity;
		_size ++;
	}
}

int* mojVektor::search(int x)
{
		for (int i=0;i< _size;i++)
			if(P[i] == x)
				return &P[i];
	return NULL;
}		

int mojVektor::capacity() const{
	return _capacity;
}
int mojVektor::size() const{
return _size;
}

void mojVektor::pop_back(){
	_size--;
	if(_capacity/_size == 2)
		_capacity/=2;
}

bool mojVektor::empty(){
	if(_size==0)
		return true;
	else
		return false;
}
int& mojVektor::at(int pos){
	return P[pos];
}
int& mojVektor::front(){
	return P[0];
}
int& mojVektor::back(){
	return P[_size-1];
}

mojVektor& mojVektor::operator=(const mojVektor& v){
	if(P != NULL) delete [] P;
	_size = 0;
	_capacity = 0;
	P = new int[v.capacity()];
	_capacity = v.capacity();
    _size = v.size();
	for(int i = 0; i < _size;i += 1)
		P[i] = v.P[i];
	return *this;
}
mojVektor& mojVektor::operator+=(const mojVektor& v){
	for (int i = 0;i < _size;i += 1)
		P[i] += v.P[i];
	return *this;
}

mojVektor mojVektor::operator+(const mojVektor& v) const{
	mojVektor v1(_size);
	for(int i = 0;i < _size; i += 1)
		v1.push_back(P[i] + v.P[i]);
	return v1;
}

int mojVektor::operator*(const mojVektor& v) const{
	int rez = 0;
	for(int i = 0;i < _size; i+= 1)
		rez += P[i] * v.P[i]; 
	return rez;
}

bool mojVektor::operator==(const mojVektor& v) const{
	for(int i = 0; i < _size; i += 1)
		if(P[i] != v.P[i])
			return false;		
	return true;
}

const int& mojVektor::operator[](int x) const{
	return P[x];
}

int& mojVektor::operator[](int x){
	return P[x];
}

int* mojVektor::begin() const{
	int* i = &P[0];
	return i;
}

int* mojVektor::end() const{
	int* k = &P[_size];
	return k;
}
int main() {

    return 0;
}
