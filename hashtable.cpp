#include<bits/stdc++.h>

using namespace std;

#define M 17

//tao danh sach lien ket don
class Node {
	public:
	    int data;
	    Node* next;
	    
	    Node()
	    {
	        data = 0;
	        next = NULL;
	    }
	    
	    Node(int da)
	    {
	        this->data = da;
	        this->next = NULL;
	    }
};

class Linkedlist {
    public: 
		Node* head;
		
	    Linkedlist() {
			head = NULL; 
		}
	    void insertNode(int);
};

void Linkedlist::insertNode(int data)
{
    Node* newNode = new Node(data);
  
    if (head == NULL) {
        head = newNode;
        return;
    }
  
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

//tao bang bam
class hash_class{
	public:
		Linkedlist list[M];
	
	public:
		int hash_func(int x);
		void insert(int x);
		void deleteitem(int k);	
		void display();
};

int hash_class::hash_func(int x){
	return(x%M);
}

void hash_class::insert(int x){
	int index= hash_func(x);
	list[index].insertNode(x);
}

void hash_class::display(){
	for(int i=0;i<M;i++){
		cout<<i<<":";
		Node *temp=list[i].head;
		while(temp!=NULL){
			cout<<temp->data<<"-";
			temp=temp->next;
		}
		cout<<"\n";
	}
}

int main(){
	hash_class h;
	int a[]={47,9,47,43,2,37,25,3,17,20,19,18,47,23,28,28,10,8,21,22,36,44,1,17,17,32,23,29,16,36,27,5,41,19,39,48,37,15,16,26,45,49,21,38,34,4,39,33,10,17,12,39,24,1,18,24,0,11,12,20,46,24,0,32,12,47,41,19,8,17,22,19,40,0,43,9,22,43,38,31,13,3,48,6,3,10,12,24,10,36,39,33,24,49,18,13,0,36,5,0};
	for(int i=0;i<100;i++){
		h.insert(a[i]);
	}
	h.display();
}
