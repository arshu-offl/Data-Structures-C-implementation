#include<iostream>
#define maxSize 100
using namespace std;

class queue{
	
	private :
	int arr[maxSize];
	int f,r;
	
	public :
	queue(){
		f = -1;
		r = -1;
	}
	
	int push(int val){
		if(r == maxSize - 1)
			return 0;
		
		arr[++r] = val;
		return 1;
	}
	
	int pop(){
		
		if(f == r)
			return -1;
		
		return arr[++f];
	}
	
	bool empty(){
		
		return f==r;
	}
	
	int front(){
		if(empty())
			return -1;
		
		return arr[f+1];
	}
};

int main()
{
	queue q;
	
	int i = 0;
	while(q.push(i++));
	
	while(!q.empty()){
		cout << q.front() << endl;
		q.pop();
	}
}
