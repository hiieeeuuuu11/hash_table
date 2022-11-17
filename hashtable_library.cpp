#include<bits/stdc++.h>

using namespace std;

#define M 2069

//tao sach
class Book{
	public:
		int code;
		string name;
		int loc;
		int num;
	
	void inBook(){
		cout<<"Nhap ma sach:";
		cin>>this->code;
		cout<<"Nhap ten sach:";
		cin>>this->name;
		cout<<"Nhap vi tri:";
		cin>>this->loc;
		cout<<"Nhap so luong:";
		cin>>this->num;
	}	
		
};

//tao danh sach lien ket don
class Node {
	public:
	    Book book;
	    Node* next;
	    
	    Node()
	    {
	        next = NULL;
	    }
	    
	    Node(Book book)
	    {
	        this->book= book;
	        this->next = NULL;
	    }
};

class Linkedlist {
    public: 
		Node* head;
	    Linkedlist() {
			head = NULL; 
		}
	    void insertNode(Book book);
    	void deleteIndex(int i);
};

//tao bang bam
class hash_class{
	public:
		Linkedlist list[M];
	
	public:
		int hash_func(string s);
		void insert(Book book);
		void insert_all(string path);
		void out(string s);
		void findbook(string s);
		void deletebook(string s);	
		void display();
};

void Linkedlist::insertNode(Book book)
{
    Node* newNode = new Node(book);
  
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

void hash_class::insert_all(string s){
	ifstream ifs(s);
	Book temp;
	string str;
	while(!ifs.eof()){ 
        ifs>>temp.code;
        //cout<<"Ma:"<<temp.code;
        ifs>>temp.name;
        //cout<<"Ten:"<<temp.name;
        ifs>>temp.loc;
        //cout<<"Cho:"<<temp.loc;
        ifs>>temp.num;
       	//cout<<"So:"<<temp.num;
        insert(temp);
    }
    ifs.close();
}

int hash_class::hash_func(string s){
	int h=0;
	for(int i=0;i<s.length();i++){
		h+=(int)(s[i])*(i+1);
	}
	return h%M;
}

void hash_class::insert(Book book){
	int index= hash_func(book.name);
	list[index].insertNode(book);
}

void hash_class::display(){
	for(int i=0;i<M;i++){
		cout<<i<<":";
		Node *temp=list[i].head;
		while(temp!=NULL){
			cout<<temp->book.name<<"-";
			temp=temp->next;
		}
		cout<<"\n";
	}
}

void hash_class::findbook(string s){
	int index=hash_func(s);
	Node *temp=list[index].head;
	while(temp!=NULL){
		if(temp->book.name==s){
			cout<<"Ma sach: "<<temp->book.code<<endl;
			cout<<"Ten sach: "<<temp->book.name<<endl;
			cout<<"Vi tri sach: "<<temp->book.loc<<endl;
			cout<<"So luong: "<<temp->book.num<<endl;
		}
		temp=temp->next;
	}
}

void Linkedlist::deleteIndex(int i){
	Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;

    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }

    temp1 = head;
    if (i == 0) {
        head = head->next;
        delete temp1;
        return;
    }
  
    while (i-- > 0) {
        temp2 = temp1;
  		temp1 = temp1->next;
    }
  
    temp2->next = temp1->next;
    delete temp1;
}

void hash_class::deletebook(string s){
	int index=hash_func(s);
	int i=0;
	Node *temp=list[index].head;
	while(temp!=NULL){
		if(temp->book.name==s){
			break;
		}
		i++;
		temp=temp->next;
	}
	list[index].deleteIndex(i);
}

void hash_class::out(string s){
	ofstream of(s);
	for(int i=0;i<M;i++){
		if(list[i].head==NULL){
			continue;
		}
		Node *temp=list[i].head;
		while(temp!=NULL){
			of<<temp->book.code<<"\n";
			of<<temp->book.name<<"\n";
			of<<temp->book.loc<<"\n";
			of<<temp->book.num<<"\n";
			temp=temp->next;
		}
	}
	of.close();
}

int main(){
	//Trien khai bang bam va nap thong tin sach tu file
	hash_class h;
	h.insert_all("thuvien.txt");
	h.display();
	
	//Tim kiem tren bang bam
	h.findbook("DacNhanTam");
	
	//Them sach
	Book b;
	b.inBook();
	h.insert(b);
	
	//Xoa sach
	h.deletebook("ToanNangCao");
	
	//Xuat thu vien ra file
	h.out("output_libra.txt");
	
}
