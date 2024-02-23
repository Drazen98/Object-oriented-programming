#include <iostream>
using namespace std;
template<class T>
class mojVektor {
protected:
    T* P;
    int _size;
    int _capacity;
public:
	mojVektor();
    mojVektor(int);
    mojVektor(const mojVektor& v);
    ~mojVektor();
    void print();
    void push_back(T);
	void pop_back();
    T* search(T);
    int capacity() const;
	int size() const;
    bool empty();
    T& at(int pos);
    T& front();
    T& back();
	T& operator=(const mojVektor&);     
	T& operator+=(const mojVektor&);
	T operator+(const mojVektor&) const;
	T operator*(const mojVektor&) const;
	bool operator==(const mojVektor&) const;
	T* begin() const;
	T* end() const;
	const T& operator[](int) const;
	T& operator[](int); 
};
template<class T>
mojVektor<T>::mojVektor(){
	P = new T [0];
	_size = 0;
	_capacity = 0;
}
template<class T>
mojVektor<T>::mojVektor(int n) {
    P = new T[n];
    _capacity = n;
    _size = 0;
}
template<class T>
mojVektor<T>::mojVektor(const mojVektor &v) {
    P = new T[v.capacity()];
    for (int i=0;i<v.size();i++){
    	P[i] = v.P[i];
	}
	_size = v.size();
	_capacity = v.capacity();

}
template<class T>
mojVektor<T>::~mojVektor(){
	delete P;
}
template<class T>
void mojVektor<T>::print(){
	cout<<P[1]<<endl;
	for(int i=0;i<_size; i++)
		cout<< P[i] << " ";
	cout<<endl;
		
}
template<class T>
void mojVektor<T>::push_back(T x){
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
template<class T>
T* mojVektor<T>::search(T x)
{
		for (int i=0;i< _size;i++)
			if(P[i] == x)
				return &P[i];
	return NULL;
}		
template<class T>
int mojVektor<T>::capacity() const{
	return _capacity;
}
template<class T>
int mojVektor<T>::size() const{
return _size;
}
template<class T>
void mojVektor<T>::pop_back(){
	_size--;
	if(_capacity/_size == 2)
		_capacity/=2;
}
template<class T>
bool mojVektor<T>::empty(){
	if(_size==0)
		return true;
	else
		return false;
}
template<class T>
T& mojVektor<T>::at(int pos){
	return P[pos];
}
template<class T>
T& mojVektor<T>::front(){
	return P[0];
}
template<class T>
T& mojVektor<T>::back(){
	return P[_size-1];
}
template<class T>
T& mojVektor<T>::operator=(const mojVektor& v){
	if(P != NULL) delete [] P;
	_size = 0;
	_capacity = 0;
	P = new T[v.capacity()];
	_capacity = v.capacity();
    _size = v.size();
	for(int i = 0; i < _size;i += 1)
		P[i] = v.P[i];
	return *this;
}
template<class T>
T& mojVektor<T>::operator+=(const mojVektor& v){
	for (int i = 0;i < _size;i += 1)
		P[i] += v.P[i];
	return *this;
}
template<class T>
T mojVektor<T>::operator+(const mojVektor& v) const{
	mojVektor v1(_size);
	for(int i = 0;i < _size; i += 1)
		v1.push_back(P[i] + v.P[i]);
	return v1;
}
template<class T>
T mojVektor<T>::operator*(const mojVektor& v) const{
	int rez = 0;
	for(int i = 0;i < _size; i+= 1)
		rez += P[i] * v.P[i]; 
	return rez;
}
template<class T>
bool mojVektor<T>::operator==(const mojVektor& v) const{
	for(int i = 0; i < _size; i += 1)
		if(P[i] != v.P[i])
			return false;		
	return true;
}
template<class T>
const T& mojVektor<T>::operator[](int x) const{
	return P[x];
}
template<class T>
T& mojVektor<T>::operator[](int x){
	return P[x];
}
template<class T>
T* mojVektor<T>::begin() const{
	T* i = &P[0];
	return i;
}
template<class T>
T*	mojVektor<T>::end() const{
	T* k = &P[_size];
	return k;
}


int main() {
	mojVektor<float> v(5);
	v.push_back(1.23);
	v.push_back(5.123);
	v.push_back(5.541);
	v.push_back(5.541);
	v.push_back(5.541);
	v.push_back(8.5421);
	v.print();
    return 0;
}
