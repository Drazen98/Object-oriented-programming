#include <iostream>
#include <vector>

using namespace std;

/*
class mojVektor {
protected:
    int* P;
    int _size;
    int _capacity;
public:
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
};

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
*/

int main() {
	vector<int> v;
	v.push_back(10);
	v.push_back(9);
	v.push_back(8);
	v.push_back(7);
	v.push_back(6);
	v.push_back(5);
	v.push_back(4);
	vector<int>::iterator v_1;
	for(v_1 = v.begin();v_1 != v.end();v_1++)
	cout<<*v_1<<" ";
    return 0;
}
