#include<iostream>
using namespace std;

class btree{
	
	public :
	btree *left,*right;
	int data;
	
	btree(){
		left = right = NULL;
	}
	btree(int val){
		left = right = NULL;
		data = val;
	}
	
	btree* insert(btree *root){
		
		if(!root)
			return NULL;
		
		int d;
		cout << "\nEnter left of " << data << " : ";
		cin >> d;
		
		if(d == -1)
			left = NULL;
		else{
			left = new btree(d);
			left = left->insert(left);
		}
		
		cout << "\nEnter right of " << data << " : ";
		cin >> d;
		
		if(d == -1)
			right = NULL;
		else{
			right = new btree(d);
			right = right->insert(right);
		}
		
		return root;
	}
	
	void inorder(btree *root){
		
		if(root){
			left->inorder(left);
			cout << data << " " ;
			right->inorder(right);
		}
	}7
};

int main()
{
	btree *root = NULL;
	cout << "Enter Root : ";
	
	int data;
	cin >> data;
	if(data != -1){
		root = new btree(data);
	}
	
	root = root->insert(root);
	root->inorder(root);
}
