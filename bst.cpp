#include<iostream>
using namespace std;

class bst{
	private :
	int data;
	bst *left,*right;
	
	public :
	bst(){
		left = right = NULL;
	}
	bst(int val){
		data = val;
		left = right = NULL;
	}
	
	int findRightMost(bst* root){
		
		if(!root->right)
			return root->data;
		
		return findRightMost(root->right);
			
	}
	
	bst* del(bst* root,int val){
		
		if(!root)
			return root;
		
		if(root->data == val){
			if(left){
				
				int best = left->findRightMost(left);
				data = best;
				left = left->del(left,best);
			}
			else 
				root = root->left;
		}
		else if(root->data > val)
			left = left->del(left,val);
		else
			right = right->del(right,val);
		
		return root;
	}
	
	bst* insert(bst* root,int val){
		
		if(!root)
			return new bst(val);
		
		if(data < val){
			if(right)
				right = right->insert(right,val);
			else
				right = new bst(val);
		}
		else if(data > val){
			if(left)
				left = left->insert(left,val);
			else
				left = new bst(val);
		}	
		return root;
	}
	
	void inorder(bst* root){
		
		if(root){
			
			left->inorder(left);
			cout << data << " ";
			right->inorder(right); 
		}
	}
	
	int search(bst* root,int val){
		if(!root)
			return -1;
		
		if(data == val)
			return 1;
		else if(data > val)
			return left->search(left,val);
		else
			return right->search(right,val);
	}
};

int main()
{
	bst *t = NULL;
	
	int k = 10;
	while(k--)
		t = t->insert(t,k);
		
	t->inorder(t);
}
