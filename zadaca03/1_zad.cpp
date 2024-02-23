#include <iostream>
#include <list>

using namespace std;

list<float>::iterator l_1;

float sum(list<float>& a){
	float s = 0;
	for (l_1 = a.begin(); l_1 != a.end(); l_1 ++)
	s += (*l_1); 
	return s;
}

float prod(list<float>& a){
	float um = 1;
	for (l_1 = a.begin(); l_1 != a.end(); l_1 ++)
	um *= (*l_1);
	return um;	
}

float min(list<float>& a){
	float m = *(a.begin());
	for (l_1 = a.begin(); l_1 != a.end(); l_1 ++)
	if(*l_1 < m)
	m = *l_1;
	return m;
}
float max(list<float>& a){
	float M = *(a.begin());
	for (l_1 = a.begin(); l_1 != a.end(); l_1 ++)
	if(*l_1 > M)
	M = *l_1;
	return M;
}

int main(){
	list<float> l1;
	
	l1.push_front(10.9);
	l1.push_front(10.8);
	l1.push_front(10.7);
	l1.push_front(10.6);
	for(l_1 = l1.begin(); l_1 != l1.end(); l_1 ++)
	cout<<*l_1<<" ";
	cout<<endl;
	cout<<"Suma je "<<sum(l1)<<endl;
	cout<<"produkt je "<<prod(l1)<<endl;
	cout<<"Min je "<<min(l1)<<endl;
	cout<<"Max je "<<max(l1)<<endl;
	return 0;
}
