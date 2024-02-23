#include <iostream>

using namespace std;
class Node { 
	public:     
	int value;     
	Node* prev;     
	Node* next;     
	Node(){};     
	Node(const Node&);     
	Node(int x){value = x;prev = nullptr;next = nullptr;};     
	Node(int x, Node* p, Node* n){value = x;prev = p;next = n;};     
	~Node(){};     
	void swap(Node& n){int tmp = value;value = n.value; n.value = tmp;}; 
}; 
Node::Node(const Node& n){
	value = n.value;
	prev = n.prev;
	next = n.next;
}

class CDLL { 
    protected:     
        Node* head;     
        Node* tail; 
    public:     
        CDLL(){head = nullptr;tail = nullptr;};     
        CDLL(const CDLL&);     
        ~CDLL();              
        void push_front(int);       
        void push_back(int); 
        void print() const;
        Node* search(int);
        bool isEmpty() const;
        bool erase(Node*);
        bool erase_at_pos(int);
        void sort();
};

void CDLL::sort(){
    int i = 0;
    Node* p;
    Node* n;
    
    do{
        
        i = 0;
        p = head;
        n = p -> next;
        
        do{
        if(p->value > n -> value && p != tail){
            p -> swap(*n);
            i++;
        }
        p = p -> next;
        n = n -> next;
        }while(p != head);

    }while(i!=0);


}

bool CDLL::erase_at_pos(int x){
Node* ptr = head;
int i = 1;
do{
        if(x == i){
            Node* p = ptr -> prev;
            Node* n = ptr -> next;
            p -> next = n;
            n -> prev = p;
            delete ptr;
            return true;
        }
        i++;
        ptr = ptr -> next;
        }while(ptr != head);
return false;

}
bool CDLL::erase(Node* pt){
Node* ptr = head;
do{
        if(ptr == pt){
            	Node* p = ptr -> prev;
                Node* n = ptr -> next;
                p -> next = n;
                n -> prev = p;
                delete ptr;
                return true;
                }
        ptr = ptr -> next;
        }while(ptr != head);
return false;
}

bool CDLL::isEmpty() const{
    return head == nullptr;
}

Node* CDLL::search(int x){
Node* ptr = head;
do{
        if(ptr -> value == x)
        return ptr;
        ptr = ptr -> next;
        }while(ptr != head);
    return nullptr;

}

CDLL::~CDLL(){
Node* ptr = head;
do{
        delete ptr;
        ptr = ptr -> next;
        }while(ptr != head);

}
CDLL::CDLL(const CDLL& c){
head = nullptr;
tail = nullptr;
Node* ptr = c.head;
do{
        this -> push_back(ptr -> value);
        ptr = ptr -> next;
        }while(ptr != c.head);

}

void CDLL::push_back(int x){
    if(head == nullptr)
    {
        Node* ptr = new Node(x);
        ptr -> prev = ptr;
        ptr -> next = ptr;
        head = ptr;
        tail = ptr;
        
}
    else{
        Node* ptr = new Node(x,tail,head);
        tail -> next = ptr;
        head -> prev = ptr;
        tail = ptr;

    }

}
void CDLL::push_front(int x){
    if(head == nullptr)
    push_back(x);
    else{
        Node* ptr = new Node(x,tail,head);
        tail -> next = ptr;
        head -> prev = ptr;
        head = ptr;

    }

}


void CDLL::print() const {
    Node* ptr = head;
    
    do{
        cout<<ptr -> value<<"  ";
        ptr = ptr -> next;
        }while(ptr != head);
        cout<<endl;
}

int main(){
	CDLL c;
    c.push_back(1);
    c.push_back(5);
    c.push_front(3);
    c.push_front(10);
    c.push_back(1325);
    c.push_back(12);
    c.push_back(547);
    c.push_front(800);
    c.push_front(13);
	c.print();
    CDLL c1 = c;
    c.sort();
    cout<<"Sortirana lista: ";
    c.print();
	return 0;
}

/*

Node* ptr = head;
do{
        ptr = ptr -> next;
        }while(ptr != head);

*/