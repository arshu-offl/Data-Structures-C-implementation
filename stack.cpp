#include<iostream>
#define maxSize 100
using namespace std;

class stack{
	
	private :
	int arr[maxSize];
	int top;

	public :
	
	stack(){
		top = -1;
	}
	
	int Top(){
		if(top != -1)
			return arr[top];
		else
			return -1;
	}
	
	int push(int data){
		if(top == maxSize - 1)
			return 0;
			
		arr[++top] = data;
		return 1;
	}
	
	int pop(){
		if(top == -1)
			return 0;
		
		top--;
		return 1;
	}
	
	bool empty(){
		return top == -1;
	}
};

int main()
{
	stack s;
	
	int i = 0;
	while(s.push(i++));
	
	while(!s.empty()){
		cout << s.Top() << endl;
		s.pop();
	}
}
