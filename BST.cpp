
 
#include<iostream>
using namespace std;

class Node {
	public:
	    int value;
    	    Node* left;
                   Node* right;

                   Node(int v){
    		value=v;
    		left=NULL;
    		right=NULL;
	     } 
};

class stack{
	private:
		int index;
		int size;
		Node** a;
	public:
		stack(int s){
			index=-1;
			size=s;
			a=new Node*[size];
		}
		~stack(){
			delete [] a;	
		}
		void push(Node* v){
			if(isFull()){
				cout<<"Stack is full\n";
			}
			else{
		    	             a[++index]=v;
			}
		}//push
	
                            void pop(){
			if(isEmpty()){
				cout<<"Stack is empty\n";
			}
			else{
	                                         a[index--];
			}
		}//pop
		Node* top(){
			return a[index];
		}//top
		bool isEmpty(){
			return (index==-1);
		}//isEmpty
		bool isFull(){
			return (index==size-1);
		}//isFull
};//class Stack

class BST{
	Node *p;
	Node *c;
	//int size=0;
	public:
		Node *root;
		BST(){
			p=NULL;
			c=NULL;
			root=NULL;
	}
		void insertion(int v){
	 		Node*nn=new Node(v);
			nn->right=NULL;
			nn->left=NULL;
			if (root==NULL){
				root=nn;
				cout<<"value is inserted"<<endl;
			}	
			else{
				c=root;
				while(c!=NULL){
					p=c;
					if(c->value>v){
						c=c->left;
					}
					else{
						c=c->right;
					}
				}//while
				if(v>p->value){
					p->right=nn;
				}
				else{
					p->left=nn;
				}
				cout<<"value is inserted"<<endl;
				//size++;
			}//else
		}///insertion
		void inorder(){
			stack s(100);
			c=root;
			while(c!=NULL || !s.isEmpty()){
				if(c!=NULL){
					s.push(c);//whats error in this line
					c=c->left;
				}
				else{
					
					c=s.top();
					s.pop();
					cout<<c->value<<" ";
					c=c->right;
				}
			}
		}//inorder
		void preorder(){
			stack s(100);
			s.push(root);
			while(!s.isEmpty()){
				c=s.top();
				cout<<c->value<<" ";
				s.pop();
				if(c->right!=NULL){
					s.push(c->right);
				}
				if(c->left!=NULL){
					s.push(c->left);
				}
			}//while
		}
		void postorder(){
			stack s(100);
			c=root;
			p=NULL;
			while(c!=NULL || !s.isEmpty()){
				if(c!=NULL){
					s.push(c);
					c=c->left;
				}
				else{
					c=s.top();
					if(c->right==NULL|| c->right==p){
						cout<<c->value<<" ";
						s.pop();
						p=c;
						c=NULL;
					}
					else{
						c=c->right;
					}
				}
			}
		}
	};

int main(){
	cout<<"********221017*********"<<endl;
	cout<<"********Aashfa Noor*********"<<endl;
	BST bst;
	bst.insertion(10);
	bst.insertion(12);
	bst.insertion(8);
	bst.insertion(2);
	cout << "\nInorder Traversal: ";
    bst.inorder();
    cout << "\npreorder Traversal: ";
    bst.preorder();
    cout << "\npostorder Traversal: ";
    bst.postorder();
	return 0;
}	

