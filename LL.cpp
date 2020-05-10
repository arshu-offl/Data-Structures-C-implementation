#include<iostream>
using namespace std;

class list{
	public :
	list *next;
	int data;
	
	list(){
		next = NULL;
	}
	list(int val){
		next = NULL;
		data = val;
	}
	
	list * insertHead(list *head,int val){
		
		list *temp = new list(val);
		temp->next = head;
		return temp;
	}
	
	list *insertEnd(list *h,int val){
		
		if(!h)
			return new list(val);
			
		list *t = h;
		while(t->next)
			t = t->next;
			
		t->next = new list(val);
		return h;
	}
	
	void print(list *head){
		list *t = head;
		
		while(t){
			cout << t->data << endl;
			t = t->next;
		}
	}
};

int main()
{
	list *l;
	
	l = l->insertEnd(l,10);
	l = l->insertEnd(l,20);
	l = l->insertEnd(l,30);
	l = l->insertHead(l,5);
	
	l->print(l);
}
