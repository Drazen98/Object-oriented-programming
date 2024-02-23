#include <iostream>
#include <cmath>
using namespace std;

class Pravokutnik;

class Tocka{
    public:
        float x,y;
        Tocka();
        Tocka(int);
        Tocka(int, int);
        Tocka(const Tocka &t);
        void print();
        bool isInside(const Pravokutnik &p);
};

class Pravokutnik {
    public:
        Tocka A, B,C;
        Pravokutnik(const Pravokutnik &p);
        Pravokutnik(const Tocka &t1, const Tocka &t2, const Tocka &t3);
        float povrsina();
        float opseg();
        void print();
};

Tocka::Tocka(){
    this -> x = 0;
    this -> y = 0;
}
Tocka::Tocka(int x){
    this -> x = x;
    this -> y = x;
}
Tocka::Tocka(int x,int y){
    this -> x = x;
    this -> y = y;
}
Tocka::Tocka(const Tocka &t){
    x = t.x;
    y = t.y;
}

void Tocka::print(){
    cout<<"("<<x<<","<<y<<")";
}
bool Tocka::isInside(const Pravokutnik &p) {
    if((x >= p.A.x && x <= p.B.x) && (y<=p.C.y && y>=p.B.y))
        return true;
    else
        return false;
}



Pravokutnik::Pravokutnik(const Tocka &t1,const Tocka &t2,const Tocka &t3){
    A = t1;
    B = t2;
    C = t3;
}
Pravokutnik::Pravokutnik(const Pravokutnik &p){
    this -> A = p.A;
    this -> B = p.B;
    this -> C = p.C;
}
float Pravokutnik::povrsina(){

    return float(sqrt(pow(A.x-B.x,2) + pow(A.y-B.y,2)) * sqrt(pow(C.x-B.x,2) + pow(C.y-B.y,2)));
}
float Pravokutnik::opseg(){
    return float(2*(sqrt(pow(A.x-B.x,2) + pow(A.y-B.y,2)) + sqrt(pow(C.x-B.x,2) + pow(C.y-B.y,2))));
}

void Pravokutnik::print(){
    cout<<"A";
    A.print();
    cout<<", B";
    B.print();
}
    int main(){

    return 0;
}